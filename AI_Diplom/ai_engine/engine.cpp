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
				result -= 10; // ���� ����� �� ���������� 1
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
				// ���������� ��������� � ����������� �� ���������� �� �������
				// ������� ��������� ������������ ��������� (�������� ���� ��������� 10, ����. ���� ���������� 5)
				// � ������������ ��������� 50
				// ����� ��������� ���������� � �� �������
				// ������ ������� �������� ����������� �� ����������
				// �.�. 1 ������ ���������� ����� - 50, 2 - 40, 3 - 30 � �.�.
				result += (10 * c_iVisibleZone / 2) / (std::max(abs(position.x - i), abs(position.y - j))); 
				
				// ���������� ���
				//if((abs(position.x - i) >= 2 || abs(position.y - j) >= 2)) // ���� ���������� �� ������ �� ���������� 
				//														   // ������� ������ ��� ������ 2
				//{
				//	result += 10; // ���� ������� �� ���������� 2
				//}
				//else
				//{
				//	result += 20; // ���� ������� �� ���������� 1
				//}
			}
		}

	return result;
}

int CAI_Engine::enemiesPositionRate(Point position, CellType** map)
{

}