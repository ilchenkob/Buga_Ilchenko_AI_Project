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

	bool IsWorked() const { return m_bIsWorked; }

private:

	CGame() 
	{ 
		m_gameField = new CGameField(); 
		m_bIsWorked = false;
	}
	~CGame() { delete m_gameField; }

	void Update();

	CGameField *m_gameField;

	bool m_bIsWorked;
};