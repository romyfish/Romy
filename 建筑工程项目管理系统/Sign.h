#pragma once
#include<iostream>
#include "publicWork.h"
using namespace std;
//标识设施，继承自市政工程，如交通信号、雕塑等
class Sign :
	public publicWork
{
public:
	Sign();
	~Sign();
	friend istream & operator>>(istream &input, Sign & R);  //重载提取运算符，输入项目信息
	void print();
};