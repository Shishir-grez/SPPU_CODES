// #include<GL/gl.h>
// #include<GL/glu.h>
#include<GL/glut.h>

void mydisplay() //user-defined function
{
   glClear(GL_COLOR_BUFFER_BIT); 
   glLoadIdentity();                   // modelview matrix, projection matrix
   
   glFlush();
}

void init()   //user-defined function
{
  glClearColor(1.0,0.0,0.0,1.0);
}


int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(100,400);
  glutInitWindowSize(200,500);
  glutCreateWindow("My first Window");
  glutDisplayFunc(mydisplay);
  init();
  glutMainLoop();
}


