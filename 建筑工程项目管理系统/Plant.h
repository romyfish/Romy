#pragma once
#include<iostream>
#include "publicWork.h"
using namespace std;
//绿化工程，继承自市政工程，常见于街头、广场等
class Plant :
	public publicWork
{
public:
	Plant();
	~Plant();
	friend istream & operator>>(istream &input, Plant & R);  //重载提取运算符，输入项目信息
	void print();
};