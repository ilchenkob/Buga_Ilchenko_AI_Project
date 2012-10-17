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
	void Update(float fdt); //�������� ���� ������ fdt ��

	void DrawField();

private:

	void DrawItems();
	void DrawAgents();

	enum CellType
	{
		CT_FREE,	//������ ��������
		CT_ITEM,	//�� ������ ��������� ����
		CT_AGENT	//�� ������ ��������� �����
	};

	CellType m_Map[c_iFieldWidth][c_iFieldHeight]; //����� ����, �������� ���������� � ���� ���� ������

	std::list<CAgent*> m_lAgents;
	std::list<CItem*> m_lItems;

};