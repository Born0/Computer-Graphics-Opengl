#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

bool night=true;
char carnival[]="CARNIVAL";

void line(double a1,double b1,double a2,double b2) // to draw line
{
    glBegin(GL_LINES);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glEnd();

}
void triangle(double a1,double b1,double a2,double b2,double a3,double b3) // to draw triangle
{
    glBegin(GL_TRIANGLES);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glVertex2f(a3,b3);
    glEnd();
}
void quad(double a1,double b1,double a2,double b2,double a3,double b3,double a4,double b4) // to draw quad
{
    glBegin(GL_QUADS);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glVertex2f(a3,b3);
    glVertex2f(a4,b4);
    glEnd();
}

void printText( float x, float y, char *st) // to print string
{
    int l,i;
    l=strlen( st );
    glColor3ub(230,196,38);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);
    }
}

void circle(GLfloat x, GLfloat y, GLfloat radius) // to draw circle
  {
    int i;
    float angle;
    glBegin(GL_POLYGON);
    for(i=0;i<100;i++)
    {
        angle = i*2*(M_PI/100);
        glVertex2f(x+(sin(angle)*radius),y+(cos(angle)*radius));
    }
    glEnd();
  }
void backGround()
{
    //---------------------------------------------SKY
    if(!  night){glColor3ub(100, 160, 210);}
    else{ glColor3ub(13, 42, 67);}
    quad( -1,-1,1,-1 ,1,1 ,-1,1 );

    //----------------------------------green ->back
    glColor3ub(4,88,0);
    triangle( .2,-.1,1,-.1 ,.6,.35 );

    //----------------------------------green ->front
    glColor3ub(83, 112, 46);
    glBegin(GL_POLYGON);
    glVertex2f(-.8,0);
    glVertex2f(-1,0);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,0);
    glVertex2f(.4,0);
    glVertex2f(-.3,.35);
    glEnd();

}

void tent()
{
    //----------------------------------------------- Large
    glColor3ub (230, 0, 5);
    quad(0.193, 0.051,0.193, -0.076,.421, -.076,.421, .051);


    glColor3ub (230, 0, 5);
    triangle(0.152, 0.051,0.46, 0.051,.309, 0.18 );


    glPushMatrix();//large wall strip->right
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052   );
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.031,0,0);
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052 );
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.031-0.031,0,0);
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052 );
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.031-0.031-0.031,0,0);
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052 );
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.031-0.031-0.031-0.031,0,0);
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052 );
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.031-0.031-0.031-0.031-0.031,0,0);
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052 );
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.031-0.031-0.031-0.031-0.031-0.031,0,0);
    glColor3ub (255, 255, 255);
    quad( 0.392, 0.052,0.392, -0.076,.408, -.076,.408, .052 );
    glPopMatrix();

    glColor3ub (0, 0, 0);
    line( 0.152,.051,0.46, 0.051 );

    glColor3ub (255, 255, 255);//roof strip->right
    triangle( 0.384, 0.051,0.422, 0.051 , .309, 0.18);

    glColor3ub (255, 255, 255);
    triangle(0.322, 0.051 ,0.345, 0.051 ,.309, 0.18 );

    glColor3ub (255, 255, 255);
    triangle(0.27, 0.051 ,0.294, 0.051 , .309, 0.18);

    glColor3ub (255, 255, 255);
    triangle( 0.197, 0.051, 0.234, 0.051 ,.309, 0.18 );

    glColor3ub (5, 0, 245);//tent gate
    triangle( 0.277, -0.076,0.34, -0.076 ,.3085, 0.0228 );

}

void gate()
{
    glTranslated(-.012,.025,0);
    //--------------------------left
    glPushMatrix();
    glScaled(1,2,1);
    glColor3ub(230,196,38);
    quad( -.415, -.37,-.402, -.37 ,-.402, -.293 ,-.415, -.293 );
    quad( -.390, -.37,-.373, -.37 ,-.373, -.316 ,-.390, -.316 );
    quad( -.360, -.37, -.334, -.37,-.334, -.138 , -.360, -.138);
    quad( -.407, -.31, -.355, -.32,-.355, -.31 ,-.407, -.32 );
    glPopMatrix();

    //-------------------------right
    glPushMatrix();
    glScaled(1,2,1);
    glRotated(180,0,1,0);
    glTranslated(.25,0,0);
    glColor3ub(230,196,38);
    quad( -.415, -.37,-.402, -.37 ,-.402, -.293 ,-.415, -.293 );
    quad( -.390, -.37,-.373, -.37 ,-.373, -.316 ,-.390, -.316 );
    quad( -.360, -.37,-.334, -.37 ,-.334, -.138 ,-.360, -.138 );
    quad( -.407, -.31,-.355, -.32 ,-.355, -.31 ,-.407, -.32 );
    glPopMatrix();

    //-------------------------frame
    quad( -.345, -.37,.1, -.37 ,.1, -.2 ,-.345, -.2 );
    glColor3ub(0,140,190);
    quad( -.345, -.37, .1, -.37,.1, -.2 ,-.345, -.2 );

    glPushMatrix();
    printText(-.165, -.3,carnival);
    glPopMatrix();

}

void character()
{
    //---------------------------------------head
    glColor3ub(250,220,190);//face
    glBegin(GL_POLYGON);
    glVertex2f(.8435,-.0941);
    glVertex2f(.8789,-.081);
    glVertex2f(.888,-.0);
    glVertex2f(.808,-.0);
    glVertex2f(.808,-.081);
    glEnd();

    glColor3ub(240,240,240);// cap
    quad( .888,-.01,.808,-.01 ,.82,.05 ,.883,.05 );

    glColor3ub(0,0,0);//eye->left
    circle(.8577,-.0426,.005);
    line(.8477,-.0374,.8707,-.0312);

    glPushMatrix();//eye->right
    glRotated(180,0,1,0);
    glTranslated(-1.68,0,0);
    glColor3ub(0,0,0);
    circle(.8577,-.0426,.005);
    line(.8477,-.0374,.8707,-.0312);
    glPopMatrix();

    line(.839,-.045,.839,-.0686);//nose

    line(.83,-.077,.84,-.08);//mouth
    line(.84,-.08,.85,-.077);

    glColor3ub(240,240,240);//body
    glBegin(GL_POLYGON);
    glVertex2f(.824,-.0941);
    glVertex2f(0.816,-.1073);
    glVertex2f(.8067,-.3);
    glVertex2f(.8947,-.3);
    glVertex2f(.878,-.10006);
    glEnd();

    glColor3ub(25,60,80);// left hand
    line(.87,-.145,.81,-.145);
    line(.87,-.17,.81,-.17);
    glColor3ub(250,220,190);
    quad(.79,-.145,.79,-.17,.81,-.17,.81,-.145);
    glColor3ub(240,240,240);
    quad(.81,-.145,.81,-.17,.87,-.17,.87,-.145);

    glPushMatrix();
    glTranslated(-.02,.03,0);
    glColor3ub(25,60,80);//right hand
    line(.87,-.145,.81,-.145);
    line(.87,-.17,.81,-.17);
    glColor3ub(250,220,190);
    quad(.79,-.145,.79,-.17,.81,-.17,.81,-.145);
    glColor3ub(240,240,240);
    quad(.81,-.145,.81,-.17,.87,-.17,.87,-.145);
    glPopMatrix();

    glColor3ub(25,60,80);//leg
    quad(.83,-.3,.83,-.37,.85,-.37,.85,-.3);
    quad(.86,-.3,.86,-.37,.88,-.37,.88,-.3);

    glColor3ub(240,240,240);//shoe
    quad(.825,-.34,.825,-.37,.85,-.37,.85,-.34);
    quad(.855,-.34,.855,-.37,.88,-.37,.88,-.34);

}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

    backGround();
    tent();
    //----------------------------------------Small Left
    glPushMatrix();
    glScaled(0.33,1,1);
    glTranslated(.149,-.15,0);
    tent();
    glPopMatrix();
    //---------------------------------------Small right
    glPushMatrix();
    glScaled(0.33,1,1);
    glTranslated(1.13,-.15,0);
    tent();
    glPopMatrix();
    //---------------------------------------gate
    gate();
    //--------------------------------------character right
    character();
    //--------------------------------------character left
    glPushMatrix();
    glRotated(180,0,1,0);
    glTranslated(-1.6,0,0);
    character();
    glPopMatrix();


   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1800, 900);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Carnival");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
