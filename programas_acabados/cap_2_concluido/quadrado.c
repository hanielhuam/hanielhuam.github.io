#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
GLfloat r, g, b;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Desenhando um quadrado");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (r, g, b);
  glBegin(GL_LINES);
  glVertex2i(30, 226);  glVertex2i(226,226);
  glVertex2i(226,226);  glVertex2i(226,30);
  glVertex2i(226,30);  glVertex2i(30,30);
  glVertex2i(30,30);  glVertex2i(30,226);
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 97:
    r= 0.0;
    g= 0.0;
    b= 1.0;
    glutPostRedisplay();
    break;
  case 118:
    r= 1.0;
    g= 0.0;
    b= 0.0;
    glutPostRedisplay();
          break;
  }
}
