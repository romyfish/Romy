#pragma once
#include<iostream>
#include "townHouse.h"
using namespace std;
//��ҵ�������̳��Է��ݽ������̣����������䡢�������䡢�����÷����ִ�������
class indusBuilding :
	public townHouse
{
public:
	indusBuilding();
	~indusBuilding();
	friend istream & operator>>(istream &input, indusBuilding & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};