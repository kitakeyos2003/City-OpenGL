#ifndef CAMERA_H
#define CAMERA_H

#include "glut.h"

class Camera {
public:
    Camera();
    ~Camera();

    void applyTransformations();
    void handleKeyboard(unsigned char key, int x, int y);
    void handleMouseMove(int x, int y);
    void handleMouseButton(int button, int state, int x, int y);

private:
    float angleX, angleY;
    float posX, posY, posZ;
    bool isDragging = false;
    int lastX, lastY;
};

#endif
