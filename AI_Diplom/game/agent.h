#pragma once
#include "config.h"
#include "engine.h"
#include "infrastructure\point.h"

class CAgent: public AbstractAgent
{
public:

	CAgent();
	CAgent( float x, float y, bool type=true );
	~CAgent();

	void Update( float fdt, global::CellType map[c_iVisibleZone][c_iVisibleZone], int x, int y );

	void SetPosition(double x, double y) { m_Pos.x = x; m_Pos.y = y; }
	Point GetPosition() const { return m_Pos; }

	bool ReadyToGo() const { return true; }

	global::CellType** GetVisibleMap() const { return m_VisibleMap; }
	
private:

	CAI_Engine *m_ptrBrain;

	global::CellType** m_VisibleMap;

	Point m_Pos;        //положение на карте
	int   m_iItemsCount;//кол-во собранных итемов
};