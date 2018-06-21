#include <GL/glut.h>
#include <stdlib.h>

int rotate = 20;
int rotate2 = 0;
int rotate3 = 0;

//Drawing funciton
void draw(void){
   /* clear all pixels */
   glClear (GL_COLOR_BUFFER_BIT);

   /* clear the modeling stack matrix */
   glLoadIdentity();

   /* set the observer */
   gluLookAt (0, 20, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   
  //gluLookAt (0, 0, 20, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   /* draw a white */
   glColor3f (1.0, 1.0, 1.0);

   /* wireframed sphere */
  /*glRotatef(rotate, 1, 0, 0);
  glRotatef(rotate2,0,1,0);*/
/*glTranslated(-11,0,0);
  glutWireTorus(1 ,4, 50, 500);
glTranslated(8,0,0);
  glutSolidSphere(2,10,20);
glTranslated(5,0,0);
  glutWireSphere(2,10,20);
glTranslated(5,0,0);
  glutSolidCube(3);
glTranslated(6,0,-1);
  glutWireCone(3,5,10,20);*/
  glPushMatrix();
    glTranslated(0,0,0);
      glScaled(1,2,1);
        glutSolidCube(2);
    glTranslated(0,0,4);      
        glutSolidCube(2);
    glColor3f (1.0, 0.0, 0.0);
    glTranslated(4,0,0);
        glutSolidCube(2);
    glTranslated(0,0,-4);     
        glutSolidCube(2);
    glTranslated(-2,1,2);
      glColor3f (0.5, 0.3, 0.7);  
      glScaled(4,0.1,4);
        glutSolidCube(2);
  glPopMatrix();
  glColor3f (0.2, 0.7, 0.3); 
    glTranslated(2,3,2);
    glutWireTeapot(1);
glFlush ();
}

void nome(){

 glBegin(GL_LINE_STRIP);
    //L
    glVertex2f( 10.0 , 30.0);
    glVertex2f( 10.0, 10.0);
    glVertex2f( 20.0 , 10.0);

  glEnd();

  glBegin(GL_LINE_STRIP);
    //u
    glVertex2f( 30.0 , 30.0);
    glVertex2f( 30.0, 10.0);
    glVertex2f( 40.0 , 10.0);
    glVertex2f( 40.0 , 30.0);

  glEnd();

  glBegin(GL_LINE_STRIP);
    //c
    glVertex2f( 60.0 , 30.0);
    glVertex2f( 50.0, 30.0);
    glVertex2f( 50.0 , 10.0);
    glVertex2f( 60.0 , 10.0);

  glEnd();

glBegin(GL_LINE_STRIP);
    //i
    glVertex2f( 70.0 , 30.0);
    glVertex2f( 70.0, 10.0);

  glEnd();

  glBegin(GL_LINE_STRIP);
    //a
    glVertex2f( 80.0 , 10.0);
    glVertex2f( 80.0, 30.0);
    glVertex2f( 90.0 , 30.0);
    glVertex2f( 90.0 , 20.0);
    glVertex2f( 80.0 , 20.0);
    glVertex2f( 90.0 , 20.0);
    glVertex2f( 90.0 , 10.0);
  glEnd();

  glBegin(GL_LINE_STRIP);
    //n
    glVertex2f( 100.0 , 10.0);
    glVertex2f( 100.0, 30.0);
    glVertex2f( 110.0 , 10.0);
    glVertex2f( 110.0 , 30.0);

  glEnd();

  glBegin(GL_LINE_LOOP);
    //n
    glVertex2f( 120.0 , 10.0);
    glVertex2f( 120.0, 30.0);
    glVertex2f( 130.0 , 30.0);
    glVertex2f( 130.0 , 10.0);

  glEnd();

}
void star(double size, double x, double y){
  glBegin(GL_TRIANGLES);

    glVertex2f( x * size, y * size);
    glVertex2f( (x + 10.0) * size, (y + 30.0) * size);
    glVertex2f( (x + 20.0) * size, y * size);

    glVertex2f( (x + 10.0) * size , (y - 10.0) * size);
    glVertex2f( (x) * size, (y + 20.0) * size);
    glVertex2f( (x  + 20.0) * size, (y + 20.0)* size );

  glEnd();


}

void keyPressed(unsigned char Key, int x, int y){
    if(Key == 'a'){
      rotate += 1;

    }
    if(Key == 'd'){
      rotate2 +=1;
    }
    if(Key == 'w'){
      rotate3 +=1;
    }
    glutPostRedisplay();

}

void reshape (int w, int h)
{
   /* set the viewpor dimensions */
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   /* set the viewing parameters */
   glMatrixMode (GL_PROJECTION);
   /* clear the projection stack matrix */
   glLoadIdentity ();
   glFrustum (-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
   /* restore the modeling matrix mode */
   glMatrixMode (GL_MODELVIEW);
}

//Main program
int main(int argc, char **argv){
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(100,100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Window");

 // glClearDepth(1.0f);                   // Set background depth to farthest
  //glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling


  glClearColor(0.0, 0.0, 0.0, 0.0);
  glutReshapeFunc(reshape);
  glClearColor (0.0, 0.0, 0.0, 0.0);

  //Call to the drawing function
  glutDisplayFunc(draw);
  glutKeyboardFunc(keyPressed);
  glutMainLoop();
  return 0;
}


