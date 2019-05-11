#include<windows.h>
#include<GL/glut.h>
void cube(void)
{
glutWireTeapot(2);
}
void display(void)
{
glClearColor(0.0,0.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
cube();
glFlush();
}
void reshape(int w,int h)
{
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,100.0);
glMatrixMode(GL_MODELVIEW);
}
int main(int agrc,char**agrv)
{
glutInit(&agrc,agrv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("A basic OpenGL Window");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
