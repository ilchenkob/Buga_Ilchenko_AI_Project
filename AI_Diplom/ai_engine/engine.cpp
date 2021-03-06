#include "engine.h"

#include "../game/game.h"

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

	Point tempAgent(agentPosition.x, agentPosition.y - 1);
	values.insert(std::make_pair(D_UP, calculatePosition(tempAgent, CAI_Engine::visibleMap(tempAgent))));
	
	tempAgent.x = agentPosition.x;
	tempAgent.y = agentPosition.y + 1;
	values.insert(std::make_pair(D_DOWN, calculatePosition(tempAgent, CAI_Engine::visibleMap(tempAgent))));

	tempAgent.x = agentPosition.x - 1;
	tempAgent.y = agentPosition.y;
	values.insert(std::make_pair(D_LEFT, calculatePosition(tempAgent, CAI_Engine::visibleMap(tempAgent))));

	tempAgent.x = agentPosition.x + 1;
	tempAgent.y = agentPosition.y;
	values.insert(std::make_pair(D_RIGHT, calculatePosition(tempAgent, CAI_Engine::visibleMap(tempAgent))));
	
	Direction direction = D_NONE;

	do
	{
		values[direction] = 0;
		int currentMax = 0;
		
		for(auto it = values.cbegin(); it != values.cend(); ++it ) 
		{
			if (it ->second > currentMax) {
				direction = it->first;
				currentMax = it->second;
			}
		}

	}
	while(!m_ptrAgent->ReadyToGo(direction));

	return direction;
}

int CAI_Engine::borderPositionRate(Point position, CellType** map)
{
	int result = 0;
	
	for(int i=-1; i < 1; i++)
		for(int j=-1; j < 1; j++)
		{
			if(i < 0 || j < 0) continue;

			if(map[i][j] == CT_BORDER)
			{
				result -= 10; // ���� ����� �� ���������� 1
			}
		}

	return result;
}

int CAI_Engine::resourcesPositionRate(Point position, CellType** map)
{
	int result = 0;

	for(int i=-2; i < 2; i++)
		for(int j=-2; j < 2; j++)
		{
			if(i < 0 || j < 0) continue;

			if(map[i][j] == CT_BORDER)
			{
				// ���������� ��������� � ����������� �� ���������� �� �������
				// ������� ��������� ������������ ��������� (�������� ���� ��������� 10, ����. ���� ���������� 5)
				// � ������������ ��������� 50
				// ����� ��������� ���������� � �� �������
				// ������ ������� �������� ����������� �� ����������
				// �.�. 1 ������ ���������� ����� - 50, 2 - 40, 3 - 30 � �.�.
				result += (10 * c_iVisibleZone / 2) / (std::max(abs(position.x - i), abs(position.y - j))); 
			}
		}

	return result;
}

int CAI_Engine::enemiesPositionRate(Point position, CellType** map)
{
	int result = 0;

	for(int i=-2; i < 2; i++)
		for(int j=-2; j < 2; j++)
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
	int x = position.x/c_iCellStep;
	int y = position.y/c_iCellStep;

	int row, coll;
	global::CellType** global_map = new global::CellType*[c_iFieldWidth];
	
	for( int i = 0; i < c_iFieldWidth; i++)
		global_map[i] = new global::CellType[c_iFieldHeight];

	CGame::Instance().GetGameField()->GetMap( global_map );

	//memset(visible_map,0,sizeof(visible_map));
	for(int i = 0; i < c_iVisibleZone; i++)
	{
		for(int j = 0; j < c_iVisibleZone; j++)
		{
			row = x+_x;
			coll = y+_y;
			if( row < 0 || row >= c_iFieldWidth ) row = x;
			if( coll < 0 || coll >= c_iFieldHeight ) coll = y;

			visible_map[i][j] = global_map[row][coll];
			_y++;
		}
		_y = -c_iCentralPoint;
		_x++;
	}

	return visible_map;
}