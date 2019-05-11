#include<windows.h>
#include<GL\glut.h>
#include<iostream>
#include<math.h>
float d,rad,xr,yr;
using namespace std;
void draw()
{
    int i;
    GLfloat p[3][2]={{0,0.4},{-0.4,-0.4},{0.4,-0.4}}, np[3][2];
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(p[0]);
    glVertex2fv(p[1]);
    glVertex2fv(p[2]);
    glEnd();
    rad=3.142*d/180;
    for(i=0;i<3;i++)
    {
        np[i][0]=xr+(p[i][0]-xr)*cos(rad)-(p[i][1]-yr)*sin(rad);
        np[i][1]=yr+(p[i][0]-xr)*sin(rad)+(p[i][1]-yr)*cos(rad);
        //np[i][0]=p[i][0]*cos(rad)-p[i][1]*sin(rad)-xr*cos(rad)+yr*sin(rad)+xr;
        //np[i][1]=p[i][0]*sin(rad)+p[i][1]*cos(rad)-xr*sin(rad)-yr*cos(rad)+yr;
    }
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(np[0]);
    glVertex2fv(np[1]);
    glVertex2fv(np[2]);
    glEnd();
    glFlush();
}
int main(int C, char *V[])
{
    cout<<"Enter the degree of rotation: ";
    cin>>d;
    cout<<"Enter the value of xr, yr: ";
    cin>>xr>>yr;
    glutInit(&C,V);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Triangle");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
