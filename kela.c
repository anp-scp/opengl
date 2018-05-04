#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>

typedef struct pixel{ GLubyte red, green, blue; } pixel;



void boundaryfill4Conn(float x, float y, pixel fill, pixel boundary){
  pixel c;
  glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
  printf("\n%d %d %d",c.red,c.green,c.blue);
  if ((c.red!=boundary.red && c.red!=boundary.blue && c.green!=boundary.green) && (c.green!=fill.red && c.blue!=fill.blue && c.red!=fill.green)) {

      glBegin(GL_POINTS);
         glColor3ub(fill.red, fill.green, fill.blue);
         glVertex2f(x,y);
      glEnd();
      glFlush();
      
      glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);            
          
      // 4-connected recurssive call
      boundaryfill4Conn(x+1,y,fill,boundary);                                           
      boundaryfill4Conn(x-1,y,fill,boundary);
      boundaryfill4Conn(x,y+1,fill,boundary);      
      boundaryfill4Conn(x, y-1,fill,boundary);


      //*
      // use for 8-connected 
      boundaryfill4Conn(x+1,y+1,fill,boundary);      
      boundaryfill4Conn(x-1, y-1,fill,boundary);
      boundaryfill4Conn(x+1,y-1,fill,boundary);                                           
      boundaryfill4Conn(x-1,y-1,fill,boundary);
      //*/

    }
}

void boundaryFill4Conn(){

      // polygon
      glBegin(GL_POLYGON);
         glColor3ub(10,10,10);
         glVertex2f(0,0);
         glVertex2f(150,0);
         glVertex2f(150,150);
         glVertex2f(0,150);
      glEnd();
      
      //*
      // use for 8-connected
      glBegin(GL_POLYGON);
         glColor3ub(10,10,10);
         glVertex2f(150,150);
         glVertex2f(150,200);
         glVertex2f(200,200);
         glVertex2f(200,150);
      glEnd();
      //*/

      glFlush();

      pixel fill, boundary;

      fill.red=255;
      fill.green=0;
      fill.blue=0;

      boundary.red=0;
      boundary.green=0;
      boundary.blue=0;

      boundaryfill4Conn(100,100,fill, boundary);

      glEnd();
      glFlush();
}

void main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400,400);
  glutInitWindowPosition(540,320);
  glutCreateWindow("Four Connected Boundary Filling:");
  glClearColor(1.0f,1.0f,1.0,0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(boundaryFill4Conn);

  gluOrtho2D(0.0,400.0,0.0,400.0);
  glutMainLoop();


}
