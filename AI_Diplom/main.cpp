#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#include "glut.h"
#include <gl\GL.h>

#include "game\config.h"
#include "game\game.h"

using namespace std;

#define KEY_ESCAPE 27
#define KEY_SPACE 32

typedef struct {
    int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

glutWindow win;


void display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		     // Clear Screen and Depth Buffer
	glLoadIdentity();
	glTranslatef(0.f,0.0f,-1.0f);		
 
	CGame::Instance().Draw();
	CGame::Instance().Update();
 
	glutSwapBuffers();

	Sleep(100);
}


void initialize () 
{
    glMatrixMode(GL_PROJECTION);												// select projection matrix
    glViewport(0, 0, win.width, win.height);									// set the viewport
    glMatrixMode(GL_PROJECTION);												// set matrix mode
    glLoadIdentity();															// reset projection matrix
    GLfloat aspect = (GLfloat) win.width / win.height;
	glOrtho(0,win.width,0,win.height,1,500);
    glMatrixMode(GL_MODELVIEW);													// specify which matrix is the current matrix
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );														// specify the clear value for the depth buffer
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );						// specify implementation-specific hints
	glClearColor(0.0, 0.0, 0.0, 1.0);											// specify clear values for the color buffers								
}


void keyboard ( unsigned char key, int mousePositionX, int mousePositionY )		
{ 
  switch ( key ) 
  {
    case KEY_ESCAPE:  
		printf("Exit from programm\n");
      exit ( 0 );   
      break;      
	case KEY_SPACE:  
		if( CGame::Instance().IsWorked() )
		{
			CGame::Instance().Stop();
			printf("Game status: Stopped\n");
		}
		else
		{
			CGame::Instance().Run();
			printf("Game status: Runned\n");
		}
      break; 

    default:      
      break;
  }
}

void main(int argc, char **argv) 
{
	srand ( time(NULL) );

	win.width = c_iFieldWidth * c_iCellStep;
	win.height = c_iFieldHeight * c_iCellStep;
	win.title = "Game window";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
	glutInitWindowSize(win.width,win.height);					// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc( display );									// register Display Function
	glutIdleFunc( display );									// register Idle Function
    glutKeyboardFunc( keyboard );								// register Keyboard Handler
	initialize();
	printf("OpenGl Init: Ok\n");
	printf("Press Esc for Quite\n");
	glutMainLoop();												// run GLUT mainloop
}