#include <GL/glut.h>
#define windowWidth 640
#define windowHeight 480

void GL_Setup(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	gluPerspective(45, (float) width / height, .1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void mainLoop() {

	static float angle;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -10);
	glRotatef(angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor3ub(150, 50, 125);
	glVertex2f(-1, 1);
	glColor3ub(000, 255, 000);
	glVertex2f(1, 1);
	glColor3ub(000, 000, 255);
	glVertex2f(1, -1);
	glColor3ub(255, 255, 000);
	glVertex2f(-1, -1);
	glEnd();
	glutSwapBuffers();
	angle += 0.25;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Hello World");
	glutIdleFunc(mainLoop);
	GL_Setup(windowWidth, windowHeight);
	glutMainLoop();
}
