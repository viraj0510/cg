//#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<stdlib.h>
using namespace std;

int xc=300,yc=300;

void displayPoint(int x,int y){
   glColor3f(0,1,0);
   glPointSize(2);
   glBegin(GL_POINTS);
   glVertex2i(x,y);
   glEnd();

}

void Simpleline(float x1,float y1,float x2,float y2){
    float step;
    float dx=x2-x1;
    float dy=y2-y1;

    if(abs(dx)>=abs(dy)){
        step=dx;
    }
    else
        step=dy;

    float xincr=dx/step;
    float yincr=dy/step;
    float x=x1;
    float y=y1;
    for(int i=0;i<=step;i++){
        displayPoint(x,y);
        x=x+xincr;
        y=y+yincr;
    }
    glFlush();

}

void plotPoint(int xc,int yc,int x,int y){
  glColor3f(0,1,1);
  glPointSize(2);
  glBegin(GL_POINTS);
  glVertex2i(xc+x,yc+y);
  glVertex2i(xc-x,yc-y);
  glVertex2i(xc+y,yc+x);
  glVertex2i(xc-y,yc-x);
  glVertex2i(xc+y,yc-x);
  glVertex2i(xc-y,yc+x);
  glVertex2i(xc-x,yc+y);
  glVertex2i(xc+x,yc-y);
  glEnd();


}

void bresenhams_circle(int xc,int yc,int radius){
   int x=0;
   int y=radius;
   plotPoint(xc,yc,x,y);
   int p=3-2*radius;
   do{
    if(p<0){
        x++;
        p=p+4*x+6;
    }
    else if(p>=0){
        x++;
        y--;
        p=p+4*(x-y)+10;
    }
    plotPoint(xc,yc,x,y);
   }while(x<=y);
   glFlush();

}


void keyboard(unsigned char key,int x,int y){
  int r=70;
  switch(key){
 case 'b':
    glClearColor(1.0,1.0,1.0,1.0);
     glClear(GL_COLOR_BUFFER_BIT);
     bresenhams_circle(xc,yc,r);
     bresenhams_circle(xc+2*r,yc,r);
     bresenhams_circle(xc,yc+2*r,r);
     bresenhams_circle(xc,yc-2*r,r);
     bresenhams_circle(xc-2*r,yc,r);
     break;

case 'q':
glClearColor(1.0, 1.0, 1.0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);
bresenhams_circle(xc,yc,r);
bresenhams_circle(xc+r+r/1.5,yc,r/1.5);
bresenhams_circle(xc-r-r/1.5,yc,r/1.5);
bresenhams_circle(xc,yc+r+r/1.5,r/1.5);
bresenhams_circle(xc,yc-r-r/1.5,r/1.5);
bresenhams_circle(xc+r+r/5.2,yc+r+r/5.2,r/1.5);
bresenhams_circle(xc+r+r/5.2,yc-r-r/5.2,r/1.5);
bresenhams_circle(xc-r-r/5.2,yc+r+r/5.2,r/1.5);
bresenhams_circle(xc-r-r/5.2,yc-r-r/5.2,r/1.5);
break;



    }
    glutPostRedisplay();

}

void initialise(){
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,600,600,0);

}

void primitives(){
  glColor3f(1,0,0);
  Simpleline(0,300,600,300);
  Simpleline(300,0,300,600);
  glutKeyboardFunc(keyboard);

}

int main(int argc,char** argv){
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE);
   glutInitWindowPosition(0,0);
   glutInitWindowSize(600,600);
   glutCreateWindow("OpenGL-Bresenhams circle drawing algo");
   initialise();
   cout<<"\n-----------------------";
   cout<<"\n b.Four touching circle";
   cout<<"\n q.eight touching circles";
   cout<<"\n----------------------";
   glutDisplayFunc(primitives);
   glutMainLoop();
   return 0;

}
