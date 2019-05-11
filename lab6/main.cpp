#include<windows.h>
#include<GL/glut.h>
float d=0;
void spin()
{
    d=d+0.05;
    if(d>360)
        d=0;
    glutPostRedisplay();
}
void drawleg(GLfloat x,GLfloat  y,GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();
}
void draw()
{
    GLfloat L[]={1,1,1}, P[]={1,1,-1,0},D1[]={1,0,0};
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,1,3,0,0,0,0,1,0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,L);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,L);
    glLightfv(GL_LIGHT0,GL_POSITION,P);
    glRotatef(d,0,1,0);
    glPushMatrix();
    glScalef(1,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    drawleg(-0.4,-0.5,-0.4);
    drawleg(-0.4,-0.5,0.4);
    drawleg(0.4,-0.5,-0.4);
    drawleg(0.4,-0.5,0.4);
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,D1);
    glTranslatef(0,0.25,0);
    glutSolidTeapot(0.2);
    glPopMatrix();
    glPopAttrib();
    glutSwapBuffers();
}
int main(int C,char *V[])
{
    glutInit(&C,V);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Teapot");
    glMatrixMode(GL_PROJECTION);
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(draw);
    glutIdleFunc(spin);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    return 0;
}
