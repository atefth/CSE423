#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159

const float RAD = PI/180;

void setup(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}
float P1 = -0.5;
float Q1 = -0.5;
float P2 = 0.5;
float Q2 = 0.5;
float radius = 0.2;

void drawRectangle (){
	glColor3f(0.15f, 0.5f, 0.15f);
	glBegin(GL_QUADS);
	glVertex2f(P1, Q1);
	glVertex2f(P2, Q1);
	glVertex2f(P2, Q2);
	glVertex2f(P1, Q2);
	glEnd();
}

void drawCircle(float radius)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (int i=0; i < 360; i++)
	{
		float degInRad = i*RAD;
		glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
	}

   glEnd();
   glFlush();
}

void onMouseDown(int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON)
    {
	  P1 -= 0.005;
	  P2 += 0.005;
	  Q1 -= 0.005;
	  Q2 += 0.005;
	  radius += 0.005;
    }else if(button == GLUT_RIGHT_BUTTON){
    	P1 += 0.005;
    	P2 -= 0.005;
    	Q1 += 0.005;
    	Q2 -= 0.005;
    	radius -= 0.005;
    }
  glutSwapBuffers();
  drawRectangle();
  drawCircle(radius);
  glFlush();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawRectangle();
	drawCircle(radius);
	glutSwapBuffers();
}

int main (int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Animation");
	setup();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseDown);
	glutMainLoop();
}
