#pragma once
#include "publicWork.h"
#include<iostream>
using namespace std;
//������ͨ���̣��̳����������̣����·���������𳵵�
class Traffic :
	public publicWork
{
protected:
	char add1[15], add2[15];  //·�������յ�λ��
	double distance;  //·�߾���
public:
	Traffic();
	~Traffic();
	void setadd(char *a1, char *a2);
	void setdst(double d);
	friend istream & operator>>(istream &input, Traffic & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};