#include<GL/glut.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
float x = 92;
float y = 400;
int flag = 0;



void init(void) {
	glClearColor(0, 0, 0, 1);

}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 500, 0);
	glMatrixMode(GL_MODELVIEW);
}

void man() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	float angle;
	glBegin(GL_POLYGON);//umbrella
	for (int i = 180; i < 360; i++)
	{
		angle = i * 3.142 / 180;
		glColor3f(1, 1, 1);
		glVertex2f((x - 2) + 29 * cos(angle), (y - 27) + 29 * sin(angle));
	}
	glEnd();
	float angle2;
	glBegin(GL_POLYGON);//head
	for (int i = 0; i < 360; i++)
	{
		angle2 = i * 3.142 / 180;
		glColor3f(1, 1, 1);
		glVertex2f(x + 11 * cos(angle2), (y - 11) + 11 * sin(angle2));
	}
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);//stick
	glVertex2f(x - 4, y - 26);
	glVertex2f(x - 4, y - 10);
	glEnd();
	glBegin(GL_LINES);//hand2
	glColor3f(1, 1, 1);
	glVertex2f(x + 1, y + 9);
	glVertex2f(x + 15, y + 18);
	glEnd();
	glBegin(GL_LINES);//leg 1
	glColor3f(1, 1, 1);
	glVertex2f(x - 1, y + 33);
	glVertex2f(x - 13, y + 43);
	glEnd();
	glBegin(GL_LINES);//leg 2
	glColor3f(1, 1, 1);
	glVertex2f(x + 1, y + 33);
	glVertex2f(x + 15, y + 43);
	glEnd();
	glBegin(GL_LINES);//hand 1
	glColor3f(1, 1, 1);
	glVertex2f(x - 5, y - 10);
	glVertex2f(x - 23, y + 5);
	glEnd();
	glBegin(GL_LINES);//hand 1
	glColor3f(1, 1, 1);
	glVertex2f(x - 23, y + 5);
	glVertex2f(x - 1, y + 9);
	glEnd();
	glBegin(GL_LINES);//body
	glColor3f(1, 1, 1);
	glVertex2f(x, y);
	glVertex2f(x, y + 33);
	glEnd();
	glBegin(GL_LINES);//land
	glColor3f(1, 1, 1);
	glVertex2f(0, 443);
	glVertex2f(999, 443);
	glEnd();
	glBegin(GL_LINES);
	for (int t = 0; t < 10; t++) {
		int x1 = rand() % 1000;
		int y1 = rand() % 499;
		glColor3f(1, 1, 1);
		glVertex2d(x1, y1);
		glVertex2d(x1, y1 + 15);
	}
	glEnd();
	glutSwapBuffers();

}
void onIdle() {
	glutPostRedisplay();
	if (x < 950)
	{
		x += 0.05;
	}
}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("first gl program");
	init();
	glutDisplayFunc(man);
	glutReshapeFunc(reshape);
	glutIdleFunc(onIdle);
	glutMainLoop();

}