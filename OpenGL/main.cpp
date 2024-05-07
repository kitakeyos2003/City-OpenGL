#include "glut.h"

void init();
void display();
void keyboard(unsigned char key, int x, int y);
void resize(int width, int height);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
void initResourcs();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);

    initResourcs();
    glutMainLoop();
    return 0;
}
