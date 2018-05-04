#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI acos(-1.0)



static GLfloat v_cloud_r=40.0;
static GLfloat v_cloud_l=-40;
static GLfloat bird1_start=35;
static GLfloat bird2_start=40;

static GLfloat x = 0;

static GLfloat b1 = 0;
static GLfloat b2 = -8;
static GLfloat c1 = -40;
static GLfloat c2 = -40;

void circle(GLdouble rad)
{
	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;

	glBegin(GL_POLYGON);
	{
		for( GLint i = 0; i <=50; i++, theta += delTheta )
		{
			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}

void spinDisplay(void)

{
        bird1_start-=0.02;
        if(bird1_start<-50) //limit
            bird1_start=35;

        bird2_start-=0.02;
        if(bird2_start<-50) //limit
            bird2_start=40;

        v_cloud_r = v_cloud_r - 0.01;
        if (v_cloud_r < -50)
            v_cloud_r = 50;

        v_cloud_l = v_cloud_l + 0.01;
        if (v_cloud_l > 50)
            v_cloud_l = -50;


        b1+= 0.02;  //boat1
        if(b1 >= 72.0)//animation limit
            b1 = 0;

        b2+= 0.02;  //boat1
        if(b2 >= 72.0)//animation limit
            b2 = -8;
        c1+=0.02;//car1
        if(c1>=80) //limit
            c1=-40;
        c2+=0.02;//car2
        if(c2>=80) //limit
            c2=-40;



x=x+0.5;
	glutPostRedisplay();
}

void bird1()
{

	glColor3f(0.6, 0.2, 0.0);

	glBegin(GL_POLYGON);

      glVertex2f (0 , 0);
	  glVertex2f (2.5 , 0);
	  glVertex2f (5.2, 4.2);
	  glVertex2f (1, 2);

	glEnd();

glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_POLYGON);

      glVertex2f (4 , 0);
	  glVertex2f (2.4 , 0);
	  glVertex2f (3.4, 1.5);
	  glVertex2f (6.8, 1.5);

	glEnd();


glColor3f(0.2, 0.2, 0.0);
	glBegin(GL_POLYGON);

      glVertex2f (4 , 0);
	  glVertex2f (5.5 , -1);
	  glVertex2f (-0.2, -0.8);
	  glVertex2f (0, 0);

	glEnd();


glColor3f(0.8, 0.4, 0.0);
	glBegin(GL_POLYGON);
	  glVertex2f (-0.2, -0.8);
	  glVertex2f (0, 0);
	   glVertex2f (-1 , 1);
	  glVertex2f (-2 , 0);
	glEnd();


}  //bird1 end


void bird2()
{

	glColor3f(0.6, 0.2, 0.0);

	glBegin(GL_POLYGON);

      glVertex2f (0 , 0);
	  glVertex2f (2.5 , 0);
	  glVertex2f (5.2, 4.2);
	  glVertex2f (1, 2);

	glEnd();

glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_POLYGON);

      glVertex2f (4 , 0);
	  glVertex2f (2.4 , 0);
	  glVertex2f (3.4, 1.5);
	  glVertex2f (6.8, 1.5);

	glEnd();


glColor3f(0.2, 0.2, 0.0);
	glBegin(GL_POLYGON);

      glVertex2f (4 , 0);
	  glVertex2f (5.5 , -1);
	  glVertex2f (-0.2, -0.8);
	  glVertex2f (0, 0);

	glEnd();


glColor3f(0.8, 0.4, 0.0);
	glBegin(GL_POLYGON);
	  glVertex2f (-0.2, -0.8);
	  glVertex2f (0, 0);
	   glVertex2f (-1 , 1);
	  glVertex2f (-2 , 0);
	glEnd();


}

                                        //bird2 end


void cloud()

{
	//left

	glPushMatrix();
	glTranslatef(4,5.5,0);
	circle(4);
	glPopMatrix();

	//right

	glPushMatrix();
	glTranslatef(-8,5.5,0);
	circle(3.5);
	glPopMatrix();

	//top left

	glPushMatrix();
	glTranslatef(-3.5,9,0);
	circle(3.5);
	glPopMatrix();

	//top right

	glPushMatrix();
	glTranslatef(1,9,0);
	circle(3);
	glPopMatrix();

	//middle

	glPushMatrix();

	//glColor3f (1, 1 ,1);
	glTranslatef(-1.5,5.5,0);
	circle(4);
	glPopMatrix();

}


void boat()//boat1
{
   glColor3f(0.0,0.0,0.0);//boat body
glBegin(GL_POLYGON);
  glVertex2f(-8,-50);
  glVertex2f(-10,-46);
   glVertex2f(-10,-41);
    glVertex2f(-8,-37);
    glVertex2f(-6,-41);
    glVertex2f(-6,-46);
     glEnd();

     glColor3f(0.0,0.0,1.0);//boat roof
glBegin(GL_POLYGON);

   glVertex2f(-6,-45);
    glVertex2f(-10,-45);

    glVertex2f(-10,-42);
    glVertex2f(-9,-41);
    glVertex2f(-7,-41);
    glVertex2f(-6,-42);

     glEnd();

     glBegin(GL_TRIANGLES);
   glVertex2f(-6,-45);
    glVertex2f(-6,-46);
    glVertex2f(-7,-45);
     glEnd();

     glBegin(GL_TRIANGLES);
   glVertex2f(-9,-45);
    glVertex2f(-10,-45);
    glVertex2f(-10,-46);
     glEnd();


}
void boat2()//boat2
{
   glColor3f(0.0,0.0,0.0);//boat body
glBegin(GL_POLYGON);
  glVertex2f(8,-50);
  glVertex2f(10,-46);
   glVertex2f(10,-41);
    glVertex2f(8,-37);
    glVertex2f(6,-41);
    glVertex2f(6,-46);
     glEnd();

     glColor3f(1.0,0.0,0.0);//boat roof
glBegin(GL_POLYGON);
   glVertex2f(6,-45);
    glVertex2f(10,-45);

    glVertex2f(10,-42);
    glVertex2f(9,-41);
    glVertex2f(7,-41);
    glVertex2f(6,-42);
     glEnd();

          glBegin(GL_TRIANGLES);
   glVertex2f(6,-45);
    glVertex2f(6,-46);
    glVertex2f(7,-45);
     glEnd();

     glBegin(GL_TRIANGLES);
   glVertex2f(9,-45);
    glVertex2f(10,-45);
    glVertex2f(10,-46);
     glEnd();


}
void car()
{
    glColor3f(1.0f,0.0f,0.0f);

   glBegin(GL_POLYGON);
  glVertex2f(0,0);
  glVertex2f(0,2);
   glVertex2f(-1,2);
    glVertex2f(-3,5);
    glVertex2f(-8,5);
    glVertex2f(-9,2);
    glVertex2f(-11,1.3);
    glVertex2d(-11,0);

    glEnd();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(-3.5,0, 10);
glutSolidSphere(1,10,10);
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(-7,0, 10);
glutSolidSphere(1,10,10);
glPopMatrix();

       glColor3f(0.0f,0.0f,0.0f);//car window

   glBegin(GL_POLYGON);
  glVertex2f(-3,2);
  glVertex2f(-4,2);
   glVertex2f(-4,3.7);
    glVertex2f(-3,3.7);
    glEnd();

      glBegin(GL_POLYGON);
  glVertex2f(-5,2);
  glVertex2f(-6,2);
   glVertex2f(-6,3.7);
    glVertex2f(-5,3.7);
    glEnd();

     glBegin(GL_TRIANGLES);
  glVertex2f(-7,2);
  glVertex2f(-8,2);
    glVertex2f(-7,3.7);
    glEnd();
}
void car2()//car2
{
    glColor3f(0.2f,0.70f,0.5f);

   glBegin(GL_POLYGON);
 glVertex2f(0,0);
  glVertex2f(0,2);
   glVertex2f(1,2);
    glVertex2f(3,5);
    glVertex2f(8,5);
    glVertex2f(9,2);
    glVertex2f(11,1.3);
    glVertex2d(11,0);
    glEnd();

    glPushMatrix();
glColor3f(0,0,0);
glTranslatef(3.5,0, 10);
glutSolidSphere(1,10,10);
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(7,0, 10);
glutSolidSphere(1,10,10);
glPopMatrix();

       glColor3f(0.0f,0.0f,0.0f);//car2 window

   glBegin(GL_POLYGON);
  glVertex2f(3,2);
  glVertex2f(4,2);
   glVertex2f(4,3.7);
    glVertex2f(3,3.7);
    glEnd();

      glBegin(GL_POLYGON);
  glVertex2f(5,2);
  glVertex2f(6,2);
   glVertex2f(6,3.7);
    glVertex2f(5,3.7);
    glEnd();

     glBegin(GL_TRIANGLES);
  glVertex2f(7,2);
  glVertex2f(8,2);
    glVertex2f(7,3.7);
    glEnd();

}
void road()
{
      glColor3f(0.35f,0.35f,0.35f);//rood
glBegin(GL_QUADS);
  glVertex2f(-40,9);
  glVertex2f(40,9);
   glVertex2f(40,-10);
    glVertex2f(-40,-10);
     glEnd();

     glColor3f(1.0f,1.0f,1.0f);
  glBegin(GL_QUADS);
  glVertex2f(-40,1);
  glVertex2f(40,1);
  glVertex2f(40,-1);
  glVertex2f(-40,-1);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
  glBegin(GL_QUADS);
  glVertex2f(-40,-10);
  glVertex2f(40,-10);
  glVertex2f(40,-12);
  glVertex2f(-40,-12);
    glEnd();


}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.6,0.6,0.9);//sky
glBegin(GL_POLYGON);
  glVertex2f(-40,50);
  glVertex2f(40,50);
  glColor3f(0.050f,0.52f,1.0f);
   glVertex2f(40,35);
    glVertex2f(-40,35);
    glEnd();






glColor3f(0.47f,0.73f,1.0f);//river
glBegin(GL_POLYGON);
glColor3f(0.4,0.9,1);
  glVertex2f(-20,35);
  glVertex2f(20,35);
   glColor3f(0.4,0.7,1);
    glVertex2f(30,-50);
    glVertex2f(-30,-50);
     glEnd();

     glColor3f(0.0f,0.0f,0.0f);//tree right 1
glBegin(GL_QUADS);
  glVertex2f(31,-24);
  glVertex2f(33,-24);
   glVertex2f(33,-28);
    glVertex2f(31,-28);
     glEnd();
     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(27,-24);
  glVertex2f(32,-19);
   glVertex2f(37,-24);

     glEnd();
     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(28,-20);
  glVertex2f(32,-16);
   glVertex2f(36,-20);

     glEnd();
glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(29,-17);
  glVertex2f(32,-12);
   glVertex2f(35,-17);

     glEnd();



     glColor3f(0.0f,0.0f,0.0f);//tree left 1
glBegin(GL_QUADS);
  glVertex2f(-31,-24);
  glVertex2f(-33,-24);
   glVertex2f(-33,-28);
    glVertex2f(-31,-28);
     glEnd();
     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(-27,-24);
  glVertex2f(-32,-19);
   glVertex2f(-37,-24);

     glEnd();
     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(-28,-20);
  glVertex2f(-32,-16);
   glVertex2f(-36,-20);

     glEnd();
glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(-29,-17);
  glVertex2f(-32,-12);
   glVertex2f(-35,-17);

     glEnd();


  glColor3f(0.0f,0.0f,0.0f);//tree right 2
glBegin(GL_QUADS);
  glVertex2f(27.5,30);
  glVertex2f(28.5,30);
    glVertex2f(28.5,33);
    glVertex2f(27.5,33);
     glEnd();

     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(25,33);
  glVertex2f(31,33);
   glVertex2f(28,38);

     glEnd();


 glColor3f(0.0f,0.0f,0.0f);//tree left 2
glBegin(GL_QUADS);
  glVertex2f(-31,20);
  glVertex2f(-33,20);
   glVertex2f(-33,24);
    glVertex2f(-31,24);
     glEnd();
     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(-27,24);
  glVertex2f(-32,28);
   glVertex2f(-37,24);

     glEnd();
     glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(-28,27.5);
  glVertex2f(-32,31);
   glVertex2f(-36,27.5);

     glEnd();
glColor3f(0.0f,0.43f,0.0f);
     glBegin(GL_TRIANGLES);
  glVertex2f(-29,30.5);
  glVertex2f(-32,35);
   glVertex2f(-35,30.5);

     glEnd();


glPushMatrix();//sun


glPushMatrix();
glColor3f(1,1,0.2);
glTranslatef(30,45, 10);
glutSolidSphere(2, 50, 50);
glPopMatrix();


glutDisplayFunc(display);	glPopMatrix();

//right

	glPushMatrix();
	glColor3f (1, 1 ,1);
	glTranslatef(v_cloud_r,35,0);
	cloud();
	glPopMatrix();

	//left

	glPushMatrix();
	glColor3f (1, 1 ,1);
	glTranslatef(v_cloud_l,35,0);
	cloud();
	glPopMatrix();




    glPushMatrix();
	glTranslatef(bird1_start,45,0);       //bird1
	bird1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bird2_start,40,0);       //bird2
	bird2();
	glPopMatrix();


glPushMatrix();//boat1
	glTranslatef(-1,b1,0);
	boat();
	glPopMatrix();

	glPushMatrix();//boat2
	glTranslatef(1,b2,0);
	boat2();
	glPopMatrix();


road();

glPushMatrix();//car
	glTranslatef(-c1,5,0);
	car();
	glPopMatrix();

glPushMatrix();//car2
	glTranslatef(c2,-5,0);
	car2();
	glPopMatrix();


glutSwapBuffers();

}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
		 {

			 glutIdleFunc(spinDisplay);
		 }
			 break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)glutDisplayFunc(display);
		 {

			 glutIdleFunc(NULL);
		 }
         break;
      default:
         break;
   }
}


void init (void)
{
   glClearColor (0.0,0.76,0.0, 0.0);//Background
   glOrtho( -40, 40,-50, 50, -40,40);//Range of the co-ordinates
}


int main()
{
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800,1000);
   glutInitWindowPosition (0,0);
   glutCreateWindow("Green");
   init();
   glutIdleFunc(spinDisplay);
   glutDisplayFunc(display);
     glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
