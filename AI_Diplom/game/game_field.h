#pragma once

#include "config.h"

#include "item.h"
#include "agent.h"

#include <stdlib.h>
#include <list>

using namespace global;

class CGameField
{
public:

	CGameField();
	~CGameField();
	void Update(float fdt); //�������� ���� ������ fdt ��

	void DrawField();

	void GenItems();

private:

	void DrawItems();
	void DrawAgents();

	CellType m_Map[c_iFieldWidth][c_iFieldHeight]; //����� ����, �������� ���������� � ���� ���� ������

	std::list<CAgent*> m_lAgents;
	std::list<CItem*> m_lItems;

};