#include "glut.h"
#include <math.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const int nt = 60;
const int ntheta = 20;
double PI = 3.14159265389;

static GLfloat colors[4][6] =
{
	{1,0,0, 0.5,0,0}, //red
	{0,1,0, 0,0.5,0}, //green
	{0,0,1, 0,0,0.5}, //blue
	{1,1,0, 0.5,0.5,0} //yellow
};

static GLfloat v_cube[8][3] =
{
	{0.0, 0.0, 0.0}, //0
	{0.0, 0.0, 3.0}, //1
	{3.0, 0.0, 3.0}, //2
	{3.0, 0.0, 0.0}, //3
	{0.0, 3.0, 0.0}, //4
	{0.0, 3.0, 3.0}, //5
	{3.0, 3.0, 3.0}, //6
	{3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
	{0, 1, 2, 3}, //bottom
	{4, 5, 6, 7}, //top
	{5, 1, 2, 6}, //front
	{0, 4, 7, 3}, // back is clockwise
	{2, 3, 7, 6}, //right
	{1, 5, 4, 0}  //left is clockwise
};

static GLfloat v_trapezoid[8][3] =
{
	{0.0, 0.0, 0.0}, //0
	{0.0, 0.0, 3.0}, //1
	{3.0, 0.0, 3.0}, //2
	{3.0, 0.0, 0.0}, //3
	{0.5, 3.0, 0.5}, //4
	{0.5, 3.0, 2.5}, //5
	{2.5, 3.0, 2.5}, //6
	{2.5, 3.0, 0.5}  //7
};

static GLubyte TquadIndices[6][4] =
{
	{0, 1, 2, 3}, //bottom
	{4, 5, 6, 7}, //top
	{5, 1, 2, 6}, //front
	{0, 4, 7, 3}, // back is clockwise
	{2, 3, 7, 6}, //right
	{1, 5, 4, 0}  //left is clockwise
};


static void getNormal3p
(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
	GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

	Ux = x2 - x1;
	Uy = y2 - y1;
	Uz = z2 - z1;

	Vx = x3 - x1;
	Vy = y3 - y1;
	Vz = z3 - z1;

	Nx = Uy * Vz - Uz * Vy;
	Ny = Uz * Vx - Ux * Vz;
	Nz = Ux * Vy - Uy * Vx;

	glNormal3f(Nx, Ny, Nz);
}

void setNormal(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
	GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

	Ux = x2 - x1;
	Uy = y2 - y1;
	Uz = z2 - z1;

	Vx = x3 - x1;
	Vy = y3 - y1;
	Vz = z3 - z1;

	Nx = Uy * Vz - Uz * Vy;
	Ny = Uz * Vx - Ux * Vz;
	Nz = Ux * Vy - Uy * Vx;

	glNormal3f(-Nx, -Ny, -Nz);
}

void drawCube(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX = 0, GLfloat ambY = 0, GLfloat ambZ = 0, GLfloat shine = 50)
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
	GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { shine };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glBegin(GL_QUADS);

	for (GLint i = 0; i < 6; i++)
	{
		getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
			v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
			v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
		glVertex3fv(&v_cube[quadIndices[i][0]][0]);
		glVertex3fv(&v_cube[quadIndices[i][1]][0]);
		glVertex3fv(&v_cube[quadIndices[i][2]][0]);
		glVertex3fv(&v_cube[quadIndices[i][3]][0]);
	}
	glEnd();
}

void drawSphere(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90)
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
	GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { shine };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16, 16);
}

void drawTorus(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings, GLfloat shine = 90)
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
	GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { shine };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glutSolidTorus(innerRadius, outerRadius, nsides, rings);
}

void drawCylinder(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90)
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
	GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { shine };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 1.5, 1.5, 19, 32, 32);

}

void matCurve(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambfactor = 1.0, GLfloat specfactor = 1.0, GLfloat shine = 50)
{
	glColor3f(1, 1, 1);
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { difX * ambfactor, difY * ambfactor, difZ * ambfactor, 1.0 };
	GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 60 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}

long long nCr(int n, int r)
{
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++)
	{
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


void drawBezierCurve(double t, float xy[2], int L, GLfloat ctrlpoints[][3])
{
	double y = 0;
	double x = 0;
	t = t > 1.0 ? 1.0 : t;
	for (int i = 0; i <= L; i++)
	{
		int ncr = nCr(L, i);
		double oneMinusTpow = pow(1 - t, double(L - i));
		double tPow = pow(t, double(i));
		double coef = oneMinusTpow * tPow * ncr;
		x += coef * ctrlpoints[i][0];
		y += coef * ctrlpoints[i][1];

	}
	xy[0] = float(x);
	xy[1] = float(y);
}

void generateMipmaps(GLuint textureID, int width, int height) {
	glBindTexture(GL_TEXTURE_2D, textureID);
	int levels = 1 + static_cast<int>(std::floor(std::log2(std::max(width, height))));
	for (int level = 1; level < levels; ++level) {
		width = std::max(1, width / 2);
		height = std::max(1, height / 2);
		glTexImage2D(GL_TEXTURE_2D, level, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
	}
}

GLuint loadTexture(const char* filename) {
	GLuint textureID;
	int width, height, channels;
	unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
	if (!image) {
		printf("Failed to load texture: %s\n", filename);
		return -1;
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	generateMipmaps(textureID, width, height);
	stbi_image_free(image);
	return textureID;
}

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
	float x, y, z, r;
	float x1, y1, z1, r1;
	float theta;

	const float startx = 0, endx = balloonctrlpoints[L][0];
	const float dx = (endx - startx) / nt;
	const float dtheta = 2 * PI / ntheta;

	float t = 0;
	float dt = 1.0 / nt;
	float xy[2];
	drawBezierCurve(t, xy, 5, balloonctrlpoints);
	x = xy[0];
	r = xy[1];
	float p1x, p1y, p1z, p2x, p2y, p2z;
	for (i = 0; i < nt; ++i)
	{
		theta = 0;
		t += dt;
		drawBezierCurve(t, xy, 5, balloonctrlpoints);
		x1 = xy[0];
		r1 = xy[1];
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= ntheta; ++j)
		{
			theta += dtheta;
			double cosa = cos(theta);
			double sina = sin(theta);
			y = r * cosa;
			y1 = r1 * cosa;
			z = r * sina;
			z1 = r1 * sina;
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
		}
		glEnd();
		x = x1;
		r = r1;
	}
}
