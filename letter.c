#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<GL/glut.h>

float P[3][5] = {
		{0,150,300,75,225},
		{0,300,0,150,150},
		{1,1,1,1,1}
	      };

float T[3][3] = {
		{-1,0,0},
		{0,1,0},
		{0,0,1}
	      };

float R[3][5];
      
void matMult()
{
	int i,j,k,sum=0;
	for(i = 0; i < 3;i++)
	{
		for(j = 0;j<5;j++)
		{
			for(k=0;k<3;k++)
			{
				sum = sum + T[i][k]*P[k][j];
			}
			R[i][j] = sum;
			sum = 0;
		}
	}
	glVertex2d(R[0][0],R[1][0]);
	glVertex2d(R[0][1],R[1][1]);
	glVertex2d(R[0][1],R[1][1]);
	glVertex2d(R[0][2],R[1][2]);
	glVertex2d(R[0][3],R[1][3]);
	glVertex2d(R[0][4],R[1][4]);
	
}		      

void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(0.0,1.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780,780,-420,420);
}

void displayCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2d(-780,0);
	glVertex2d(780,0);
	glVertex2d(0,420);
	glVertex2d(0,-420);
	glVertex2d(P[0][0],P[1][0]);
	glVertex2d(P[0][1],P[1][1]);
	glVertex2d(P[0][1],P[1][1]);
	glVertex2d(P[0][2],P[1][2]);
	glVertex2d(P[0][3],P[1][3]);
	glVertex2d(P[0][4],P[1][4]);
	matMult();
	glEnd();
	glFlush();
}

void keyCB(unsigned char k, int x, int y)
{
	if(k == 'q')
		exit(0);
}

void main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366,780);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Letter");
	myInit();
	glutDisplayFunc(displayCB);
	glutKeyboardFunc(keyCB);
	glutMainLoop();
}

