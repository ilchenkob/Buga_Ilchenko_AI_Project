#include "agent.h"
#include "config.h"

#include "..\ai_engine\engine.h"

using namespace global;

CAgent::CAgent() 
{ 
	m_ptrBrain = new CAI_Engine();
	m_ptrBrain->SetAgent( this );

	m_iItemsCount = 0; 
	m_VisibleMap = new global::CellType*[c_iVisibleZone];
	for(int i = 0; i < c_iVisibleZone; i++)
		m_VisibleMap[i] = new global::CellType[c_iVisibleZone];
}

CAgent::CAgent( float x, float y, bool type ) 
{ 
	m_ptrBrain = new CAI_Engine();
	m_ptrBrain->SetAgent( this );

	m_VisibleMap = new global::CellType*[c_iVisibleZone];
	for(int i = 0; i < c_iVisibleZone; i++)
		m_VisibleMap[i] = new global::CellType[c_iVisibleZone];

	m_Pos.x = x; 
	m_Pos.y = y; 
	m_iItemsCount = 0; 
}

CAgent::~CAgent()
{
	delete this;
}

void CAgent::Update( float fdt, CellType map[c_iVisibleZone][c_iVisibleZone], int x, int y )
{
	memcpy(m_VisibleMap, map, sizeof(map));
}