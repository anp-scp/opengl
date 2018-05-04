#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

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

void ddaLineAlgo(int x1, int Y1, int x2, int Y2, float r, float g, float b)
{
	int i;
	float x,y,dx,dy,step,xinc,yinc;
	glColor3f(r,g,b);
	dx = (x2-x1);
	dy = (Y2-Y1);
	if(abs(dx) > abs(dy))
		step = abs(dx);
	else 
		step = abs(dy);
	xinc = dx/step;
	yinc = dy/step;
	i = 1; x = x1; y = Y1;
	while(i<=step)
	{
		glVertex2d(round(x),round(y));
		i++;
		x += xinc;
		y += yinc;
	}
	glVertex2d(round(x),round(y));
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
	}
}

void keyCB(unsigned char k, int x, int y)
{
	if(k == 'q')
		exit(0);
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

