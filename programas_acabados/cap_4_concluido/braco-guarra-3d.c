 #include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, dedo_medio = 0, dedo_indicador = 0, dedo_polegar = 0, rot_em_y = 0;
// dedo_medio (primeiro dedo de cima)
// dedo_indicador (segundo dedo de cima)
// dedo_polegar (dedo de baixo)

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  //glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /* origem posicionada no ombro */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) rot_em_y, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  /* origem posicionada no centro do bra�o */ 
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glColor3f (1.0, 0.0, 0.0);
  glutSolidCube (1.0);
  glPopMatrix();
   
  /* origem posicionada no cotovelo */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glColor3f (0.0, 1.0, 0.0);
  glutSolidCube (1.0);
  glPopMatrix();
  
  // para levar a origem a ponta do antebraço
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  /*desenhando o dedo medio (cima)*/
  glTranslatef (0.0, 0.2, -0.30);
  glRotatef ((GLfloat) dedo_medio, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef (0.5, 0.15, 0.2);
  glColor3f (0.0, 1.0, 1.0);
  glutSolidCube (1.0);
  glPopMatrix();
  glPushMatrix(); // para continuar no meio do antebraço

  /*desenhando o dedo indicador (cima)*/
  glTranslatef (0.0, 0.2, 0.3);
  glRotatef ((GLfloat) dedo_indicador, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef (0.5, 0.15, 0.2);
  glColor3f (0.0, 0.0, 1.0);
  glutSolidCube (1.0);
  glPopMatrix();

  /*desenhando o dedo polegar (baixo)*/
  glTranslatef (0.0, -0.2, 0.0);
  glRotatef ((GLfloat) dedo_polegar, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef (0.5, 0.15, 0.2);
  glColor3f (1.0, 1.0, 0.0);
  glutSolidCube (1.0);
  glPopMatrix();


  /* origem volta para o sistema de coordenadas original */
  glPopMatrix();
  
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'i':
    dedo_indicador = (dedo_indicador + 5) % 360;
    glutPostRedisplay();
    break;
  case 'I':
    dedo_indicador = (dedo_indicador - 5) % 360;
    glutPostRedisplay();
    break;
  case 'm':
    dedo_medio = (dedo_medio + 5) % 360;
    glutPostRedisplay();
    break;
  case 'M':
    dedo_medio = (dedo_medio - 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    dedo_polegar = (dedo_polegar + 5) % 360;
    glutPostRedisplay();
    break;
  case 'P':
    dedo_polegar = (dedo_polegar - 5) % 360;
    glutPostRedisplay();
    break;
  case 'B':
    rot_em_y = (rot_em_y + 5) % 360;
    glutPostRedisplay();
    break;
  case 'b':
    rot_em_y = (rot_em_y - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
