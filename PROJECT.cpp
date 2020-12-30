#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
using namespace std;

float anglel_M = 0.0f;
float anglel_N = 0.0f;
GLfloat speed_M= 0.0f;
GLfloat speed_N = 0.0f;


void quad(double a1,double b1,double a2,double b2,double a3,double b3,double a4,double b4) // to draw quad
{
    glBegin(GL_QUADS);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glVertex2f(a3,b3);
    glVertex2f(a4,b4);
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
void update(int value)
{
//FOR MARRY GO ROUND
anglel_M+= speed_M;
if (anglel_M>360)
{
    anglel_M-=360;
}
//FOR BOAT
anglel_N+=speed_N;
if (anglel_N> 10)
{
    speed_N = -0.5;
}
else if(anglel_N<-10)
{
    speed_N=+0.5;
}

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void keyboardHandle(unsigned char key, int x, int y) {

   switch (key) {
      case 'm':
        anglel_M += speed_M;
        speed_M+=0.75;
        update(0);
        break;
      case 'M':
        speed_M=0.0;
        break;
      case 'n':
        speed_N+=0.4;
        update(0);
        break;
      case 'N':
          speed_N = 0.0;
          break;
      case 'e':
         exit(0);
         break;
   }
}
void drawScene() {
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glPushMatrix();
//BOAT
glTranslatef(-0.4363f,0.0185f, 0.0f);
glRotatef(anglel_N, 1.0, 0.0, 1.0);
//Main Boat
glColor3ub(255, 87, 34);
triangle(-0.0816,0.0214,-0.1293,0.034,-0.0816,-0.0123);
quad(-0.0816,0.0086,-0.0816,-0.0123,0.0772,-0.0123,0.0772,0.0086);
triangle(0.0772,-0.0123,0.1255,0.034,0.0772,0.0233);
quad(0.053,0.0248,0.0271,0.0248,0.0271,0.0086,0.053,0.0086);
quad(-0.0255,0.0248,-0.0508,0.0248,-0.0508,0.0086,-0.0255,0.0086);
triangle(0,0.043,-0.0093,0.0086,0.009,0.0086);
//BARS
glColor3ub(62, 39, 35);
triangle(0,0.1919,-0.0402,0.0248,-0.0304,0.0248);
triangle(0,0.1919,0.0351,0.0248,0.0447,0.0248);
glPopMatrix();

glColor3ub(121, 125, 127);
triangle(-0.4348,0.2,-0.5555,-0.018,-0.54,-0.018);
triangle(-0.4348,0.2,-0.3278,-0.018,-0.3123,-0.018);

glPushMatrix();
glColor3ub(216, 67, 21);
glTranslatef(-0.4348f,0.18, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.03;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();


//MARRY GO ROUND
glPushMatrix();
glTranslatef(-0.82,0.142f, 0.0f);
glRotatef(anglel_M, 0.0, 0.0, 1.0);

//MARRY GO ROUND
glColor3ub(236, 240, 241);
glBegin(GL_LINE_LOOP);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.11;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();

glColor3ub(236, 240, 241);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0,0.116);
glVertex2f(-0.12,0);
glVertex2f(0,-0.117);
glVertex2f(0.12,0);
glEnd();

//bars
quad(-0.0017,0.1289,-0.0017,-0.135,0.0017,-0.135,0.0017,0.1289);
quad(-0.13204,0.0026,-0.13204,0,0.13204,0,0.13204,0.0026);

//BLOCK over ring.
glColor3ub(133, 193, 233);
quad(-0.0135,0.118,-0.0135,0.092,0.0127,0.092,0.0127,0.118);
glColor3ub(231, 76, 60);
quad(-0.1271,0.0142,-0.1271,-0.0123,-0.1005,-0.0123,-0.1005,0.0142);
glColor3ub(244, 208, 63);
quad(0.0985,0.0132,0.0985,-0.0132,0.125,-0.0132,0.125,0.0132);
glColor3ub(142, 68, 173);
quad(-0.0129,-0.0992,-0.0129,-0.1257,0.01337,-0.1257,0.01337,-0.0992);

//AXIS of ROTATION
glColor3ub(236, 240, 241);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.01;
    float x = r * cos(A);
	float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();


//BASE OF MERRY GO ROUND
glPushMatrix();
glColor3ub(120, 40, 31 );
triangle(-0.82,0.1423,-0.89,-0.0134,-0.85,-0.0134);
triangle(-0.82,0.1423,-0.78,-0.0174,-0.74,-0.0174);
quad(-0.825,0.1423,-0.825,0.1344,-0.81527,0.1344,-0.81527,0.1423);
glPopMatrix();

//TICKET COUNTER
glColor3ub(244, 208, 63);
glPushMatrix();
glTranslatef(-0.656f,-0.02f, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.04;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();


//ROOF TOP
glColor3ub(244, 208, 63);
glBegin(GL_POLYGON);
glVertex2f(-0.6046,-0.014);
glVertex2f(-0.6173,-0.005);
glVertex2f(-0.6963,-0.005);
glVertex2f(-0.709,-0.014);
glVertex2f(-0.7246,-0.014);
glVertex2f(-0.7246,-0.03);
glVertex2f(-0.5896,-0.03);
glVertex2f(-0.5896,-0.014);
glEnd();

//ROOF
glColor3ub(211, 47, 47 );
quad(-0.7246,-0.03,-0.7606,-0.0508,-0.5519,-0.0508,-0.5896,-0.03);
glColor3ub(244, 143, 177);
quad(-0.7031,-0.03,-0.7175,-0.0508,-0.59435,-0.0508,-0.61134,-0.03);
glColor3ub(211, 47, 47 );
quad(-0.668,-0.03,-0.6752,-0.0508,-0.6365,-0.0508,-0.6443,-0.03);
glColor3ub(211, 47, 47 );
quad(-0.7508,-0.05,-0.7508,-0.1747,-0.5628,-0.1747,-0.5628,-0.05);

//GLASS
glColor3ub(174, 214, 241);
quad(-0.7408,-0.0527,-0.7408,-0.1153,-0.5723,-0.1153,-0.5723,-0.0527);

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(-0.6578f,-0.1071f, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.02;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();
//BARS IN BOTTOM
glColor3ub(244, 143, 177);
quad(-0.7408,-0.1153,-0.7408,-0.1733,-0.5723,-0.1733,-0.5723,-0.1153);
glColor3ub(211, 47, 47 );
quad(-0.722,-0.1153,-0.722,-0.1733,-0.7034,-0.1733,-0.7034,-0.1153);
quad(-0.684,-0.1153,-0.684,-0.1733,-0.6669,-0.1733,-0.6669,-0.1153);
quad(-0.6471,-0.1153,-0.6471,-0.1733,-0.629,-0.1733,-0.629,-0.1153);
quad(-0.6096,-0.1153,-0.6096,-0.1733,-0.5917,-0.1733,-0.5917,-0.1153);

glColor3ub(211, 47, 47 );
triangle(-0.7606,-0.0508,-0.74,-0.0678,-0.7175,-0.0508);
glColor3ub(244, 143, 177);
triangle(-0.7175,-0.0508,-0.6964,-0.0678,-0.6752,-0.0508);
glColor3ub(211, 47, 47 );
triangle(-0.6752,-0.0508,-0.6554,-0.0678,-0.6365,-0.0508);
glColor3ub(244, 143, 177);
triangle(-0.6365,-0.0508,-0.6121,-0.0678,-0.59435,-0.0508);
glColor3ub(211, 47, 47 );
triangle(-0.59435,-0.0508,-0.5705,-0.0678,-0.5519,-0.0508);

//ICE CART
glColor3ub(100, 30, 22);
quad(-0.8245,-0.3044,-0.8245,-0.3088,-0.8009,-0.3088,-0.8009,-0.3044);
glColor3ub(110, 44, 0);
quad(-0.9227,-0.2979,-0.9149,-0.3052,-0.8247,-0.3052,-0.8175,-0.2979);
glColor3ub(160, 64, 0);
glBegin(GL_POLYGON);
glVertex2f(-0.9149,-0.3052);
glVertex2f(-0.9149,-0.3181);
glVertex2f(-0.8998,-0.3343);
glVertex2f(-0.8433,-0.3341);
glVertex2f(-0.8247,-0.3181);
glVertex2f(-0.8247,-0.3052);
glEnd();

glColor3ub(250, 215, 160);
glBegin(GL_POLYGON);
glVertex2f(-0.9035,-0.2536);
glVertex2f(-0.9125,-0.262);
glVertex2f(-0.9125,-0.2979);
glVertex2f(-0.8274,-0.2979);
glVertex2f(-0.8274,-0.262);
glVertex2f(-0.835,-0.2536);
glEnd();

glColor3ub(236, 240, 241);
quad(-0.9083,-0.2645,-0.9083,-0.2951,-0.8346,-0.2951,-0.8346,-0.2645);

//ice cream shape
glColor3ub(245, 176, 65);
triangle(-0.895,-0.273,-0.8573,-0.2603,-0.868,-0.2443);
glPushMatrix();
glColor3ub(125, 60, 152);
glTranslatef(-0.8539,-0.2455, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.0095;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();
glPushMatrix();
glColor3ub(93, 173, 226);
glTranslatef(-0.8581,-0.2589, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.0095;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();
glPushMatrix();
glColor3ub(236, 64, 122);
glTranslatef(-0.8678,-0.2448, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.0095;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();



//WHEELS
glPushMatrix();
glColor3ub(39, 55, 70);
glTranslatef(-0.843f,-0.3343f, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.015;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glColor3ub(121, 125, 127 );
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.0057;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(39, 55, 70);
glTranslatef(-0.899f,-0.3343f, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.015;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glColor3ub(121, 125, 127 );
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.0057;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();
	glutSwapBuffers();
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	cout<<"\n Press 'm' for rotating the Marry Go Round.\n";
	cout<<"\n Press 'Shift m' for stop the rotation of Marry Go Round.\n";
    cout<<"\n Press 'n' for swinging the Boat.\n";
	cout<<"\n Press 'Shift n' for stop the swinging.\n";
	cout<<"\n Press 'e' for exit.\n";
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(250, 450);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keyboardHandle);
	glutTimerFunc(100, update, 0);

	glutMainLoop();
	return 0;
}


