#pragma once
#include "building.h"
//市政工程
class publicWork :
	public Building
{
protected:
	double donation;  //记录资金来源包含的社会捐赠金额
public:
	publicWork();
	~publicWork();
	double getDonation();
	void setDonation(double d);
};