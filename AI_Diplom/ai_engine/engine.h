#pragma once
#include "point.h"
#include "config.h"
#include <stdlib.h>
#include <map>
#include <list>

using namespace global;

class AbstractAgent
{
public:

	virtual bool ReadyToGo() = 0;
	
	virtual Point GetPosition() = 0;

	virtual global::CellType** GetVisibleMap() = 0;

};

class CAI_Engine
{
public:

	CAI_Engine() {}

	void SetAgent( AbstractAgent* ptr ) { m_ptrAgent = ptr; };

	Direction MakeDesision();

private:

	AbstractAgent *m_ptrAgent;

	CellType** visibleMap(Point position);

	int borderPositionRate(Point position, CellType** map);

	int resourcesPositionRate(Point position, CellType** map);

	int enemiesPositionRate(Point position, CellType** map);

	int calculatePosition(Point position, CellType** map);
};