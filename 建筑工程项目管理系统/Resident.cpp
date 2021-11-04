#include"building.h"
#include "townHouse.h"
#include "civilBuilding.h"
#include "Resident.h"
using namespace std;

Resident::Resident() {}
Resident::~Resident()
{
	code = 0;
	name[0] = '\0';
}
istream & operator>>(istream &input, Resident & R)  //������ȡ������������ס������Ŀ��Ϣ
{
	//����������Ŀ�ı�š����ơ�����״̬����������1��δ������2�������赥λ��������ַ��ʩ������������ͬ���ʽ���Դ����Ŀ��˾��0�����д��1�����߾��У�2������ͬ�������ڡ���ͬ�깤���ڣ��������
	int y1, m1, d1, y2, m2, d2;
	input >> R.code >> R.name >> R.status >> R.company >> R.address.city >> R.address.district >> R.address.street >> R.area >> R.cost >> R.source >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	Date da1(y1, m1, d1), da2(y2, m2, d2);
	R.setBegin(da1);
	R.setEnd(da2);
	if (R.source)
	{
		cout << "����������";
		input >> R.loan;
	}
	else R.loan = 0;
	return input;
}
void Resident::print()
{
	//���������Ŀ�����͡���š����ơ�����״̬�����赥λ��������ַ��ʩ������������ͬ���ʽ���Դ����Ŀ��˾��0�����д��1�����߾��У�2������ͬ�������ڡ���ͬ�깤����
	cout << "��ס����" << "\t" << code << "\t" << name << "\t" << (status == true ? "������" : "δ����") << "\t���赥λ��" << company << "\t������ַ��" << address.city << address.district << address.street << "\n\tʩ����������" << area << "ƽ����\t��ͬ��" << cost << "��Ԫ�����\t�ʽ���Դ��";
	if (source == 0) cout << "��Ŀ��˾";
	if (source == 1) cout << "���д���";
	if (source == 2) cout << "���߾���";
	if (source) cout << "\t�����" << loan;
	cout << "\n\t��ͬ�������ڣ�" << begin.year << "��" << begin.month << "��" << begin.day << "��\t��ͬ�깤���ڣ�" << end.year << "��" << end.month << "��" << end.day << "��" << endl;
}