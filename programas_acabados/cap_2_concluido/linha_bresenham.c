#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

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
/*int abs(int result){
	if(result>=0) return result;
	else return result*(-1);
}*/
int Sinal(int result){
	if(result >= 0)    return 1;
	else return -1;
}
void display(void){
  int i,x1=40,x2=200,y1=200,y2=10,x,y,Delta_x,Delta_y,s1,s2,Troca,Temp, new_e;
  
 x = x1;
 y = y1;
 Delta_x = abs(x2 - x1);
 Delta_y = abs(y2 - y1);
 s1=Sinal(x2 - x1);
 s2=Sinal(y2 - y1);
 if(Delta_y > Delta_x){
   Temp = Delta_x;
   Delta_x = Delta_y;
   Delta_y = Temp;
   Troca = 1;
 }
 else{
   Troca = 0;
 }
 new_e = 2*Delta_y - Delta_x;
 


  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 1.0, 0.0);
  glBegin(GL_POINTS);
for(i=1; i<= Delta_x; i++){
   
   glVertex2i(x,y);
   while (new_e >= 0){
     if(Troca == 1){
       //Muda para a proxima linha de rasterização
       x = x + s1;
     }
     else{
       y = y + s2;
     }
     new_e = new_e - 2*Delta_x;
   }

   //Permanece nesta linha de rasterização
   if(Troca == 1){
     y = y + s2;
   }
   else{
     x = x + s1;
   }
   new_e= new_e + 2*Delta_y;
   
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
