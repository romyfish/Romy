// JavaScript Document
var phtary = document.getElementsByName("smlpht");
var phtshow = document.getElementById("phtshw");
var txtary = document.getElementsByName("txt");
var t = 1;
var timer = null;

function changeBig(temp) {
	clearInterval(timer);
	var pary = document.getElementsByName("smlpht");
	var bigp = document.getElementById("phtshw");
	var tary = document.getElementsByName("txt");
	for(var i = 0; i < tary.length; i++) {
		pary[i].className = "smlphoto";
		if(temp.src == pary[i].src)
			tary[i].style.display = "block";
		else tary[i].style.display = "none";
	}
	bigp.src = temp.src;
	temp.className = "smlphoto_b";
}

function backBig(temp) {
	temp.className = "smlphoto";
	var pary = document.getElementsByName("smlpht");
	var bigp = document.getElementById("phtshw");
	var tary = document.getElementsByName("txt");
	pary[t].className = "smlphoto_b";
	for(var i = 0; i < tary.length; i++) {
		if(i == t)
			tary[t].style.display = "block";
		else tary[i].style.display = "none";
	}
	bigp.src = pary[t].src;
	timer = null;
	delayloop();
}

function changephoto() {
	phtary[t].className = "smlphoto_b";
	txtary[t].style.display = "block";
	phtshow.src = phtary[t].src;
	phtshow.alt = phtary[t].alt;
	if (t == 0) {
		phtary[3].className = "smlphoto";
		txtary[3].style.display = "none";
	} else {
		phtary[t - 1].className = "smlphoto";
		txtary[t - 1].style.display = "none";
	}
	if (t < 3) t++;
	else t = 0;
}

function delayloop() {
	if (timer == null) {
		timer = setInterval(changephoto, 3000);
	} else {
		clearInterval(timer);
		timer = null;
	}
}

delayloop(); //运行计时器的控制函数

function showFull() {
	var upd = "对联全文：\n";
	upd += "    五百里滇池，奔来眼底。披襟岸帻，喜茫茫空阔无边！看：东骧神骏，西翥灵仪， 北走蜿蜒，南翔缟素。高人韵士，何妨选胜登临，趁蟹屿螺洲，梳裹就风鬟雾鬓；更苹 天苇地，点缀些翠羽丹霞。莫孤负：四围香稻，万顷晴沙，九夏芙蓉，三春杨柳。\n";
	upd += "    数千年往事，注到心头。把酒凌虚，叹滚滚英雄谁在？想：汉习楼船，唐标铁柱， 宋挥玉斧，元跨革囊。伟烈丰功，费尽移山心力，尽珠帘画栋，卷不及暮雨朝云；便断 碣残碑，都付与苍烟落照。只赢得：几杵疏钟，半江渔火，两行秋雁，一枕清霜。\n";
	upd += "    ——孙髯翁\n";
	alert(upd);
}
