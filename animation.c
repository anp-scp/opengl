#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

int j = 0;

// function to initialize
void myInit ()
{
	// making background color black as first 
	// 3 arguments all are 0.0
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	// making picture color green (in RGB mode), as middle argument is 1.0
	glColor3f(0.0, 1.0, 0.0);
	
	// breadth of picture boundary is 1 pixel
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	
	// setting window dimension in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

void circle(float adj)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float x, y, p;
	x = 0; y = 100;
	p = (5/4)-y;
	while(x<=y)
	{
		x++;
		if(p<0)
		p = p+(2*x)+1;
		else
		{
			y--;
			p = p+(2*x)-(2*y) +1;
		}
		glVertex2d(x,y+(adj));
		glVertex2d(y,x+(adj));
		glVertex2d(x,-y+(adj));
		glVertex2d(y,-x+(adj));
		glVertex2d(-x,-y+(adj));
		glVertex2d(-y,-x+(adj));
		glVertex2d(-x,y+(adj));
		glVertex2d(-y,x+(adj));
	}
	glEnd();
	glFlush();
}

void display (void) 
{
	int i;
	while(1)
	{
		for(i=320;i>=-320;i-=1)
			circle(i);
		for(i=-320;i<=320;i+=1)
			circle(i);
		if(j == 1)
			break;
	}
}

void keyCB(unsigned char k, int x, int y)
{
	if(k == 'q')
		j=1;
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// giving window size in X- and Y- direction
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	
	// Giving name to window
	glutCreateWindow("Circle Drawing");
	myInit();
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyCB);
	glutMainLoop();
}

