#pragma once
#include<iostream>
#include "townHouse.h"
using namespace std;
//工业建筑，继承自房屋建筑工程，如生产车间、辅助车间、动力用房、仓储建筑等
class indusBuilding :
	public townHouse
{
public:
	indusBuilding();
	~indusBuilding();
	friend istream & operator>>(istream &input, indusBuilding & R);  //重载提取运算符，输入项目信息
	void print();
};