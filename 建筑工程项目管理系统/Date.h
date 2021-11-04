#pragma once
class Date  //日期类
{
public:
	int year, month, day;  //年、月、日
	Date();
	Date(int y, int m, int d);
	Date(const Date & da);
	void setDate(int y, int m, int d);
	int count();  //计算当前日期是该年的第几天
	bool operator<=(Date t);  //重载“<="运算符，比较日期的前后
	friend int operator-(Date c1, Date c2);  //重载“-”运算符，计算两个日期的间隔天数，c1在c2之后
};