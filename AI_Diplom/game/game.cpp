#include "game.h"
#include "config.h"

void CGame::Run()
{
	m_bIsWorked = true;
}

void CGame::Stop()
{
	m_bIsWorked = false;
}

void CGame::Update()
{
	m_gameField->Update(c_iTimeSpan);
}