// lab2-NgoAnBinh.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <math.h>

#define PI 3.14159265

char title[] = "Bouncing Ball 2D";

int WindowWidth = 640;
int WindowHeight = 480;
int WindowPosX = 50;
int WindowPosY = 50;

GLfloat ballRadius = 0.2f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.070f;
int refreshMillis = 30;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(ballX, ballY, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	int numSegments = 100;
	GLfloat angle;
	for ( int i = 0; i <= numSegments; i++)
	{
		angle = i*2.0f * PI / numSegments;
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();
	glutSwapBuffers();
	ballX += xSpeed;
	ballY += ySpeed;
	if (ballX > ballXMax)
	{
		ballX = ballXMax;
		xSpeed = -xSpeed;
	}
	else if (ballX < ballXMin)
	{
		ballX = ballXMin;
		xSpeed = -xSpeed;
	}
	if (ballY > ballYMax)
	{
		ballY = ballYMax;
		ySpeed = -ySpeed;
	}
	else if (ballY < ballYMin)
	{
		ballY = ballYMin;
		ySpeed = -ySpeed;
	}
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) 
	{
		height = 1;
	}
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
	{
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else
	{
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXRight, clipAreaXLeft,  clipAreaYBottom, clipAreaYTop);
	ballXMin = clipAreaXLeft + ballRadius;
	ballXMax = clipAreaXRight - ballRadius;
	ballYMin = clipAreaYBottom + ballRadius;
	ballYMax = clipAreaYTop - ballRadius;
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition(WindowPosX, WindowPosY);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, Timer, 0);
	initGL();
	glutMainLoop();
	return 0;
}