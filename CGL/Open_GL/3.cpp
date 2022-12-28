#include<GL/glut.h>

void mydisplay()
{
   glClear(GL_COLOR_BUFFER_BIT); 
   glLoadIdentity();  //resets modelview matrix
     
   glBegin(GL_QUADS);
    
   glColor3f(1.0,0.5,0.0);
   glVertex2f(50.0,50.0);
   glVertex2f(200.0,50.0);
   glVertex2f(200.0,300.0);
   glVertex2f(100.0,300.0); 
   
  glEnd();
   
   glFlush();
}

void init()
{
  glClearColor(0.0,0.0,0.0,1.0);
}

void reshape(int w, int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();  //resets projection matrix
   gluOrtho2D(-100,100,-100,100);
   //gluOrtho2D(0,500,0,500);
   glMatrixMode(GL_MODELVIEW);  

  
}


int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Triangle");
  glutDisplayFunc(mydisplay);
  glutReshapeFunc(reshape);
  init();
  glutMainLoop();
}


