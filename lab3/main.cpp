#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
float V[8][3]= {{0,0,0},{0.5,0,0},{0.5,0.5,0},{0,0.5,0},{0,0,0.5},{0.5,0,0.5},{0.5,0.5,0.5},{0,0.5,0.5}};
float NV[8][3];
float d=0,r;
char ax;
void spin()
{
    d=d+0.05;
    if(d>360)
        d=0;
    glutPostRedisplay();
}
void drawface(int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
    glVertex3fv(NV[a]);
    glVertex3fv(NV[b]);
    glVertex3fv(NV[c]);
    glVertex3fv(NV[d]);
    glEnd();
}
void draw()
{
    int i;
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    r=d*3.142/180;
    if(ax=='x')
        for(i=0;i<8;i++)
        {
            NV[i][0]=V[i][0];
            NV[i][1]=V[i][1]*cos(r)-V[i][2]*sin(r);
            NV[i][2]=V[i][1]*sin(r)+V[i][2]*cos(r);
        }
    if(ax=='y')
        for(i=0;i<8;i++)
        {
            NV[i][0]=V[i][0]*cos(r)-V[i][2]*sin(r);
            NV[i][1]=V[i][1];
            NV[i][2]=V[i][0]*sin(r)+V[i][2]*cos(r);
        }
    if(ax=='z')
        for(i=0;i<8;i++)
        {
            NV[i][0]=V[i][0]*cos(r)-V[i][1]*sin(r);
            NV[i][1]=V[i][0]*sin(r)+V[i][1]*cos(r);
            NV[i][2]=V[i][2];
        }
    glColor3f(1,0,0);
    drawface(7,6,5,4);
    glColor3f(0,1,0);
    drawface(6,2,1,5);
    glColor3f(0,0,1);
    drawface(0,3,2,1);
    glColor3f(1,0,1);
    drawface(4,7,3,0);
    glColor3f(0,1,1);
    drawface(7,3,2,6);
    glColor3f(1,1,0);
    drawface(4,0,1,5);
    glutSwapBuffers();
}
int main(int C,char *V[])
{
    cout<<"Enter the axis: ";
    cin>>ax;
    glutInit(&C,V);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Colored Cube");
    glutDisplayFunc(draw);
    glutIdleFunc(spin);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
