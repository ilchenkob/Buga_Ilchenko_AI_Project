#pragma once

#include "infrastructure\point.h"

class CAgent
{
public:
	CAgent();

	void Update( float fdt );

	~CAgent();
private:
	
	Point m_Pos;       //��������� �� �����
	int   m_ItemsCount;//���-�� ��������� ������
};