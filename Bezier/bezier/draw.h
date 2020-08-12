#include <math.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include<conio.h>
#include <GL/glut.h>
#include <stdio.h>
#include <vector>


class Draw
{
public:

    ///This function draws a point at the point (l,720-m) having color value (r,g,b).
    ///
    ///@param l x coordinate of the point to be drawn
    ///@param m y coordinate of the point to be drawn
    ///@param r red value of the color of the point to be drawn
    ///@param g green value of the color of the point to be drawn
    ///@param b blue value of the color of the point to be drawn
    void drawDot(int l, int m, float r, float g, float b);


    ///This function draws a line between points (l,m) & (j,i).
    ///
    ///@param l x coordinate of the first point to be drawn
    ///@param m y coordinate of the first point to be drawn
    ///@param l j coordinate of the second point to be drawn
    ///@param m i coordinate of the second point to be drawn
    void drawLine(float l,float m, float j, float i);

};

