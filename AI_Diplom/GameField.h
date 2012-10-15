#include "Item.h"
#include "game\agent.h"

#pragma once
class CGameField
{
public:
	CGameField(void);

	CItem *m_Items;
	CAgent *m_Agents;

	void Update();

	~CGameField(void);
};

