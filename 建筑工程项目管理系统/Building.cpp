#include<iostream>
#include<cstring>
#include"Date.h"
#include"building.h"
using namespace std;
Building::Building()
{
	code = 0;
	status = 0;
	area = 0;
	cost = 0;
	source = 0;
}
Building::~Building()
{
	code = 0;
	name[0] = '\0';
}
long Building::getCode() { return code; }
bool Building::getStatus() { return status; }
void Building::setStatus(bool s) { status = s; }
char* Building::getName() { return name; }
char* Building::getCompany() { return company; }
void Building::setCompany(char *c) { strcpy_s(company, 20, c); }
char* Building::getAdd1() { return address.city; }
void Building::setAdd1(char* a) { strcpy_s(address.city, 10, a); }
char* Building::getAdd2() { return address.district; }
void Building::setAdd2(char* a) { strcpy_s(address.district, 10, a); }
char* Building::getAdd3() { return address.street; }
void Building::setAdd3(char *a) { strcpy_s(address.street, 10, a); }
double Building::getArea() { return area; }
void Building::setArea(double a) { area = a; }
double Building::getCost() { return cost; }
void Building::setCost(double c) { area = c; }
int Building::getSource() { return source; }
void Building::setSource(int s) { source = s; }
Date Building::getBegin() { return begin; }
void Building::setBegin(Date b) { begin = b; }
Date Building::getEnd() { return end; }
void Building::setEnd(Date e) { end = e; }
void Building::print() {}