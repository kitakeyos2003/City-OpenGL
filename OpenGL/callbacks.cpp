#include "glut.h"
#include "camera.h"
#include <iostream>

void drawScene();
void setupLights();

extern Camera camera;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	camera.applyTransformations();
	//glEnable(GL_LIGHTING);
	//setupLights();
	drawScene();
	//glDisable(GL_LIGHTING);
	glFlush();
	glutSwapBuffers();
}

bool lightStates[2] = { false, false};

void toggleLight(int lightNumber) {
	lightStates[lightNumber] = !lightStates[lightNumber];
	int light_id = GL_LIGHT0 + lightNumber;
	if (lightStates[lightNumber]) {
		glEnable(light_id);
	}
	else {
		glDisable(light_id);
	}
	std::cout << "Light " << lightNumber << " is " << lightStates[lightNumber] << "\n";
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'q':
		toggleLight(0);
		break;
	case 'e':
		toggleLight(1);
		break;
	default:
		camera.handleKeyboard(key, x, y);
		break;
	}
	glutPostRedisplay();
}

void resize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio = (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	gluPerspective(60, ratio, 1, 500);
	glMatrixMode(GL_MODELVIEW);
}

void mouseMove(int x, int y) {
	camera.handleMouseMove(x, y);
	glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
	camera.handleMouseButton(button, state, x, y);
	glutPostRedisplay();
}
