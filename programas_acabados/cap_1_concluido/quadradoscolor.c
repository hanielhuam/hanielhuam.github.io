#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);
void HSItoRGB(int h, float s, float i);

/* cores do quadrado */
GLfloat r=0.0, g=0.0, b=0.0;
float s = 0.5, i=0.5;
int h[4]={0,80,160,240};

int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  glutTimerFunc(33, timer, 1);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  //glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void HSItoRGB(int h, float s, float i) {
  if (h>= 0 && h < 120)
  {
    b = i*(1-s)/3;
    r = i*(1+(s*cos(h*M_PI/180.0)/cos((60-h)*M_PI/180.0)))/3;
    g = i*(1-(r+b));
  }
 if (h >=120 && h < 240)
  {
    h = h-120;
    r = i*(1-s)/3;
    g = i*(1+(s*cos(h*M_PI/180.0)/cos((60-h)*M_PI/180.0)))/3;
    b = i*(1-(r+g));
  }
 if (h >= 240 && h <= 360)
  {
    h = h-240;
    g = i*(1-s)/3;
    b = i*(1+(s*cos(h*M_PI/180.0)/cos((60-h)*M_PI/180.0)))/3;
    r = i*(1-(g+b));
  }
}


void timer(int value){
  h[0] = (h[0] + 10)%360;
  h[1] = (h[1] + 20)%360;
  h[2] = (h[2] + 5)%360;
  h[3] = (h[3] + 1)%360;
  glutPostRedisplay();
  glutSwapBuffers();
  glutTimerFunc(33, timer, 1);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);

  //vertice1
  HSItoRGB(h[0], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.25,0.25);
  //vertice2
  HSItoRGB(h[1], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.75,0.25);
  //vertice3
  HSItoRGB(h[2], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.75,0.75);
  //vertice4
  HSItoRGB(h[3], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.25,0.75);

  glEnd();
  glFlush();

}


