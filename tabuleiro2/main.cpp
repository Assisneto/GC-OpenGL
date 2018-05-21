#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void init (void);
void display (void);
void keyboard (unsigned char key, int x, int y);




int main (int argc, char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256,256);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Desenhando uma Tabuleiro");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
void init (void){
    glClearColor(0.0,0.0,0.0,1.0);
    glOrtho(0,256,0,256,-1,1);
}

void tabuleiro (float x, float y){
    glBegin(GL_QUADS);
    float a2 = 2.5; //tamanho do quadrado
    glVertex2f(a2*(x+0.0),a2*(y+0.0));
    glVertex2f(a2*(x+0.0),a2*(y+5.0));
    glVertex2f(a2*(x+5.0),a2*(y+5.0));
    glVertex2f(a2*(x+5.0),a2*(y+0.0));
    glEnd();
}

void borda (void){
    float a = 2.5; //tamanho da borda dever ser igual ao do tamanho do quadrado
    float b = 15.0 + 1.0;//o valor de b deve ser igual quantidade de quadrados + um
    glBegin(GL_LINE_LOOP);
    glVertex2f(a*5.0,a*5.0);
    glVertex2f(a*5.0,a*(b*5.0));
    glVertex2f(a*(b*5.0),a*(b*5.0));
    glVertex2f(a*(b*5.0),a*5.0);
    glEnd();
}

void display (void){
    int t = 20;//quantidade de quadrados
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    for (int i = 0; i < t; i++ ){
        float y = y + 5.0;
        float x = 0;
        for (int j = 0; j < t; j++){
            x = x + 5.0;
            if (i % 2 == 0 && j % 2 != 0 || i % 2 != 0 && j % 2 == 0){
                tabuleiro(x,y);
            }

        }
    }
    borda();
    glFlush();
}

void keyboard (unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            break;
    }
}

