#pragma once
#include<iostream>
#include "publicWork.h"
using namespace std;
//�̻����̣��̳����������̣������ڽ�ͷ���㳡��
class Plant :
	public publicWork
{
public:
	Plant();
	~Plant();
	friend istream & operator>>(istream &input, Plant & R);  //������ȡ�������������Ŀ��Ϣ
	void print();
};