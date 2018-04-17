# include <GL/glut.h>
# include <cstdlib>
# include <stdio.h>

using namespace std;

void init();
void display();

void horizontalIVT(int * x, int * y, float z){
    glVertex2i((*x), (*y));
    glVertex2i(((*x)/(2))*z, (*y));
    *x = ((*x)/(2))*z;
}
void horizontal(int * x, int * y, float z){
   glVertex2i((*x), (*y));
    glVertex2i((((*x)*2)*z), (*y));
    *x = (((*x)*2)*z);
}
void diagonal(int * x, int * y, float z){
     glVertex2i((*x), (*y));
     glVertex2i(((*x) *(2))*z, (((*y)*2)*z));
     *x = ((*x) *(2))*z; 
     *y = (((*y)*2)*z);

} 
void diagonalIVT(int * x, int * y, float z){
    glVertex2i((*x), (*y));
    glVertex2i(((*x) *2)*z, ((*y)/2)*z);
    *x = ((*x) *2)*z;
    *y = ((*y)/2)*z;
}
void diagonalIVTASC(int * x, int * y, float z){
    glVertex2i((*x), (*y));
    glVertex2i(((((*x))*z)/2)+(z*4), (((*y))*z)*2.5);
    *x = (((*x)/2)*z)/2;
    *y = (((*y)*2)*z)/2;

}
void estrela(int x, int y, int tamanho){
    glBegin(GL_LINE_STRIP); 
    glVertex2d(x-(tamanho/2),y-(tamanho/2));
    glVertex2d(x+(tamanho*4),y+(tamanho*4));
    glVertex2d(x-(tamanho/4),y+(tamanho*4));
    glVertex2d(x+(tamanho*4),y-(tamanho/4));
    glVertex2d(x+(tamanho*2),y+(tamanho*6));
    glVertex2d(x-(tamanho/2),y-(tamanho/2));

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Desenhando meu nome");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

void display() {
    // quando os valores inicias são diferente a estrela e melhor formada
    int x = 20;
    int y = 20;
    int z = 3;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    estrela(x,y,10);
   //estrela(x,y,25);
   //estrela(x,y,35);

    glEnd();
    glFlush();
}
