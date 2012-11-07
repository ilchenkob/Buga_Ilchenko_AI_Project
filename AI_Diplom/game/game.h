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
	void Update();

	bool IsWorked() const { return m_bIsWorked; }

	void GenItems() { m_gameField->GenItems(); }

private:

	CGame() 
	{ 
		m_gameField = new CGameField(); 
		m_bIsWorked = true;
	}
	~CGame() { delete m_gameField; }

	CGameField *m_gameField;

	bool m_bIsWorked;
};