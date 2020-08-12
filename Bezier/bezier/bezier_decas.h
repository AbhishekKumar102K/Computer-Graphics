#include <math.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include<conio.h>
#include <GL/glut.h>
#include <stdio.h>
#include <vector>

using namespace std;

class bezierDeCas
{
public:
    /// This function divides the line joining a & b in the (t:1-t)
    /// @param t It is the ratio in which the line is divided
    /// @param a the first coordinate of the line joining (May be x & y)
    /// @param b the second coordinate of the line joining (May be x & y)
    float lerp(float t, float a, float b);

    ///This function finds the point at parameter 'u' (x(u)) on the curve joining the first point and the last point in the points vector pair.
    /// @param u The parameter that decides the ratio in which the line is divided.
    /// @param points The vector pair that stores the coordinates of the all the points on the screen
    pair<float, float> Bezier(float u, vector<pair<float,float> > points);

    /// This function draws the curve between points p0 and p1 using drawline() function.
    /// @param points The vector pair that stores the coordinates of the all the points on the screen
    void draw_curve(vector<pair<float,float> > points);
};

