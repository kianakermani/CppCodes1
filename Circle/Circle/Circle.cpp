#include <iostream>
#include <GL/glut.h>
float r = 1.0;
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	int N = 360;
	float d = 2 * 3.14 / N;
	float angle = 0.0;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < N; i++) {
		angle = i * d;
		glVertex2f(r * cos(angle), r * sin(angle));
	}
	glEnd();
	glFlush();

}
void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int x, char** y) {
	glutInit(&x, y);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	init();
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;


}