#include"project.h"
using namespace std;

const char *fileDat1 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\��ס������Ŀ�б�.dat";
const char *fileDat2 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\�칫������Ŀ�б�.dat";
const char *fileDat3 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\����������Ŀ�б�.dat";
const char *fileDat4 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\��ҵ������Ŀ�б�.dat";
const char *fileDat5 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\��������Ŀ�б�.dat";
const char *fileDat6 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\������ͨ��Ŀ�б�.dat";
const char *fileDat7 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\�̻�������Ŀ�б�.dat";
const char *fileDat8 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\��ʶ��ʩ��Ŀ�б�.dat";
const char *fileTxt0 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\���ý�����Ŀ�б�.txt";
const char *fileTxt01 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\���ݽ���������Ŀ�б�.txt";
const char *fileTxt02 = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\����������Ŀ�б�.txt";
const char *fileTxt = "C:\\Users\\Romy\\source\\repos\\����������Ŀ����ϵͳ\\�ܽ�����Ŀ�б�.txt";

int main()
{
	cout << "                  ���н���������Ŀ����ϵͳ" << endl;
Menu:
	int x;
	cout << "\n-------------------------�˵�-------------------------\n";
	cout << "1����ʼ��  2������Ŀ��Ϣ���в���  3����ѯɸѡ  4���б���ʾ  5������ͳ��  0���˳�����ϵͳ\n";
	cout << "�������Ҫ�������֣�";
	cin >> x;
	if (x == 0) return 0;
	if (x == 1)
	{
		Initial(fileDat1, 1);
		Initial(fileDat2, 2);
		Initial(fileDat3, 3);
		Initial(fileDat4, 4);
		Initial(fileDat5, 5);
		Initial(fileDat6, 6);
		Initial(fileDat7, 7);
		Initial(fileDat8, 8);
		fstream ifile(fileTxt, ios::out);
		ifile.close();
		ifile.open(fileTxt01, ios::out);
		ifile.close();
		ifile.open(fileTxt02, ios::out);
		ifile.close();
		ifile.open(fileTxt0, ios::out);
		ifile.close();
		cout << "��ɳ�ʼ����\n";
		goto Menu;
	}
	if (x == 2)
	{
		cout << "ѡ�����Ŀ��Ϣ����¼�롢�޸ġ�ɾ������\n";
		while (1)
		{
			int y;
			cout << "1��¼��  2���޸�  3��ɾ��  0���˳�\n";
			cout << "�������Ҫ�������֣�";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 3))
			{
				cout << "����������������룡\n";
				cout << endl;
				continue;
			}
			if (y == 1)                                 //��Ŀ��Ϣ����
			{
				cout << "-------------------------��Ŀ��Ϣ����-------------------------\n";
				while (1)
				{
					cout << "ѡ��¼����Ŀ���\n";
					int z;
					cout << "���ݽ���������Ŀ��  1�����ý���  2����ҵ����\n"
						<< "����������Ŀ��3��������  4��������ͨ  5���̻�����  6����ʶ��ʩ\n"
						<< "0���˳�\n"
						<< "�������Ҫ�������֣�";
					cin >> z;
					if (z == 0) break;
					if (z == 1)
					{
						int xx = 0;
						cout << "1����ס����  2���칫����  3����������\n";
						cout << "�������Ҫ�������֣�";
						cin >> xx;
						cout << "������������Ŀ�ı�š����ơ�����״̬����������1��δ������0�������赥λ��������ַ���С������ֵ��Կո���������ʩ������������λ/ƽ���ף�����ͬ����λ/��Ԫ����ң����ʽ���Դ����Ŀ��˾��0�����д��1�����߾��У�2������ͬ�������ڡ���ͬ�깤���ڣ��ꡢ�¡����Կո�����\n"
							<< "��ע������Ϣ���Կո������\n";
						if (xx == 1)
						{
							int count1;
							Resident resident;
							fstream fdat1(fileDat1, ios::in | ios::out | ios::binary);
							fdat1.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat1.read((char*)&count1, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //���Ҿ�ס������Ŀ�ļ�β
							{
								fdat1.read((char*)&resident, sizeof(resident));
							} while (!endMark(resident));             //�ж��ļ��Ƿ������־
							fdat1.seekp(-long(sizeof(Resident)), ios::cur);  //��дָ��λ��
							cin >> resident;
							count1++;
							fdat1.write((char*)&resident, sizeof(Resident));  //д��¼����ס������Ŀ�ļ�
							fdat1.write((char*)&mark, sizeof(Resident));  //д�ļ�������־
							fdat1.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat1.write((char*)&count1, sizeof(int));  //���´洢��Ŀ������
							fdat1.close();
						}
						if (xx == 2)
						{
							int count2;
							Office office;
							fstream fdat2(fileDat2, ios::in | ios::out | ios::binary);
							fdat2.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat2.read((char*)&count2, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //�����ļ�β
							{
								fdat2.read((char*)&office, sizeof(office));  //�Ƿ���������±ꣿ
							} while (!endMark(office));             //�ж��ļ��Ƿ������־
							fdat2.seekp(-long(sizeof(Office)), ios::cur);  //��дָ��λ��
							cin >> office;
							count2++;
							fdat2.write((char*)&office, sizeof(Office));  //д��¼���칫������Ŀ�ļ�
							fdat2.write((char*)&mark, sizeof(Office));  //д�ļ�������־
							fdat2.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat2.write((char*)&count2, sizeof(int));  //���´洢��Ŀ������
							fdat2.close();
						}
						if (xx == 3)
						{
							int count3;
							Service service;
							fstream fdat3(fileDat3, ios::in | ios::out | ios::binary);
							fdat3.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat3.read((char*)&count3, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //�����ļ�β
							{
								fdat3.read((char*)&service, sizeof(service));  //�Ƿ���������±ꣿ
							} while (!endMark(service));             //�ж��ļ��Ƿ������־
							fdat3.seekp(-long(sizeof(Service)), ios::cur);  //��дָ��λ��
							cin >> service;
							count3++;
							fdat3.write((char*)&service, sizeof(Service));  //д��¼������������Ŀ�ļ�
							fdat3.write((char*)&mark, sizeof(Service));  //д�ļ�������־
							fdat3.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat3.write((char*)&count3, sizeof(int));  //���´洢��Ŀ������
							fdat3.close();
						}
					}
					if (z == 2)
					{
						cout << "������������Ŀ�ı�š����ơ�����״̬����������1��δ������0�������赥λ��������ַ���С������ֵ��Կո�������ʩ������������λ/ƽ���ף�����ͬ����λ/��Ԫ����ң����ʽ���Դ����Ŀ��˾��0�����д��1�����߾��У�2������ͬ�������ڡ���ͬ�깤���ڣ��ꡢ�¡����Կո�����\n"
							<< "��ע������Ϣ���Կո������\n";
						int count4;
						indusBuilding indusbuilding;
						fstream fdat4(fileDat4, ios::in | ios::out | ios::binary);
						fdat4.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
						fdat4.read((char*)&count4, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
						do                                        //�����ļ�β
						{
							fdat4.read((char*)&indusbuilding, sizeof(indusbuilding));  //�Ƿ���������±ꣿ
						} while (!endMark(indusbuilding));             //�ж��ļ��Ƿ������־
						fdat4.seekp(-long(sizeof(indusBuilding)), ios::cur);  //��дָ��λ��
						cin >> indusbuilding;
						count4++;
						fdat4.write((char*)&indusbuilding, sizeof(indusBuilding));  //д��¼����ҵ������Ŀ�ļ�
						fdat4.write((char*)&mark, sizeof(indusBuilding));  //д�ļ�������־
						fdat4.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
						fdat4.write((char*)&count4, sizeof(int));  //���´洢��Ŀ������
						fdat4.close();
					}
					if (z > 2)
					{
						cout << "������������Ŀ�ı�š����ơ�����״̬����������1��δ������0�������赥λ��������ַ���С������ֵ��Կո�������ʩ������������λ/ƽ���ף�����ͬ����λ/��Ԫ����ң����ʽ���Դ����Ŀ��˾��0����������1�����߾��У�2��������ͬ�������ڡ���ͬ�깤���ڣ��ꡢ�¡����Կո�����\n"
							<< "��ע������Ϣ���Կո������\n";

						if (z == 3)
						{
							int count5;
							Structure structure;
							fstream fdat5(fileDat5, ios::in | ios::out | ios::binary);
							fdat5.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat5.read((char*)&count5, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //�����ļ�β
							{
								fdat5.read((char*)&structure, sizeof(structure));  //�Ƿ���������±ꣿ
							} while (!endMark(structure));             //�ж��ļ��Ƿ������־
							fdat5.seekp(-long(sizeof(Structure)), ios::cur);  //��дָ��λ��
							cin >> structure;
							count5++;
							fdat5.write((char*)&structure, sizeof(Structure));  //д��¼����������Ŀ�ļ�
							fdat5.write((char*)&mark, sizeof(Structure));  //д�ļ�������־
							fdat5.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat5.write((char*)&count5, sizeof(int));  //���´洢��Ŀ������
							fdat5.close();
						}
						if (z == 4)
						{
							int count6;
							Traffic traffic;
							fstream fdat6(fileDat6, ios::in | ios::out | ios::binary);
							fdat6.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat6.read((char*)&count6, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //�����ļ�β
							{
								fdat6.read((char*)&traffic, sizeof(traffic));  //�Ƿ���������±ꣿ
							} while (!endMark(traffic));             //�ж��ļ��Ƿ������־
							fdat6.seekp(-long(sizeof(Traffic)), ios::cur);  //��дָ��λ��
							cin >> traffic;
							count6++;
							fdat6.write((char*)&traffic, sizeof(Traffic));  //д��¼��������ͨ������Ŀ�ļ�
							fdat6.write((char*)&mark, sizeof(Traffic));  //д�ļ�������־
							fdat6.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat6.write((char*)&count6, sizeof(int));  //���´洢��Ŀ������
							fdat6.close();
						}
						if (z == 5)
						{
							int count7;
							Plant plant;
							fstream fdat7(fileDat7, ios::in | ios::out | ios::binary);
							fdat7.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat7.read((char*)&count7, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //�����ļ�β
							{
								fdat7.read((char*)&plant, sizeof(plant));  //�Ƿ���������±ꣿ
							} while (!endMark(plant));             //�ж��ļ��Ƿ������־
							fdat7.seekp(-long(sizeof(Plant)), ios::cur);  //��дָ��λ��
							cin >> plant;
							count7++;
							fdat7.write((char*)&plant, sizeof(Plant));  //д��¼���̻�������Ŀ�ļ�
							fdat7.write((char*)&mark, sizeof(Plant));  //д�ļ�������־
							fdat7.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat7.write((char*)&count7, sizeof(int));  //���´洢��Ŀ������
							fdat7.close();
						}
						if (z == 6)
						{
							int count8;
							Sign sign;
							fstream fdat8(fileDat8, ios::in | ios::out | ios::binary);
							fdat8.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
							fdat8.read((char*)&count8, sizeof(int));  //�����ļ��洢��Ŀ�����������ڴ棬����Ӧcount������¼
							do                                        //�����ļ�β
							{
								fdat8.read((char*)&sign, sizeof(sign));  //�Ƿ���������±ꣿ
							} while (!endMark(sign));             //�ж��ļ��Ƿ������־
							fdat8.seekp(-long(sizeof(Sign)), ios::cur);  //��дָ��λ��
							cin >> sign;
							count8++;
							fdat8.write((char*)&sign, sizeof(Sign));  //д��¼����ʶ��ʩ��Ŀ�ļ�
							fdat8.write((char*)&mark, sizeof(Sign));  //д�ļ�������־
							fdat8.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
							fdat8.write((char*)&count8, sizeof(int));  //���´洢��Ŀ������
							fdat8.close();
						}
					}
					cout << "��Ŀ��Ϣ�����¼�룡" << endl;
					cout << endl;
				}
			}
			if (y == 2)
			{
				cout << "-------------------------��Ŀ��Ϣ�޸�-------------------------\n";
				while (1)
				{
					int flag = 0;
					int z;
					cout << "��ѡ��ͨ�����ƣ����룺1�����ţ����룺2��������Ҫ�޸ĵ���Ŀ\n"
						<< "�˳���0\n";
					cin >> z;
					char iname[20];
					long icode = 0;
					if (z == 0) break;
					if (z == 1)
					{
						cout << "���������Ŀ���ƣ�";
						cin >> iname;
					}
					if (z == 2)
					{
						cout << "���������Ŀ��ţ�";
						cin >> icode;
					}
					Change1<Resident>(fileDat1, iname, icode, flag);
					Change1<Office>(fileDat2, iname, icode, flag);
					Change1<Service>(fileDat3, iname, icode, flag);
					Change1<indusBuilding>(fileDat4, iname, icode, flag);
					Change2<Structure>(fileDat5, iname, icode, flag);
					Change2<Traffic>(fileDat6, iname, icode, flag);
					Change2<Plant>(fileDat7, iname, icode, flag);
					Change2<Sign>(fileDat8, iname, icode, flag);
					if (flag == 0) cout << "δ�ҵ������޸ĵ���Ŀ������������" << endl;
					else cout << "\n��Ŀ��Ϣ������޸ģ�" << endl;
					cout << endl;
				}
			}
			if (y == 3)
			{
				cout << "-------------------------��Ŀ��Ϣɾ��-------------------------\n";
				while (1)
				{
					int flag = 0;
					int z;
					cout << "��ѡ��ͨ�����ƣ����룺1�����ţ����룺2��������Ҫɾ������Ŀ\n"
						<< "�˳���0\n";
					cin >> z;
					char iname[20];
					long icode = 0;
					if (z == 0) break;
					if (z == 1)
					{
						cout << "���������Ŀ���ƣ�";
						cin >> iname;
					}
					if (z == 2)
					{
						cout << "���������Ŀ��ţ�";
						cin >> icode;
					}
					Delete<Resident>(fileDat1, iname, icode, flag);
					Delete<Office>(fileDat2, iname, icode, flag);
					Delete<Service>(fileDat3, iname, icode, flag);
					Delete<indusBuilding>(fileDat4, iname, icode, flag);
					Delete<Structure>(fileDat5, iname, icode, flag);
					Delete<Traffic>(fileDat6, iname, icode, flag);
					Delete<Plant>(fileDat7, iname, icode, flag);
					Delete<Sign>(fileDat8, iname, icode, flag);
					if (flag == 0) cout << "δ�ҵ�����ɾ������Ŀ������������" << endl;
					else cout << "\n��Ŀ��Ϣ�����ɾ����" << endl;
					cout << endl;
				}
			}
			cout << endl;
		}
		goto Menu;
	}
	if (x == 3)
	{
		cout << "ѡ�������ѯɸѡ����\n";
		while (1)
		{
			int y;
			cout << "1�������Ƽ�����Ŀ  2������ż�����Ŀ  3��������״̬ɸѡ  4��������״̬ɸѡ  5��������ʱ��ɸѡ  6��������λ��ɸѡ  0���˳�\n";
			cout << "�������Ҫ�������֣�";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 6))
			{
				cout << "����������������룡\n";
				continue;
			}
			int i, n = 0, flag = 0;
			Building **pbuilding = new Building*;  //������ά���飬ʹ����Ԫ��Ϊ����ָ��
			pbuilding = totalarray(n);
			if (y == 1)
			{
				while (1)
				{
					char iname[20];
					cout << "���������Ŀ���ƣ�";
					cin >> iname;
					for (i = 0; i < n; i++)
					{
						if (strcmp(pbuilding[i]->getName(), iname) == 0)
						{
							pbuilding[i]->print();
							flag = 1;
							break;
						}
					}
					if (flag == 1) break;
					else cout << "�Ҳ�������Ŀ���Ƿ��������룿(�ǣ�1����0��\n";
					int f;
					cin >> f;
					if (f == 0) break;
				}
			}
			if (y == 2)
			{
				while (1)
				{
					long icode;
					cout << "���������Ŀ��ţ�";
					cin >> icode;
					for (i = 0; i < n; i++)
					{
						if (pbuilding[i]->getCode() == icode)
						{
							pbuilding[i]->print();
							flag = 1;
							break;
						}
					}
					if (flag == 1) break;
					else cout << "�Ҳ�������Ŀ���Ƿ��������룿(�ǣ�1����0��\n";
					int f;
					cin >> f;
					if (f == 0) break;
				}
			}
			if (y == 3)
			{
				while (1)
				{
					bool ista;
					cout << "ѡ���ѯ��������Ŀ����1����ѯδ������Ŀ����0��";
					cin >> ista;
					for (i = 0; i < n; i++)
					{
						if (pbuilding[i]->getStatus() == ista)
						{
							pbuilding[i]->print();
							flag = 1;
						}
					}
					if (flag == 1) break;
					else cout << "�Ҳ�������Ŀ���Ƿ��������룿(�ǣ�1����0��\n";
					int f;
					cin >> f;
					if (f == 0) break;
				}
			}
			if (y == 4)
			{
				struct tm t;
				time_t current;
				time(&current);
				localtime_s(&t, &current);
				Date now(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
				while (1)
				{
					int istu;
					cout << "ѡ���ѯ������Ŀ����1����ѯ�ڽ���Ŀ����2����ѯ������Ŀ����3��";
					cin >> istu;
					if (istu == 1)  //��������ǰʱ�����ں�ͬ����ʱ��
					{
						for (i = 0; i < n; i++)
						{
							if (now <= pbuilding[i]->getBegin())
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (istu == 2)  //�ڽ�����ǰʱ�����ں�ͬ����ʱ�䣬�������깤ʱ��
					{
						for (i = 0; i < n; i++)
						{
							if (pbuilding[i]->getBegin() <= now && now <= pbuilding[i]->getEnd())
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (istu == 3)  //��������ͬ�깤ʱ�����ڵ�ǰʱ��
					{
						for (i = 0; i < n; i++)
						{
							if (pbuilding[i]->getEnd() <= now)
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (flag == 1) break;
					else cout << "�Ҳ�������Ŀ���Ƿ��������룿(�ǣ�1����0��\n";
					int f;
					cin >> f;
					if (f == 0) break;
				}
			}
			if (y == 5)
			{
				while (1)
				{
					int iday;
					char c;
					cout << "������ɸѡ�Ĺ���������";
					cin >> iday;
					cout << "��ѡ��鿴����Ϊ" << iday << "�켰���ϣ�����+�������£�����-����Χ����Ŀ��";
					cin >> c;
					if (c == '+')
					{
						for (i = 0; i < n; i++)
						{
							if (pbuilding[i]->getEnd() - pbuilding[i]->getBegin() >= iday)
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (c == '-')
					{
						for (i = 0; i < n; i++)
						{
							if (pbuilding[i]->getEnd() - pbuilding[i]->getBegin() <= iday)
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (flag == 1) break;
					else cout << "�Ҳ�������Ŀ���Ƿ��������룿(�ǣ�1����0��\n";
					int f;
					cin >> f;
					if (f == 0) break;
				}
			}
			if (y == 6)
			{
				while (1)
				{
					Address iadd;
					int range;
					cout << "ѡ����Ŀ������λ�õ�ɸѡ��Χ��1���У�2������3���ֵ�����";
					cin >> range;
					if (range == 1)
					{
						cout << "��������У�";
						cin >> iadd.city;
						for (i = 0; i < n; i++)
						{
							if (strcmp(pbuilding[i]->getAdd1(), iadd.city) == 0)
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (range == 2)
					{
						cout << "����������";
						cin >> iadd.district;
						for (i = 0; i < n; i++)
						{
							if (strcmp(pbuilding[i]->getAdd2(), iadd.district) == 0)
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (range == 3)
					{
						cout << "������ֵ���";
						cin >> iadd.street;
						for (i = 0; i < n; i++)
						{
							if (strcmp(pbuilding[i]->getAdd3(), iadd.street) == 0)
							{
								pbuilding[i]->print();
								flag = 1;
							}
						}
					}
					if (flag == 1) break;
					else cout << "�Ҳ�������Ŀ���Ƿ��������룿(�ǣ�1����0��\n";
					int f;
					cin >> f;
					if (f == 0) break;
				}
			}
			cout << endl;
		}
		goto Menu;
	}
	if (x == 4)
	{
		cout << "ѡ��������ʾ�����б�\n";
		while (1)
		{
			int y, num = 0;
			cout << "1��������Ŀ����\n"
				<< "2�����ݽ���������Ŀ�б�  3������������Ŀ�б�\n"
				<< "4�����ý�����Ŀ�б�  5����ҵ������Ŀ�б�\n"
				<< "6����������Ŀ�б�  7��������ͨ�����б�  8���̻������б�  9����ʶ��ʩ�б�\n"
				<< "0���˳�\n"
				<< "�������Ҫ�������֣�";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 9))
			{
				cout << "����������������룡\n";
				continue;
			}
			if (y == 1)
			{
				Building **pbuilding = new Building*;
				pbuilding = totalarray(num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(pbuilding, num);
				for (int i = 0; i < num; i++)
					pbuilding[i]->print();
				cout << "�Ƿ����ı��ļ������ǣ�1����0����";
				int g;
				cin >> g;
				if (g)
				{
					fstream opfile(fileTxt, ios::out);
					if (!opfile)
					{
						cerr << "File could not be open." << endl;
						abort();
					}
					opfile << "                    �ܽ�����Ŀ�б�\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "��ţ�" << pbuilding[i]->getCode() << "\t" << "���ƣ�" << pbuilding[i]->getName() << "\t" << (pbuilding[i]->getStatus() == true ? "������" : "δ����") << "\t���赥λ��" << pbuilding[i]->getCompany() << "\t������ַ��" << pbuilding[i]->getAdd1() << pbuilding[i]->getAdd2() << pbuilding[i]->getAdd3() << "\n\tʩ����������" << pbuilding[i]->getArea() << "ƽ����\t��ͬ��" << pbuilding[i]->getCost() << "��Ԫ�����";
						opfile << "\n\t��ͬ�������ڣ�" << pbuilding[i]->getBegin().year << "��" << pbuilding[i]->getBegin().month << "��" << pbuilding[i]->getBegin().day << "��\t��ͬ�깤���ڣ�" << pbuilding[i]->getEnd().year << "��" << pbuilding[i]->getEnd().month << "��" << pbuilding[i]->getEnd().day << "��\n";
					}
					cout << "�����д�ı��ļ���\n";
					opfile.close();
				}
			}
			if (y == 2)
			{
				townHouse **ptownhouse = new townHouse*;
				ptownhouse = totalarray01(num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(ptownhouse, num);
				for (int i = 0; i < num; i++)
					ptownhouse[i]->print();
				cout << "�Ƿ����ı��ļ������ǣ�1����0����";
				int g;
				cin >> g;
				if (g)
				{
					fstream opfile(fileTxt01, ios::out);
					if (!opfile)
					{
						cerr << "File could not be open." << endl;
						abort();
					}
					opfile << "                    ���ݽ���������Ŀ�б�\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "��ţ�" << ptownhouse[i]->getCode() << "\t" << "���ƣ�" << ptownhouse[i]->getName() << "\t" << (ptownhouse[i]->getStatus() == true ? "������" : "δ����") << "\t���赥λ��" << ptownhouse[i]->getCompany() << "\t������ַ��" << ptownhouse[i]->getAdd1() << ptownhouse[i]->getAdd2() << ptownhouse[i]->getAdd3() << "\n\tʩ����������" << ptownhouse[i]->getArea() << "ƽ����\t��ͬ��" << ptownhouse[i]->getCost() << "��Ԫ�����";
						opfile << "\n\t��ͬ�������ڣ�" << ptownhouse[i]->getBegin().year << "��" << ptownhouse[i]->getBegin().month << "��" << ptownhouse[i]->getBegin().day << "��\t��ͬ�깤���ڣ�" << ptownhouse[i]->getEnd().year << "��" << ptownhouse[i]->getEnd().month << "��" << ptownhouse[i]->getEnd().day << "��\n";
					}
					cout << "�����д�ı��ļ���\n";
					opfile.close();
				}
			}
			if (y == 3)
			{
				publicWork **ppublicwork = new publicWork*;
				ppublicwork = totalarray02(num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(ppublicwork, num);
				for (int i = 0; i < num; i++)
					ppublicwork[i]->print();
				cout << "�Ƿ����ı��ļ������ǣ�1����0����";
				int g;
				cin >> g;
				if (g)
				{
					fstream opfile(fileTxt02, ios::out);
					if (!opfile)
					{
						cerr << "File could not be open." << endl;
						abort();
					}
					opfile << "                    ����������Ŀ�б�\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "��ţ�" << ppublicwork[i]->getCode() << "\t" << "���ƣ�" << ppublicwork[i]->getName() << "\t" << (ppublicwork[i]->getStatus() == true ? "������" : "δ����") << "\t���赥λ��" << ppublicwork[i]->getCompany() << "\t������ַ��" << ppublicwork[i]->getAdd1() << ppublicwork[i]->getAdd2() << ppublicwork[i]->getAdd3() << "\n\tʩ����������" << ppublicwork[i]->getArea() << "ƽ����\t��ͬ��" << ppublicwork[i]->getCost() << "��Ԫ�����";
						opfile << "\n\t��ͬ�������ڣ�" << ppublicwork[i]->getBegin().year << "��" << ppublicwork[i]->getBegin().month << "��" << ppublicwork[i]->getBegin().day << "��\t��ͬ�깤���ڣ�" << ppublicwork[i]->getEnd().year << "��" << ppublicwork[i]->getEnd().month << "��" << ppublicwork[i]->getEnd().day << "��\n";
					}
					cout << "�����д�ı��ļ���\n";
					opfile.close();
				}
			}
			if (y == 4)
			{
				civilBuilding **pcivilbuilding = new civilBuilding*;
				pcivilbuilding = totalarray0(num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(pcivilbuilding, num);
				for (int i = 0; i < num; i++)
					pcivilbuilding[i]->print();
				cout << "�Ƿ����ı��ļ������ǣ�1����0����";
				int g;
				cin >> g;
				if (g)
				{
					fstream opfile(fileTxt0, ios::out);
					if (!opfile)
					{
						cerr << "File could not be open." << endl;
						abort();
					}
					opfile << "                    ���ý�����Ŀ�б�\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "��ţ�" << pcivilbuilding[i]->getCode() << "\t" << "���ƣ�" << pcivilbuilding[i]->getName() << "\t" << (pcivilbuilding[i]->getStatus() == true ? "������" : "δ����") << "\t���赥λ��" << pcivilbuilding[i]->getCompany() << "\t������ַ��" << pcivilbuilding[i]->getAdd1() << pcivilbuilding[i]->getAdd2() << pcivilbuilding[i]->getAdd3() << "\n\tʩ����������" << pcivilbuilding[i]->getArea() << "ƽ����\t��ͬ��" << pcivilbuilding[i]->getCost() << "��Ԫ�����";
						opfile << "\n\t��ͬ�������ڣ�" << pcivilbuilding[i]->getBegin().year << "��" << pcivilbuilding[i]->getBegin().month << "��" << pcivilbuilding[i]->getBegin().day << "��\t��ͬ�깤���ڣ�" << pcivilbuilding[i]->getEnd().year << "��" << pcivilbuilding[i]->getEnd().month << "��" << pcivilbuilding[i]->getEnd().day << "��\n";
					}
					cout << "�����д�ı��ļ���\n";
					opfile.close();
				}
			}
			if (y == 5)
			{
				indusBuilding *indusbuilding = new indusBuilding;
				Readdat(fileDat4, indusbuilding, num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(indusbuilding, num);
				for (int i = 0; i < num; i++)
					indusbuilding[i].print();
			}
			if (y == 6)
			{
				Structure *structure = new Structure;
				Readdat(fileDat5, structure, num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(structure, num);
				for (int i = 0; i < num; i++)
					structure[i].print();
			}
			if (y == 7)
			{
				Traffic *traffic = new Traffic;
				Readdat(fileDat6, traffic, num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(traffic, num);
				for (int i = 0; i < num; i++)
					traffic[i].print();
			}
			if (y == 8)
			{
				Plant *plant = new Plant;
				Readdat(fileDat7, plant, num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(plant, num);
				for (int i = 0; i < num; i++)
					plant[i].print();
			}
			if (y == 9)
			{
				Sign *sign = new Sign;
				Readdat(fileDat8, sign, num);
				if (num == 0)
				{
					cout << "���б�Ϊ�գ�" << endl;
					cout << endl;
					continue;
				}
				sort(sign, num);
				for (int i = 0; i < num; i++)
					sign[i].print();
			}
			cout << endl;
		}
		goto Menu;
	}
	if (x == 5)
	{
		cout << "ѡ��鿴����ͳ�Ƶ���Ŀ���\n";
		while (1)
		{
			int y, totalnum = 0;
			double totalarea = 0, totalcost = 0;
			cout << "1��������Ŀ\n"
				<< "2�����ݽ���������Ŀ  3������������Ŀ\n"
				<< "4�����ý�����Ŀ  5����ҵ������Ŀ\n"
				<< "6��������  7��������ͨ����  8���̻�����  9����ʶ��ʩ\n"
				<< "0���˳�\n"
				<< "�������Ҫ�������֣�";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 9))
			{
				cout << "����������������룡\n";
				continue;
			}
			if (y == 1)
			{
				cout << "������Ŀ ����ͳ�ƣ�  ";
				Building **pbuilding = new Building*;
				pbuilding = totalarray(totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += pbuilding[i]->getArea();
					totalcost += pbuilding[i]->getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 2)
			{
				cout << "���ݽ���������Ŀ ����ͳ�ƣ�  ";
				townHouse **ptownhouse = new townHouse*;
				ptownhouse = totalarray01(totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += ptownhouse[i]->getArea();
					totalcost += ptownhouse[i]->getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 3)
			{
				cout << "����������Ŀ ����ͳ�ƣ�  ";
				publicWork **ppublicwork = new publicWork*;
				ppublicwork = totalarray02(totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += ppublicwork[i]->getArea();
					totalcost += ppublicwork[i]->getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 4)
			{
				cout << "���ý�����Ŀ ����ͳ�ƣ�  ";
				civilBuilding **pcivilbuilding = new civilBuilding*;
				pcivilbuilding = totalarray0(totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += pcivilbuilding[i]->getArea();
					totalcost += pcivilbuilding[i]->getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 5)
			{
				cout << "��ҵ������Ŀ ����ͳ�ƣ�  ";
				indusBuilding *indusbuilding = new indusBuilding;
				Readdat(fileDat4, indusbuilding, totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += indusbuilding[i].getArea();
					totalcost += indusbuilding[i].getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 6)
			{
				cout << "������ ����ͳ�ƣ�  ";
				Structure *structure = new Structure;
				Readdat(fileDat5, structure, totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += structure[i].getArea();
					totalcost += structure[i].getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 7)
			{
				cout << "������ͨ���� ����ͳ�ƣ�  ";
				Traffic *traffic = new Traffic;
				Readdat(fileDat6, traffic, totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += traffic[i].getArea();
					totalcost += traffic[i].getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 8)
			{
				cout << "�̻����� ����ͳ�ƣ�  ";
				Plant *plant = new Plant;
				Readdat(fileDat7, plant, totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += plant[i].getArea();
					totalcost += plant[i].getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			if (y == 9)
			{
				cout << "��ʶ��ʩ ����ͳ�ƣ�  ";
				Sign *sign = new Sign;
				Readdat(fileDat8, sign, totalnum);
				cout << "�ܼ���Ŀ��" << totalnum << "��";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += sign[i].getArea();
					totalcost += sign[i].getCost();
				}
				cout << "\t�ܼ�ʩ����������" << totalarea << "ƽ����\t�ܼƺ�ͬ��" << totalcost << "��Ԫ�����" << endl;
			}
			cout << endl;
		}
		goto Menu;
	}
}
template<typename T>
int endMark(T building)  //���غ������жϿձ�־��¼���ļ�������
{
	if (building.getCode() == 0) return 1;
	else return 0;
}
int endMark(Building *building)  //���غ������жϿձ�־��¼���ļ�������
{
	if (building->getCode() == 0) return 1;
	else return 0;
}
template<typename T>
void sort(T *building, int size)  //����
{
	int i, flag, p, g;
	T temp;
	bool f;
	cout << "��ѡ������ؼ��֣�Ĭ�ϣ�0��ʩ�������1����ͬ��2����\n";
	cin >> g;
	if (g == 0) return;
	cout << "��ѡ������ؼ��֣�����1������0����\n";
	cin >> f;
	if (g == 1)
	{
		for (p = 1; p < size; p++)
		{
			flag = 1;
			for (i = 0; i < size - p; i++)
			{
				if (f&&building[i].getArea() > building[i + 1].getArea())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
				if (!f&&building[i].getArea() < building[i + 1].getArea())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
			}
		}
	}
	if (g == 2)
	{
		for (p = 1; p < size; p++)
		{
			flag = 1;
			for (i = 0; i < size - p; i++)
			{
				if (f&&building[i].getCost() > building[i + 1].getCost())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
				if (!f&&building[i].getCost() < building[i + 1].getCost())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
			}
		}
	}
}
template<typename T>
void sort(T **building, int size)  //����2
{
	int i, flag, p, g;
	T *temp;
	bool f;
	cout << "��ѡ������ؼ��֣�Ĭ�ϣ�0��ʩ�������1����ͬ��2����\n";
	cin >> g;
	if (g == 0) return;
	cout << "��ѡ������ؼ��֣�����1������0����\n";
	cin >> f;
	if (g == 1)
	{
		for (p = 1; p < size; p++)
		{
			flag = 1;
			for (i = 0; i < size - p; i++)
			{
				if (f&&building[i]->getArea() > building[i + 1]->getArea())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
				if (!f&&building[i]->getArea() < building[i + 1]->getArea())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
			}
		}
	}
	if (g == 2)
	{
		for (p = 1; p < size; p++)
		{
			flag = 1;
			for (i = 0; i < size - p; i++)
			{
				if (f&&building[i]->getCost() > building[i + 1]->getCost())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
				if (!f&&building[i]->getCost() < building[i + 1]->getCost())
				{
					temp = building[i];
					building[i] = building[i + 1];
					building[i + 1] = temp;
				}
			}
		}
	}
}
void Initial(const char *fileDat, int f)  //��Ŀ�ļ���ʼ��
{
	fstream fdat(fileDat, ios::out | ios::binary);
	fdat.seekp(0, ios::beg);
	const int num = 0;
	fdat.write((char*)&num, sizeof(int));
	if (f == 1) fdat.write((char*)&mark, sizeof(Resident));
	if (f == 2) fdat.write((char*)&mark, sizeof(Office));
	if (f == 3) fdat.write((char*)&mark, sizeof(Service));
	if (f == 4) fdat.write((char*)&mark, sizeof(indusBuilding));
	if (f == 5) fdat.write((char*)&mark, sizeof(Structure));
	if (f == 6) fdat.write((char*)&mark, sizeof(Traffic));
	if (f == 7) fdat.write((char*)&mark, sizeof(Plant));
	if (f == 8) fdat.write((char*)&mark, sizeof(Sign));
	fdat.close();
}
template<typename T>
void Change1(const char *fileDat, char *iname, long icode, int &flag)  //��Ŀ��Ϣ�޸�
{
	if (flag == 1) return;
	T building;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (!fdat)
	{
		cout << "��Ŀ�ļ������ڣ�����г�ʼ��\n";
		return;
	}
	fdat.seekg(sizeof(int), ios::beg);                  //��ָ���Ƶ��ļ�ͷ����ͳ�ƺ�
	do                                        //���������Ŀ
	{
		fdat.read((char*)&building, sizeof(T));  //
	} while (building.getCode() != icode && strcmp(building.getName(), iname) != 0 && !endMark(building));   //�ж��Ƿ��ҵ����ļ��Ƿ����
	if (endMark(building)) return;
	if (building.getCode() == icode || strcmp(building.getName(), iname) == 0)
	{
		flag = 1;
		building.print();
		int xx;
		while (1)
		{
			cout << "\n������Ҫ�޸ĸ���Ŀ��1������״̬ 2�����赥λ 3��������ַ 4��ʩ�������� 5����ͬ��� 6���ʽ���Դ 7����ͬ�������� 8����ͬ�깤���� 9�����д������";
			cin >> xx;
			if (!(xx >= 1 && xx <= 9))
			{
				cout << "����������������룡\n";
				continue;
			}
			if (xx == 1)
			{
				cout << "�������޸ĺ������״̬����������1��δ������0����";
				bool temp;
				while (cin >> temp)
				{
					if (temp != building.getStatus())
					{
						building.setStatus(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "����״̬�Ѿ��޸�Ϊ��" << (temp ? "������" : "δ����") << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ�����״̬�Ѿ�Ϊ��" << (temp ? "������" : "δ����")
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (xx == 2)
			{
				cout << "�������޸ĺ�Ľ��赥λ��";
				char temp[10];
				while (cin >> temp)
				{
					if (temp != building.getCompany())
					{
						building.setCompany(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "���赥λ�Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ����赥λ�Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (xx == 3)
			{
				cout << "�������޸ĺ�Ľ�����ַ��";
				Address temp;
				while (cin >> temp.city >> temp.district >> temp.street)
				{
					if (temp.city != building.getAdd1() || temp.district != building.getAdd2() || temp.street != building.getAdd3())
					{
						building.setAdd1(temp.city);
						building.setAdd2(temp.district);
						building.setAdd3(temp.street);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "������ַ�Ѿ��޸�Ϊ��" << temp.city << temp.district << temp.street << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ����赥λ�Ѿ�Ϊ��" << temp.city << temp.district << temp.street
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (xx == 4)
			{
				cout << "�������޸ĺ��ʩ����������";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getArea())
					{
						building.setArea(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "ʩ���������Ѿ��޸�Ϊ��" << temp << "ƽ����\n";
						break;
					}
					else
					{
						cout << "�����޸ģ�ʩ�����������Ѿ�Ϊ��" << temp
							<< "ƽ����\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (xx == 5)
			{
				cout << "�������޸ĺ�ĺ�ͬ��";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getCost())
					{
						building.setCost(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "��ͬ����Ѿ��޸�Ϊ��" << temp << "��Ԫ�����\n";
						break;
					}
					else
					{
						cout << "�����޸ģ���ͬ����Ѿ�Ϊ��" << temp
							<< "��Ԫ�����\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (xx == 6)
			{
				cout << "�������޸ĺ���ʽ���Դ��";  //�������������ݳ�Ա��
				int temp;
				while (cin >> temp)
				{
					if (temp != building.getSource())
					{
						building.setSource(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "�ʽ���Դ�Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ��ʽ���Դ�Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (xx == 7)
			{
				cout << "�������޸ĺ�ĺ�ͬ�������ڣ�";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setBegin(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
				fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
				cout << "��ͬ���������Ѿ��޸�Ϊ��" << tempy << "��" << tempm << "��" << tempd << "��" << "\n";
			}
			if (xx == 8)
			{
				cout << "�������޸ĺ�ĺ�ͬ�깤���ڣ�";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setEnd(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
				fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
				cout << "��ͬ�깤�����Ѿ��޸�Ϊ��" << tempy << "��" << tempm << "��" << tempd << "��" << "\n";
			}
			if (xx == 9)
			{
				double temp;
				cout << "�������޸ĺ�����д����";
				while (cin >> temp)
				{
					if (temp != building.getLoan())
					{
						building.setLoan(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "���д������Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ����д������Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			break;
		}
		fdat.close();
	}
}
template<typename T>
void Change2(const char *fileDat, char *iname, long icode, int &flag)  //��Ŀ��Ϣ�޸�
{
	if (flag == 1) return;
	T building;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (!fdat)
	{
		cout << "��Ŀ�ļ������ڣ�����г�ʼ��\n";
		return;
	}
	fdat.seekg(sizeof(int), ios::beg);                  //��ָ���Ƶ��ļ�ͷ����ͳ�ƺ�
	do                                        //���������Ŀ
	{
		fdat.read((char*)&building, sizeof(T));  //
	} while (building.getCode() != icode && strcmp(building.getName(), iname) != 0 && !endMark(building));   //�ж��Ƿ��ҵ����ļ��Ƿ����
	if (endMark(building)) return;
	if (building.getCode() == icode || strcmp(building.getName(), iname) == 0)
	{
		flag = 1;
		building.print();
		int x;
		while (1)
		{
			cout << "\n������Ҫ�޸ĸ���Ŀ��1������״̬ 2�����赥λ 3��������ַ 4��ʩ�������� 5����ͬ��� 6���ʽ���Դ 7����ͬ�������� 8����ͬ�깤���� 9������������";
			cin >> x;
			if (!(x >= 1 && x <= 9))
			{
				cout << "����������������룡\n";
				continue;
			}
			if (x == 1)
			{
				cout << "�������޸ĺ������״̬����������1��δ������0����";
				bool temp;
				while (cin >> temp)
				{
					if (temp != building.getStatus())
					{
						building.setStatus(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "����״̬�Ѿ��޸�Ϊ��" << (temp ? "������" : "δ����") << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ�����״̬�Ѿ�Ϊ��" << (temp ? "������" : "δ����")
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (x == 2)
			{
				cout << "�������޸ĺ�Ľ��赥λ��";
				char temp[10];
				while (cin >> temp)
				{
					if (temp != building.getCompany())
					{
						building.setCompany(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "���赥λ�Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ����赥λ�Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (x == 3)
			{
				cout << "�������޸ĺ�Ľ�����ַ��";
				Address temp;
				while (cin >> temp.city >> temp.district >> temp.street)
				{
					if (temp.city != building.getAdd1() || temp.district != building.getAdd2() || temp.street != building.getAdd3())
					{
						building.setAdd1(temp.city);
						building.setAdd2(temp.district);
						building.setAdd3(temp.street);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "������ַ�Ѿ��޸�Ϊ��" << temp.city << temp.district << temp.street << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ����赥λ�Ѿ�Ϊ��" << temp.city << temp.district << temp.street
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (x == 4)
			{
				cout << "�������޸ĺ��ʩ����������";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getArea())
					{
						building.setArea(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "ʩ���������Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ�ʩ�����������Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (x == 5)
			{
				cout << "�������޸ĺ�ĺ�ͬ��";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getCost())
					{
						building.setCost(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "��ͬ����Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ���ͬ����Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (x == 6)
			{
				cout << "�������޸ĺ���ʽ���Դ��";  //�������������ݳ�Ա��
				int temp;
				while (cin >> temp)
				{
					if (temp != building.getSource())
					{
						building.setSource(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "�ʽ���Դ�Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ��ʽ���Դ�Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			if (x == 7)
			{
				cout << "�������޸ĺ�ĺ�ͬ�������ڣ�";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setBegin(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
				fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
				cout << "��ͬ���������Ѿ��޸�Ϊ��" << tempy << "��" << tempm << "��" << tempd << "��" << "\n";
			}
			if (x == 8)
			{
				cout << "�������޸ĺ�ĺ�ͬ�깤���ڣ�";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setEnd(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
				fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
				cout << "��ͬ�깤�����Ѿ��޸�Ϊ��" << tempy << "��" << tempm << "��" << tempd << "��" << "\n";
			}
			if (x == 9)
			{
				double temp;
				cout << "�������޸ĺ����������";
				while (cin >> temp)
				{
					if (temp != building.getDonation())
					{
						building.setDonation(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //�ļ�дָ�븴λ
						fdat.write((char*)&building, sizeof(T));  //д�޸ĺ��¼
						cout << "����������Ѿ��޸�Ϊ��" << temp << "\n";
						break;
					}
					else
					{
						cout << "�����޸ģ����д������Ѿ�Ϊ��" << temp
							<< "\n�Ƿ��������룿���ǣ�1����0��\n";
						int yy;
						cin >> yy;
						if (yy) cout << "�������룺";
						else
						{
							cout << "�˳�����Ŀ���޸Ĳ�����\n";
							break;
						}
					}
				}
			}
			break;
		}
	}
	fdat.close();
}
template<typename T>
void Delete(const char *fileDat, char *iname, long icode, int &flag)  //��Ŀ��Ϣɾ��
{
	if (flag == 1) return;
	T building;
	int pn = 0, num;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (!fdat)
	{
		cout << "��Ŀ�ļ������ڣ�����г�ʼ��\n";
		return;
	}
	fdat.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
	fdat.read((char*)&num, sizeof(int));
	do                                        //���������Ŀ
	{
		fdat.read((char*)&building, sizeof(T));  //
		pn++;
	} while (building.getCode() != icode && strcmp(building.getName(), iname) != 0 && !endMark(building));   //�ж��Ƿ��ҵ����ļ��Ƿ����
	if (endMark(building)) return;
	if (building.getCode() == icode || strcmp(building.getName(), iname) == 0)
	{
		flag = 1;
		building.print();
		int xx;
		cout << "�Ƿ�ȷ�Ͻ�����Ŀ��Ϣɾ�������ǣ�1����0��\n";
		cin >> xx;
		if (xx == 1)
		{
			pn = num - pn;
			num--;
			T *temp = new T[pn];
			fdat.read((char*)temp, pn * sizeof(T));  //���������ļ��ڵ���Ŀ��Ϣ����temp����
			fdat.seekp(-long((pn + 1) * sizeof(T)), ios::cur);
			for (int i = 0; i < pn; i++)
				fdat.write((char*)&temp[i], sizeof(T));
			fdat.write((char*)&mark, sizeof(T));  //д�ļ�������־
			fdat.seekp(0, ios::beg);  //��дָ�������ļ�ͷ
			fdat.write((char*)&num, sizeof(int));  //���´洢��Ŀ������
			fdat.close();
		}
	}
}
template<typename T>
void Readdat(const char *fileDat, T* & building, int &num)  //fileDatΪf�����Ŀ�ļ�,TΪ�����������
{
	int i;
	fstream fdat(fileDat, ios::in | ios::binary);
	if (!fdat)
	{
		cout << "��Ŀ�ļ������ڣ�����г�ʼ��\n";
		return;
	}
	fdat.seekg(0, ios::beg);                  //��ָ���Ƶ��ļ�ͷ
	fdat.read((char*)&num, sizeof(int));  //�����洢����Ŀ����
	T *t = new T[num];
	building = new T[num];
	for (i = 0; i < num; i++)
	{
		fdat.read((char*)&t[i], sizeof(t[i]));
		if (t[i].getCode() != 0)
			building[i] = t[i];
		else break;
	}
	fdat.close();
}
Building** totalarray(int &num)  //����Ŀ����
{
	int j, i = 0, n = 0;
	Building **totalb = new Building*;  //������ά���飬ʹ����Ԫ��Ϊ����ָ��
	Resident *resident = new Resident;
	Readdat(fileDat1, resident, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &resident[j];
	Office *office = new Office;
	Readdat(fileDat2, office, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &office[j];
	Service *service = new Service;
	Readdat(fileDat3, service, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &service[j];
	indusBuilding *indusbuilding = new indusBuilding;
	Readdat(fileDat4, indusbuilding, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &indusbuilding[j];
	Structure *structure = new Structure;
	Readdat(fileDat5, structure, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &structure[j];
	Traffic *traffic = new Traffic;
	Readdat(fileDat6, traffic, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &traffic[j];
	Plant *plant = new Plant;
	Readdat(fileDat7, plant, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalb[i] = &plant[j];
	Sign *sign = new Sign;
	Readdat(fileDat8, sign, n);
	num += n;
	for (j = 0; i < num; i++) totalb[i] = &sign[j];
	return totalb;
}
townHouse** totalarray01(int &num)  //���ݽ���������Ŀ����
{
	int j, i = 0, n = 0;
	townHouse **totalt = new townHouse*;  //������ά���飬ʹ����Ԫ��Ϊ����ָ��
	Resident *resident = new Resident;
	Readdat(fileDat1, resident, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalt[i] = &resident[j];
	Office *office = new Office;
	Readdat(fileDat2, office, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalt[i] = &office[j];
	Service *service = new Service;
	Readdat(fileDat3, service, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalt[i] = &service[j];
	indusBuilding *indusbuilding = new indusBuilding;
	Readdat(fileDat4, indusbuilding, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalt[i] = &indusbuilding[j];
	return totalt;
}
civilBuilding** totalarray0(int &num)  //���ý�����Ŀ����
{
	int j, i = 0, n = 0;
	civilBuilding **totalc = new civilBuilding*;  //������ά���飬ʹ����Ԫ��Ϊ����ָ��
	Resident *resident = new Resident;
	Readdat(fileDat1, resident, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalc[i] = &resident[j];
	Office *office = new Office;
	Readdat(fileDat2, office, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalc[i] = &office[j];
	Service *service = new Service;
	Readdat(fileDat3, service, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalc[i] = &service[j];
	return totalc;
}
publicWork** totalarray02(int &num)  //����������Ŀ����
{
	int j, i = 0, n = 0;
	publicWork **totalp = new publicWork*;  //������ά���飬ʹ����Ԫ��Ϊ����ָ��
	Structure *structure = new Structure;
	Readdat(fileDat5, structure, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalp[i] = &structure[j];
	Traffic *traffic = new Traffic;
	Readdat(fileDat6, traffic, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalp[i] = &traffic[j];
	Plant *plant = new Plant;
	Readdat(fileDat7, plant, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalp[i] = &plant[j];
	Sign *sign = new Sign;
	Readdat(fileDat8, sign, n);
	num += n;
	for (j = 0; i < num; i++, j++) totalp[i] = &sign[j];
	return totalp;
}