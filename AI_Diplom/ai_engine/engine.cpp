#include "engine.h"

#include "point.h"
#include "config.h"
#include <stdlib.h>
#include <list>

using namespace global;

Direction CAI_Engine::MakeDesision()
{
	CellType** visibleMap = m_ptrAgent->GetVisibleMap();
	Point agentPosition = m_ptrAgent->GetPosition();

	std::map<Direction, int> values;

	values.insert(std::make_pair(D_NONE, calculatePosition(agentPosition, visibleMap)));


	int currentMax = 0;
	Direction direction = D_NONE;
	for(auto it = values.cbegin(); it != values.cend(); ++it ) 
	{
		if (it ->second > currentMax) {
			direction = it->first;
			currentMax = it->second;
		}
	}

	return direction;
}

int CAI_Engine::borderPositionRate(Point position, CellType** map)
{
	int result = 0;
	
	for(int i=position.x - 1; i<position.x + 1; i++)
		for(int j=position.y - 1; j<position.y + 1; j++)
		{
			if(i < 0 || j < 0) continue;

			if(map[i][j] == CT_BORDER)
			{
				result -= 10; // есть стены на расстоянии 1
			}
		}

	return result;
}

int CAI_Engine::resourcesPositionRate(Point position, CellType** map)
{
	int result = 0;

	for(int i=position.x - 2; i<position.x + 2; i++)
		for(int j=position.y - 2; j<position.y + 2; j++)
		{
			if(i < 0 || j < 0) continue;

			if(map[i][j] == CT_BORDER)
			{
				// наращивает результат в зависимости от расстояния до ресурса
				// сначала вычисляет максимальный результат (например зона видимости 10, знач. макс расстояние 5)
				// а максимальный результат 50
				// затем вычисляем расстояние и до ресурса
				// теперь находим обратную зависимость от расстояния
				// т.е. 1 клетка расстояния равна - 50, 2 - 40, 3 - 30 и т.д.
				result += (10 * c_iVisibleZone / 2) / (std::max(abs(position.x - i), abs(position.y - j))); 
			}
		}

	return result;
}

int CAI_Engine::enemiesPositionRate(Point position, CellType** map)
{
	int result = 0;

	for(int i=position.x - 2; i<position.x + 2; i++)
		for(int j=position.y - 2; j<position.y + 2; j++)
		{
			if(i < 0 || j < 0 || i == j) continue;

			if(map[i][j] == CT_AGENT)
			{
				result += (-10 * c_iVisibleZone / 2) / (std::max(abs(position.x - i), abs(position.y - j))); 
			}
		}

		return result;
}

int CAI_Engine::calculatePosition(Point position, CellType** map)
{
	return borderPositionRate(position, map) 
		+ resourcesPositionRate(position, map) 
		+ enemiesPositionRate(position, map);
}

CellType** CAI_Engine::visibleMap(Point position)
{
	CellType **visible_map = new CellType *[c_iVisibleZone];

	for (int i = 0; i < c_iVisibleZone; i++)
		visible_map[i] = new CellType [c_iVisibleZone];

	int _x = -c_iCentralPoint;
	int _y = -c_iCentralPoint;
	int x = position.x;
	int y = position.y;

	int row, coll;

	memset(visible_map,0,sizeof(visible_map));
	for(int i = 0; i < c_iVisibleZone; i++)
	{
		for(int j = 0; j < c_iVisibleZone; j++)
		{
			row = x+_x;
			coll = y+_y;
			if( row < 0 || row >= c_iFieldWidth ) row = x;
			if( coll < 0 || coll >= c_iFieldHeight ) coll = y;

			visible_map[i][j] = m_Map[row][coll];
			_y++;
		}
		_y = -c_iCentralPoint;
		_x++;
	}

	return visible_map;
}