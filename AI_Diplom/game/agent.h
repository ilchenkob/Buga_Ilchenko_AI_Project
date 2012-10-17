#pragma once

#include "infrastructure\point.h"

class CAgent
{
public:
	CAgent();

	void Update( float fdt );

	~CAgent();
private:
	
	Point m_Pos;       //положение на карте
	int   m_ItemsCount;//кол-во собранных итемов
};