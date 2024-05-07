#include "glut.h"

void setupLights() {
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat position[] = { 20.0f, 50.0f, 50.0f, 0.0f };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);


    GLfloat lightColor[] = { 1.0, 0.0, 0.0, 1.0 }; // Màu sáng trắng
    GLfloat lightPosition[] = { 0.0, 15, 200.0, 1.0 }; // Vị trí nguồn sáng

    glEnable(GL_LIGHTING);

    for (int i = 0; i < 10; i++) {
        int light_id = GL_LIGHT0 + i;
        glEnable(light_id);
        glLightfv(light_id, GL_DIFFUSE, lightColor);
        glLightfv(light_id, GL_POSITION, lightPosition);
    }
}
