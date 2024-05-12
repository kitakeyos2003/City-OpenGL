#include "camera.h"
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

Camera::Camera() : angleX(0.0), angleY(0.0), posX(0.0), posY(15.0), posZ(320.0), isDragging(false), lastX(0), lastY(0) {}

Camera::~Camera() {
    
}

// Áp  dụng các thay đổi (Di chuyển, hướng nhìn)
void Camera::applyTransformations() {
    glLoadIdentity();
    glTranslatef(-posX, -posY, -posZ);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
}

void Camera::handleKeyboard(unsigned char key, int x, int y) {
    const float step = 1.0f;
    float radYaw = angleY * M_PI / 180.0;
    float radPitch = angleX * M_PI / 180.0;

    switch (key) {
    case 'w':
        posX += step * sin(radYaw);
        posZ -= step * cos(radYaw);
        break;
    case 's':
        posX -= step * sin(radYaw);
        posZ += step * cos(radYaw);
        break;
    case 'a':
        posX -= step * cos(radYaw);
        posZ -= step * sin(radYaw);
        break;
    case 'd':
        posX += step * cos(radYaw);
        posZ += step * sin(radYaw);
        break;
    case ' ':
        posY += step;
        break;
    case 'c':
        posY -= step;
        break;
    }
}

void Camera::handleMouseMove(int x, int y) {
    if (isDragging) {
        int dx = x - lastX;
        int dy = y - lastY;

        angleY += dx * 0.1f;
        angleX += dy * 0.1f;

        angleX = std::max(std::min(angleX, 89.0f), -89.0f);

        lastX = x;
        lastY = y;
    }
}


void Camera::handleMouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = true;
            lastX = x;
            lastY = y;
        }
        else if (state == GLUT_UP) {
            isDragging = false;
        }
    }
}

Camera camera;
