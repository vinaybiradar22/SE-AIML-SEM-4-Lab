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

void drawLine(int x1, int y1, int x2, int y2, int x3, int y3){
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	
	glVertex2i(x1, y1);
	glVertex2i(x3, y3);
	
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);

	glEnd();
}

void reflect(int x1, int y1, int x2, int y2, int x3, int y3 ){
	drawLine(x1, y1, x2, y2, x3, y3);
	x2 =-x2;
	x3=-x3;
	drawLine(x1, y1, x2, y2, x3, y3);
}



void scale(int x1, int y1, int x2, int y2, int x3, int y3 ){
//	int sfx,sfy;
//	cout<<"Enter scaling factor for x & y : ";
//	cin>>sfx>>sfy;

	int sfx = 3, sfy = 2;
	drawLine(x1, y1, x2, y2, x3, y3);
	
	x1 = x1*sfx;
	y1 = y1*sfy;
	
	x2 = x2*sfx;
	y2 = y2*sfy;
	
	x3 = x3*sfx;
	y3 = y3*sfy;
	
	
	drawLine(x1, y1, x2, y2, x3, y3);
	
	
}

void rotate(int x1, int y1, int x2, int y2){
//	int deg;
//	cout<<"Enter rotating angle for x & y : ";
//	cin>>deg;

	double deg =60;
	deg = deg/90;
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	
	x1 = x1*cos(deg) - y1*sin(deg);
	y1 = x1*sin(deg) + y1*cos(deg);
	
	x2 = x2*cos(deg) - y2*sin(deg);
	y2 = x2*sin(deg) + y2*cos(deg);
	
//	x3 = x3*cos(deg) - y3*sin(deg);
//	y3 = x3*sin(deg) + y3*cos(deg);
	
	
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	
	
}



void menu()
{
	int x1=10, y1=40, x2=10, y2=150, x3=80, y3=40;

//	int x1=50, y1=100, x2=500, y2=150, x3=50, y3=40;
	int op;
	cout<<"Enter Operation you want to do: \n";
	cout<<"**********Menu*********"<<"\n";
	cout<<"1. Scaling\n";
	cout<<"2. Rotate\n";
	cout<<"3. Reflection\n";
	cin>>op;
	if(op==1){
		scale(x1, y1, x2, y2, x3, y3);
	}
	else if(op==2){
		rotate(x1, y1, x2, y2);
	}
//	else if(op==3){
//		reflect(x1, y1, x2, y2, x3, y3);
//	}

//	int x1=10, y1=40, x2=10, y2=150, x3=80, y3=40;

//	scale(x1, y1, x2, y2, x3, y3);
//	rotate(x1, y1, x2, y2);
	
}


void window(){
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(500,-500,500,-500);
//	quadrant();
	menu();
	glFlush();
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment 6");
	glutDisplayFunc(window);
	glutMainLoop();	
	
	return 0;
}
