#pragma once
class Date  //������
{
public:
	int year, month, day;  //�ꡢ�¡���
	Date();
	Date(int y, int m, int d);
	Date(const Date & da);
	void setDate(int y, int m, int d);
	int count();  //���㵱ǰ�����Ǹ���ĵڼ���
	bool operator<=(Date t);  //���ء�<="��������Ƚ����ڵ�ǰ��
	friend int operator-(Date c1, Date c2);  //���ء�-��������������������ڵļ��������c1��c2֮��
};