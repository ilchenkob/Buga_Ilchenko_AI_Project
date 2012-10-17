#include "agent.h"
#include "config.h"

#include "..\ai_engine\engine.h"

using namespace global;

CAgent::CAgent() 
{ 
	m_Brain = new CTree_ai();
	m_iItemsCount = 0; 
}

CAgent::CAgent( float x, float y, bool type ) 
{ 
	if( type )
		m_Brain = new CTree_ai();
	else
		m_Brain = new CSmart_ai();

	m_Pos.x = x; 
	m_Pos.y = y; 
	m_iItemsCount = 0; 
}

CAgent::~CAgent()
{
	delete this;
}

void CAgent::Update( float fdt, CellType map[c_iVisibleZone][c_iVisibleZone] )
{
	Direction dir = m_Brain->GetDecision( map );

	switch (dir)
	{
		case D_LEFT: m_Pos.x -= c_iCellStep;
			break;
		case D_RIGHT: m_Pos.x += c_iCellStep;
			break;
		case D_UP: m_Pos.y += c_iCellStep;
			break;
		case D_DOWN: m_Pos.y -= c_iCellStep;
			break;
	}
	
}