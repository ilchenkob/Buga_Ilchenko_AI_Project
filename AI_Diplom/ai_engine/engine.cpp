#include "engine.h"

#include "point.h"
#include "config.h"
#include <stdlib.h>
#include <list>

using namespace global;

Direction CAI_Engine::GetDecision( CellType map[c_iVisibleZone][c_iVisibleZone] )
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