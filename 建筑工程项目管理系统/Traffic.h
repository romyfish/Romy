#pragma once
#include "publicWork.h"
#include<iostream>
using namespace std;
//公共交通工程，继承自市政工程，如道路、地铁、火车等
class Traffic :
	public publicWork
{
protected:
	char add1[15], add2[15];  //路线起点和终点位置
	double distance;  //路线距离
public:
	Traffic();
	~Traffic();
	void setadd(char *a1, char *a2);
	void setdst(double d);
	friend istream & operator>>(istream &input, Traffic & R);  //重载提取运算符，输入项目信息
	void print();
};