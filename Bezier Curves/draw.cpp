#pragma once
#include "draw.h"

 //Drawing a point
void Draw::drawDot(int l, int m, float r, float g, float b)
{
    glColor3f(r,g,b);
	glBegin(GL_POINTS);
	glVertex2i(l,720-m);
	glEnd();
}

//Draw line between passed set of 2 points
void Draw::drawLine(float l,float m, float j, float i)
{
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(l,m);    //first point coordinates
	glVertex2f(j,i);    //second point coordinates
	glEnd();
}
