#include "glut.h"
#include <math.h>

void drawCube(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX = 0, GLfloat ambY = 0, GLfloat ambZ = 0, GLfloat shine = 50);
void drawSphere(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90);
void drawTorus(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings, GLfloat shine = 90);
void drawCylinder(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90);
void setNormal(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3);
void matCurve(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambfactor = 1.0, GLfloat specfactor = 1.0, GLfloat shine = 50);
void drawBezierCurve(double t, float xy[2], int L, GLfloat ctrlpoints[][3]);
GLuint loadTexture(const char* filename);

GLuint _h1Brick, _h1Door, _h1Roof, _h1Window;

GLuint _h2Brick, _h2Door, _h2Roof, _h2Window;
GLuint _banner, _warningSignSlipperyRoad, _trafficSign2, _flag;

float  h = 5, h1 = 6, d1 = 4, g = 1, g1 = 2;

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
	_flag = loadTexture("res/flag.jpg");
}

void drawStand(float x, float y, float z)
{
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
}

void drawTowerBlocks(float x, float y, float z)
{
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
}

void drawBench(float x, float y, float z, float rotateYAngle) {
	// Màu gỗ sáng cho phần ghế ngồi
	GLfloat seatColor[] = { 0.91f, 0.76f, 0.65f }; // Màu nâu sáng/beige
	// Màu gỗ tối cho phần tựa lưng
	GLfloat backrestColor[] = { 0.55f, 0.27f, 0.07f }; // Màu nâu đậm, giả sử màu này cho tựa lưng
	// Màu kim loại tối cho khung ghế
	GLfloat metalColor[] = { 0.1f, 0.1f, 0.1f }; // Màu xám đậm gần như đen

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotateYAngle, 0, 1, 0);
	glScalef(2, 2, 2);

	// Ghế ngồi được làm từ các thanh gỗ
	glColor3fv(seatColor); // Đặt màu cho ghế ngồi
	glPushMatrix();
	glTranslatef(0, 1.0, 0); // Nâng ghế ngồi lên vị trí mong muốn
	glScalef(4, 0.4, 1);     // Phóng to để tạo thành ghế ngồi
	glutSolidCube(1);
	glPopMatrix();

	// Tựa lưng được làm từ các thanh gỗ
	glColor3fv(backrestColor); // Đặt màu cho tựa lưng
	glPushMatrix();
	glTranslatef(0, 1.35, -0.5); // Đặt vị trí và góc cho tựa lưng
	glScalef(4, 1.1, 0.4);        // Phóng to để tạo thành tựa lưng
	glutSolidCube(1);
	glPopMatrix();

	// Chân ghế được làm từ kim loại màu tối
	glColor3fv(metalColor); // Đặt màu cho chân ghế
	glPushMatrix();
	glTranslatef(-1.8, 0.5, 0.4); // Đặt vị trí cho chân ghế
	glScalef(0.2, 1, 0.2);        // Phóng to để tạo thành chân ghế
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

void drawStar(GLfloat x, GLfloat y)
{
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
}

void drawBinSegment(float x, float y, float z, const GLfloat color[3]) {
	glColor3fv(color);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();
}

// Function to draw the entire set of bins
void drawWasteBinSet() {
	// Define colors for each bin
	GLfloat redColor[] = { 1.0f, 0.0f, 0.0f };
	GLfloat yellowColor[] = { 1.0f, 1.0f, 0.0f };
	GLfloat greenColor[] = { 0.0f, 1.0f, 0.0f };

	// Set the initial x position
	float initialX = -1.0f;

	// Draw three bin segments with different colors
	drawBinSegment(initialX, 0.5f, 0.0f, redColor);     // Red bin
	drawBinSegment(initialX + 1.0f, 0.5f, 0.0f, yellowColor); // Yellow bin
	drawBinSegment(initialX + 2.0f, 0.5f, 0.0f, greenColor);  // Green bin
}

void drawChair()
{
	glColor3f(0.91f, 0.76f, 0.65f);
	//seat part
	glPushMatrix();
	glScalef(0.5, 0.05, 0.5);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat left back
	glPushMatrix();
	glTranslatef(0, -1.5, 0);
	glScalef(0.05, 1.4, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat right back
	glPushMatrix();
	glTranslatef(1.35, -1.5, 0);
	glScalef(0.05, 1.4, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat horizontal up back
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glScalef(0.5, 0.05, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat horizontal up back
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(0.5, 0.05, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat horizontal up back
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glScalef(0.5, 0.05, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat left front leg
	glPushMatrix();
	glTranslatef(0, -1.5, 1.3);
	glScalef(0.05, .55, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

	//seat right front leg
	glPushMatrix();
	glTranslatef(1.35, -1.5, 1.3);
	glScalef(0.05, .55, 0.05);
	drawCube(0.8, 0.2, 0.4, 0.4, 0.1, 0.2);
	glPopMatrix();

}

void drawTable()
{
	glColor3f(0.55f, 0.27f, 0.07f);
	//table
	glPushMatrix();
	glScalef(4, 0.3, 4);
	drawSphere(0.8, 0.4, 0.00, 0.4, 0.2, 0);
	glPopMatrix();

	//stand
	glPushMatrix();
	glScalef(0.1, -0.8, -0.1);
	drawCube(0, 0, 0, 0, 0, 0.5);
	glPopMatrix();

	//stand bottom
	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glScalef(1, 0.2, 1);
	drawSphere(1, 0.549, 0.00, 0.5, 0.2745, 0);
	glPopMatrix();
}

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

void drawGround() {
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.6, 0.4);
	glVertex3f(-200.0, 0.0, -200.0);
	glVertex3f(-200.0, 0.0, 200.0);
	glVertex3f(200.0, 0.0, 200.0);
	glVertex3f(200.0, 0.0, -200.0);
	glEnd();
}

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

const int nt = 60;
const int ntheta = 20;
const double PI = 3.14159265389;

void balloonBezier()
{
	int L = 5;
	GLfloat balloonctrlpoints[6][3] =
	{
		{ 0.0, 0.0, 0.0}, {0.7,0.8,0},
		{2,0.9,0}, {2.3,0.5,0},
		{2.5, 0.1,0}, {2.4, 0, 0}
	};

	int i, j;
	float x, y, z, r;                //current coordinates
	float x1, y1, z1, r1;            //next coordinates
	float theta;

	const float startx = 0, endx = balloonctrlpoints[L][0];
	//number of angular slices
	const float dx = (endx - startx) / nt;    //x step size
	const float dtheta = 2 * PI / ntheta;        //angular step size

	float t = 0;
	float dt = 1.0 / nt;
	float xy[2];
	drawBezierCurve(t, xy, 5, balloonctrlpoints);
	x = xy[0];
	r = xy[1];
	//rotate about z-axis
	float p1x, p1y, p1z, p2x, p2y, p2z;
	for (i = 0; i < nt; ++i)              //step through x
	{
		theta = 0;
		t += dt;
		drawBezierCurve(t, xy, 5, balloonctrlpoints);
		x1 = xy[0];
		r1 = xy[1];

		//draw the surface composed of quadrilaterals by sweeping theta
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= ntheta; ++j)
		{
			theta += dtheta;
			double cosa = cos(theta);
			double sina = sin(theta);
			y = r * cosa;
			y1 = r1 * cosa;    //current and next y
			z = r * sina;
			z1 = r1 * sina;    //current and next z

			//edge from point at x to point at next x
			glVertex3f(x, y, z);

			if (j > 0)
			{
				setNormal(p1x, p1y, p1z, p2x, p2y, p2z, x, y, z);
			}
			else
			{
				p1x = x;
				p1y = y;
				p1z = z;
				p2x = x1;
				p2y = y1;
				p2z = z1;

			}
			glVertex3f(x1, y1, z1);

			//forms quad with next pair of points with incremented theta value
		}
		glEnd();
		x = x1;
		r = r1;
	}
}


void balloon()
{
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(2, 2.5, 2);
	balloonBezier();
	glPopMatrix();

}

void balloonLine()
{
	matCurve(0, 0, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(1, 10);
	glVertex2f(1, 1);
	glEnd();
}

void balloons()
{
	matCurve(1, 0, 0);
	glPushMatrix();
	glTranslatef(3, -10, 0.6);
	glColor3f(0.4, 0.5, 0.1);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -19, 0.6);
	balloonLine();
	glPopMatrix();

	matCurve(0, 0, 1);
	glPushMatrix();
	glTranslatef(6.2, -11, 0.6);
	glColor3f(0.1, 0.8, 0.3);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -18, 0.6);
	glRotatef(-22, 0, 0, 1);
	balloonLine();
	glPopMatrix();


	matCurve(1, 1, 0);
	glPushMatrix();
	glTranslatef(0, -11, 0.6);
	glColor3f(0.5, 0.5, 0.9);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -18, 0.6);
	glRotatef(22, 0, 0, 1);
	balloonLine();
	glPopMatrix();

	matCurve(1, 0.5, 0);
	glPushMatrix();
	glTranslatef(3, -13, 2.6);
	glColor3f(0.2, 0.6, 0.6);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -20, 0.6);
	glRotatef(16, 1, 0, 0);
	balloonLine();
	glPopMatrix();

	matCurve(1, 0, 1);
	glPushMatrix();
	glTranslatef(3, -13, -1.8);
	glColor3f(0.9, 0.7, 0.1);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, -20, 0.6);
	glRotatef(-14, 1, 0, 0);
	balloonLine();
	glPopMatrix();

}

void quad1()
{
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10, 4, 3);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 4, 3);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 3);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10, 0, 3);
	glEnd();
}

void quad2()
{
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 8, 5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 8, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 5);
	glEnd();
}

void cart()
{
	glPushMatrix();
	glScalef(1, 2, 1);
	quad1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	glScalef(1, 2, 1);
	quad1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -2);
	quad2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, 0, -2);
	quad2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 11, -2);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1.25, 1);
	quad1();
	glPopMatrix();

}

void balloonCart(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);

	balloons();

	glPushMatrix();
	glTranslatef(0, -20, 0);
	glScalef(0.5, 0.5, 1);
	glColor3f(0.1, 0.5, 0.8);
	cart();
	glPopMatrix();

	glPopMatrix();
}

void drawHouse1(float x, float y, float z, float rotate) {

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(15, 15, 15);
	glRotatef(rotate, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);
	// Front side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 0.1);  glVertex3f(-2, 0, 1);
	glTexCoord3f(4.0, 2.0, 0.1);  glVertex3f(2, 0, 1);
	glTexCoord3f(4.0, 0.0, 0.1);  glVertex3f(2, -1.5, 1);
	glTexCoord3f(0.0, 0.0, 0.1);  glVertex3f(-2, -1.5, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Roof
	glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord3f(4.0, 2.0, 0);glVertex3f(2.2, 0.5, 0);
	glTexCoord3f(4.0, 0.0, 1.25); glVertex3f(2.2, -0.1, 1.25);
	glTexCoord3f(0.0, 0.0, 1.25); glVertex3f(-2.2, -0.1, 1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Door);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Door
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(-0.3, -0.4, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.3, -0.4, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.3, -1.5, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(-0.3, -1.5, 1.0001);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Window Left
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(-1.5, -0.3, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(-0.75, -0.3, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(-0.75, -0.8, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(-1.5, -0.8, 1.0001);
	glEnd();

	glBegin(GL_QUADS);  // Window Right
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(1.5, -0.3, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.75, -0.3, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.75, -0.8, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(1.5, -0.8, 1.0001);
	glEnd();
	glPopMatrix();

	// Back side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, -1);  glVertex3f(-2, 0, -1);
	glTexCoord3f(4.0, 2.0, -1);  glVertex3f(2, 0, -1);
	glTexCoord3f(4.0, 0.0, -1);  glVertex3f(2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, -1);  glVertex3f(-2, -1.5, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Roof
	glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord3f(4.0, 2.0, 0);glVertex3f(2.2, 0.5, 0);
	glTexCoord3f(4.0, 0.0, -1.25); glVertex3f(2.2, -0.1, -1.25);
	glTexCoord3f(0.0, 0.0, -1.25); glVertex3f(-2.2, -0.1, -1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h1Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Window Left
	glTexCoord3f(0.0, 1.0, -1.0001); glVertex3f(-1.5, -0.3, -1.0001);
	glTexCoord3f(1.0, 1.0, -1.0001); glVertex3f(-0.75, -0.3, -1.0001);
	glTexCoord3f(1.0, 0.0, -1.0001); glVertex3f(-0.75, -0.8, -1.0001);
	glTexCoord3f(0.0, 0.0, -1.0001); glVertex3f(-1.5, -0.8, -1.0001);
	glEnd();

	glBegin(GL_QUADS);  // Window Right
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(1.5, -0.3, -1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.75, -0.3, -1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.75, -0.8, -1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(1.5, -0.8, -1.0001);
	glEnd();
	glPopMatrix();

	// Right side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 1); glVertex3f(2, 0, 1);
	glTexCoord3f(2.0, 2.0, -1); glVertex3f(2, 0, -1);
	glTexCoord3f(2.0, 0.0, -1); glVertex3f(2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, 1); glVertex3f(2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);  // Wall Upper
	glTexCoord3f(0.0, 1.0, 0); glVertex3f(2, 0.5, 0);
	glTexCoord3f(1.0, 0.0, 1); glVertex3f(2, 0, 1);
	glTexCoord3f(-1.0, 0.0, -1); glVertex3f(2, 0, -1);
	glEnd();
	glPopMatrix();

	// Left side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h1Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 1);    glVertex3f(-2, 0, 1);
	glTexCoord3f(2.0, 2.0, -1);    glVertex3f(-2, 0, -1);
	glTexCoord3f(2.0, 0.0, -1);    glVertex3f(-2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, 1);    glVertex3f(-2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);  // Wall Upper
	glTexCoord3f(0.0, 1.0, 0);    glVertex3f(-2, 0.5, 0);
	glTexCoord3f(1.0, 0.0, 1);    glVertex3f(-2, 0, 1);
	glTexCoord3f(-1.0, 0.0, -1);    glVertex3f(-2, 0, -1);
	glEnd();
	glPopMatrix();


	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

}



void drawHouse2(float x, float y, float z, float rotate) {

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(15, 15, 15);
	glRotatef(rotate, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);
	// Front side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 0.1);  
	glVertex3f(-2, 0, 1);
	glTexCoord3f(4.0, 2.0, 0.1);  
	glVertex3f(2, 0, 1);
	glTexCoord3f(4.0, 0.0, 0.1);  
	glVertex3f(2, -1.5, 1);
	glTexCoord3f(0.0, 0.0, 0.1);  
	glVertex3f(-2, -1.5, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Roof
	glTexCoord3f(0.0, 2.0, 0); 
	glVertex3f(-2.2, 0.5, 0);
	glTexCoord3f(4.0, 2.0, 0);
	glVertex3f(2.2, 0.5, 0);
	glTexCoord3f(4.0, 0.0, 1.25); 
	glVertex3f(2.2, -0.1, 1.25);
	glTexCoord3f(0.0, 0.0, 1.25); 
	glVertex3f(-2.2, -0.1, 1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Door);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Door
	glTexCoord3f(0.0, 1.0, 1.0001); 
	glVertex3f(-0.3, -0.4, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); 
	glVertex3f(0.3, -0.4, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001);
	glVertex3f(0.3, -1.5, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); 
	glVertex3f(-0.3, -1.5, 1.0001);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Window Left
	glTexCoord3f(0.0, 1.0, 1.0001); 
	glVertex3f(-1.5, -0.3, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); 
	glVertex3f(-0.75, -0.3, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); 
	glVertex3f(-0.75, -0.8, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); 
	glVertex3f(-1.5, -0.8, 1.0001);
	glEnd();

	glBegin(GL_QUADS);  // Window Right
	glTexCoord3f(0.0, 1.0, 1.0001); 
	glVertex3f(1.5, -0.3, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); 
	glVertex3f(0.75, -0.3, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); 
	glVertex3f(0.75, -0.8, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); 
	glVertex3f(1.5, -0.8, 1.0001);
	glEnd();
	glPopMatrix();

	// Back side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, -1);  glVertex3f(-2, 0, -1);
	glTexCoord3f(4.0, 2.0, -1);  glVertex3f(2, 0, -1);
	glTexCoord3f(4.0, 0.0, -1);  glVertex3f(2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, -1);  glVertex3f(-2, -1.5, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Roof
	glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord3f(4.0, 2.0, 0);glVertex3f(2.2, 0.5, 0);
	glTexCoord3f(4.0, 0.0, -1.25); glVertex3f(2.2, -0.1, -1.25);
	glTexCoord3f(0.0, 0.0, -1.25); glVertex3f(-2.2, -0.1, -1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _h2Window);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Window Left
	glTexCoord3f(0.0, 1.0, -1.0001); glVertex3f(-1.5, -0.3, -1.0001);
	glTexCoord3f(1.0, 1.0, -1.0001); glVertex3f(-0.75, -0.3, -1.0001);
	glTexCoord3f(1.0, 0.0, -1.0001); glVertex3f(-0.75, -0.8, -1.0001);
	glTexCoord3f(0.0, 0.0, -1.0001); glVertex3f(-1.5, -0.8, -1.0001);
	glEnd();

	glBegin(GL_QUADS);  // Window Right
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(1.5, -0.3, -1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.75, -0.3, -1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.75, -0.8, -1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(1.5, -0.8, -1.0001);
	glEnd();
	glPopMatrix();

	// Right side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 1); glVertex3f(2, 0, 1);
	glTexCoord3f(2.0, 2.0, -1); glVertex3f(2, 0, -1);
	glTexCoord3f(2.0, 0.0, -1); glVertex3f(2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, 1); glVertex3f(2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);  // Wall Upper
	glTexCoord3f(0.0, 1.0, 0); glVertex3f(2, 0.5, 0);
	glTexCoord3f(1.0, 0.0, 1); glVertex3f(2, 0, 1);
	glTexCoord3f(-1.0, 0.0, -1); glVertex3f(2, 0, -1);
	glEnd();
	glPopMatrix();

	// Left side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _h2Brick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 1);    glVertex3f(-2, 0, 1);
	glTexCoord3f(2.0, 2.0, -1);    glVertex3f(-2, 0, -1);
	glTexCoord3f(2.0, 0.0, -1);    glVertex3f(-2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, 1);    glVertex3f(-2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);  // Wall Upper
	glTexCoord3f(0.0, 1.0, 0);    glVertex3f(-2, 0.5, 0);
	glTexCoord3f(1.0, 0.0, 1);    glVertex3f(-2, 0, 1);
	glTexCoord3f(-1.0, 0.0, -1);    glVertex3f(-2, 0, -1);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);


	glPopMatrix();

}

void drawBanner(float x, float y, float z, float rotateYAngle) {
	
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotateYAngle, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, 30.0f, -10.38f); // Điều chỉnh độ cao của bảng để nó nằm trên mặt bàn
	glScalef(10, 10, 10);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _banner);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(-1.7, -0.85, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(1.7, -0.85, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(1.7, 0.85, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(-1.7, 0.85, 1.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	// Bảng
	glPushMatrix();
	glTranslatef(0, 30.0f, -1.0f);
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(40.0f, 20.0f, 1.0f);
	glutSolidCube(1.0);
	glPopMatrix();

	// Chân bảng 1
	glPushMatrix();
	glTranslatef(-18.5f, 19.0f, -1.0f);
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(1.0f, 40.0f, 1.0f); 
	glutSolidCube(1.0);
	glPopMatrix();

	// Chân bảng 2
	glPushMatrix();
	glTranslatef(18.5f, 19.0f, -1.0f); 
	glColor3f(0.5f, 0.35f, 0.05f); 
	glScalef(1.0f, 40.0f, 1.0f); 
	glutSolidCube(1.0);
	glPopMatrix();


	glPopMatrix();
}

void drawPole() {
	glColor3f(0.5, 0.5, 0.5); // Màu của cột
	glPushMatrix();
	glTranslatef(0.0, 6.0, -1.0); // Di chuyển cột về phía sau
	glScalef(0.5, 10.0, 0.5); // Kích thước của cột (chiều dài, chiều cao, chiều rộng)
	glutSolidCube(1.0); // Vẽ cột dưới dạng hình hộp
	glPopMatrix();
}

void drawTriangleSign() {
	glColor3f(1.0, 1.0, 1.0); // Màu của biển báo
	glPushMatrix();
	glTranslatef(0.0, 12.0, -0.5); // Di chuyển biển báo lên trên cột
	glScalef(5, 5, 5);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _warningSignSlipperyRoad);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.5, -1.0); glVertex3f(0.0, 1.0, 0.0);   // Đỉnh trên
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0); // Đỉnh dưới bên trái
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void drawTrafficTriangleSign(float x, float y, float z, float rotateYAngle) {
	glPushMatrix();
	glRotatef(rotateYAngle, 0, 1, 0);
	glTranslatef(x, y, z);

	drawPole();
	drawTriangleSign();
	glPopMatrix();
}

void drawCircularSign() {
	glColor3f(1.0, 1.0, 1.0); // Màu của biển báo
	glPushMatrix();
	glTranslatef(0.0, 11.0, -0.5); // Di chuyển biển báo lên trên cột
	glScalef(7, 7, 7);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _trafficSign2);
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

void drawTrafficCircularSign(float x, float y, float z, float rotateYAngle) {
	glPushMatrix();
	glRotatef(rotateYAngle, 0, 1, 0);
	glTranslatef(x, y, z);

	drawPole();
	drawCircularSign();
	glPopMatrix();
}

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
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(-1.7, -0.9, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(1.7, -0.9, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(1.7, 0.9, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(-1.7, 0.9, 1.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glColor3f(0.5, 0.5, 0.5); // Màu của cột
	glPushMatrix();
	glTranslatef(0.0, 6.0, -1.0); // Di chuyển cột về phía sau
	glScalef(0.5, 50.0, 0.5); // Kích thước của cột (chiều dài, chiều cao, chiều rộng)
	glutSolidCube(1.0); // Vẽ cột dưới dạng hình hộp
	glPopMatrix();

	glPopMatrix();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawGround();
	drawRoads();

	drawFlag(70, 19, 10);
	drawBanner(30, 2, 120, 270);
	drawHouse1(60, 22.5, 150, 90);

	drawHouse2(20, 22.5, 120, 270);

	drawHouse1(-20, 22.5, 150, 90);

	drawTrafficTriangleSign(25, 0, 100, 0);

	drawTrafficCircularSign(25, 0, 180, 0);

	balloonCart(-10, 20, 160);

	drawDiningSet(80, 2.2, 100);

	drawDiningSet(80, 2.2, 120);
	drawDiningSet(80, 2.2, 140);
	

	drawStand(-10, 8, 130);

	drawTowerBlocks(150, 0, -150);
	drawTowerBlocks(80, 0, -90);

	drawTowerBlocks(150, 0, -90);
	drawTowerBlocks(150, 0, -30);

	drawTowerBlocks(-150, 0, -30);
	drawTowerBlocks(-150, 0, -110);

	drawTowerBlocks(-150, 0, -180);

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


	drawTree(-15, 3.6, 50);
	drawTree(-15, 3.6, -40);
	drawTree(-15, 3.6, 20);
	drawTree(-15, 3.6, -10);
	drawTree(-15, 3.6, -80);
	drawTree(-15, 3.6, -120);
	drawTree(-15, 3.6, -160);


	drawBench(-80, 2.2, 130, 90);
	drawBench(-70, 2.2, 130, 270);

	drawBench(-80, 2.2, 150, 90);
	drawBench(-70, 2.2, 150, 270);


	drawBench(-80, 2.2, 170, 90);
	drawBench(-70, 2.2, 170, 270);
}
