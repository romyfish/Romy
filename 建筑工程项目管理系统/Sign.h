#pragma once
#include<iostream>
#include "publicWork.h"
using namespace std;
//��ʶ��ʩ���̳����������̣��罻ͨ�źš����ܵ�
class Sign :
	public publicWork
{
public:
	Sign();
	~Sign();
	friend istream & operator>>(istream &input, Sign & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};