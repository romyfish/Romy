#pragma once
#include<iostream>
#include "civilBuilding.h"
using namespace std;
//�����������̳������ý��������̳���ѧУ���Ļ�չ�ݡ�ҽԺ������վ������վ���������ݡ��Ƶꡢ�ʾ֡������
class Service :
	public civilBuilding
{
public:
	Service();
	~Service();
	friend istream & operator>>(istream &input, Service & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};