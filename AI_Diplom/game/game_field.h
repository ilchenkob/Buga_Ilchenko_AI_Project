#pragma once

#include "config.h"

#include "item.h"
#include "agent.h"

#include <stdio.h>
#include <list>

class CGameField
{
public:

	CGameField();
	~CGameField();
	void Update(float fdt); //Обновить поле спустя fdt мс

	void DrawField();

private:

	void DrawItems();
	void DrawAgents();

	enum CellType
	{
		CT_FREE,	//клетка свободна
		CT_ITEM,	//на клетке находится Итем
		CT_AGENT	//на клетке находится Агент
	};

	CellType m_Map[c_iFieldWidth][c_iFieldHeight]; //карта мира, хранящая информацию о всем мире вцелом

	std::list<CAgent*> m_lAgents;
	std::list<CItem*> m_lItems;

};