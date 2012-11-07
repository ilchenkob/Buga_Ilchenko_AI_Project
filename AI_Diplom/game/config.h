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
		CT_FREE,	//клетка свободна
		CT_ITEM,	//на клетке находится Итем
		CT_AGENT,	//на клетке находится Агент
		CT_BORDER   //на клетке стена
	};
}