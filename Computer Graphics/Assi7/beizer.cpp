#include <iostream>
#include <GL/glut.h>
#include <Math.h>

using namespace std;

class Points{
	public:
		int x1, y1;
		void setxy(int x, int y){
			x1=x;
			y1=y;
		}
	
};

static int pointsnum = 0;

static Points point[4];

void plotPoint(Points p){
	glBegin(GL_POINTS);
	glPointSize(3.0);
	glVertex2i(p.x1, p.y1);
	glEnd();
	glFlush();
}

void plotLine(Points p1, Points p2){
	glBegin(GL_LINES);
	glVertex2i(p1.x1, p1.y1);
	glVertex2i(p2.x1, p2.y1);
	glEnd();
	glFlush();
}

Points beizer(Points p1, Points p2, Points p3, Points p4, double t){
	Points p;
	double a1 = pow(1-t,3);
	double a2 = pow(1-t,2)*3*t;
	double a3 = (1-t)*3*t*t;
	double a4 = t*t*t;
	
	p.x1 = a1*p1.x1 + a2*p2.x1 + a3*p3.x1 + a4*p4.x1;
	p.y1 = a1*p1.y1 + a2*p2.y1 + a3*p3.y1 + a4*p4.y1;
	
	return p;
}

void mouse(int button, int state, int x,int y){
	


	if(state == GLUT_DOWN){
		point[pointsnum].setxy(x,480-y);
		glColor3f(1,1,1);
		plotPoint(point[pointsnum]);
		glColor3f(1,0,0);
		if (pointsnum > 0) plotLine(point[pointsnum - 1], point[pointsnum]);
		if (pointsnum == 3){		
			
			glColor3f(1, 1, 0);
			Points pstart = point[0];
			for(double t = 0.0;t<=1.0;t += 0.01){
			Points p = beizer(point[0], point[1], point[2], point[3], t);
			plotLine(pstart, p);
			pstart = p;
			}
			pointsnum = 0;
		}
		else{
			pointsnum++;
		}
	
	}
	
	
}

void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(2);
	gluOrtho2D(0,640,0,480);	
	
}

void display(void){}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Beizer Curve");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	
	
	return 0;
}














