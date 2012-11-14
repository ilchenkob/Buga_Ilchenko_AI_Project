#include "agent.h"
#include "config.h"

#include "..\ai_engine\engine.h"

using namespace global;

CAgent::CAgent() 
{ 
	m_iItemsCount = 0; 
	m_VisibleMap = new global::CellType*[c_iVisibleZone];
	
	for(int i = 0; i < c_iVisibleZone; i++)
		m_VisibleMap[i] = new global::CellType[c_iVisibleZone];

	m_ptrBrain = new CAI_Engine();
	m_ptrBrain->SetAgent( this );
}

CAgent::CAgent( float x, float y, bool type ) 
{ 
	m_VisibleMap = new global::CellType*[c_iVisibleZone];
	for(int i = 0; i < c_iVisibleZone; i++)
		m_VisibleMap[i] = new global::CellType[c_iVisibleZone];

	m_Pos.x = x; 
	m_Pos.y = y; 
	m_iItemsCount = 0; 

	m_ptrBrain = new CAI_Engine();
	m_ptrBrain->SetAgent( this );

}

CAgent::~CAgent()
{
	delete this;
}

void CAgent::Update( float fdt, CellType map[c_iVisibleZone][c_iVisibleZone], int x, int y )
{
	//memcpy(m_VisibleMap, map, sizeof(map));
	for(int i = 0; i < c_iVisibleZone; i++)
	{
		for(int j = 0; j < c_iVisibleZone; j++)
		{
			m_VisibleMap[i][j] = map[i][j];
		}
	}
	Direction newDirection = m_ptrBrain->MakeDesision();

	switch(newDirection)
	{
	case D_UP:
		m_Pos.y - 1;
		break;
	case D_DOWN:
		m_Pos.y + 1;
		break;
	case D_LEFT:
		m_Pos.x - 1;
		break;
	case D_RIGHT:
		m_Pos.x + 1;
		break;
	default:
		break;
	}
}