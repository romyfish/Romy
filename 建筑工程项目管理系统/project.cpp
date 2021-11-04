#include"project.h"
using namespace std;

const char *fileDat1 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\居住建筑项目列表.dat";
const char *fileDat2 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\办公建筑项目列表.dat";
const char *fileDat3 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\生活活动建筑项目列表.dat";
const char *fileDat4 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\工业建筑项目列表.dat";
const char *fileDat5 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\构筑物项目列表.dat";
const char *fileDat6 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\公共交通项目列表.dat";
const char *fileDat7 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\绿化工程项目列表.dat";
const char *fileDat8 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\标识设施项目列表.dat";
const char *fileTxt0 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\民用建筑项目列表.txt";
const char *fileTxt01 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\房屋建筑工程项目列表.txt";
const char *fileTxt02 = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\市政工程项目列表.txt";
const char *fileTxt = "C:\\Users\\Romy\\source\\repos\\建筑工程项目管理系统\\总建筑项目列表.txt";

int main()
{
	cout << "                  城市建筑工程项目管理系统" << endl;
Menu:
	int x;
	cout << "\n-------------------------菜单-------------------------\n";
	cout << "1：初始化  2：对项目信息进行操作  3：查询筛选  4：列表显示  5：总量统计  0：退出管理系统\n";
	cout << "请根据需要输入数字：";
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
		cout << "完成初始化！\n";
		goto Menu;
	}
	if (x == 2)
	{
		cout << "选择对项目信息进行录入、修改、删除操作\n";
		while (1)
		{
			int y;
			cout << "1：录入  2：修改  3：删除  0：退出\n";
			cout << "请根据需要输入数字：";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 3))
			{
				cout << "输入错误，请重新输入！\n";
				cout << endl;
				continue;
			}
			if (y == 1)                                 //项目信息输入
			{
				cout << "-------------------------项目信息输入-------------------------\n";
				while (1)
				{
					cout << "选择录入项目类别\n";
					int z;
					cout << "房屋建筑工程项目：  1：民用建筑  2：工业建筑\n"
						<< "市政工程项目：3：构筑物  4：公共交通  5：绿化工程  6：标识设施\n"
						<< "0：退出\n"
						<< "请根据需要输入数字：";
					cin >> z;
					if (z == 0) break;
					if (z == 1)
					{
						int xx = 0;
						cout << "1：居住建筑  2：办公建筑  3：生活活动建筑\n";
						cout << "请根据需要输入数字：";
						cin >> xx;
						cout << "请依次输入项目的编号、名称、审批状态（已审批：1；未审批：0）、建设单位、建筑地址（市、区、街道以空格间隔开）、施工许可面积（单位/平方米）、合同金额（单位/万元人民币）、资金来源（项目公司：0；银行贷款：1；两者均有：2）、合同开工日期、合同完工日期（年、月、日以空格间隔）\n"
							<< "（注：各信息间以空格隔开）\n";
						if (xx == 1)
						{
							int count1;
							Resident resident;
							fstream fdat1(fileDat1, ios::in | ios::out | ios::binary);
							fdat1.seekg(0, ios::beg);                  //读指针移到文件头
							fdat1.read((char*)&count1, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找居住建筑项目文件尾
							{
								fdat1.read((char*)&resident, sizeof(resident));
							} while (!endMark(resident));             //判断文件是否结束标志
							fdat1.seekp(-long(sizeof(Resident)), ios::cur);  //置写指针位置
							cin >> resident;
							count1++;
							fdat1.write((char*)&resident, sizeof(Resident));  //写记录至居住建筑项目文件
							fdat1.write((char*)&mark, sizeof(Resident));  //写文件结束标志
							fdat1.seekp(0, ios::beg);  //将写指针置于文件头
							fdat1.write((char*)&count1, sizeof(int));  //更新存储项目的数量
							fdat1.close();
						}
						if (xx == 2)
						{
							int count2;
							Office office;
							fstream fdat2(fileDat2, ios::in | ios::out | ios::binary);
							fdat2.seekg(0, ios::beg);                  //读指针移到文件头
							fdat2.read((char*)&count2, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找文件尾
							{
								fdat2.read((char*)&office, sizeof(office));  //是否加上数组下标？
							} while (!endMark(office));             //判断文件是否结束标志
							fdat2.seekp(-long(sizeof(Office)), ios::cur);  //置写指针位置
							cin >> office;
							count2++;
							fdat2.write((char*)&office, sizeof(Office));  //写记录至办公建筑项目文件
							fdat2.write((char*)&mark, sizeof(Office));  //写文件结束标志
							fdat2.seekp(0, ios::beg);  //将写指针置于文件头
							fdat2.write((char*)&count2, sizeof(int));  //更新存储项目的数量
							fdat2.close();
						}
						if (xx == 3)
						{
							int count3;
							Service service;
							fstream fdat3(fileDat3, ios::in | ios::out | ios::binary);
							fdat3.seekg(0, ios::beg);                  //读指针移到文件头
							fdat3.read((char*)&count3, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找文件尾
							{
								fdat3.read((char*)&service, sizeof(service));  //是否加上数组下标？
							} while (!endMark(service));             //判断文件是否结束标志
							fdat3.seekp(-long(sizeof(Service)), ios::cur);  //置写指针位置
							cin >> service;
							count3++;
							fdat3.write((char*)&service, sizeof(Service));  //写记录至生活活动建筑项目文件
							fdat3.write((char*)&mark, sizeof(Service));  //写文件结束标志
							fdat3.seekp(0, ios::beg);  //将写指针置于文件头
							fdat3.write((char*)&count3, sizeof(int));  //更新存储项目的数量
							fdat3.close();
						}
					}
					if (z == 2)
					{
						cout << "请依次输入项目的编号、名称、审批状态（已审批：1；未审批：0）、建设单位、建筑地址（市、区、街道以空格间隔）、施工许可面积（单位/平方米）、合同金额（单位/万元人民币）、资金来源（项目公司：0；银行贷款：1；两者均有：2）、合同开工日期、合同完工日期（年、月、日以空格间隔）\n"
							<< "（注：各信息间以空格隔开）\n";
						int count4;
						indusBuilding indusbuilding;
						fstream fdat4(fileDat4, ios::in | ios::out | ios::binary);
						fdat4.seekg(0, ios::beg);                  //读指针移到文件头
						fdat4.read((char*)&count4, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
						do                                        //查找文件尾
						{
							fdat4.read((char*)&indusbuilding, sizeof(indusbuilding));  //是否加上数组下标？
						} while (!endMark(indusbuilding));             //判断文件是否结束标志
						fdat4.seekp(-long(sizeof(indusBuilding)), ios::cur);  //置写指针位置
						cin >> indusbuilding;
						count4++;
						fdat4.write((char*)&indusbuilding, sizeof(indusBuilding));  //写记录至工业建筑项目文件
						fdat4.write((char*)&mark, sizeof(indusBuilding));  //写文件结束标志
						fdat4.seekp(0, ios::beg);  //将写指针置于文件头
						fdat4.write((char*)&count4, sizeof(int));  //更新存储项目的数量
						fdat4.close();
					}
					if (z > 2)
					{
						cout << "请依次输入项目的编号、名称、审批状态（已审批：1；未审批：0）、建设单位、建筑地址（市、区、街道以空格间隔）、施工许可面积（单位/平方米）、合同金额（单位/万元人民币）、资金来源（项目公司：0；社会捐赠：1；两者均有：2））、合同开工日期、合同完工日期（年、月、日以空格间隔）\n"
							<< "（注：各信息间以空格隔开）\n";

						if (z == 3)
						{
							int count5;
							Structure structure;
							fstream fdat5(fileDat5, ios::in | ios::out | ios::binary);
							fdat5.seekg(0, ios::beg);                  //读指针移到文件头
							fdat5.read((char*)&count5, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找文件尾
							{
								fdat5.read((char*)&structure, sizeof(structure));  //是否加上数组下标？
							} while (!endMark(structure));             //判断文件是否结束标志
							fdat5.seekp(-long(sizeof(Structure)), ios::cur);  //置写指针位置
							cin >> structure;
							count5++;
							fdat5.write((char*)&structure, sizeof(Structure));  //写记录至构筑物项目文件
							fdat5.write((char*)&mark, sizeof(Structure));  //写文件结束标志
							fdat5.seekp(0, ios::beg);  //将写指针置于文件头
							fdat5.write((char*)&count5, sizeof(int));  //更新存储项目的数量
							fdat5.close();
						}
						if (z == 4)
						{
							int count6;
							Traffic traffic;
							fstream fdat6(fileDat6, ios::in | ios::out | ios::binary);
							fdat6.seekg(0, ios::beg);                  //读指针移到文件头
							fdat6.read((char*)&count6, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找文件尾
							{
								fdat6.read((char*)&traffic, sizeof(traffic));  //是否加上数组下标？
							} while (!endMark(traffic));             //判断文件是否结束标志
							fdat6.seekp(-long(sizeof(Traffic)), ios::cur);  //置写指针位置
							cin >> traffic;
							count6++;
							fdat6.write((char*)&traffic, sizeof(Traffic));  //写记录至公共交通工程项目文件
							fdat6.write((char*)&mark, sizeof(Traffic));  //写文件结束标志
							fdat6.seekp(0, ios::beg);  //将写指针置于文件头
							fdat6.write((char*)&count6, sizeof(int));  //更新存储项目的数量
							fdat6.close();
						}
						if (z == 5)
						{
							int count7;
							Plant plant;
							fstream fdat7(fileDat7, ios::in | ios::out | ios::binary);
							fdat7.seekg(0, ios::beg);                  //读指针移到文件头
							fdat7.read((char*)&count7, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找文件尾
							{
								fdat7.read((char*)&plant, sizeof(plant));  //是否加上数组下标？
							} while (!endMark(plant));             //判断文件是否结束标志
							fdat7.seekp(-long(sizeof(Plant)), ios::cur);  //置写指针位置
							cin >> plant;
							count7++;
							fdat7.write((char*)&plant, sizeof(Plant));  //写记录至绿化工程项目文件
							fdat7.write((char*)&mark, sizeof(Plant));  //写文件结束标志
							fdat7.seekp(0, ios::beg);  //将写指针置于文件头
							fdat7.write((char*)&count7, sizeof(int));  //更新存储项目的数量
							fdat7.close();
						}
						if (z == 6)
						{
							int count8;
							Sign sign;
							fstream fdat8(fileDat8, ios::in | ios::out | ios::binary);
							fdat8.seekg(0, ios::beg);                  //读指针移到文件头
							fdat8.read((char*)&count8, sizeof(int));  //将该文件存储项目的数量读入内存，由相应count变量记录
							do                                        //查找文件尾
							{
								fdat8.read((char*)&sign, sizeof(sign));  //是否加上数组下标？
							} while (!endMark(sign));             //判断文件是否结束标志
							fdat8.seekp(-long(sizeof(Sign)), ios::cur);  //置写指针位置
							cin >> sign;
							count8++;
							fdat8.write((char*)&sign, sizeof(Sign));  //写记录至标识设施项目文件
							fdat8.write((char*)&mark, sizeof(Sign));  //写文件结束标志
							fdat8.seekp(0, ios::beg);  //将写指针置于文件头
							fdat8.write((char*)&count8, sizeof(int));  //更新存储项目的数量
							fdat8.close();
						}
					}
					cout << "项目信息已完成录入！" << endl;
					cout << endl;
				}
			}
			if (y == 2)
			{
				cout << "-------------------------项目信息修改-------------------------\n";
				while (1)
				{
					int flag = 0;
					int z;
					cout << "请选择通过名称（输入：1）或编号（输入：2）查找需要修改的项目\n"
						<< "退出：0\n";
					cin >> z;
					char iname[20];
					long icode = 0;
					if (z == 0) break;
					if (z == 1)
					{
						cout << "请输入该项目名称：";
						cin >> iname;
					}
					if (z == 2)
					{
						cout << "请输入该项目编号：";
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
					if (flag == 0) cout << "未找到所需修改的项目！请重新输入" << endl;
					else cout << "\n项目信息已完成修改！" << endl;
					cout << endl;
				}
			}
			if (y == 3)
			{
				cout << "-------------------------项目信息删除-------------------------\n";
				while (1)
				{
					int flag = 0;
					int z;
					cout << "请选择通过名称（输入：1）或编号（输入：2）查找需要删除的项目\n"
						<< "退出：0\n";
					cin >> z;
					char iname[20];
					long icode = 0;
					if (z == 0) break;
					if (z == 1)
					{
						cout << "请输入该项目名称：";
						cin >> iname;
					}
					if (z == 2)
					{
						cout << "请输入该项目编号：";
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
					if (flag == 0) cout << "未找到所需删除的项目！请重新输入" << endl;
					else cout << "\n项目信息已完成删除！" << endl;
					cout << endl;
				}
			}
			cout << endl;
		}
		goto Menu;
	}
	if (x == 3)
	{
		cout << "选择所需查询筛选操作\n";
		while (1)
		{
			int y;
			cout << "1：按名称检索项目  2：按编号检索项目  3：按审批状态筛选  4：按建设状态筛选  5：按工期时长筛选  6：按地理位置筛选  0：退出\n";
			cout << "请根据需要输入数字：";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 6))
			{
				cout << "输入错误，请重新输入！\n";
				continue;
			}
			int i, n = 0, flag = 0;
			Building **pbuilding = new Building*;  //创建二维数组，使数组元素为基类指针
			pbuilding = totalarray(n);
			if (y == 1)
			{
				while (1)
				{
					char iname[20];
					cout << "请输入该项目名称：";
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
					else cout << "找不到该项目！是否重新输入？(是：1；否：0）\n";
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
					cout << "请输入该项目编号：";
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
					else cout << "找不到该项目！是否重新输入？(是：1；否：0）\n";
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
					cout << "选择查询已审批项目输入1，查询未审批项目输入0：";
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
					else cout << "找不到该项目！是否重新输入？(是：1；否：0）\n";
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
					cout << "选择查询待建项目输入1，查询在建项目输入2、查询竣工项目输入3：";
					cin >> istu;
					if (istu == 1)  //待建，当前时间早于合同开工时间
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
					if (istu == 2)  //在建，当前时间晚于合同开工时间，且早于完工时间
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
					if (istu == 3)  //竣工，合同完工时间早于当前时间
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
					else cout << "找不到该项目！是否重新输入？(是：1；否：0）\n";
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
					cout << "请输入筛选的工期天数：";
					cin >> iday;
					cout << "请选择查看工期为" << iday << "天及以上（输入+）或以下（输入-）范围的项目：";
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
					else cout << "找不到该项目！是否重新输入？(是：1；否：0）\n";
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
					cout << "选择项目按地理位置的筛选范围（1：市，2：区，3：街道）：";
					cin >> range;
					if (range == 1)
					{
						cout << "请输入城市：";
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
						cout << "请输入区域：";
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
						cout << "请输入街道：";
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
					else cout << "找不到该项目！是否重新输入？(是：1；否：0）\n";
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
		cout << "选择所需显示何种列表\n";
		while (1)
		{
			int y, num = 0;
			cout << "1：所有项目总览\n"
				<< "2：房屋建筑工程项目列表  3：市政工程项目列表\n"
				<< "4：民用建筑项目列表  5：工业建筑项目列表\n"
				<< "6：构筑物项目列表  7：公共交通工程列表  8：绿化工程列表  9：标识设施列表\n"
				<< "0：退出\n"
				<< "请根据需要输入数字：";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 9))
			{
				cout << "输入错误，请重新输入！\n";
				continue;
			}
			if (y == 1)
			{
				Building **pbuilding = new Building*;
				pbuilding = totalarray(num);
				if (num == 0)
				{
					cout << "该列表为空！" << endl;
					cout << endl;
					continue;
				}
				sort(pbuilding, num);
				for (int i = 0; i < num; i++)
					pbuilding[i]->print();
				cout << "是否导入文本文件？（是：1，否：0）：";
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
					opfile << "                    总建筑项目列表\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "编号：" << pbuilding[i]->getCode() << "\t" << "名称：" << pbuilding[i]->getName() << "\t" << (pbuilding[i]->getStatus() == true ? "已审批" : "未审批") << "\t建设单位：" << pbuilding[i]->getCompany() << "\t建筑地址：" << pbuilding[i]->getAdd1() << pbuilding[i]->getAdd2() << pbuilding[i]->getAdd3() << "\n\t施工许可面积：" << pbuilding[i]->getArea() << "平方米\t合同金额：" << pbuilding[i]->getCost() << "万元人民币";
						opfile << "\n\t合同开工日期：" << pbuilding[i]->getBegin().year << "年" << pbuilding[i]->getBegin().month << "月" << pbuilding[i]->getBegin().day << "日\t合同完工日期：" << pbuilding[i]->getEnd().year << "年" << pbuilding[i]->getEnd().month << "月" << pbuilding[i]->getEnd().day << "日\n";
					}
					cout << "已完成写文本文件！\n";
					opfile.close();
				}
			}
			if (y == 2)
			{
				townHouse **ptownhouse = new townHouse*;
				ptownhouse = totalarray01(num);
				if (num == 0)
				{
					cout << "该列表为空！" << endl;
					cout << endl;
					continue;
				}
				sort(ptownhouse, num);
				for (int i = 0; i < num; i++)
					ptownhouse[i]->print();
				cout << "是否导入文本文件？（是：1，否：0）：";
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
					opfile << "                    房屋建筑工程项目列表\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "编号：" << ptownhouse[i]->getCode() << "\t" << "名称：" << ptownhouse[i]->getName() << "\t" << (ptownhouse[i]->getStatus() == true ? "已审批" : "未审批") << "\t建设单位：" << ptownhouse[i]->getCompany() << "\t建筑地址：" << ptownhouse[i]->getAdd1() << ptownhouse[i]->getAdd2() << ptownhouse[i]->getAdd3() << "\n\t施工许可面积：" << ptownhouse[i]->getArea() << "平方米\t合同金额：" << ptownhouse[i]->getCost() << "万元人民币";
						opfile << "\n\t合同开工日期：" << ptownhouse[i]->getBegin().year << "年" << ptownhouse[i]->getBegin().month << "月" << ptownhouse[i]->getBegin().day << "日\t合同完工日期：" << ptownhouse[i]->getEnd().year << "年" << ptownhouse[i]->getEnd().month << "月" << ptownhouse[i]->getEnd().day << "日\n";
					}
					cout << "已完成写文本文件！\n";
					opfile.close();
				}
			}
			if (y == 3)
			{
				publicWork **ppublicwork = new publicWork*;
				ppublicwork = totalarray02(num);
				if (num == 0)
				{
					cout << "该列表为空！" << endl;
					cout << endl;
					continue;
				}
				sort(ppublicwork, num);
				for (int i = 0; i < num; i++)
					ppublicwork[i]->print();
				cout << "是否导入文本文件？（是：1，否：0）：";
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
					opfile << "                    市政工程项目列表\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "编号：" << ppublicwork[i]->getCode() << "\t" << "名称：" << ppublicwork[i]->getName() << "\t" << (ppublicwork[i]->getStatus() == true ? "已审批" : "未审批") << "\t建设单位：" << ppublicwork[i]->getCompany() << "\t建筑地址：" << ppublicwork[i]->getAdd1() << ppublicwork[i]->getAdd2() << ppublicwork[i]->getAdd3() << "\n\t施工许可面积：" << ppublicwork[i]->getArea() << "平方米\t合同金额：" << ppublicwork[i]->getCost() << "万元人民币";
						opfile << "\n\t合同开工日期：" << ppublicwork[i]->getBegin().year << "年" << ppublicwork[i]->getBegin().month << "月" << ppublicwork[i]->getBegin().day << "日\t合同完工日期：" << ppublicwork[i]->getEnd().year << "年" << ppublicwork[i]->getEnd().month << "月" << ppublicwork[i]->getEnd().day << "日\n";
					}
					cout << "已完成写文本文件！\n";
					opfile.close();
				}
			}
			if (y == 4)
			{
				civilBuilding **pcivilbuilding = new civilBuilding*;
				pcivilbuilding = totalarray0(num);
				if (num == 0)
				{
					cout << "该列表为空！" << endl;
					cout << endl;
					continue;
				}
				sort(pcivilbuilding, num);
				for (int i = 0; i < num; i++)
					pcivilbuilding[i]->print();
				cout << "是否导入文本文件？（是：1，否：0）：";
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
					opfile << "                    民用建筑项目列表\n";
					for (int i = 0; i < num; i++)
					{
						opfile << "编号：" << pcivilbuilding[i]->getCode() << "\t" << "名称：" << pcivilbuilding[i]->getName() << "\t" << (pcivilbuilding[i]->getStatus() == true ? "已审批" : "未审批") << "\t建设单位：" << pcivilbuilding[i]->getCompany() << "\t建筑地址：" << pcivilbuilding[i]->getAdd1() << pcivilbuilding[i]->getAdd2() << pcivilbuilding[i]->getAdd3() << "\n\t施工许可面积：" << pcivilbuilding[i]->getArea() << "平方米\t合同金额：" << pcivilbuilding[i]->getCost() << "万元人民币";
						opfile << "\n\t合同开工日期：" << pcivilbuilding[i]->getBegin().year << "年" << pcivilbuilding[i]->getBegin().month << "月" << pcivilbuilding[i]->getBegin().day << "日\t合同完工日期：" << pcivilbuilding[i]->getEnd().year << "年" << pcivilbuilding[i]->getEnd().month << "月" << pcivilbuilding[i]->getEnd().day << "日\n";
					}
					cout << "已完成写文本文件！\n";
					opfile.close();
				}
			}
			if (y == 5)
			{
				indusBuilding *indusbuilding = new indusBuilding;
				Readdat(fileDat4, indusbuilding, num);
				if (num == 0)
				{
					cout << "该列表为空！" << endl;
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
					cout << "该列表为空！" << endl;
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
					cout << "该列表为空！" << endl;
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
					cout << "该列表为空！" << endl;
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
					cout << "该列表为空！" << endl;
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
		cout << "选择查看总量统计的项目类别\n";
		while (1)
		{
			int y, totalnum = 0;
			double totalarea = 0, totalcost = 0;
			cout << "1：所有项目\n"
				<< "2：房屋建筑工程项目  3：市政工程项目\n"
				<< "4：民用建筑项目  5：工业建筑项目\n"
				<< "6：构筑物  7：公共交通工程  8：绿化工程  9：标识设施\n"
				<< "0：退出\n"
				<< "请根据需要输入数字：";
			cin >> y;
			if (y == 0) break;
			if (!(y >= 1 && y <= 9))
			{
				cout << "输入错误，请重新输入！\n";
				continue;
			}
			if (y == 1)
			{
				cout << "所有项目 总量统计：  ";
				Building **pbuilding = new Building*;
				pbuilding = totalarray(totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += pbuilding[i]->getArea();
					totalcost += pbuilding[i]->getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 2)
			{
				cout << "房屋建筑工程项目 总量统计：  ";
				townHouse **ptownhouse = new townHouse*;
				ptownhouse = totalarray01(totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += ptownhouse[i]->getArea();
					totalcost += ptownhouse[i]->getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 3)
			{
				cout << "市政工程项目 总量统计：  ";
				publicWork **ppublicwork = new publicWork*;
				ppublicwork = totalarray02(totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += ppublicwork[i]->getArea();
					totalcost += ppublicwork[i]->getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 4)
			{
				cout << "民用建筑项目 总量统计：  ";
				civilBuilding **pcivilbuilding = new civilBuilding*;
				pcivilbuilding = totalarray0(totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += pcivilbuilding[i]->getArea();
					totalcost += pcivilbuilding[i]->getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 5)
			{
				cout << "工业建筑项目 总量统计：  ";
				indusBuilding *indusbuilding = new indusBuilding;
				Readdat(fileDat4, indusbuilding, totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += indusbuilding[i].getArea();
					totalcost += indusbuilding[i].getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 6)
			{
				cout << "构筑物 总量统计：  ";
				Structure *structure = new Structure;
				Readdat(fileDat5, structure, totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += structure[i].getArea();
					totalcost += structure[i].getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 7)
			{
				cout << "公共交通工程 总量统计：  ";
				Traffic *traffic = new Traffic;
				Readdat(fileDat6, traffic, totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += traffic[i].getArea();
					totalcost += traffic[i].getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 8)
			{
				cout << "绿化工程 总量统计：  ";
				Plant *plant = new Plant;
				Readdat(fileDat7, plant, totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += plant[i].getArea();
					totalcost += plant[i].getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			if (y == 9)
			{
				cout << "标识设施 总量统计：  ";
				Sign *sign = new Sign;
				Readdat(fileDat8, sign, totalnum);
				cout << "总计项目：" << totalnum << "个";
				for (int i = 0; i < totalnum; i++)
				{
					totalarea += sign[i].getArea();
					totalcost += sign[i].getCost();
				}
				cout << "\t总计施工许可面积：" << totalarea << "平方米\t总计合同金额：" << totalcost << "万元人民币" << endl;
			}
			cout << endl;
		}
		goto Menu;
	}
}
template<typename T>
int endMark(T building)  //重载函数，判断空标志记录（文件结束）
{
	if (building.getCode() == 0) return 1;
	else return 0;
}
int endMark(Building *building)  //重载函数，判断空标志记录（文件结束）
{
	if (building->getCode() == 0) return 1;
	else return 0;
}
template<typename T>
void sort(T *building, int size)  //排序
{
	int i, flag, p, g;
	T temp;
	bool f;
	cout << "请选择排序关键字（默认：0，施工面积：1，合同金额：2）：\n";
	cin >> g;
	if (g == 0) return;
	cout << "请选择排序关键字（升序：1，降序：0）：\n";
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
void sort(T **building, int size)  //排序2
{
	int i, flag, p, g;
	T *temp;
	bool f;
	cout << "请选择排序关键字（默认：0，施工面积：1，合同金额：2）：\n";
	cin >> g;
	if (g == 0) return;
	cout << "请选择排序关键字（升序：1，降序：0）：\n";
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
void Initial(const char *fileDat, int f)  //项目文件初始化
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
void Change1(const char *fileDat, char *iname, long icode, int &flag)  //项目信息修改
{
	if (flag == 1) return;
	T building;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (!fdat)
	{
		cout << "项目文件不存在，请进行初始化\n";
		return;
	}
	fdat.seekg(sizeof(int), ios::beg);                  //读指针移到文件头数量统计后
	do                                        //查找相符项目
	{
		fdat.read((char*)&building, sizeof(T));  //
	} while (building.getCode() != icode && strcmp(building.getName(), iname) != 0 && !endMark(building));   //判断是否找到及文件是否结束
	if (endMark(building)) return;
	if (building.getCode() == icode || strcmp(building.getName(), iname) == 0)
	{
		flag = 1;
		building.print();
		int xx;
		while (1)
		{
			cout << "\n请输入要修改该项目（1：审批状态 2：建设单位 3：建筑地址 4：施工许可面积 5：合同金额 6：资金来源 7：合同开工日期 8：合同完工日期 9：银行贷款金额）：";
			cin >> xx;
			if (!(xx >= 1 && xx <= 9))
			{
				cout << "输入错误，请重新输入！\n";
				continue;
			}
			if (xx == 1)
			{
				cout << "请输入修改后的审批状态（已审批：1；未审批：0）：";
				bool temp;
				while (cin >> temp)
				{
					if (temp != building.getStatus())
					{
						building.setStatus(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "审批状态已经修改为：" << (temp ? "已审批" : "未审批") << "\n";
						break;
					}
					else
					{
						cout << "不必修改！审批状态已经为：" << (temp ? "已审批" : "未审批")
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (xx == 2)
			{
				cout << "请输入修改后的建设单位：";
				char temp[10];
				while (cin >> temp)
				{
					if (temp != building.getCompany())
					{
						building.setCompany(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "建设单位已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！建设单位已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (xx == 3)
			{
				cout << "请输入修改后的建筑地址：";
				Address temp;
				while (cin >> temp.city >> temp.district >> temp.street)
				{
					if (temp.city != building.getAdd1() || temp.district != building.getAdd2() || temp.street != building.getAdd3())
					{
						building.setAdd1(temp.city);
						building.setAdd2(temp.district);
						building.setAdd3(temp.street);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "建筑地址已经修改为：" << temp.city << temp.district << temp.street << "\n";
						break;
					}
					else
					{
						cout << "不必修改！建设单位已经为：" << temp.city << temp.district << temp.street
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (xx == 4)
			{
				cout << "请输入修改后的施工许可面积：";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getArea())
					{
						building.setArea(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "施工许可面积已经修改为：" << temp << "平方米\n";
						break;
					}
					else
					{
						cout << "不必修改！施工许可面积：已经为：" << temp
							<< "平方米\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (xx == 5)
			{
				cout << "请输入修改后的合同金额：";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getCost())
					{
						building.setCost(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "合同金额已经修改为：" << temp << "万元人民币\n";
						break;
					}
					else
					{
						cout << "不必修改！合同金额已经为：" << temp
							<< "万元人民币\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (xx == 6)
			{
				cout << "请输入修改后的资金来源：";  //派生类特有数据成员！
				int temp;
				while (cin >> temp)
				{
					if (temp != building.getSource())
					{
						building.setSource(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "资金来源已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！资金来源已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (xx == 7)
			{
				cout << "请输入修改后的合同开工日期：";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setBegin(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
				fdat.write((char*)&building, sizeof(T));  //写修改后记录
				cout << "合同开工日期已经修改为：" << tempy << "年" << tempm << "月" << tempd << "日" << "\n";
			}
			if (xx == 8)
			{
				cout << "请输入修改后的合同完工日期：";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setEnd(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
				fdat.write((char*)&building, sizeof(T));  //写修改后记录
				cout << "合同完工日期已经修改为：" << tempy << "年" << tempm << "月" << tempd << "日" << "\n";
			}
			if (xx == 9)
			{
				double temp;
				cout << "请输入修改后的银行贷款金额：";
				while (cin >> temp)
				{
					if (temp != building.getLoan())
					{
						building.setLoan(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "银行贷款金额已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！银行贷款金额已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
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
void Change2(const char *fileDat, char *iname, long icode, int &flag)  //项目信息修改
{
	if (flag == 1) return;
	T building;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (!fdat)
	{
		cout << "项目文件不存在，请进行初始化\n";
		return;
	}
	fdat.seekg(sizeof(int), ios::beg);                  //读指针移到文件头数量统计后
	do                                        //查找相符项目
	{
		fdat.read((char*)&building, sizeof(T));  //
	} while (building.getCode() != icode && strcmp(building.getName(), iname) != 0 && !endMark(building));   //判断是否找到及文件是否结束
	if (endMark(building)) return;
	if (building.getCode() == icode || strcmp(building.getName(), iname) == 0)
	{
		flag = 1;
		building.print();
		int x;
		while (1)
		{
			cout << "\n请输入要修改该项目（1：审批状态 2：建设单位 3：建筑地址 4：施工许可面积 5：合同金额 6：资金来源 7：合同开工日期 8：合同完工日期 9：社会捐赠金额）：";
			cin >> x;
			if (!(x >= 1 && x <= 9))
			{
				cout << "输入错误，请重新输入！\n";
				continue;
			}
			if (x == 1)
			{
				cout << "请输入修改后的审批状态（已审批：1；未审批：0）：";
				bool temp;
				while (cin >> temp)
				{
					if (temp != building.getStatus())
					{
						building.setStatus(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "审批状态已经修改为：" << (temp ? "已审批" : "未审批") << "\n";
						break;
					}
					else
					{
						cout << "不必修改！审批状态已经为：" << (temp ? "已审批" : "未审批")
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (x == 2)
			{
				cout << "请输入修改后的建设单位：";
				char temp[10];
				while (cin >> temp)
				{
					if (temp != building.getCompany())
					{
						building.setCompany(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "建设单位已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！建设单位已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (x == 3)
			{
				cout << "请输入修改后的建筑地址：";
				Address temp;
				while (cin >> temp.city >> temp.district >> temp.street)
				{
					if (temp.city != building.getAdd1() || temp.district != building.getAdd2() || temp.street != building.getAdd3())
					{
						building.setAdd1(temp.city);
						building.setAdd2(temp.district);
						building.setAdd3(temp.street);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "建筑地址已经修改为：" << temp.city << temp.district << temp.street << "\n";
						break;
					}
					else
					{
						cout << "不必修改！建设单位已经为：" << temp.city << temp.district << temp.street
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (x == 4)
			{
				cout << "请输入修改后的施工许可面积：";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getArea())
					{
						building.setArea(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "施工许可面积已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！施工许可面积：已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (x == 5)
			{
				cout << "请输入修改后的合同金额：";
				double temp;
				while (cin >> temp)
				{
					if (temp != building.getCost())
					{
						building.setCost(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "合同金额已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！合同金额已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (x == 6)
			{
				cout << "请输入修改后的资金来源：";  //派生类特有数据成员！
				int temp;
				while (cin >> temp)
				{
					if (temp != building.getSource())
					{
						building.setSource(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "资金来源已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！资金来源已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
							break;
						}
					}
				}
			}
			if (x == 7)
			{
				cout << "请输入修改后的合同开工日期：";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setBegin(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
				fdat.write((char*)&building, sizeof(T));  //写修改后记录
				cout << "合同开工日期已经修改为：" << tempy << "年" << tempm << "月" << tempd << "日" << "\n";
			}
			if (x == 8)
			{
				cout << "请输入修改后的合同完工日期：";
				int tempy, tempm, tempd;
				cin >> tempy >> tempm >> tempd;
				Date temp(tempy, tempm, tempd);
				building.setEnd(temp);
				fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
				fdat.write((char*)&building, sizeof(T));  //写修改后记录
				cout << "合同完工日期已经修改为：" << tempy << "年" << tempm << "月" << tempd << "日" << "\n";
			}
			if (x == 9)
			{
				double temp;
				cout << "请输入修改后的社会捐赠金额：";
				while (cin >> temp)
				{
					if (temp != building.getDonation())
					{
						building.setDonation(temp);
						fdat.seekp(-long(sizeof(T)), ios::cur);  //文件写指针复位
						fdat.write((char*)&building, sizeof(T));  //写修改后记录
						cout << "社会捐赠金额已经修改为：" << temp << "\n";
						break;
					}
					else
					{
						cout << "不必修改！银行贷款金额已经为：" << temp
							<< "\n是否重新输入？（是：1，否：0）\n";
						int yy;
						cin >> yy;
						if (yy) cout << "重新输入：";
						else
						{
							cout << "退出该项目的修改操作！\n";
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
void Delete(const char *fileDat, char *iname, long icode, int &flag)  //项目信息删除
{
	if (flag == 1) return;
	T building;
	int pn = 0, num;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (!fdat)
	{
		cout << "项目文件不存在，请进行初始化\n";
		return;
	}
	fdat.seekg(0, ios::beg);                  //读指针移到文件头
	fdat.read((char*)&num, sizeof(int));
	do                                        //查找相符项目
	{
		fdat.read((char*)&building, sizeof(T));  //
		pn++;
	} while (building.getCode() != icode && strcmp(building.getName(), iname) != 0 && !endMark(building));   //判断是否找到及文件是否结束
	if (endMark(building)) return;
	if (building.getCode() == icode || strcmp(building.getName(), iname) == 0)
	{
		flag = 1;
		building.print();
		int xx;
		cout << "是否确认将此项目信息删除？（是：1；否：0）\n";
		cin >> xx;
		if (xx == 1)
		{
			pn = num - pn;
			num--;
			T *temp = new T[pn];
			fdat.read((char*)temp, pn * sizeof(T));  //将二进制文件内的项目信息存入temp数组
			fdat.seekp(-long((pn + 1) * sizeof(T)), ios::cur);
			for (int i = 0; i < pn; i++)
				fdat.write((char*)&temp[i], sizeof(T));
			fdat.write((char*)&mark, sizeof(T));  //写文件结束标志
			fdat.seekp(0, ios::beg);  //将写指针置于文件头
			fdat.write((char*)&num, sizeof(int));  //更新存储项目的数量
			fdat.close();
		}
	}
}
template<typename T>
void Readdat(const char *fileDat, T* & building, int &num)  //fileDat为f类别项目文件,T为导出类的数组
{
	int i;
	fstream fdat(fileDat, ios::in | ios::binary);
	if (!fdat)
	{
		cout << "项目文件不存在，请进行初始化\n";
		return;
	}
	fdat.seekg(0, ios::beg);                  //读指针移到文件头
	fdat.read((char*)&num, sizeof(int));  //读出存储的项目数量
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
Building** totalarray(int &num)  //总项目数组
{
	int j, i = 0, n = 0;
	Building **totalb = new Building*;  //创建二维数组，使数组元素为基类指针
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
townHouse** totalarray01(int &num)  //房屋建筑工程项目数组
{
	int j, i = 0, n = 0;
	townHouse **totalt = new townHouse*;  //创建二维数组，使数组元素为基类指针
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
civilBuilding** totalarray0(int &num)  //民用建筑项目数组
{
	int j, i = 0, n = 0;
	civilBuilding **totalc = new civilBuilding*;  //创建二维数组，使数组元素为基类指针
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
publicWork** totalarray02(int &num)  //市政工程项目数组
{
	int j, i = 0, n = 0;
	publicWork **totalp = new publicWork*;  //创建二维数组，使数组元素为基类指针
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