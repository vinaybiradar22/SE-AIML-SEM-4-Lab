//-lopengl32
//-lfreeglut
//-lglu32


#include <iostream>
#include <Gl/glut.h>
#include <math.h>

using namespace std;

void display(int x, int y){
	
	glBegin(GL_POINTS);
	glColor3f(0,1,0);
	glVertex2i(x,y);
	glEnd();
}

void quadrant(){
	int xmax = glutGet(GLUT_WINDOW_WIDTH);
	int ymax = glutGet(GLUT_WINDOW_HEIGHT);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(xmax / 2, 0);
	glVertex2i(xmax / 2, ymax);
	glVertex2i(0, ymax / 2);
	glVertex2i(xmax, ymax / 2);
	glEnd();
}

void circle(int m, int n)
{	
	int xmax = glutGet(GLUT_WINDOW_WIDTH);
	int ymax = glutGet(GLUT_WINDOW_HEIGHT);
	int x = xmax/2;
	int y = ymax/2;
	
    display(x+m, y+n);
    display(x-m, y+n);
    display(x+m, y-n);
    display(x-m, y-n);
    display(x+n, y+m);
    display(x-n, y+m);
    display(x+n, y-m);
    display(x-n, y-m);
}

void circleBres()
{
	int x = 10, y = 10, r = 50;
    int m = 0, n = r;
    int d = 3 - 2 * r;
    
    
    while (m<=n)
    { 
      
        if (d >= 0)
        {
            n--; 
            m++;
            
            d = d + (4 * (m - n)) + 10;
            circle(m, n);
        }
        else{
        	m++;
        	d = d +( 4 * m)+ 6;
        	circle( m, n);
        	
		}
            
    }
}


void window(){
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	quadrant();
	circleBres();
	glFlush();
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment 3");
	glutDisplayFunc(window);
	glutMainLoop();	
	
	return 0;
}
