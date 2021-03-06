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

void circle(float adjx, float adj)
{
	float x, y, p;
	x = 0; y = 100;
	p = (5/4)-y;
	glVertex2d(x+(adjx),y+(adj));
		glVertex2d(y+(adjx),x+(adj));
		glVertex2d(x+(adjx),-y+(adj));
		glVertex2d(y+(adjx),-x+(adj));
		glVertex2d(-x+(adjx),-y+(adj));
		glVertex2d(-y+(adjx),-x+(adj));
		glVertex2d(-x+(adjx),y+(adj));
		glVertex2d(-y+(adjx),x+(adj));
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
		glVertex2d(x+(adjx),y+(adj));
		glVertex2d(y+(adjx),x+(adj));
		glVertex2d(x+(adjx),-y+(adj));
		glVertex2d(y+(adjx),-x+(adj));
		glVertex2d(-x+(adjx),-y+(adj));
		glVertex2d(-y+(adjx),-x+(adj));
		glVertex2d(-x+(adjx),y+(adj));
		glVertex2d(-y+(adjx),x+(adj));
	}
}

void fill4conn(int x, int y, pixel fill, pixel old)
{
	pixel c;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
	//printf("\n%f %f %f",c.r,c.g,c.b);
	if((c.r==old.r && c.g==old.g && c.b==old.b))
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
	}
}

void displayCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0,10);
	glVertex2f(150,10);
	glVertex2f(150,150);
	glVertex2f(0,150);*/
	glBegin(GL_POINTS);
	circle(150,150);
	glEnd();
	glFlush();
	
	pixel fill,old;
	fill.r = 1.0;
	fill.g = 0.0;
	fill.b = 0.0;
	
	old.r = 1.0;
	old.g = 1.0;
	old.b = 1.0;
	
	fill4conn(100,100,fill,old);
	
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
