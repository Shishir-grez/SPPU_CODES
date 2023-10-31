#include<GL/glut.h>

void mydisplay()
{
   glClear(GL_COLOR_BUFFER_BIT); 
   glLoadIdentity();  //resets modelview matrix
   
   glBegin(GL_TRIANGLES);
     glColor3f(1.0,0.0,0.0);
    glVertex2f(-3.0,-3.0);
     glVertex2f(-2.0,-2.0);
     glVertex2f(-4.0,-2.0); 
     
  /* glColor3f(0.0,0.5,1.0);
   glVertex2f(-50.0,-20.0);
    glVertex2f(30.0,60.0);
     glVertex2f(80.0,90.0);
     
   glColor3f(0.0,1.0,0.0);
     glVertex2f(-50.0,-20.0); 
     glVertex2f(-20.0,-30.0); 
     glVertex2f(-50.0,-70.0);*/
     
      
     
 glEnd();
   
  glFlush();
}

void init()
{
  glClearColor(0.0,0.0,0.0,1.0);
}

void reshape(int w, int h)  //user-defined function
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION); // projection sets the model within viewport dimensions
   glLoadIdentity();  //resets projection matrix
   gluOrtho2D(-10,0,-10,0); // orthographic projection is the way to setup 3d enviornment on 2d screen
   glMatrixMode(GL_MODELVIEW);   // places the viewer at origin with the view direction aligned with the negative Z axis 
}



int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(500,500);
  glutCreateWindow("Triangle");
  glutDisplayFunc(mydisplay);
  glutReshapeFunc(reshape);
  init();
  glutMainLoop();
}
  

