#include <GL/glut.h>
#include <stdlib.h>

GLfloat rf[4] = {1.0,1.0,1.0,1.0}, gf[4] = {1.0,1.0,1.0,1.0}, bf[4] = {0.0,0.0,0.0,0.0};

GLfloat rb[4] = {1.0,1.0,1.0,1.0}, gb[4] = {1.0,1.0,1.0,1.0}, bb[4] = {0.0,0.0,0.0,0.0};

GLint x[4]={30,143,30,143},y[4]={226,226,113,113};

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Preenchendo regiões");
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
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
	/*borda do poliguino 1*/
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rb[0], gb[0], bb[0]);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();
       /*fundo do poliguino 1*/
 glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[0], gf[0], bf[0]);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();
	/*borda do poliguino 2*/
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rb[1], gb[1], bb[1]);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();
	/*fundo do poliguino 2*/
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[1], gf[1], bf[1]);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();
	/*borda do poliguino 3*/
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rb[2], gb[2], bb[2]);
  glBegin(GL_POLYGON);
  glVertex2i(30,113);  glVertex2i(113,113);
  glVertex2i(113,30);  glVertex2i(30,30); 
  glEnd();
	/*fundo do poliguino 3*/
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[2], gf[2], bf[2]);
  glBegin(GL_POLYGON);
  glVertex2i(30,113);  glVertex2i(113,113);
  glVertex2i(113,30);  glVertex2i(30,30); 
  glEnd();
	/*borda do poliguino 4*/
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rb[3], gb[3], bb[3]);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();
	/*fundo do poliguino 4*/
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[3], gf[3], bf[3]);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();
  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
	/*o eixo do mouse eh invertido em relacao ao da tela
	por isso que fazemos a cordenada y do mouse como: 256 - a coordenada y da tela*/ 
  case 98:	/*mudar a cor da borda do poliguino 1*/
	if(x>=30 && x<=113 && y<=(256-143) && y>=(256-225)){
	rb[0] = (GLfloat)rand()/(RAND_MAX+1.0);
	gb[0] = (GLfloat)rand()/(RAND_MAX+1.0);
	bb[0] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	/*mudar a cor da borda do poliguino 2*/
	if(x>=143 && x<=226 && y<=(256-143) && y>=(256-225)){
	rb[1] = (GLfloat)rand()/(RAND_MAX+1.0);
	gb[1] = (GLfloat)rand()/(RAND_MAX+1.0);
	bb[1] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	/*mudar a cor da borda do poliguino 3*/
	if(x>=30 && x<=113 && y<=(256-30) && y>=(256-113)){
	rb[2] = (GLfloat)rand()/(RAND_MAX+1.0);
	gb[2] = (GLfloat)rand()/(RAND_MAX+1.0);
	bb[2] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	/*mudar a cor da borda do poliguino 4*/
	if(x>=143 && x<=226 && y<=(256-30) && y>=(256-113)){
	rb[3] = (GLfloat)rand()/(RAND_MAX+1.0);
	gb[3] = (GLfloat)rand()/(RAND_MAX+1.0);
	bb[3] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	else{ break; }
	
	
	case 102: /*mudar a cor do fundo do poliguino 1*/
	if(x>=30 && x<=113 && y<=(256-143) && y>=(156-226)){
	rf[0] = (GLfloat)rand()/(RAND_MAX+1.0);
	gf[0] = (GLfloat)rand()/(RAND_MAX+1.0);
	bf[0] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}
	
	/*mudar a cor do fundo do poliguino 2*/
	if(x>=143 && x<=226 && y<=(256-143) && y>=(256-225)){
	rf[1] = (GLfloat)rand()/(RAND_MAX+1.0);
	gf[1] = (GLfloat)rand()/(RAND_MAX+1.0);
	bf[1] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	/*mudar a cor do fundo do poliguino 3*/
	if(x>=30 && x<=113 && y<=(256-30) && y>=(256-113)){
	rf[2] = (GLfloat)rand()/(RAND_MAX+1.0);
	gf[2] = (GLfloat)rand()/(RAND_MAX+1.0);
	bf[2] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	/*mudar a cor do fundo do poliguino 4*/
	if(x>=143 && x<=226 && y<=(256-30) && y>=(256-113)){
	rf[3] = (GLfloat)rand()/(RAND_MAX+1.0);
	gf[3] = (GLfloat)rand()/(RAND_MAX+1.0);
	bf[3] = (GLfloat)rand()/(RAND_MAX+1.0);
	glutPostRedisplay();
	break;
	}

	else{ break; }
	
}
}

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:

/*o eixo do mouse eh invertido em relacao ao da tela
	por isso que fazemos a cordenada y do mouse como: 256 - a coordenada y da tela*/ 

	/*mudar a cor da borda e do fundo do poliguino 1*/
	if (state == GLUT_DOWN && x>=30 && x<=113 && y<=(256-143) && y>=(256-226)) {
	  rb[0]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gb[0]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bb[0]=(GLfloat)rand()/(RAND_MAX+1.0);
	  rf[0]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gf[0]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bf[0]=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	  break;
	}
	
	/*mudar a cor da borda e do fundo do poliguino 2*/
	if (state == GLUT_DOWN && x>=143 && x<=226 && y<=(256-143) && y>=(256-226)) {
	  rb[1]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gb[1]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bb[1]=(GLfloat)rand()/(RAND_MAX+1.0);
	  rf[1]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gf[1]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bf[1]=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	  break;
	}

	/*mudar a cor da borda e do fundo do poliguino 3*/
	if (state == GLUT_DOWN && x>=30 && x<=113 && y<=(256-30) && y>=(256-113)) {
	  rb[2]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gb[2]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bb[2]=(GLfloat)rand()/(RAND_MAX+1.0);
	  rf[2]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gf[2]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bf[2]=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	  break;
	}
	/*mudar a cor da borda e do fundo do poliguino 4*/
	if (state == GLUT_DOWN && x>=143 && x<=226 && y<=(256-30) && y>=(256-113)) {
	  rb[3]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gb[3]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bb[3]=(GLfloat)rand()/(RAND_MAX+1.0);
	  rf[3]=(GLfloat)rand()/(RAND_MAX+1.0);
	  gf[3]=(GLfloat)rand()/(RAND_MAX+1.0);
	  bf[3]=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	  break;
	}

	break;

  }
}

