// JavaScript Document

//用于测试时删除cookie
//document.cookie = "username=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";

function setCookie(cname, cvalue, exdays) {
	var d = new Date();
	d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
	var expires = "expires=" + d.toGMTString();
	document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie(cname) {
	var name = cname + "=";
	var decodedCookie = decodeURIComponent(document.cookie);
	var ca = decodedCookie.split(';');
	for (var i = 0; i < ca.length; i++) {
		var c = ca[i];
		while (c.charAt(0) == ' ') {
			c = c.substring(1);
		}
		if (c.indexOf(name) == 0) {
			return c.substring(name.length, c.length);
		}
	}
	return "";
}

function initial() {
	var user = getCookie("username");
	if (user != "") {
		var greet = document.getElementById("greet");
		greet.innerHTML = "欢迎您，" + user + "！";
		//alert(user + "，欢迎您！");
	} else {
		user = prompt("请输入姓名：");
		if (user != "" && user != null) {
			setCookie("username", user, 30);
			var greeti = document.getElementById("greet");
			greeti.innerHTML = "欢迎您，" + user + "！";
		}
	}
	for (var i = 0; i < localStorage.length; i++) {
		//var num = "No." + i;
		var cnt = localStorage[localStorage.key(i)];
		var arr = cnt.split('*');
		showPst(arr[0], arr[1], arr[2], arr[3]);
	}
}

function showPst(ptime, user, pcnt, rpls) {
	var vtbody = document.getElementById("tcnt");
	var vtr = document.createElement("tr");
	var vtd1 = document.createElement("td");
	var chk = document.createElement("input");
	chk.type = "checkbox";
	vtd1.appendChild(chk);
	vtr.appendChild(vtd1);
	var vtd2 = document.createElement("td");
	var vp1 = document.createElement("p");
	vp1.innerHTML = ptime;
	vtd2.appendChild(vp1);
	vtr.appendChild(vtd2);
	var vtd3 = document.createElement("td");
	var vp2 = document.createElement("p");
	vp2.innerHTML = user;
	vtd3.appendChild(vp2);
	vtr.appendChild(vtd3);
	var vtd4 = document.createElement("td");
	var vp3 = document.createElement("p");
	vp3.className = "cnt";
	vp3.innerHTML = pcnt;
	vtd4.appendChild(vp3);
	var vdiv = document.createElement("div");
	vdiv.className = "rplPart";
	vdiv.name = "rplpt";
	var vul = document.createElement("ul");
	vul.className = "replys";
	var rpl = rpls.split('^');
	for (var i = 0; i < rpl.length; i++) {
		if (rpl[i] != "") {
			var vli = document.createElement("li");
			vli.innerHTML = rpl[i];
			vul.appendChild(vli);
		}
	}
	vdiv.appendChild(vul);
	var vbtr = document.createElement("button");
	vbtr.className = "replybt";
	vbtr.onclick = function () {
		reply(this)
	};
	vbtr.innerHTML = "回帖";
	vdiv.appendChild(vbtr);
	vtd4.appendChild(vdiv);
	vtr.appendChild(vtd4);
	vtbody.appendChild(vtr);
}

function post() {
	var ptime = new Date().toLocaleString();
	var user = getCookie("username");
	var pcnt = document.getElementById("ipt_post").value;
	var posted = document.getElementsByTagName("tr");
	var count = posted.length;
	var num = "No." + count;
	var content = ptime + "*" + user + "*" + pcnt + "*";
	localStorage[num] = content;
}

function reply(temp) {
	var rplcnt = prompt("请输入回帖内容：");
	var user = getCookie("username");
	var rpl = "<b>" + user + "</b>：" + rplcnt;
	var the_tr = temp.parentNode.parentNode.parentNode;
	var trs = document.getElementsByTagName("tr");
	var i = 0;
	var n = localStorage.length;
	for (; i < trs.length; i++) {
		if (trs[i] == the_tr) break;
	}
	var num = "No." + (n - i + 1);
	localStorage[num] += rpl + "^";
	location.reload();
}

function selectAll() {
	var chkbox = document.getElementsByTagName("input");
	for (var i = 0; i < chkbox.length; i++) {
		chkbox[i].checked = true;
	}
}

function cancelAll() {
	var chkbox = document.getElementsByTagName("input");
	for (var i = 0; i < chkbox.length; i++) {
		chkbox[i].checked = false;
	}
}

function deleteSel() {
	var chkbox = document.getElementsByTagName("input");
	var chkn = chkbox.length;
	var flag = 0;
	for (var i = 0; i < chkn; i++) {
		var n = localStorage.length - i + flag;
		if (n == 0) break;
		if (chkbox[i].checked) {
			var num = "No." + n;
			delete localStorage[num];
			var nn = n + 1;
			var nnum = "No." + nn;
			while (localStorage.hasOwnProperty(nnum)) {
				localStorage[num] = localStorage[nnum];
				delete localStorage[nnum];
				num = "No." + nn;
				nn++;
				nnum = "No." + nn;
			}
			flag++;
		}
	}
	location.reload();
}
