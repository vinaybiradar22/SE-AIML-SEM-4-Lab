//-lopengl32
//-lfreeglut
//-lglu32


#include <iostream>
#include <Gl/glut.h>
#include <math.h>

using namespace std;

int round(float x){
	int n = (int)(x+0.5);
	return n;
}

void display(int x, int y){
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void dda(){
	float x,y,x1,y1,x2,y2,dx,dy,Xinc,Yinc,i,step;
	x1=10;
	y1=30;
	x2=80;
	y2=-60;

	dx = x2-x1;
	dy = y2-y1;
	
	if(abs(dx)>=abs(dy)){
		step=abs(dx);
	}
	else{
		step=abs(dy);
	}
	
	Xinc=dx/step;
	Yinc=dy/step;
	
	x=x1;
	y=y1;
	
	for(i=0;i<=step;i++){
		display(round(x),round(y));
		cout<<round(x)<<" "<<round(y)<<"\n";
		x += Xinc;
		y += Yinc; 
	}
	glFlush();
	
}

void window(){
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100,100,-100,100);
	
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment 2");
	window();
	glutDisplayFunc(dda);
	glutMainLoop();	
	
	return 0;
}
