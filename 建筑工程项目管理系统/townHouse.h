#pragma once
#include "building.h"
//���ݽ�������
class townHouse :
	public Building
{
protected:
	double loan;  //��¼�ʽ���Դ���������д�����
public:
	townHouse();
	~townHouse();
	double getLoan();
	void setLoan(double l);
};