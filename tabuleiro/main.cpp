# include <GL/glut.h>
# include <cstdlib>
# include <stdio.h>

using namespace std;

void init();
void display();

void tabuleiro(int x){
    for(int i = 1; i < x; i++){
        
         for(int b = 1; b < x; b++){
        
            if (i%2 == 1 && b%2 == 1 ) {
                glColor3f(1.0,0.3,0.6);
            }else{
                glColor3f(0.5,0.4,0.8);
            }
            glBegin(GL_QUADS);
            glVertex2d(5*b,5*i);
            glVertex2d(10*b,5*i);
            glVertex2d(10*b,10*i);
            glVertex2d(5*b,10*i);
            glEnd();
        }
        
    
    }
    

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
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
    glClear(GL_COLOR_BUFFER_BIT);

    tabuleiro(10);

    glFlush();
}
