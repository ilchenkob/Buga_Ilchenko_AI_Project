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
	void Update(float fdt); //Обновить поле спустя fdt мс

	void DrawField();

	void GenItems();

	void GetMap( CellType** buff )
	{
		memcpy(buff,m_Map,sizeof(m_Map));
	}
	
private:

	void DrawItems();
	void DrawAgents();

	std::list<CAgent*> m_lAgents;
	std::list<CItem*> m_lItems;

	CellType m_Map[c_iFieldWidth][c_iFieldHeight]; //карта мира, хранящая информацию о всем мире вцелом
};
