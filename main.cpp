#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

static GLfloat spin = 0.0;

void display(void){
    //clear the previous pixels
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    //f = floating point,3 vertex,showing the display color,RGB
    glColor3f(1.0,1.0,1.0);
     //build a rectangular shape x1,y1,x2,y2
    glRectf(-25.0,-4.0,25.0,4.0);
    glRectf(-4.0,-25.0,4.0,25.0);
    //change the color of solid torus
    glColor3f(0.0,0.0,1.0);
    //1.00 inner radius,6.4 outer radius
    glutSolidTorus(1.00,6.4,10,100);
    glPopMatrix();
    glFlush();
 }

 void spinDisplay_right1(void){
    //negative means spin in clockwise
    spin = -.20;
    glutPostRedisplay();
    glRotatef(spin,0.0,0.0,1.0);
 }

void init(void){
    glClearColor(1.0,0.0,0.0,0.0);
    //my graph size -50<=x,y<=50
    glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);
}

int a = 0;

//if u press s it will start rotate
//in presence of spin if u press s again it will stop
//hold k to speed up
//hold i to speed down

void my_keyboard(unsigned char key,int x, int y){
    switch(key){
    case 's':
        {
            if(a==0){
                glutIdleFunc(spinDisplay_right1);
                a=1;
            }
            else{
                glutIdleFunc(NULL);
                a=0;
            }
        }
    case 'k':
        {
            glRotatef(-10,0.0,0.0,1.0);
            break;
        }
    case 'i':
        {
            glRotatef(10,0.0,0.0,1.0);
            break;
        }
    default:
        break;
    }
}

int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Rotating Fan");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
