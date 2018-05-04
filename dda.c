#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

float x1,x2,Y1,Y2;
void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(-800,800,-800,800);
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

void displayCB(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	ddaLineAlgo(-800,0,800,0,1.0,0.0,0.0);
	ddaLineAlgo(0,800,0,-800,1.0,0.0,0.0);
	ddaLineAlgo(x1,Y1,x2,Y2,0.0,0.0,0.0);
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
	scanf("%f%f",&x1,&Y1);
	printf("\nEnter x2, y2:");
	scanf("%f%f",&x2,&Y2);
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
