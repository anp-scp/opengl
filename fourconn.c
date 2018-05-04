#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<stdlib.h>

typedef struct pixel
{
	GLubyte red,green,blue;
} pixel;

void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3ub(0,0,0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780,780,-420,420);
}

void fill4conn(int x, int y, pixel fill, pixel old)
{
	pixel c;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
	printf("\n%d %d %d",c.red,c.green,c.blue);
	if(0)
	{
		glBegin(GL_POINTS);
		glColor3ub(fill.red,fill.green,fill.blue);
		glVertex2f(x,y);
		glEnd();
		glFlush();
		
		glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);
		printf("\n%d %d",x,y);
		fill4conn(x+1,y,fill,old);
		fill4conn(x,y+1,fill,old);
		fill4conn(x-1,y,fill,old);
		fill4conn(x,y-1,fill,old);
	}
}

void displayCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3ub(10,10,10);
	glVertex2f(0,0);
	glVertex2f(150,0);
	glVertex2f(150,150);
	glVertex2f(0,150);
	glEnd();
	glFlush();
	
	pixel fill,old;
	fill.red = 255;
	fill.green = 0;
	fill.blue = 0;
	
	old.red = 255;
	old.green = 255;
	old.blue = 255;
	
	fill4conn(400,400,fill,old);
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366,780);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello");
	myInit();
	glutDisplayFunc(displayCB);
	glutMainLoop();
}
