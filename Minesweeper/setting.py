import random
from enum import Enum

WIDTH = 30  # 横向方块个数
HEIGHT = 16  # 纵向方块个数
SIZE = 20  # 方块实际长宽
MINE_NUM = 99  # 雷数

class Status(Enum):  # 枚举方块的状态
    initial = 0  # 初始
    open = 1  # 打开且无雷
    mine = 2  # 有雷
    blood = 3  # 踩雷
    flag = 4  # 插旗
    sign = 5  # 标记
    hint = 6  # 单击时
    double = 7  # 双击时

class Block(object):
    def __init__(self, x, y, mine=0):
        self._x = x
        self._y = y
        self._mine = 0
        self.set_mine(mine)
        self._status = Status.initial
        self._around_mine_count = -1

    def __repr__(self):
        return str(self._mine)

    def getx(self):
        return self._x

    def setx(self, x):
        self._x = x

    x = property(getx, setx)

    def gety(self):
        return self._y

    def sety(self, y):
        self._y = y

    y = property(gety, sety)

    def get_mine(self):
        return self._mine

    def set_mine(self, mine):
        self._mine = mine

    mine = property(get_mine, set_mine, doc='0:无雷 1:有雷')

    def get_status(self):
        return self._status

    def set_status(self, mine):
        self._status = mine

    status = property(get_status, set_status, doc='Status')

    def get_around_mine_count(self):
        return self._around_mine_count

    def set_around_mine_count(self, around_mine_count):
        self._around_mine_count = around_mine_count

    around_mine_count = property(get_around_mine_count, set_around_mine_count, doc='周围雷数')

def _get_around(x, y):
    # 返回的列表由(x, y)周围方块的坐标组成
    return [(i, j)
            for i in range(max(0, x - 1), min(WIDTH - 1, x + 1) + 1)
            for j in range(max(0, y - 1), min(HEIGHT - 1, y + 1) + 1)
            if i != x or j != y]

class Sweeper(object):
    def __init__(self):
        self._blocks = [[Block(i, j) for i in range(WIDTH)] for j in range(HEIGHT)]

        # 通过random模块中的sample函数，产生在方块总数范围内的MINE_NUM个随机数
        for t in random.sample(range(WIDTH * HEIGHT), MINE_NUM):
            x = t // WIDTH
            if t % WIDTH:
                y = t % WIDTH - 1
            else: y = WIDTH - 1
            self._blocks[x][y].mine = 1

    def get_blocks(self):
        return self._blocks

    blocks = property(fget=get_blocks)

    def get_block(self, x, y):
        return self._blocks[y][x]

    def sweep_mine(self, x, y):
        # 如果踩雷
        if self._blocks[y][x].mine:
            self._blocks[y][x].status = Status.blood
            return False

        # 打开安全则把状态改为open
        self._blocks[y][x].status = Status.open

        arounds = _get_around(x, y)

        _sum = 0
        for i, j in arounds:
            if self._blocks[j][i].mine:
                _sum += 1
        self._blocks[y][x].around_mine_count = _sum

        # 如果周围雷数为零，则递归调用sweep_mine函数，即打开其周围八个方块，甚至能更多
        if _sum == 0:
            for i, j in arounds:
                if self._blocks[j][i].around_mine_count == -1:
                    self.sweep_mine(i, j)

        return True

    def double_mouse_button_down(self, x, y):
        if self._blocks[y][x].around_mine_count == 0:
            return True

        self._blocks[y][x].status = Status.double

        arounds = _get_around(x, y)

        sumf = 0  # 记录周围插旗的数量
        for i, j in _get_around(x, y):
            if self._blocks[j][i].status == Status.flag:
                sumf += 1
        result = True
        if sumf == self._blocks[y][x].around_mine_count:  # 若周围插旗数与周围雷数相等
            for i, j in arounds:
                if self._blocks[j][i].status == Status.initial:
                    if not self.sweep_mine(i, j):  # 对于没有被插旗的方块，如果本身是雷，则插旗错误，扫雷失败
                        result = False
        else:  # 如果插旗数不与雷数相等，则在点击时状态设置为hint，即出现被按压的效果
            for i, j in arounds:
                if self._blocks[j][i].status == Status.initial:
                    self._blocks[j][i].status = Status.hint
        return result

    def double_mouse_button_up(self, x, y):
        self._blocks[y][x].status = Status.open
        for i, j in _get_around(x, y):  # 还原方块被按压的效果
            if self._blocks[j][i].status == Status.hint:
                self._blocks[j][i].status = Status.initial


