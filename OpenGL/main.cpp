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
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D");

    init();
    initResourcs();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}
