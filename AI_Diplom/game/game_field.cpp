#include "game_field.h"
#include "agent.h"
#include "config.h"

#include "glut.h"
#include <gl\GL.h>

CGameField::CGameField()
{
	memset(m_Map, 0, sizeof(m_Map));
	
	int x;
	int y;

	for( int i = 0; i < 10; i++ )	//генерируем агентов
	{
		do{
			x = rand()%c_iFieldWidth;
			y = rand()%c_iFieldHeight;
		}while( m_Map[x][y] != CT_FREE );

		CAgent *temp = new CAgent(x*c_iCellStep,y*c_iCellStep);
		m_Map[x][y] = CT_AGENT;
		m_lAgents.push_back(temp);
	}

	for( int i = 0; i < 15; i++ )	//генерируем итемы
	{
		do{
			x = rand()%c_iFieldWidth;
			y = rand()%c_iFieldHeight;
		}while( m_Map[x][y] != CT_FREE );

		CItem *temp = new CItem(x*c_iCellStep,y*c_iCellStep);
		m_Map[x][y] = CT_ITEM;
		m_lItems.push_back(temp);
	}
}

CGameField::~CGameField()
{
	m_lAgents.clear();
	m_lItems.clear();
}

void CGameField::Update(float fdt)
{
	std::list<CAgent*>::iterator it1 = m_lAgents.begin();
	for(; it1 != m_lAgents.end(); ++it1)
	{
		(*it1)->Update(fdt);
	}

	std::list<CItem*>::iterator it2 = m_lItems.begin();
	for(; it2 != m_lItems.end(); ++it2)
	{
		(*it2)->Update(fdt);
	}
}

void CGameField::DrawField()
{
	glBegin(GL_QUADS);			//рисуем фон игрового поля		
		glColor3f(0.8f,0.8f,0.8f);			
		glVertex2f( 0.0f, 0.0f);
		glVertex2f( (float)(c_iFieldWidth*c_iCellStep), 0.0f);
		glVertex2f( (float)(c_iFieldWidth*c_iCellStep), (float)(c_iFieldHeight*c_iCellStep));
		glVertex2f( 0.0f, (float)(c_iFieldHeight*c_iCellStep));
	glEnd();				
	glBegin(GL_LINES);		
		glColor3f(0.76f,0.76f, 0.76f);	
		for( int i = 0; i < 64; i++ )
		{
			glVertex2f( (float)c_iCellStep*i, 0.0f);
			glVertex2f( (float)c_iCellStep*i, (float)(c_iFieldHeight*c_iCellStep));
		}
		for( int i = 0; i < 48; i++ )
		{
			glVertex2f( 0.f, 10.f*i);
			glVertex2f( (float)(c_iFieldWidth*c_iCellStep), 10.f*i);
		}
	glEnd();	
	
	DrawItems();				//рисуем итемы на поле
	DrawAgents();				//рисуем агентов на поле
}

void CGameField::DrawItems()
{
	glPointSize(5.f);
	glBegin(GL_POINTS);
		glColor3f(0.f,0.f,1.f);

		std::list<CItem*>::iterator it = m_lItems.begin();
		for(; it != m_lItems.end(); ++it)
		{
			glVertex2f( (*it)->GetPosition().x, (*it)->GetPosition().y );
		}
	glEnd();
}

void CGameField::DrawAgents()
{
	glPointSize(8.f);
	glBegin(GL_POINTS);
		glColor3f(1.f,0.f,0.f);

		std::list<CAgent*>::iterator it = m_lAgents.begin();
		for(; it != m_lAgents.end(); ++it)
		{
			glVertex2f( (*it)->GetPosition().x, (*it)->GetPosition().y );
		}
	glEnd();
}
