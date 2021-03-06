#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#define PI 3.14159

const float RAD = PI/180;

float width = 0.05;
float height = 0.5;
float radius = 0.1;

void drawAnyCircle(float radius, int angleStart, int angleEnd, float x, float y){
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (int i=angleStart; i < angleEnd; i++){
		float degInRad = i*RAD;
		glVertex2f(cos(degInRad)*radius + x,sin(degInRad)*radius + y);
	}

	glEnd();
	glFlush();
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

void drawHorizontalTopSemiCircle(float radius, float y){
	drawAnyCircle(radius, 0, 180, 0, y);
}

void drawHorizontalBottomSemiCircle(float radius, float y){
	drawAnyCircle(radius, 180, 360, 0, y);
}

void drawVerticalRightSemiCircle(float radius, float x){
	drawAnyCircle(radius, -90, 90, x, 0);
}

void drawVerticalLeftSemiCircle(float radius, float x){
	drawAnyCircle(radius, 90, 270, x, 0);
}

void drawCircle(float radius, float x, float y){
	drawAnyCircle(radius, 0, 360, x, y);
}

void drawLeftWing(float x1, float y1, float x2, float y2, float radius){
	drawRectangle(x1, x2, y1, y2);
	drawVerticalLeftSemiCircle(radius, x2);
}

void drawRightWing(float x1, float y1, float x2, float y2, float radius){
	drawRectangle(x1, x2, y1, y2);
	drawVerticalRightSemiCircle(radius, x2);
}

void drawTopWing(float x1, float y1, float x2, float y2, float radius){
	drawRectangle(x1, x2, y1, y2);
	drawHorizontalTopSemiCircle(radius, y2);
}

void drawBottomWing(float x1, float y1, float x2, float y2, float radius){
	drawRectangle(x1, x2, y1, y2);
	drawHorizontalBottomSemiCircle(radius, y2);
}

void drawWings(float wingHeight, float wingWidth){
	drawTopWing(-wingWidth, 0, wingWidth, wingHeight, wingWidth);
	drawBottomWing(-wingWidth, 0, wingWidth, -wingHeight, wingWidth);
	drawLeftWing(0, -wingWidth, -wingHeight, wingWidth, wingWidth);
	drawRightWing(0, -wingWidth, wingHeight, wingWidth, wingWidth);
}

void drawFan(float width, float height, float radius){
	drawWings(height, width);
	drawCircle(radius, 0, 0);
}

void drawFanEfficiently(){

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawFan(width, height, 0.10);
	glutSwapBuffers();
}

int main (int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Fan");
	glutDisplayFunc(display);
	glutMainLoop();
}
