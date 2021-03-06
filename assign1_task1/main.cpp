#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159

const float RAD = PI/180;

float p1 = -0.5f;
float p2 = 0.5f;
float q1 = -0.5f;
float q2 = 0.5f;

void setup(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void drawRectangle (float x1, float x2, float y1, float y2){
	glColor3f(0.15f, 0.5f, 0.15f);
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
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

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawRectangle(p1, p2, q1, q2);
	drawCircle(0.2);
	glutSwapBuffers();
}

int main (int argc, char *argv[]){
	printf("Input x1");
	scanf("%f", &p1);
	printf("Input x2");
	scanf("%f", &p2);
	printf("Input x1");
	scanf("%f", &q1);
	printf("Input x2");
	scanf("%f", &q2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Flag");
	setup();
	glutDisplayFunc(display);
	glutMainLoop();
}
