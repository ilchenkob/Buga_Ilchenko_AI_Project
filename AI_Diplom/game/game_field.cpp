#include "game_field.h"

#include "glut.h"
#include <gl\GL.h>

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
	//TODO: рисуем игровое поле
	//--------
	glBegin(GL_TRIANGLES);					
		glColor3f(0.0f,0.0f,1.0f);			
		glVertex3f( 0.0f, 1.0f, 0.0f);		
		glColor3f(0.0f,1.0f,0.0f);			
		glVertex3f(-1.0f,-1.0f, 0.0f);		
		glColor3f(1.0f,0.0f,0.0f);			
		glVertex3f( 1.0f,-1.0f, 0.0f);		
	glEnd();				

	glBegin(GL_TRIANGLES);					
		glColor3f(-10.0f,0.0f,1.0f);			
		glVertex3f( 0.0f, 1.0f, 0.0f);		
		glColor3f(0.0f,1.0f,0.0f);			
		glVertex3f(-10.0f,-1.0f, 0.0f);		
		glColor3f(1.0f,0.0f,0.0f);			
		glVertex3f( 0.03f,-1.0f, 0.0f);		
	glEnd();	
	//----------------------------------

	DrawItems();
	DrawAgents();
}

void CGameField::DrawItems()
{
	std::list<CItem*>::iterator it = m_lItems.begin();
	for(; it != m_lItems.end(); ++it)
	{
		//TODO: рисуем текущий итем
	}
}

void CGameField::DrawAgents()
{
	std::list<CAgent*>::iterator it = m_lAgents.begin();
	for(; it != m_lAgents.end(); ++it)
	{
		//TODO: рисуем текущего агента
	}
}
