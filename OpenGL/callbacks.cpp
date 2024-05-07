#include "glut.h"
#include "camera.h"
#include <iostream>

extern void drawScene();
extern void handleKeyboardInput(unsigned char key, int x, int y);

extern Camera camera;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera.applyTransformations();
	drawScene();
	glutSwapBuffers();
}

bool lightStates[10] = { true, true, true, true, true, true, true, true, true, true };

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
		toggleLight(3);
		break;
	case 'e':
		toggleLight(4);
		break;
	default:
		camera.handleKeyboard(key, x, y);
		break;
	}
	glutPostRedisplay();
}

void resize(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, width / height, 1.0, 600.0);
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
