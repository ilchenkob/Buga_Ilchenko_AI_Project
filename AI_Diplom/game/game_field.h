#pragma once

#include "item.h"
#include "agent.h"

#include <stdio.h>
#include <list>

class CGameField
{
public:

	CGameField() {};
	void Update(float fdt); //�������� ���� ������ fdt ��

	void DrawField();

private:
	
	void DrawItems();
	void DrawAgents();

	std::list<CAgent*> m_lAgents;
	std::list<CItem*> m_lItems;

};