#include<windows.h>
#include<GL/glut.h>
#include<math.h>
int AnFlag=0,yFlag=1,xFlag=1;
double yC=-50,xC=-10,x[4],Y1[4],Y2[4],Y3[4];
void mymenu(int id)
{
    switch(id)
    {
    case 1: AnFlag=1;break;
    case 2: AnFlag=0;break;
    case 3: exit(0);
    }
}
void idle()
{
    if(AnFlag==1)
    {
        if(yC<50&&yFlag==1)
            yC+=0.2;
        if(yC>=50&&yFlag==1)
            yFlag=0;
        if(yC>-50&&yFlag==0)
            yC-=0.2;
        if(yC<=-50&&yFlag==0)
            yFlag=1;
        if(xC<20&&xFlag==1)
            xC+=0.2;
        if(xC>=20&&xFlag==1)
            xFlag=0;
        if(xC>-20&&xFlag==0)
            xC-=0.2;
        if(xC<=-20&&xFlag==0)
            xFlag=1;
    }
    glutPostRedisplay();
}
void Draw()
{
    int i=0;
    double t,xt[200],Y1t[200],Y2t[200],Y3t[200];
    glClear(GL_COLOR_BUFFER_BIT);
    x[0]=300-xC;x[1]=200;x[2]=200;x[3]=100;
    Y1[0]=450;Y1[1]=450+yC;Y1[2]=450-yC;Y1[3]=450;
    Y2[0]=400;Y2[1]=400+yC;Y2[2]=400-yC;Y2[3]=400;
    Y3[0]=350;Y3[1]=350+yC;Y3[2]=350-yC;Y3[3]=350;
    for(t=0.0;t<1.0;t+=0.005)
    {
        xt[i]=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        Y1t[i]=pow(1-t,3)*Y1[0]+3*t*pow(1-t,2)*Y1[1]+3*pow(t,2)*(1-t)*Y1[2]+pow(t,3)*Y1[3];
        Y2t[i]=pow(1-t,3)*Y2[0]+3*t*pow(1-t,2)*Y2[1]+3*pow(t,2)*(1-t)*Y2[2]+pow(t,3)*Y2[3];
        Y3t[i]=pow(1-t,3)*Y3[0]+3*t*pow(1-t,2)*Y3[1]+3*pow(t,2)*(1-t)*Y3[2]+pow(t,3)*Y3[3];
        i++;
    }
    glColor3f(1,1,0);
    glBegin(GL_QUAD_STRIP);
    for(i=0;i<200;i++)
    {
        glVertex2d(xt[i],Y1t[i]);
        glVertex2d(xt[i],Y2t[i]);
    }
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_QUAD_STRIP);
    for(i=0;i<200;i++)
    {
        glVertex2d(xt[i],Y2t[i]);
        glVertex2d(xt[i],Y3t[i]);
    }
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glRectf(85,460,100,0);
    glFlush();
}
void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Flag");
	MyInit();
	glutDisplayFunc(Draw);
	glutCreateMenu(mymenu);
	glutIdleFunc(idle);
	glutAddMenuEntry("Animate",1);
	glutAddMenuEntry("Stop",2);
	glutAddMenuEntry("Exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
