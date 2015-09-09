#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void pontosdacircunferencia(int x, int y);

int xp=128;
int yp=128;
int raio=50;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma linha");
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
   
int x = 0;
int y = raio;
int d = 1 - raio;
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3f (0.0, 0.0, 0.0);
  glBegin(GL_POINTS);
  glVertex2i(xp+x,yp+y);
 while(y > x){
   if(d < 0){
     d = d + 2*x + 3;
     x = x + 1;
   }
   else{
     d = d + 2*(x-y) + 5;
     x = x + 1;
     y = y - 1;
   }
     glVertex2i(xp+x,yp+y);
     glVertex2i(xp+x,xp-y);
     glVertex2i(xp-x,yp+y);
     glVertex2i(xp-x,yp-y);
     glVertex2i(xp+y,yp+x);
     glVertex2i(xp+y,yp-x);
     glVertex2i(xp-y,yp+x);
     glVertex2i(xp-y,yp-x);
 
}
   glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}
