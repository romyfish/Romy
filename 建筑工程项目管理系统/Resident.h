#pragma once
#include<iostream>
#include "civilBuilding.h"
using namespace std;
//居住建筑，继承自民用建筑，如住宅、公寓、宿舍、别墅等
class Resident :
	public civilBuilding
{
public:
	Resident();
	~Resident();
	friend istream & operator>>(istream &input, Resident & R);  //重载提取运算符，输入居住建筑项目信息
	void print();
};