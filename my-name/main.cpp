# include <GL/glut.h>
# include <cstdlib>
# include <stdio.h>

using namespace std;

void init();
void display();

void vertical(int x, int y, float z){
    glVertex2i(x, y);
    glVertex2i(x, y*2*z);
}
void horizontal(int x, int y, float z){
    glVertex2i(x, y);
    glVertex2i(x*(2*z), y);
}
void diagonal(int x, int y, float z){
     glVertex2i(x, y);
     glVertex2i(x *(1.5*z), y*(2*z)); 
     int *results = (int*)malloc(2*sizeof(int));

} 
void diagonalIVT(int x, int y, float z){
    glVertex2i(x, y);
    glVertex2i(x *1.4*z, y/2/z);
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
    int x = 10;
    int y = 20;
    int z = 1;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES); 
        // Escrevendo letra "A" sem função
        // glVertex2i(10, 20);
        // glVertex2i(15, 40);
        // glVertex2i(15, 40);
        // glVertex2i(20, 20);
        // glVertex2d(12, 27);
        // glVertex2d(18, 27);
        // Escrevendo letra "A" com função
        diagonal(x,y,z);
        diagonalIVT(x*1.5,y*2,z);
        horizontal(12,27,0.8);
        // Escrevendo letra "S" com função
        glColor3f(1.0,0,1.0);
        horizontal(x+12,y,0.7);
        vertical(x+20,y,0.7);
        horizontal(x+12,y+8,0.7);
        vertical(x+12,y+8,0.7);
        horizontal(x+12,y+19,0.7);
        // S
        glColor3f(0,1.0,1.0);
        x = x + 10;
        y = y ;
        horizontal(x+12,y,0.7);
        vertical(x+24,y,0.7);
        horizontal(x+12,y+8,0.7);
        vertical(x+12,y+8,0.7);
        horizontal(x+12,y+19,0.7);
        // I
        vertical(x+27,y,1.002);
        // S
        glColor3f(1.0,1.0,0);
        x = x + 17;
        y = y ;
        horizontal(x+12,y,0.6);
        vertical(x+21,y,0.7);
        horizontal(x+12,y+8,0.6);
        vertical(x+12,y+8,0.7);
        horizontal(x+12,y+19,0.6);

    glEnd();
    glFlush();
}
