#pragma once
#include<iostream>
#include "publicWork.h"
using namespace std;
//������̳��Է��ݽ������̣��������������ˮ����ˮ��������ˮ��ʩϵͳ��
class Structure :
	public publicWork
{
public:
	Structure();
	~Structure();
	friend istream & operator>>(istream &input, Structure & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};