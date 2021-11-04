#include"building.h"
#include "publicWork.h"
#include "Structure.h"
#include "Sign.h"
using namespace std;

Sign::Sign() {}
Sign::~Sign()
{
	code = 0;
	name[0] = '\0';
}
istream & operator>>(istream &input, Sign & R)  //������ȡ�������������Ŀ��Ϣ
{
	//����������Ŀ�ı�š����ơ�����״̬�����赥λ��������ַ��ʩ������������ͬ���ʽ���Դ���������0����������1�����߾��У�2������ͬ�������ڡ���ͬ�깤����
	int y1, m1, d1, y2, m2, d2;
	input >> R.code >> R.name >> R.status >> R.company >> R.address.city >> R.address.district >> R.address.street >> R.area >> R.cost >> R.source >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	Date da1(y1, m1, d1), da2(y2, m2, d2);
	R.setBegin(da1);
	R.setEnd(da2);
	if (R.source)
	{
		cout << "��������������";
		input >> R.donation;
	}
	else R.donation = 0;
	return input;
}
void Sign::print()
{
	//���������Ŀ�����͡���š����ơ�����״̬�����赥λ��������ַ��ʩ������������ͬ���ʽ���Դ���������0����������1�����߾��У�2������ͬ�������ڡ���ͬ�깤����
	cout << "��ʶ��ʩ" << "\t" << code << "\t" << name << "\t" << (status == true ? "������" : "δ����") << "\t���赥λ��" << company << "\t������ַ��" << address.city << address.district << address.street << "\n\tʩ����������" << area << "ƽ����\t��ͬ��" << cost << "��Ԫ�����\t�ʽ���Դ��";
	if (source == 0) cout << "��Ŀ��˾";
	if (source == 1) cout << "������";
	if (source == 2) cout << "���߾���";
	if (source) cout << "\t��������" << donation;
	cout << "\n\t��ͬ�������ڣ�" << begin.year << "��" << begin.month << "��" << begin.day << "��\t��ͬ�깤���ڣ�" << end.year << "��" << end.month << "��" << end.day << "��" << endl;
}