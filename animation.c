#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

int yinc=0;
int rad=0;
int i=1;

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

void Timer(int ex){
   glutPostRedisplay();
   glutTimerFunc(1,Timer,10);
}

void circle(float adj,float extra_r)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float x, y, p;
	x = 0; y = 100+extra_r;
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
	glutSwapBuffers();
}

void keyCB(unsigned char k, int x, int y)
{
	if(k == 'q')
		exit(0);
}

void display (void) 
{
	circle(yinc,rad);
	if(yinc == 320)
		i=-1;
	else if(yinc == -320)
		i=1;
	yinc+=i;
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);// giving window size in X- and Y- direction
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Circle Drawing");// Giving name to window
	myInit();
	glutDisplayFunc(display);
	glutTimerFunc(0,Timer,0);
	glutKeyboardFunc(keyCB);
	glutMainLoop();
}
