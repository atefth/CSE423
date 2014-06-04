#include <GL/glut.h>

void setup(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float x1 = -0.5f;
	float y1 = -0.5f;
	float x2 = 0.5f;
	float y2 = 0.5f;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	glutSwapBuffers();
}

void animate(){

}

int main (int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Animation");
	setup();
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutMainLoop();
}
