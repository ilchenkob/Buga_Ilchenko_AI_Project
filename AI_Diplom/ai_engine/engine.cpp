#include "engine.h"

#include "point.h"
#include "config.h"
#include <stdlib.h>
#include <list>

using namespace global;

Direction CTree_ai::GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] )
{
	CellType tMap[c_iVisibleZone][c_iVisibleZone];
	memcpy(tMap, map, sizeof(tMap));

	if( tMap[c_iCentralPoint - 1][c_iCentralPoint] == CT_FREE )
		return D_LEFT;
	else
	if( tMap[c_iCentralPoint + 1][c_iCentralPoint] == CT_FREE )
		return D_RIGHT;
	else
	if( tMap[c_iCentralPoint][c_iCentralPoint - 1] == CT_FREE )
		return D_DOWN;
	else
	if( tMap[c_iCentralPoint][c_iCentralPoint + 1] == CT_FREE )
		return D_UP;

	return D_NONE;
}

Direction CSmart_ai::GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] )
{
	CellType tMap[c_iVisibleZone][c_iVisibleZone];

	memcpy(tMap, map, sizeof(tMap));

	int nearest = c_iCentralPoint*2;

	for(int i = 0; i < c_iVisibleZone; i++)
		for(int j = 0; j < c_iVisibleZone; j++)
		{
			if(tMap[i][j] == CT_ITEM) 
			{
				int x = c_iCentralPoint - i;
				int y = c_iCentralPoint - j;

				int distance = std::min(std::abs(x), std::abs(y));

				if(distance < nearest)
				{
					if(x > y) 
					{
						m_previousWay = x >= -y 
							? D_RIGHT
							: D_UP;
					}
					else
					{
						m_previousWay = x >= -y
							? D_DOWN
							: D_LEFT;
					}
				}
			}
		}
	
	return m_previousWay == D_NONE 
		? m_previousWay = (Direction)(rand()*3)
		: m_previousWay;
}