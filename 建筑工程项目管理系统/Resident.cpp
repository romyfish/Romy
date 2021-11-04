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
istream & operator>>(istream &input, Resident & R)  //重载提取运算符，输入居住建筑项目信息
{
	//依次输入项目的编号、名称、审批状态（已审批：1；未审批：2）、建设单位、建筑地址、施工许可面积、合同金额、资金来源（项目公司：0；银行贷款：1；两者均有：2）、合同开工日期、合同完工日期（、贷款金额）
	int y1, m1, d1, y2, m2, d2;
	input >> R.code >> R.name >> R.status >> R.company >> R.address.city >> R.address.district >> R.address.street >> R.area >> R.cost >> R.source >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	Date da1(y1, m1, d1), da2(y2, m2, d2);
	R.setBegin(da1);
	R.setEnd(da2);
	if (R.source)
	{
		cout << "请输入贷款金额：";
		input >> R.loan;
	}
	else R.loan = 0;
	return input;
}
void Resident::print()
{
	//依次输出项目的类型、编号、名称、审批状态、建设单位、建筑地址、施工许可面积、合同金额、资金来源（项目公司：0；银行贷款：1；两者均有：2）、合同开工日期、合同完工日期
	cout << "居住建筑" << "\t" << code << "\t" << name << "\t" << (status == true ? "已审批" : "未审批") << "\t建设单位：" << company << "\t建筑地址：" << address.city << address.district << address.street << "\n\t施工许可面积：" << area << "平方米\t合同金额：" << cost << "万元人民币\t资金来源：";
	if (source == 0) cout << "项目公司";
	if (source == 1) cout << "银行贷款";
	if (source == 2) cout << "两者均有";
	if (source) cout << "\t贷款金额：" << loan;
	cout << "\n\t合同开工日期：" << begin.year << "年" << begin.month << "月" << begin.day << "日\t合同完工日期：" << end.year << "年" << end.month << "月" << end.day << "日" << endl;
}