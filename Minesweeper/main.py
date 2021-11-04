import pygame
import sys
import time
from enum import Enum
from pygame.locals import *
from setting import *

pygame.init()  # 游戏初始化
pygame.mixer.init()  # 游戏音效初始化
# 通过方块的个数和大小设置实际屏幕窗口显示的大小
RealWIDTH = WIDTH * SIZE
RealHEIGHT = (HEIGHT + 2) * SIZE
screen = pygame.display.set_mode((RealWIDTH, RealHEIGHT))
pygame.display.set_caption('扫雷')  # 设置显示游戏名
# pygame.mouse.set_cursor(size=(24,24),...)
# 本来想通过mouse模块中的set_cursor函数，将鼠标光标放大一些便于玩家观看和操作，但由于不了解应该如何设置相应的掩码关键字，只能放弃

# 图像处理
# 加载三个状态脸的位图
img_face_death_up = pygame.image.load('face_death_up.bmp').convert()
img_face_smile_up = pygame.image.load('face_smile_up.bmp').convert()
img_face_victory_up = pygame.image.load('face_victory_up.bmp').convert()
img_face_death_down = pygame.image.load('face_death_down.bmp').convert()
img_face_smile_down = pygame.image.load('face_smile_down.bmp').convert()
img_face_victory_down = pygame.image.load('face_victory_down.bmp').convert()
fsize = int(SIZE * 1.25)  # 笑脸大小比方块稍大一些
img_face_death_up = pygame.transform.smoothscale(img_face_death_up, (fsize, fsize))
img_face_smile_up = pygame.transform.smoothscale(img_face_smile_up, (fsize, fsize))
img_face_victory_up = pygame.transform.smoothscale(img_face_victory_up, (fsize, fsize))
img_face_death_down = pygame.transform.smoothscale(img_face_death_down, (fsize, fsize))
img_face_smile_down = pygame.transform.smoothscale(img_face_smile_down, (fsize, fsize))
img_face_victory_down = pygame.transform.smoothscale(img_face_victory_down, (fsize, fsize))

# 加载显示各个数字和图案方块的位图
img0 = pygame.image.load('0.bmp').convert()  # 表示被打开且周围没有雷的方块
img1 = pygame.image.load('1.bmp').convert()
img2 = pygame.image.load('2.bmp').convert()
img3 = pygame.image.load('3.bmp').convert()
img4 = pygame.image.load('4.bmp').convert()
img5 = pygame.image.load('5.bmp').convert()
img6 = pygame.image.load('6.bmp').convert()
img7 = pygame.image.load('7.bmp').convert()
img8 = pygame.image.load('8.bmp').convert()
img_blank = pygame.image.load('blank.bmp').convert()
img_flag = pygame.image.load('flag.bmp').convert()
img_sign = pygame.image.load('sign.bmp').convert()
img_mine = pygame.image.load('mine.bmp').convert()
img_blood = pygame.image.load('blood.bmp').convert()
img_error = pygame.image.load('error.bmp').convert()
# 设置其大小与每个方块的size一致
img0 = pygame.transform.smoothscale(img0, (SIZE, SIZE))
img1 = pygame.transform.smoothscale(img1, (SIZE, SIZE))
img2 = pygame.transform.smoothscale(img2, (SIZE, SIZE))
img3 = pygame.transform.smoothscale(img3, (SIZE, SIZE))
img4 = pygame.transform.smoothscale(img4, (SIZE, SIZE))
img5 = pygame.transform.smoothscale(img5, (SIZE, SIZE))
img6 = pygame.transform.smoothscale(img6, (SIZE, SIZE))
img7 = pygame.transform.smoothscale(img7, (SIZE, SIZE))
img8 = pygame.transform.smoothscale(img8, (SIZE, SIZE))
img_blank = pygame.transform.smoothscale(img_blank, (SIZE, SIZE))
img_flag = pygame.transform.smoothscale(img_flag, (SIZE, SIZE))
img_sign = pygame.transform.smoothscale(img_sign, (SIZE, SIZE))
img_mine = pygame.transform.smoothscale(img_mine, (SIZE, SIZE))
img_blood = pygame.transform.smoothscale(img_blood, (SIZE, SIZE))
img_error = pygame.transform.smoothscale(img_error, (SIZE, SIZE))

# 音频文件加载并处理音量
bomb_sound = pygame.mixer.Sound("bomb.wav")
vict_sound = pygame.mixer.Sound("victory.wav")
bomb_sound.set_volume(0.1)
vict_sound.set_volume(0.1)

# 基本属性
bgc = (225, 225, 225)  # 设置背景色
# 设置脸在窗口中的位置
fpos_x = (RealWIDTH - fsize) // 2
fpos_y = (SIZE * 2 - fsize) // 2
# 设置计时器和剩余雷数的字体及大小
nfont = pygame.font.Font('CLK.TTF', int(SIZE * 1.8))  # 得分的字体
numc = (250, 40, 40) # 数字颜色
# 枚举类型表示游戏状态
class GameLife(Enum):
    initial = 0
    on = 1
    win = 2
    over = 3

# 建立数字方块位图的字典，便于用相应的数字直接进行索引
img_dict = {0: img0, 1: img1, 2: img2, 3: img3, 4: img4, 5: img5, 6: img6, 7: img7, 8: img8}

game_status = GameLife.initial
sweeper = Sweeper()
start_time = None  # 初轮开始时间
run_time = 0       # 该轮开始时长

while True:
    # 进入游戏循环
    screen.fill(bgc)  # 填充背景
    
    for event in pygame.event.get():  # 捕捉事件
        face_status = 0  # 记录脸被点击或松开的变量
        if event.type == QUIT:
            sys.exit()
        elif event.type == MOUSEBUTTONDOWN:
            # 通过事件触发的位置得到方块的坐标
            mouse_x, mouse_y = event.pos
            x = mouse_x // SIZE
            y = mouse_y // SIZE - 2
            b1, b2, b3 = pygame.mouse.get_pressed()  # b1,b2,b3分别为鼠标左键、滑轮、右键
            if b1 and y < 0:
                if fpos_x <= mouse_x <= fpos_x + fsize and fpos_y <= mouse_y <= fpos_y + fsize:
                    face_status =  1  # 检测并记录脸是否被点击
            elif b1 and not b3 and not game_status == GameLife.over and not game_status == GameLife.win:
                block = sweeper.get_block(x, y)
                if block.status == Status.initial:
                    block.status = Status.hint  # 检测并记录脸是否被点击
            if game_status == GameLife.on and y >= 0:
                if b1 and b3:  # 若同时点击鼠标左右键
                    block = sweeper.get_block(x, y)
                    if block.status == Status.open:
                        if not sweeper.double_mouse_button_down(x, y):
                            game_status = GameLife.over
        elif event.type == MOUSEBUTTONUP:
            if y < 0:
                if fpos_x <= mouse_x <= fpos_x + fsize and fpos_y <= mouse_y <= fpos_y + fsize:
                    game_status = GameLife.initial  # 脸被点击后，则重新开始游戏
                    sweeper = Sweeper()
                    start_time = time.time()
                    run_time = 0
                    continue

            if game_status == GameLife.initial:  # 任意方块被点击后，游戏正式开始
                game_status = GameLife.on
                start_time = time.time()
                run_time = 0
                
            if game_status == GameLife.on:
                block = sweeper.get_block(x, y)
                if b1 and not b3:   # 松开鼠标左键
                    if block.status == Status.hint:
                        if not sweeper.sweep_mine(x, y):
                            game_status = GameLife.over
                elif not b1 and b3:   # 松开鼠标右键
                    if block.status == Status.initial:
                        block.status = Status.flag
                    elif block.status == Status.flag:
                        block.status = Status.sign
                    elif block.status == Status.sign:
                        block.status = Status.initial
                if b1 and b3:  # 松开左右键
                    if block.status == Status.double:
                        sweeper.double_mouse_button_up(x, y)

    if game_status == GameLife.on:  # 计算游戏时长，单位为秒
        run_time = int(time.time() - start_time)

    # 事件捕捉完毕，对游戏画面进行显示
    # 游戏进行时，显示时长
    img_time = nfont.render('%03d' % run_time, True, numc, (0, 0, 0))
    screen.blit(img_time, (525, 0))
    # 对所有方块检测状态并显示相应图案，同时计算插旗和打开的方块的数量
    flag_count = 0
    safe_count = 0
    # 对二维矩阵的每个元素进行操作
    for row in sweeper.blocks:
        for block in row:
            pos = (block.x * SIZE, (block.y + 2) * SIZE)
            if block.status == Status.open:
                screen.blit(img_dict[block.around_mine_count], pos)
                safe_count += 1  # 当检测到的方块被安全打开时，无雷的计数变量自增
            elif block.status == Status.double:
                screen.blit(img_dict[block.around_mine_count], pos)
            elif block.status == Status.blood:
                screen.blit(img_blood, pos)
            elif block.status == Status.flag:
                screen.blit(img_flag, pos)
                flag_count += 1
                if game_status == GameLife.over and block.mine == 0:
                    screen.blit(img_error, pos)  # 游戏结束时，显示插错旗的方块
            elif block.status == Status.sign:
                screen.blit(img_sign, pos)
            elif block.status == Status.hint:
                screen.blit(img0, pos)
            elif game_status == GameLife.over and block.mine:
                screen.blit(img_mine, pos)  #游戏结束时，显示所有雷
            elif block.mine == 0 and block.status == Status.flag:
                screen.blit(img_error, pos)
            elif block.status == Status.initial:
                screen.blit(img_blank, pos)

    if WIDTH * HEIGHT - safe_count == MINE_NUM:
        # 如果所有没有打开的方块与雷的总数相等，游戏胜利
        game_status = GameLife.win

    if not game_status == GameLife.win:
        img_num = nfont.render('%02d' % (MINE_NUM - flag_count), True, numc, (0, 0, 0))
        screen.blit(img_num, (20, 0))
        
    if game_status == GameLife.win:
        # 游戏胜利，雷数直接归零，并自动在雷上标注红旗，同时播放胜利的音效
        vict_sound.play()
        if face_status:
            screen.blit(img_face_victory_down, (fpos_x, fpos_y))
        else:
            screen.blit(img_face_victory_up, (fpos_x, fpos_y))
        img_num = nfont.render('00', True, numc, (0, 0, 0))
        screen.blit(img_num, (20, 0))
        for row in sweeper.blocks:
            for block in row:
                pos = (block.x * SIZE, (block.y + 2) * SIZE)
                if block.mine:
                    screen.blit(img_flag, pos)     
    elif game_status == GameLife.over:
        bomb_sound.play()  # 失败时播放地雷爆炸的音效
        if face_status:
            screen.blit(img_face_death_down, (fpos_x, fpos_y))
        else:
            screen.blit(img_face_death_up, (fpos_x, fpos_y))
    else:
        if face_status:
            screen.blit(img_face_smile_down, (fpos_x, fpos_y))
        else:
            screen.blit(img_face_smile_up, (fpos_x, fpos_y))

    templs = [sweeper.blocks[0][i] for i in range(3)]  # 为使前三块方块不被后显示的雷数的黑色背景遮挡，对该四块重新进行显示
    for block in templs:
        pos = (block.x * SIZE, (block.y + 2) * SIZE)
        if block.status == Status.open:
            screen.blit(img_dict[block.around_mine_count], pos)
            safe_count += 1
        elif block.status == Status.double:
            screen.blit(img_dict[block.around_mine_count], pos)
        elif block.status == Status.blood:
            screen.blit(img_blood, pos)
        elif block.status == Status.flag:
            screen.blit(img_flag, pos)
            flag_count += 1
            if game_status == GameLife.over and block.mine == 0:
                screen.blit(img_error, pos)  # 游戏结束时，显示插错旗的方块
        elif block.status == Status.sign:
            screen.blit(img_sign, pos)
        elif block.status == Status.hint:
            screen.blit(img0, pos)
        elif game_status == GameLife.over and block.mine:
            screen.blit(img_mine, pos)  #游戏结束时，显示所有雷
        elif block.mine == 0 and block.status == Status.flag:
            screen.blit(img_error, pos)
        elif block.status == Status.initial:
            screen.blit(img_blank, pos)
        
    pygame.display.update()


