#include"building.h"
#include "publicWork.h"
using namespace std;

publicWork::publicWork() {}
publicWork::~publicWork()
{
	code = 0;
	name[0] = '\0';
}
double publicWork::getDonation() { return donation; }
void publicWork::setDonation(double d) { donation = d; }