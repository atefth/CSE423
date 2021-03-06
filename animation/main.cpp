#include <GL/glut.h>
#include <stdio.h>

float x1 = -0.075f;
float y1 = -0.075f;
float x2 = 0.075f;
float y2 = 0.075f;
float distanceMovedX = 0;
float distanceMovedY = 0;
float xShift = 0;
float yShift = 0.005;

void setup(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void drawRectangle(){
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glTranslatef(xShift, 0, 0);
	glPushMatrix();
	glColor3f(0.0f, 0.05f, 0.05f);
	drawRectangle();
	glPopMatrix();

	glutSwapBuffers();
}

void animate(){
	distanceMovedX+= xShift;
	if(distanceMovedX != 0){
		if(distanceMovedX > 1.075){
			xShift = -2.175;
		}else{
			xShift = 0.005;
		}
	}
	glutPostRedisplay();
}

void onMouseDown(int button, int state, int x, int y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		if (distanceMovedX == 0){
			xShift = 0.005;
		}else{
			xShift = 0;
		}
	}
}

int main (int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Animation");
	setup();
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutMouseFunc(onMouseDown);
	glutMainLoop();
}
