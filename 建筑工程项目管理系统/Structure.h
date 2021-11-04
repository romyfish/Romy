#pragma once
#include<iostream>
#include "publicWork.h"
using namespace std;
//构筑物，继承自房屋建筑工程，如桥梁、隧道、水渠、水塔、给排水设施系统等
class Structure :
	public publicWork
{
public:
	Structure();
	~Structure();
	friend istream & operator>>(istream &input, Structure & R);  //重载提取运算符，输入项目信息
	void print();
};