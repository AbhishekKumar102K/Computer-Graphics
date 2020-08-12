#pragma once
#include "draw.h"
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

//FUNCTION TO ILLUMINATE PIXELS BY 8-WAY SYMMETRY
void Draw_Circle(int x, int y, int xoff, int yoff)
{
	glVertex2f(xoff+x,yoff+y);						//XOFF - X_COORDINATE OF THE CENTRE
	glVertex2f(xoff-x,yoff+y);
	glVertex2f(xoff+x,yoff-y);						//YOFF - Y_COORDINATE OF THE CENTRE
	glVertex2f(xoff-x,yoff-y);
	glVertex2f(xoff+y,yoff+x);
	glVertex2f(xoff-y,yoff+x);
	glVertex2f(xoff+y,yoff-x);
	glVertex2f(xoff-y,yoff-x);
}

//FUNCTION TO DRAW A LINE BETWEEN TWO POINTS USING BRESENHAM'S LINE DRAWING ALGORITHM
//WHEN SLOPE IS <=1, ILLUMINATING 1 PIXEL PER COLUMN
void draw_line1(int x1, int y1, int x2, int y2)
{
	int k = y2 > y1 ? 1 : -1;
	int dx = x2 - x1;
	int dy = abs(y2 - y1);
	int d = 2 * dy - dx;
	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	int x = x1;
	int y = y1;
	glVertex2f(x,y);
	while (x < x2)
	{
		if (d <= 0)
			d += incrE;
		else
		{
			d += incrNE;
			y += k;
		}
		x += 1;
		glVertex2f(x,y);
	}
}

//FUNCTION TO DRAW A LINE BETWEEN TWO POINTS USING BRESENHAM'S LINE DRAWING ALGORITHM
//WHEN SLOPE IS >1, ILLUMINATING 1 PIXEL PER ROW
void draw_line2(int x1, int y1, int x2, int y2)
{
	int k = x2 > x1 ? 1 : -1;
	int dx = abs(x2 - x1);
	int dy = y2 - y1;
	int d = 2 * dx - dy;
	int incrE = 2 * dx;
	int incrNE = 2 * (dx - dy);
	int x = x1;
	int y = y1;
	glVertex2f(x,y);
	while (y < y2)
	{
		if (d <= 0)
			d += incrE;
		else
		{
			d += incrNE;
			x += k;
		}
		y += 1;
		glVertex2f(x,y);
	}
}

//TO DECIDE WHICH FUNCTION TO CALL(draw_line1 or draw_line2) BASED ON SLOPE
void line(int x1, int y1, int x2, int y2)
{
	if ((x2 >= x1) && (y2 >= y1))
	{
		if (x2 - x1 > y2 - y1)
			draw_line1(x1, y1, x2, y2);
		else
			draw_line2(x1, y1, x2, y2);
	}
	else if ((x2 >= x1) && (y2 < y1))
	{
		if (x2 - x1 > y1 - y2)
			draw_line1(x1, y1, x2, y2);
		else
			draw_line2(x2, y2, x1, y1);
	}
	else
		line(x2, y2, x1, y1);
}

//BRESEMHAM'S CIRCLE DRAWING ALGORITHM TO DRAW A CIRCLE WITH RADIUS R, CENTRE AT *(XOFF,YOFF)
void printCircle(int xoff, int yoff, int r)
{
	int radius = r;
	int x=0;
	int y=radius;
	int d= 1-radius;
	int deltaE = 3;
	int deltaSE = -2*radius + 5;
	Draw_Circle(x,y,xoff,yoff);

	while(y>x)								//DRAW ONLY 1/8 OF THE CIRCLE
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
		Draw_Circle(x,y,xoff,yoff);			//8-WAY SYMMETRY
	}
}

