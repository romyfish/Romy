#pragma once
#include"Date.h"
struct Address  //地址结构
{
	char city[15];
	char district[15];
	char street[15];  //从州市或区县范围至街道范围
};
class Building
{
protected:
	long code;        //项目编号
	bool status;      //审批状态
	char name[20];      //项目名称
	char company[20];   //建设单位
	Address address;  //建筑地址（包括从州市或区县范围至街道范围的结构）
	double area;      //施工许可面积
	double cost;      //合同金额
	int source;       //资金来源
	Date begin;       //合同开工日期
	Date end;         //合同完工日期
public:
	Building();
	virtual ~Building();
	long getCode();
	bool getStatus();
	void setStatus(bool s);
	char* getName();
	char* getCompany();
	void setCompany(char *c);
	char* getAdd1();
	void setAdd1(char* a);
	char* getAdd2();
	void setAdd2(char* a);
	char* getAdd3();
	void setAdd3(char *a);
	double getArea();
	void setArea(double a);
	double getCost();
	void setCost(double c);
	int getSource();
	void setSource(int s);
	Date getBegin();
	void setBegin(Date b);
	Date getEnd();
	void setEnd(Date e);
	virtual void print();
};