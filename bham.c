#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int x1,x2,Y1,Y2;
void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(-800,800,-800,800);
}

int sign(int x)
{
	if(x<0)
		return -1;
	else
		return 1;
}

void bham(int x1,int Y1, int x2, int Y2, float r, float g, float b)
{
	int i = 0;
	int x,y,dx,dy,d,temp,flag = 0,stepx,stepy;
	glColor3f(r,g,b);
	dx = (x2-x1);
	dy = (Y2-Y1);
	if(abs(dy)>=abs(dx))
	{
		temp=x1;x1=Y1;Y1=temp;
		temp=x2;x2=Y2;Y2=temp;
		flag = 1;
	}
	dx = (x2 - x1);
	dy = (Y2 - Y1);
	stepx = sign(dx);
	stepy = sign(dy);
	dx = abs(dx);
	dy = abs(dy);
	d = (2*dy) - dx;
	x = x1; y = Y1;
	if(flag)
		glVertex2d(y,x);
	else
		glVertex2d(x,y);
	while(i<abs(dx))
	{
		i++;
		x += stepx;
		if(d<0)
			d = d + (2*dy);
		else
		{
			d = d+2*(dy-dx);
			y += stepy;
		}
		if(flag)
			glVertex2d(y,x);
		else
			glVertex2d(x,y);
	}
}

void displayCB(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	bham(-800,0,800,0,1.0,0.0,0.0);
	bham(0,800,0,-800,1.0,0.0,0.0);
	bham(x1,Y1,x2,Y2,0.0,0.0,0.0);
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
	printf("\nEnter x1, y1:");
	scanf("%d%d",&x1,&Y1);
	printf("\nEnter x2, y2:");
	scanf("%d%d",&x2,&Y2);
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
