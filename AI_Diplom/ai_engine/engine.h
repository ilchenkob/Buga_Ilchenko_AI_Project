#pragma once
#include "point.h"
#include "config.h"
#include <stdlib.h>
#include <list>

using namespace global;

class CAI_Engine
{
public:
	CAI_Engine() {}

	global::Direction GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] );

private:

	std::list<Point> m_Way; //путь - позиции в которых мы были

};