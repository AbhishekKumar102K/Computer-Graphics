
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;
void display();
void reshape(int , int);

void printCircle(int, int, int);
void Draw_Circle(int,int,int ,int);
int xoff,yoff,r;

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}
int main(int argc, char** argv)
{
    cout<<"Enter the Coordinates of the center\n";
    cout<<"Enter the X-coordinate :";
    cin>>xoff;
    cout<<"Enter the Y-coordinate :";
    cin>>yoff;
    cout<<"Enter the radius of the circle :";
    cin>>r;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(720,720);

	glutCreateWindow("Window 1");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}

/**
  *This function uses the 8 way symmetry of circles and replicates any point (x,y) along y=x, y=-x lines keeping center as origin
  @param x X coordinate of pixel to be illuminated
  @param y Y coordinate of pixel to be illuminated
  @param xoff X coordinate of center
  @param yoff Y coordinate of center
*/
void Draw_Circle(int x, int y, int xoff, int yoff)
{
	glVertex2f(xoff+x,yoff+y);
	glVertex2f(xoff-x,yoff+y);
	glVertex2f(xoff+x,yoff-y);
	glVertex2f(xoff-x,yoff-y);
	glVertex2f(xoff+y,yoff+x);
	glVertex2f(xoff-y,yoff+x);
	glVertex2f(xoff+y,yoff-x);
	glVertex2f(xoff-y,yoff-x);
}



/**
  *This function uses the 8 way symmetry of circles and replicates any point (x,y) along y=x, y=-x lines keeping center as origin
  @param xoff X coordinate of center
  @param yoff Y coordinate of center
  @param r radius of the circle
*/
void printCircle(int xoff, int yoff, int r)
{
	int radius = r;
	int x=0;
	int y=radius;
	int d= 1-radius;
	int deltaE = 3;
	int deltaSE = -2*radius + 5;
	Draw_Circle(x,y,xoff,yoff);

	while(y>x)
	{
		if(d<0)
		{
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else
		{
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		Draw_Circle(x,y,xoff,yoff);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,0,0);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	printCircle(xoff,yoff,r);
	glEnd();
	glFlush();
}


void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
}
