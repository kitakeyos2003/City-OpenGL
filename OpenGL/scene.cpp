#include "glut.h"
#include <math.h>

void balloonBezier();

// Vẽ một khối hình hộp với các thuộc tính vật liệu có thể điều chỉnh
void drawCube(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX = 0, GLfloat ambY = 0, GLfloat ambZ = 0, GLfloat shine = 50);

// Vẽ một hình cầu với các thuộc tính vật liệu có thể điều chỉnh
void drawSphere(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90);

// Vẽ một chiếc vòng tròn (torus) với các thuộc tính vật liệu có thể điều chỉnh
void drawTorus(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings, GLfloat shine = 90);

// Vẽ một hình trụ với các thuộc tính vật liệu có thể điều chỉnh
void drawCylinder(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90);

// Thiết lập pháp tuyến cho bề mặt
void setNormal(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3);

// Điều chỉnh các thuộc tính vật liệu cho việc vẽ đường cong
void matCurve(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambfactor = 1.0, GLfloat specfactor = 1.0, GLfloat shine = 50);

// Vẽ đường cong Bezier
void drawBezierCurve(double t, float xy[2], int L, GLfloat ctrlpoints[][3]);

// Tải một texture từ file
GLuint loadTexture(const char* filename);

// Các texture (hình ảnh)
GLuint _h1Brick, _h1Door, _h1Roof, _h1Window;
GLuint _h2Brick, _h2Door, _h2Roof, _h2Window;
GLuint _banner, _warningSignSlipperyRoad, _trafficSign2, _trafficSign3, _trafficSign4, _flag;

float  h = 5, h1 = 6, d1 = 4, g = 1, g1 = 2;

// Khởi tạo tài nguyên bằng cách tải các texture
void initResourcs() {
	_h1Brick = loadTexture("res/h1_bricks.bmp");
	_h1Door = loadTexture("res/h1_door.bmp");
	_h1Roof = loadTexture("res/h1_roof.bmp");
	_h1Window = loadTexture("res/h1_window.bmp");

	_h2Brick = loadTexture("res/h2_bricks.jpg");
	_h2Door = loadTexture("res/h1_door.bmp");
	_h2Roof = loadTexture("res/h2_roof.jpg");
	_h2Window = loadTexture("res/h2_window.jpg");


	_banner = loadTexture("res/banner.jpg");
	_warningSignSlipperyRoad = loadTexture("res/warning-sign-slippery-road.jpg");
	_trafficSign2 = loadTexture("res/traffic-sign-2.jpg");
	_trafficSign3 = loadTexture("res/traffic-sign-3.jpg");
	_trafficSign4 = loadTexture("res/traffic-sign-4.jpg");
	_flag = loadTexture("res/flag.jpg");
}


// Vẽ stand
void drawStand(float x, float y, float z)
{
	glPushMatrix();

	glColor3f(1, 0.8, 0);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y - h1, z + d1);
	glVertex3f(x + h, y - h1, z + d1);
	glVertex3f(x + h, y, z);
	glEnd();
	glColor3f(1, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x + h, y, z);
	glVertex3f(x + h, y - h1, z - d1);
	glVertex3f(x, y - h1, z - d1);
	glEnd();

	glColor3f(0.6, 0.12, 0.4);

	glBegin(GL_POLYGON);
	glVertex3f(x, y - h1, z + d1);
	glVertex3f(x, y - h1 - 2, z + d1);
	glVertex3f(x + 1, y - h1 - 2, z + d1);
	glVertex3f(x + 1, y - h1, z + d1);
	glEnd();

	glColor3f(0.6, 0.12, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(x + h, y - h1, z + d1);
	glVertex3f(x + h, y - h1 - 2, z + d1);
	glVertex3f(x + h - 1, y - h1 - 2, z + d1);
	glVertex3f(x + h - 1, y - h1, z + d1);
	glEnd();

	glColor3f(0.6, 0.12, 0.4);

	glBegin(GL_POLYGON);
	glVertex3f(x, y - h1, z - d1);
	glVertex3f(x, y - h1 - 2, z - d1);
	glVertex3f(x + 1, y - h1 - 2, z - d1);
	glVertex3f(x + 1, y - h1, z - d1);
	glEnd();

	glColor3f(0.6, 0.12, 0.4);

	glBegin(GL_POLYGON);
	glVertex3f(x + h, y - h1, z - d1);
	glVertex3f(x + h, y - h1 - 2, z - d1);
	glVertex3f(x + h - 1, y - h1 - 2, z - d1);
	glVertex3f(x + h - 1, y - h1, z - d1);
	glEnd();

	glPopMatrix();
}


// Vẽ các tòa nhà cao tầng
void drawTowerBlocks(float x, float y, float z)
{
	glPushMatrix();
	int i;
	int j;
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z + 0.5);
	glVertex3f(x + 45, y, z + 0.5);
	glVertex3f(x + 45, y + 100, z + 0.5);
	glVertex3f(x, y + 100, z + 0.5);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
	for (j = 0;j < 8;j++)
	{
		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(11 * i, 0, 0);
			glBegin(GL_POLYGON);
			glVertex3f(x + 2, y + 98, z);
			glVertex3f(x + 10, y + 98, z);
			glVertex3f(x + 10, y + 88, z);
			glVertex3f(x + 2, y + 88, z);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}
	glColor3f(0, 0, 0);
	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(11 * i, 0, 0);
			glBegin(GL_LINE_LOOP);
			glVertex3f(x + 2, y + 98, z);
			glVertex3f(x + 10, y + 98, z);
			glVertex3f(x + 10, y + 88, z);
			glVertex3f(x + 2, y + 88, z);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z + 45 - 0.5);
	glVertex3f(x + 45, y, z + 45 - 0.5);
	glVertex3f(x + 45, y + 100, z + 45 - 0.5);
	glVertex3f(x, y + 100, z + 45 - 0.5);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);

	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(11 * i, 0, 0);
			glBegin(GL_POLYGON);
			glVertex3f(x + 2, y + 98, z + 45);
			glVertex3f(x + 10, y + 98, z + 45);
			glVertex3f(x + 10, y + 88, z + 45);
			glVertex3f(x + 2, y + 88, z + 45);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}
	glColor3f(0, 0, 0);

	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(11 * i, 0, 0);
			glBegin(GL_LINE_LOOP);
			glVertex3f(x + 2, y + 98, z + 45);
			glVertex3f(x + 10, y + 98, z + 45);
			glVertex3f(x + 10, y + 88, z + 45);
			glVertex3f(x + 2, y + 88, z + 45);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(x + 0.5, y, z);
	glVertex3f(x + 0.5, y, z + 45);
	glVertex3f(x + 0.5, y + 100, z + 45);
	glVertex3f(x + 0.5, y + 100, z);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(0, 0, 11 * i);
			glBegin(GL_POLYGON);
			glVertex3f(x, y + 98, z + 2);
			glVertex3f(x, y + 98, z + 10);
			glVertex3f(x, y + 88, z + 10);
			glVertex3f(x, y + 88, z + 2);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}
	glColor3f(0, 0, 0);
	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(0, 0, 11 * i);
			glBegin(GL_LINE_LOOP);
			glVertex3f(x, y + 98, z + 2);
			glVertex3f(x, y + 98, z + 10);
			glVertex3f(x, y + 88, z + 10);
			glVertex3f(x, y + 88, z + 2);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}

	glColor3f(0.6, 0.6, 0.6);

	glBegin(GL_POLYGON);
	glVertex3f(x + 45 - 0.5, y, z - 0.5);
	glVertex3f(x + 45 - 0.5, y, z + 45 - 0.5);
	glVertex3f(x + 45 - 0.5, y + 100, z + 45 - 0.5);
	glVertex3f(x + 45 - 0.5, y + 100, z - 0.5);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(0, 0, 11 * i);
			glBegin(GL_POLYGON);
			glVertex3f(x + 45, y + 98, z + 2);
			glVertex3f(x + 45, y + 98, z + 10);
			glVertex3f(x + 45, y + 88, z + 10);
			glVertex3f(x + 45, y + 88, z + 2);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}
	glColor3f(0, 0, 0);
	for (j = 0;j < 8;j++)
	{

		glPushMatrix();
		glTranslatef(0, -12 * j, 0);
		for (i = 0;i < 4;i++)
		{
			glPushMatrix();
			glTranslatef(0, 0, 11 * i);
			glBegin(GL_LINE_LOOP);
			glVertex3f(x + 45, y + 98, z + 2);
			glVertex3f(x + 45, y + 98, z + 10);
			glVertex3f(x + 45, y + 88, z + 10);
			glVertex3f(x + 45, y + 88, z + 2);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z - 0.5);
	glVertex3f(x + 45, y, z - 0.5);
	glVertex3f(x + 45, y, z + 45 - 0.5);
	glVertex3f(x, y, z + 45 - 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(x, y + 100, z);
	glVertex3f(x + 45, y + 100, z);
	glVertex3f(x + 45, y + 100, z + 45);
	glVertex3f(x, y + 100, z + 45);
	glEnd();

	glPopMatrix();
}


// Vẽ ghế dài
void drawBench(float x, float y, float z, float rotateYAngle) {
	GLfloat seatColor[] = { 0.91f, 0.76f, 0.65f }; 
	GLfloat backrestColor[] = { 0.55f, 0.27f, 0.07f };
	GLfloat metalColor[] = { 0.1f, 0.1f, 0.1f };

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotateYAngle, 0, 1, 0);
	glScalef(2, 2, 2);

	glColor3fv(seatColor);
	glPushMatrix();
	glTranslatef(0, 1.0, 0);
	glScalef(4, 0.4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3fv(backrestColor);
	glPushMatrix();
	glTranslatef(0, 1.35, -0.5);
	glScalef(4, 1.1, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	glColor3fv(metalColor);
	glPushMatrix();
	glTranslatef(-1.8, 0.5, 0.4);
	glScalef(0.2, 1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 0.5, 0.4);
	glScalef(0.2, 1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.8, 0.5, -0.4);
	glScalef(0.2, 1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 0.5, -0.4);
	glScalef(0.2, 1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}


// Vẽ ngôi sao
void drawStar(GLfloat x, GLfloat y)
{
	glPushMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + 1.5, y - 4);
	glVertex2f(x + 6.5, y - 5.5);
	glVertex2f(x + 2.5, y - 9);
	glVertex2f(x + 4.5, y - 14);
	glVertex2f(x, y - 11.5);
	glVertex2f(x - 4.5, y - 14);
	glVertex2f(x - 3, y - 9);
	glVertex2f(x - 6.5, y - 5.5);
	glVertex2f(x - 1.5, y - 5);
	glVertex2f(x, y);
	glEnd();

	glPopMatrix();
}


// Vẽ ghế
void drawChair()
{
	
	glPushMatrix();
	glColor3f(0.91f, 0.76f, 0.65f);

	glPushMatrix();
	glScalef(0.5, 0.05, 0.5);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.5, 0);
	glScalef(0.05, 1.4, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.35, -1.5, 0);
	glScalef(0.05, 1.4, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2, 0);
	glScalef(0.5, 0.05, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(0.5, 0.05, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glScalef(0.5, 0.05, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.5, 1.3);
	glScalef(0.05, .55, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.35, -1.5, 1.3);
	glScalef(0.05, .55, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	glPopMatrix();
}


// Vẽ bàn
void drawTable()
{
	glColor3f(0.55f, 0.27f, 0.07f);

	glPushMatrix();
	glScalef(4, 0.3, 4);
	drawSphere(0.8, 0.4, 0.00, 0.4, 0.2, 0);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, -0.8, -0.1);
	drawCube(0, 0, 0, 0, 0, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glScalef(1, 0.2, 1);
	drawSphere(1, 0.549, 0.00, 0.5, 0.2745, 0);
	glPopMatrix();
}


// Vẽ bộ bàn ghế
void drawDiningSet(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1, 1.5, 1);

	glPushMatrix();
	glTranslatef(0, 1.1, 0);
	drawTable();
	glPopMatrix();

	for (int i = 0; i <= 360; i += 72)
	{
		glPushMatrix();
		glRotatef(i, 0, 1, 0);
		glTranslatef(0, 0.1, -4);
		drawChair();
		glPopMatrix();
	}

	glPopMatrix();
}


// Vẽ nền đất
void drawGround() {
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.6, 0.4);
	glVertex3f(-200.0, 0.0, -200.0);
	glVertex3f(-200.0, 0.0, 200.0);
	glVertex3f(200.0, 0.0, 200.0);
	glVertex3f(200.0, 0.0, -200.0);
	glEnd();
}


// Vẽ các đoạn đường
void drawRoads() {
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex3f(0, 0.01, -200);
	glVertex3f(0, 0.01, 200);
	glVertex3f(18, 0.01, 200);
	glVertex3f(18, 0.01, -200);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0, 0.01, -200);
	glVertex3f(0, 0.01, 200);
	glVertex3f(18, 0.01, 200);
	glVertex3f(18, 0.01, -200);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(44, 0.01, -200);
	glVertex3f(44, 0.01, 160);
	glVertex3f(54, 0.01, 160);
	glVertex3f(54, 0.01, -200);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(54, 0.01, -180);
	glVertex3f(54, 0.01, -160);
	glVertex3f(200, 0.01, -160);
	glVertex3f(200, 0.01, -180);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(18, 0.01, 160);
	glVertex3f(18, 0.01, 170);
	glVertex3f(200, 0.01, 170);
	glVertex3f(200, 0.01, 160);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(-200, 0.01, 90);
	glVertex3f(-200, 0.01, 100);
	glVertex3f(0, 0.01, 100);
	glVertex3f(0, 0.01, 90);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-90, 0.01, -200);
	glVertex3f(-90, 0.01, 90);
	glVertex3f(-80, 0.01, 90);
	glVertex3f(-80, 0.01, -200);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(8.5, 0.02, -200);
	glVertex3f(8.5, 0.02, 200);
	glVertex3f(9.5, 0.02, 200);
	glVertex3f(9.5, 0.02, -200);
	glEnd();
}


// Vẽ cây
void drawTree(float x, float y, float z) {
	glColor3f(0.3, 0.015, 0.13);
	glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidCube(7);
	glPopMatrix();

	glColor3f(0.015, 0.3, 0.13);
	glPushMatrix();
	glTranslatef(x, y + 23, z);
	glScalef(1.1, 2.3, 0.8);
	glutSolidSphere(10, 15, 6);
	glFlush();
	glPopMatrix();
}

// Vẽ quả bóng bay
void drawBalloon()
{
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(2, 2.5, 2);
	balloonBezier();
	glPopMatrix();

}


// Vẽ dây nối vào bóng bay
void drawBalloonLine()
{
	matCurve(0, 0, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(1, 10);
	glVertex2f(1, 1);
	glEnd();
}


// Vẽ trùm bóng bay
void drawBalloons()
{
	matCurve(1, 0, 0);
	glPushMatrix();
	glTranslatef(3, -10, 0.6);
	glColor3f(0.4, 0.5, 0.1);
	drawBalloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -19, 0.6);
	drawBalloonLine();
	glPopMatrix();

	matCurve(0, 0, 1);
	glPushMatrix();
	glTranslatef(6.2, -11, 0.6);
	glColor3f(0.1, 0.8, 0.3);
	drawBalloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -18, 0.6);
	glRotatef(-22, 0, 0, 1);
	drawBalloonLine();
	glPopMatrix();


	matCurve(1, 1, 0);
	glPushMatrix();
	glTranslatef(0, -11, 0.6);
	glColor3f(0.5, 0.5, 0.9);
	drawBalloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -18, 0.6);
	glRotatef(22, 0, 0, 1);
	drawBalloonLine();
	glPopMatrix();

	matCurve(1, 0.5, 0);
	glPushMatrix();
	glTranslatef(3, -13, 2.6);
	glColor3f(0.2, 0.6, 0.6);
	drawBalloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -20, 0.6);
	glRotatef(16, 1, 0, 0);
	drawBalloonLine();
	glPopMatrix();

	matCurve(1, 0, 1);
	glPushMatrix();
	glTranslatef(3, -13, -1.8);
	glColor3f(0.9, 0.7, 0.1);
	drawBalloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -20, 0.6);
	glRotatef(-14, 1, 0, 0);
	drawBalloonLine();
	glPopMatrix();

}


// Vẽ giỏ
void drawCart()
{
	glPushMatrix();
	glScalef(1, 2, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10, 4, 3);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 4, 3);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 3);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10, 0, 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	glScalef(1, 2, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10, 4, 3);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 4, 3);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 3);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10, 0, 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -2);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 8, 5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 8, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, 0, -2);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 8, 5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 8, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 11, -2);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1.25, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10, 4, 3);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 4, 3);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 3);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10, 0, 3);
	glEnd();
	glPopMatrix();

}


// Vẽ giỏ bóng bay (bóng bay + giỏ)
void balloonCart(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);

	drawBalloons();

	glPushMatrix();
	glTranslatef(0, -20, 0);
	glScalef(0.5, 0.5, 1);
	glColor3f(0.1, 0.5, 0.8);
	drawCart();
	glPopMatrix();

	glPopMatrix();
}


// Vẽ nhà 1
void drawHouse1(float x, float y, float z, float rotate) {

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(15, 15, 15);
	glRotatef(rotate, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0);
	glVertex3f(-2, 0, 1);
	glTexCoord2f(4.0, 2.0);
	glVertex3f(2, 0, 1);
	glTexCoord2f(4.0, 0.0);
	glVertex3f(2, -1.5, 1);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-2, -1.5, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0);
	glVertex3f(-2.2, 0.5, 0);
	glTexCoord2f(4.0, 2.0);
	glVertex3f(2.2, 0.5, 0);
	glTexCoord2f(4.0, 0.0);
	glVertex3f(2.2, -0.1, 1.25);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-2.2, -0.1, 1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Door);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.3, -0.4, 1.0001);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.3, -0.4, 1.0001);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.3, -1.5, 1.0001);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.3, -1.5, 1.0001);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.5, -0.3, 1.0001);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.75, -0.3, 1.0001);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.75, -0.8, 1.0001);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.5, -0.8, 1.0001);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.5, -0.3, 1.0001);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.75, -0.3, 1.0001);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.75, -0.8, 1.0001);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.5, -0.8, 1.0001);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0);  glVertex3f(-2, 0, -1);
	glTexCoord2f(4.0, 2.0);  glVertex3f(2, 0, -1);
	glTexCoord2f(4.0, 0.0);  glVertex3f(2, -1.5, -1);
	glTexCoord2f(0.0, 0.0);  glVertex3f(-2, -1.5, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord2f(4.0, 2.0);glVertex3f(2.2, 0.5, 0);
	glTexCoord2f(4.0, 0.0); glVertex3f(2.2, -0.1, -1.25);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.2, -0.1, -1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.5, -0.3, -1.0001);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.75, -0.3, -1.0001);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.75, -0.8, -1.0001);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.5, -0.8, -1.0001);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, -0.3, -1.0001);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.75, -0.3, -1.0001);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.75, -0.8, -1.0001);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, -0.8, -1.0001);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0); glVertex3f(2, 0, 1);
	glTexCoord2f(2.0, 2.0); glVertex3f(2, 0, -1);
	glTexCoord2f(2.0, 0.0); glVertex3f(2, -1.5, -1);
	glTexCoord2f(0.0, 0.0); glVertex3f(2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0, 1.0); glVertex3f(2, 0.5, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(2, 0, 1);
	glTexCoord2f(-1.0, 0.0); glVertex3f(2, 0, -1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0);    glVertex3f(-2, 0, 1);
	glTexCoord2f(2.0, 2.0);    glVertex3f(-2, 0, -1);
	glTexCoord2f(2.0, 0.0);    glVertex3f(-2, -1.5, -1);
	glTexCoord2f(0.0, 0.0);    glVertex3f(-2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0, 1.0);    glVertex3f(-2, 0.5, 0);
	glTexCoord2f(1.0, 0.0);    glVertex3f(-2, 0, 1);
	glTexCoord2f(-1.0, 0.0);    glVertex3f(-2, 0, -1);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);


	glPopMatrix();

}


// Vẽ nhà 2
void drawHouse2(float x, float y, float z, float rotate) {

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(15, 15, 15);
	glRotatef(rotate, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0, 2.0);  
	glVertex3f(-2, 0, 1);
	glTexCoord2f(4.0, 2.0);  
	glVertex3f(2, 0, 1);
	glTexCoord2f(4.0, 0.0);  
	glVertex3f(2, -1.5, 1);
	glTexCoord2f(0.0, 0.0);  
	glVertex3f(-2, -1.5, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0); 
	glVertex3f(-2.2, 0.5, 0);
	glTexCoord2f(4.0, 2.0);
	glVertex3f(2.2, 0.5, 0);
	glTexCoord2f(4.0, 0.0); 
	glVertex3f(2.2, -0.1, 1.25);
	glTexCoord2f(0.0, 0.0); 
	glVertex3f(-2.2, -0.1, 1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Door);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0, 1.0); 
	glVertex3f(-0.3, -0.4, 1.0001);
	glTexCoord2f(1.0, 1.0); 
	glVertex3f(0.3, -0.4, 1.0001);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.3, -1.5, 1.0001);
	glTexCoord2f(0.0, 0.0); 
	glVertex3f(-0.3, -1.5, 1.0001);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0, 1.0); 
	glVertex3f(-1.5, -0.3, 1.0001);
	glTexCoord2f(1.0, 1.0); 
	glVertex3f(-0.75, -0.3, 1.0001);
	glTexCoord2f(1.0, 0.0); 
	glVertex3f(-0.75, -0.8, 1.0001);
	glTexCoord2f(0.0, 0.0); 
	glVertex3f(-1.5, -0.8, 1.0001);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); 
	glVertex3f(1.5, -0.3, 1.0001);
	glTexCoord2f(1.0, 1.0); 
	glVertex3f(0.75, -0.3, 1.0001);
	glTexCoord2f(1.0, 0.0); 
	glVertex3f(0.75, -0.8, 1.0001);
	glTexCoord2f(0.0, 0.0); 
	glVertex3f(1.5, -0.8, 1.0001);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0, 2.0);  glVertex3f(-2, 0, -1);
	glTexCoord2f(4.0, 2.0);  glVertex3f(2, 0, -1);
	glTexCoord2f(4.0, 0.0);  glVertex3f(2, -1.5, -1);
	glTexCoord2f(0.0, 0.0);  glVertex3f(-2, -1.5, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord2f(4.0, 2.0);glVertex3f(2.2, 0.5, 0);
	glTexCoord2f(4.0, 0.0); glVertex3f(2.2, -0.1, -1.25);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.2, -0.1, -1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.5, -0.3, -1.0001);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.75, -0.3, -1.0001);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.75, -0.8, -1.0001);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.5, -0.8, -1.0001);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, -0.3, -1.0001);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.75, -0.3, -1.0001);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.75, -0.8, -1.0001);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, -0.8, -1.0001);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0); glVertex3f(2, 0, 1);
	glTexCoord2f(2.0, 2.0); glVertex3f(2, 0, -1);
	glTexCoord2f(2.0, 0.0); glVertex3f(2, -1.5, -1);
	glTexCoord2f(0.0, 0.0); glVertex3f(2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0, 1.0); glVertex3f(2, 0.5, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(2, 0, 1);
	glTexCoord2f(-1.0, 0.0); glVertex3f(2, 0, -1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 2.0);    glVertex3f(-2, 0, 1);
	glTexCoord2f(2.0, 2.0);    glVertex3f(-2, 0, -1);
	glTexCoord2f(2.0, 0.0);    glVertex3f(-2, -1.5, -1);
	glTexCoord2f(0.0, 0.0);    glVertex3f(-2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0, 1.0);    glVertex3f(-2, 0.5, 0);
	glTexCoord2f(1.0, 0.0);    glVertex3f(-2, 0, 1);
	glTexCoord2f(-1.0, 0.0);    glVertex3f(-2, 0, -1);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);


	glPopMatrix();

}


// Vẽ banner giao thông
void drawBanner(float x, float y, float z, float rotateYAngle) {
	
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotateYAngle, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, 30.0f, -10.38f);
	glScalef(10, 10, 10);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _banner);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.7, -0.85, 1.0001);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.7, -0.85, 1.0001);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.7, 0.85, 1.0001);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.7, 0.85, 1.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 20.0f, -1.2f);
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(13.5f, 7.0f, 0.25f);
	drawCube(0.5, 0.2, 0.2, 0.25, 0.1, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-18.5f, 0.0f, -2.0f);
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.5f, 13.75f, 0.5f); 
	drawCube(0.5, 0.2, 0.2, 0.25, 0.1, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.5f, 0.0f, -2.0f);
	glColor3f(0.5f, 0.35f, 0.05f); 
	glScalef(0.5f, 13.75f, 0.5f);
	drawCube(0.5, 0.2, 0.2, 0.25, 0.1, 0.1);
	glPopMatrix();

	glPopMatrix();
}


// Vẽ cột của biển báo giao thông
void drawPole() {
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(0.0, 5.0, -1.0); 
	glScalef(0.5, 10.0, 0.5); 
	glutSolidCube(1.0);
	glPopMatrix();
}

// Vẽ mặt biển báo giao thông hình tam giác
void drawTriangleSign() {
	glColor3f(1.0, 1.0, 1.0); 
	glPushMatrix();
	glTranslatef(0.0, 12.0, -0.5); 
	glScalef(5, 5, 5);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _warningSignSlipperyRoad);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.5, -1.0); glVertex3f(0.0, 1.0, 0.0); 
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

// Vẽ biển báo giao thông hình tam giác (Cột + Mặt biển báo)
void drawTrafficTriangleSign(float x, float y, float z, float rotateYAngle) {
	glPushMatrix();
	glRotatef(rotateYAngle, 0, 1, 0);
	glTranslatef(x, y, z);

	drawPole();
	drawTriangleSign();
	glPopMatrix();
}


// Vẽ mặt biển báo giao thông hình tròn
void drawCircularSign(GLuint trafficSign) {
	double PI = 3.14159265389;
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 11.0, -0.5);
	glScalef(7, 7, 7);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, trafficSign);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float angle = i * PI / 180;
		float x = 0.5 * cos(angle);
		float y = 0.5 * sin(angle);
		glTexCoord2f((1.0 - (x + 0.5)), 1.0 - (y + 0.5));
		glVertex2f(x, y); 
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

// Vẽ biển báo giao thông hình tròn (Cột + Mặt biển báo)
void drawTrafficCircularSign(GLuint trafficSign, float x, float y, float z, float rotateYAngle) {
	glPushMatrix();
	glRotatef(rotateYAngle, 0, 1, 0);
	glTranslatef(x, y, z);

	drawPole();
	drawCircularSign(trafficSign);
	glPopMatrix();
}


// Vẽ cờ VN
void drawFlag(float x, float y, float z) {

	glPushMatrix();
	glTranslatef(x, y, z);
	
	glPushMatrix();
	glTranslatef(8.5, 26, -6);
	glScalef(5, 5, 5);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _flag);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.7, -0.9, 1.0001);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.7, -0.9, 1.0001);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.7, 0.9, 1.0001);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.7, 0.9, 1.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, -20.0, -1.5); 
	glScalef(0.2, 17.0, 0.2); 
	drawCube(0.5, 0.2, 0.2, 0.25, 0.1, 0.1);
	glPopMatrix();

	glPopMatrix();
}


// Vẽ toàn cảnh
void drawScene() {
	drawGround();
	drawRoads();

	drawHouse1(60, 22.5, 150, 90);
	drawHouse1(-20, 22.5, 150, 90);
	drawHouse2(20, 22.5, 120, 270);

	drawStand(-10, 8, 130);

	drawTowerBlocks(150, 1, -150);
	drawTowerBlocks(80, 1, -90);

	drawTowerBlocks(150, 1, -90);
	drawTowerBlocks(150, 1, -30);

	drawTowerBlocks(-150, 1, -30);
	drawTowerBlocks(-150, 1, -110);

	drawTowerBlocks(-150, 1, -180);	
	
	drawStar(20, 240);
	drawStar(180, 220);
	drawStar(-30, 280);
	drawStar(190, 280);
	drawStar(100, 220);
	drawStar(-230, 250);
	drawStar(-190, 210);
	drawStar(-88, 260);
	drawStar(88, 270);
	drawStar(-170, 280);
	drawBanner(30, 2, 120, 270);

	drawFlag(70, 20, 10);
	drawTree(-15, 3.6, 50);
	drawTree(-15, 3.6, -40);
	drawTree(-15, 3.6, 20);
	drawTree(-15, 3.6, -10);
	drawTree(-15, 3.6, -80);
	drawTree(-15, 3.6, -120);
	drawTree(-15, 3.6, -160);
	
	drawTrafficTriangleSign(22, 0, 100, 0);
	drawTrafficCircularSign(_trafficSign3, 22, 0, -100, 0);
	drawTrafficCircularSign(_trafficSign2, 22, 0, 155, 0);
	drawTrafficCircularSign(_trafficSign4, 22, 0, 190, 0);

	balloonCart(-10, 20, 160);

	drawDiningSet(80, 2.5, 100);

	drawDiningSet(80, 2.5, 120);
	drawDiningSet(80, 2.5, 140);
	


	drawBench(-80, 2.2, 130, 90);
	drawBench(-70, 2.2, 130, 270);

	drawBench(-80, 2.2, 150, 90);
	drawBench(-70, 2.2, 150, 270);


	drawBench(-80, 2.2, 170, 90);
	drawBench(-70, 2.2, 170, 270);
	
}
