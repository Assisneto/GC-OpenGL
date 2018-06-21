#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void init (void);
void display (void);
void keyboard (unsigned char key, int x, int y);

int t = 10, ex = 0, ey = 0, graus = 0; 


int main (int argc, char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Desenhando um Tabuleiro");
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

void quadradoteste (float x, float y){
    glBegin(GL_QUADS);
    glVertex2f(x+1.0,y+1.0);
    glVertex2f(x+1.0,y+5.0);
    glVertex2f(x+6.0,y+5.0);
    glVertex2f(x+6.0,y+1.0);
    glEnd();
}

void barra (float tamanho, float ex, float ey){
    glColor3f(0.5,0.5,1.0);
    glBegin(GL_QUADS);
    glVertex2f(t*(ex+0.0),t*(ey+0.0));
    glVertex2f(t*(ex+0.0),t*(ey+4.0));
    glVertex2f(t*(ex+1.0),t*(ey+4.0));
    glVertex2f(t*(ex+1.0),t*(ey+0.0));
    glEnd();
}
void quadrado (void){
    float t = 10.0;
    float x = 2.0;
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(t*(x+0.0),t*(0.0));
    glVertex2f(t*(x+0.0),t*(2.0));
    glVertex2f(t*(x+2.0),t*(2.0));
    glVertex2f(t*(x+2.0),t*(0.0));
    glEnd();
}

void tee (void){
    float t = 10.0;
    float x = 5.0;
    glColor3f(1.0,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2f(t*(x+0.0),t*(1.0));
    glVertex2f(t*(x+0.0),t*(2.0));
    glVertex2f(t*(x+1.0),t*(2.0));
    glVertex2f(t*(x+1.0),t*(1.0));

    glVertex2f(t*(x+1.0),t*(0.0));
    glVertex2f(t*(x+1.0),t*(3.0));
    glVertex2f(t*(x+2.0),t*(3.0));
    glVertex2f(t*(x+2.0),t*(0.0));
    glEnd();
}
void zee (void){
    float t = 10.0;
    float x = 8.0;
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(t*(x+0.0),t*(0.0));
    glVertex2f(t*(x+0.0),t*(1.0));
    glVertex2f(t*(x+2.0),t*(1.0));
    glVertex2f(t*(x+2.0),t*(0.0));

    glVertex2f(t*(x+1.0),t*(1.0));
    glVertex2f(t*(x+1.0),t*(2.0));
    glVertex2f(t*(x+3.0),t*(2.0));
    glVertex2f(t*(x+3.0),t*(1.0));
    glEnd();
}
void ele (void){
    float t = 10.0;
    float x = 12.0;
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(t*(x+0.0),t*(0.0));
    glVertex2f(t*(x+0.0),t*(1.0));
    glVertex2f(t*(x+3.0),t*(1.0));
    glVertex2f(t*(x+3.0),t*(0.0));

    glVertex2f(t*(x+2.0),t*(1.0));
    glVertex2f(t*(x+2.0),t*(2.0));
    glVertex2f(t*(x+3.0),t*(2.0));
    glVertex2f(t*(x+3.0),t*(1.0));
    glEnd();
}

void display (void){
    glClear(GL_COLOR_BUFFER_BIT);
    glRotated(graus,0,0,1);
    barra(t,ex,ey);
    glFlush();
}

void keyboard (unsigned char key, int x, int y){
    switch(key){
        case 'a':
            ex -= 1;
            break;
        case 'd':
            ex += 1;
             break;
        case 'w':
            ey += 1;
            break;
        case 's':
            ey -= 1;
            break;
        case 'q':
            graus -= 1;
            break;
        case 'e':
            graus += 1;
            break;    
        }
    glutPostRedisplay();
}

