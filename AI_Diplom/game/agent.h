#pragma once
#include "config.h"
#include "..\ai_engine\engine.h"
#include "infrastructure\point.h"

class CAgent
{
public:
	CAgent();
	CAgent( float x, float y, bool type=true );
	~CAgent();

	void Update( float fdt, global::CellType map[c_iVisibleZone][c_iVisibleZone] );

	void SetPosition(double x, double y) { m_Pos.x = x; m_Pos.y = y; }
	Point GetPosition() const { return m_Pos; }

	
private:

	CAI_Engine *m_Brain;

	Point m_Pos;       //положение на карте
	int   m_iItemsCount;//кол-во собранных итемов
};