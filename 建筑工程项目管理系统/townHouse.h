#pragma once
#include "building.h"
//房屋建筑工程
class townHouse :
	public Building
{
protected:
	double loan;  //记录资金来源包含的银行贷款金额
public:
	townHouse();
	~townHouse();
	double getLoan();
	void setLoan(double l);
};