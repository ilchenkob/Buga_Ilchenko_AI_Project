#pragma once

#include "game_field.h"

class CGame
{
public:
	static CGame& Instance() 
	{ 
		static CGame inst; 
		return inst; 
	}

	void Run();
	void Stop();

	void Draw() { m_gameField->DrawField(); }

private:

	CGame() { m_gameField = new CGameField(); }
	~CGame() { delete m_gameField; }

	void Update();

	CGameField *m_gameField;

	bool m_bIsWorked;
};