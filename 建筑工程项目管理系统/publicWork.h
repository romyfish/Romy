#pragma once
#include "building.h"
//��������
class publicWork :
	public Building
{
protected:
	double donation;  //��¼�ʽ���Դ���������������
public:
	publicWork();
	~publicWork();
	double getDonation();
	void setDonation(double d);
};