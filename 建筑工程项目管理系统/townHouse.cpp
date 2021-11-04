#include"building.h"
#include "townHouse.h"
using namespace std;

townHouse::townHouse() {}
townHouse::~townHouse()
{
	code = 0;
	name[0] = '\0';
}
double townHouse::getLoan() { return loan; }
void townHouse::setLoan(double l) { loan = l; }