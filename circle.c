#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int x,y;
void Init()
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
	gluOrtho2D(-800, 800, -800, 800);
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

void circle()
{
	float p;
	p = (5/4)-y;
	//glColor3f(1.0,0.0,0.0);
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
		printf("\n%d %d",x,y);
		glVertex2d(round(x),round(y));
		glVertex2d(y,x);
		glVertex2d(x,-y);
		glVertex2d(y,-x);
		glVertex2d(-x,-y);
		glVertex2d(-y,-x);
		glVertex2d(-x,y);
		glVertex2d(-y,x);
	}
}

void displayCB(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	ddaLineAlgo(-800,0,800,0,1.0,0.0,0.0);
	circle();
	glEnd();
	glFlush();	
}

void keyCB(unsigned char key, int x,int y)
{
	if(key == 'q')
		exit(0);
}

void main(int argc, char **argv)
{
	printf("\nEnter x, r:");
	scanf("%d%d",&x,&y);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow("DDA Line");
	Init();
	glutDisplayFunc(displayCB);
	glutKeyboardFunc(keyCB);
	glutMainLoop();
}
