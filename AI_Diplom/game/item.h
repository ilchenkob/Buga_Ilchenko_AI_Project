#include "point.h";
#pragma once
class CItem
{
public:
	CItem();
	CItem( float x, float y ) 
	{ 
		m_Pos.x = x; 
		m_Pos.y = y; 
	}
	~CItem();

	void Update( float fdt );

	void SetPosition(double x, double y) { m_Pos.x = x; m_Pos.y = y; }
	Point GetPosition() const { return m_Pos; }

	
private:
	
	Point m_Pos;       //положение на карте
};

