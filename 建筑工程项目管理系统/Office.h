#pragma once
#include<iostream>
#include "civilBuilding.h"
using namespace std;
//办公建筑，继承自民用建筑，如行政办公楼、企事业办公楼、科研实验所等
class Office :
	public civilBuilding
{
public:
	Office();
	~Office();
	friend istream & operator>>(istream &input, Office & R);  //重载提取运算符，输入项目信息
	void print();
};