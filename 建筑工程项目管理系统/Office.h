#pragma once
#include<iostream>
#include "civilBuilding.h"
using namespace std;
//�칫�������̳������ý������������칫¥������ҵ�칫¥������ʵ������
class Office :
	public civilBuilding
{
public:
	Office();
	~Office();
	friend istream & operator>>(istream &input, Office & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};