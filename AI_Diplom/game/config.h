#pragma once

const int   c_iTimeSpan     = 200;
const int   c_iFieldWidth   = 64;
const int   c_iFieldHeight  = 48;
const int   c_iCellStep     = 10;
const int   c_iVisibleZone  = 5;
const int   c_iCentralPoint = 2;

namespace global
{
	enum Direction
	{
		D_NONE,
		D_LEFT,
		D_RIGHT,
		D_UP,
		D_DOWN
	};

	enum CellType
	{
		CT_FREE,	//������ ��������
		CT_ITEM,	//�� ������ ��������� ����
		CT_AGENT,	//�� ������ ��������� �����
		CT_BORDER   //�� ������ �����
	};
}