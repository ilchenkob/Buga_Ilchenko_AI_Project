#pragma once

#include "infrastructure\point.h"

class CAgent
{
public:
	CAgent() { m_iItemsCount = 0; }
	CAgent( float x, float y ) 
	{ 
		m_Pos.x = x; 
		m_Pos.y = y; 
		m_iItemsCount = 0; 
	}
	~CAgent();

	void Update( float fdt );

	void SetPosition(double x, double y) { m_Pos.x = x; m_Pos.y = y; }
	Point GetPosition() const { return m_Pos; }

	
private:
	
	Point m_Pos;       //положение на карте
	int   m_iItemsCount;//кол-во собранных итемов
};