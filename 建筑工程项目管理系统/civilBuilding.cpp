#include"building.h"
#include "townHouse.h"
#include "civilBuilding.h"
using namespace std;

civilBuilding::civilBuilding() {}
civilBuilding::~civilBuilding()
{
	code = 0;
	name[0] = '\0';
}