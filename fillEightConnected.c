#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<stdlib.h>

typedef struct pixel
{
	GLfloat r,g,b;
} pixel;

void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,400,0,400);
}

void fill4conn(int x, int y, pixel fill, pixel old)
{
	pixel c;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
	//printf("\n%f %f %f",c.r,c.g,c.b);
	if((c.r==old.r && c.g==old.g && c.r==old.b))
	{
		glBegin(GL_POINTS);
		glColor3f(fill.r,fill.g,fill.b);
		glVertex2f(x,y);
		glEnd();
		glFlush();
		printf("\n%d %d",x,y);
		fill4conn(x+1,y,fill,old);
		fill4conn(x,y+1,fill,old);
		fill4conn(x-1,y,fill,old);
		fill4conn(x,y-1,fill,old);
		fill4conn(x+1,y+1,fill,old);      
		fill4conn(x-1, y-1,fill,old);
	        fill4conn(x+1,y-1,fill,old);                                           
        	fill4conn(x-1,y-1,fill,old);
	}
}

void displayCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0,10);
	glVertex2f(150,10);
	glVertex2f(150,150);
	glVertex2f(150,200);
	glVertex2f(200,200);
	glVertex2f(200,150);
	glVertex2f(0,150);
	glEnd();
	glFlush();
	
	pixel fill,old;
	fill.r = 1.0;
	fill.g = 0.0;
	fill.b = 0.0;
	
	old.r = 0.0;
	old.g = 1.0;
	old.b = 0.0;
	
	fill4conn(50,50,fill,old);
	
	glEnd();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(540,0);
	glutCreateWindow("Hello");
	myInit();
	glutDisplayFunc(displayCB);
	glutMainLoop();
}
