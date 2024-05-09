#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<stdlib.h>
using namespace std;

void displayPoint(int x,int y){
     glColor3f(0,1,0);
     glPointSize(2);
     glBegin(GL_POINTS);
     glVertex2i(x,y);
     glEnd();
}
float x01,x2,y01,y2;
int ch;
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

void Dottedline(float x1,float y1,float x2,float y2){
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
    displayPoint(x,y);
    for(int i=0;i<=step;i++){
            if(i%4==0){
        displayPoint(x,y);
            }
        x=x+xincr;
        y=y+yincr;
    }
    glFlush();


}

void myMouse(int button,int state,int x,int y){
  static int xst,yst,pt=0;
  if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
    if(pt==0){
        xst=x;
        yst=y;
        x01=xst;
        y01=yst;
        pt=pt+1;
    }
    else{
        x2=x;
        y2=y;
        if(ch==1){
            Simpleline(xst,yst,x,y);
        }
        else if(ch==2){
            Dottedline(xst,yst,x,y);
        }
        xst=x;
        yst=y;
    }
  }

    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        pt=0;
    }

 glFlush();

  }




void keyboard(unsigned char key,int x,int y){
  switch(key){
  case 's':
    ch=1;
    glutMouseFunc(myMouse);
    break;

  case 'd':
     ch=2;
     glutMouseFunc(myMouse);
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
   glutCreateWindow("OpenGL-DDA algo");
   initialise();
   cout<<"\n-----------------------";
   cout<<"\n s.Simple line";
   cout<<"\n d.Dotted line";
   cout<<"\n----------------------";
   glutDisplayFunc(primitives);
   glutMainLoop();
   return 0;

}
