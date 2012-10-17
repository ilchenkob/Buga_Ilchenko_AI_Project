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

	virtual Direction GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] ) = 0;

};

class CTree_ai: public CAI_Engine
{
public:

	CTree_ai() {}

	Direction GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] );

private:

	std::list<Point> m_Way; //путь - позиции в которых мы были
};

class CSmart_ai: public CAI_Engine
{
public:

	CSmart_ai() {}

	Direction GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] );

private:

	std::list<Point> m_Way; //путь - позиции в которых мы были
};