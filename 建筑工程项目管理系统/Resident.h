#pragma once
#include<iostream>
#include "civilBuilding.h"
using namespace std;
//��ס�������̳������ý�������סլ����Ԣ�����ᡢ������
class Resident :
	public civilBuilding
{
public:
	Resident();
	~Resident();
	friend istream & operator>>(istream &input, Resident & R);  //������ȡ������������ס������Ŀ��Ϣ
	void print();
};