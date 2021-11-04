#pragma once
#include<iostream>
#include "civilBuilding.h"
using namespace std;
//生活活动建筑，继承自民用建筑，如商场、学校、文化展馆、医院、客运站、消防站、体育场馆、酒店、邮局、景点等
class Service :
	public civilBuilding
{
public:
	Service();
	~Service();
	friend istream & operator>>(istream &input, Service & R);  //重载提取运算符，输入项目信息
	void print();
};