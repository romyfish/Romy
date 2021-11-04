#pragma once
#include "townHouse.h"
//民用建筑，继承自房屋建筑工程
class civilBuilding :
	public townHouse
{
public:
	civilBuilding();
	~civilBuilding();
};