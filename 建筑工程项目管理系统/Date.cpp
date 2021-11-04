#include<iostream>
#include"Date.h"
using namespace std;
Date::Date() {}
Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
Date::Date(const Date & da)
{
	year = da.year;
	month = da.month;
	day = da.day;
}
void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int Date::count()  //计算当前日期是该年的第几天
{
	int i, ds = 0;
	for (i = month - 1; i >= 1; i--)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) ds += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11) ds += 30;
		else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ds += 29;
		else ds += 28;
	}
	ds += day;
	return ds;
}
bool Date::	operator<=(Date t)  //重载“<="运算符，比较日期的前后
{
	if (year < t.year || year == t.year&&month < t.month || year == t.year&&month == t.month&&day <= t.day) return true;
	else return false;
}
int operator-(Date c1, Date c2)  //友元函数重载“-”运算符，计算两个日期的间隔天数，c1在c2之后
{
	int ds = 0;
	if (c1.year - c2.year)
	{
		if (c1.year - c2.year > 1)
		{
			int i, f = 0;
			for (i = c2.year + 1; i < c1.year; i++)
				if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) f++;
			ds = (c1.year - c2.year - 1 - f) * 365 + f * 366;
		}
		ds += ((c2.year % 4 == 0 && c2.year % 100 != 0 || c2.year % 400 == 0) ? 366 : 365) - c2.count() + c1.count();
	}
	else ds = c1.count() - c2.count();
	return ds;
}