#pragma once
#include"Date.h"
struct Address  //��ַ�ṹ
{
	char city[15];
	char district[15];
	char street[15];  //�����л����ط�Χ���ֵ���Χ
};
class Building
{
protected:
	long code;        //��Ŀ���
	bool status;      //����״̬
	char name[20];      //��Ŀ����
	char company[20];   //���赥λ
	Address address;  //������ַ�����������л����ط�Χ���ֵ���Χ�Ľṹ��
	double area;      //ʩ��������
	double cost;      //��ͬ���
	int source;       //�ʽ���Դ
	Date begin;       //��ͬ��������
	Date end;         //��ͬ�깤����
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