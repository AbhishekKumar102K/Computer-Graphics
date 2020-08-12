#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<iostream>

using namespace std;
void display();
void reshape(int , int);

void draw_line2(int,int,int,int);
void draw_line1(int, int,int,int);
void line(int,int,int,int);



void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}
int xo,yo,x1,y1;
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	cout<<"Enter coordinates of the two end points of the line\n";
	cout<<"xo = ";
	cin>>xo;
	cout<<"yo = ";
	cin>>yo;
	cout<<"x1 = ";
	cin>>x1;
	cout<<"y1 = ";
	cin>>y1;

	glutInitWindowPosition(200,100);
	glutInitWindowSize(1280,720);

	glutCreateWindow("Window 1");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}

/**
    *This Function implements the Bresenham's Line Drawing Algorithm for |slope| <=1
    @param x1 X coordinate of the first point
    @param y1 Y coordinate of the first point
    @param x2 X coordinate of the second point
    @param y2 Y coordinate of the second point
*/
void line1(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;               // change in x
	int dy = abs(y2 - y1);          // change in y
	int d = 2 * dy - dx;            // initial decision parameter
	int incrE = 2 * dy;             // increment in east direction
	int incrNE = 2 * (dy - dx);     // increment in north east direction
	int x = x1;
	int y = y1;
	glVertex2f(x,y);                // Plot pixel
	while (x < x2)
	{
		if (d <= 0)                 //If midpoint is above the line then increment by incrE
			d += incrE;
		else
		{
			d += incrNE;            //If midpoint lies below the line then increment by incrNE
			if(y2>y1)               //If slope of the line is positive, increment y
                y++;
            else
                y--;                //If slope of the line is negative, decrement y
		}
		x ++;                       //One pixel per column
		glVertex2f(x,y);
	}
}
/**
    *This Function implements the Bresenham's Line Drawing Algorithm for |slope| > 1
    @param x1 X coordinate of the first point
    @param y1 Y coordinate of the first point
    @param x2 X coordinate of the second point
    @param y2 Y coordinate of the second point
*/
void line2(int x1, int y1, int x2, int y2)
{
	int dx = abs(x2 - x1);          // change in x
	int dy = y2 - y1;               // change in y
	int d = 2 * dx - dy;            // initial decision parameter
	int incrE = 2 * dx;             // increment in east direction
	int incrNE = 2 * (dx - dy);     // increment in north east direction
	int x = x1;
	int y = y1;
	glVertex2f(x,y);                // Plot pixel
	while (y < y2)
	{
		if (d <= 0)
			d += incrE;             //If midpoint is above the line then increment by incrE
		else
		{
			d += incrNE;            //If midpoint is above the line then increment by incrNE
			if(x2>x1)
                x++;                //If slope of the line is positive
            else
                x--;                //If slope of the line is negative
		}
		y ++;                       //One pixel per row
		glVertex2f(x,y);            //Plot pixel
	}
}

/**
    *This Function checks the slope of the given line and then decides whether to call line1() (if |slope|<=1) or line2() (if |slope|>1)
    @param x1 X coordinate of the first point
    @param y1 Y coordinate of the first point
    @param x2 X coordinate of the second point
    @param y2 Y coordinate of the second point
*/

void line(int x1, int y1, int x2, int y2)
{
	if ((x2 >= x1) && (y2 >= y1))           //if (x1,y1) is to the left of and below (x2,y2)
	{
		if (x2 - x1 > y2 - y1)              //|slope| < 1
			line1(x1, y1, x2, y2);
		else                                //|slope| >=1
			line2(x1, y1, x2, y2);
	}
	else if ((x2 >= x1) && (y2 < y1))       //if (x1,y1) is to the left of and above (x2,y2)
	{
		if (x2 - x1 > y1 - y2)              //|slope| < 1
			line1(x1, y1, x2, y2);
		else
			line2(x2, y2, x1, y1);          //|slope| >=1
	}
	else
		line(x2, y2, x1, y1);               //Interchange (x1,y1) and (x2,y2)
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,0,0);

	glPointSize(1.0);
	glBegin(GL_POINTS);
	line(xo,yo,x1,y1);

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
