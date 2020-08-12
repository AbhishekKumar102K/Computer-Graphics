#pragma once
#include "bezier_decas.h"
#include "draw.h"
using namespace std;
float bezierDeCas::lerp(float t, float a, float b)
{
    return (1-t)*a + (t*b); // returns the coordinates of the point which divides the line connecting a & b into (t:1-t)
}


pair<float, float> bezierDeCas::Bezier(float u, vector<pair<float,float> > points)
{
    vector<pair<float,float> > q = points;
    int n = points.size(); // total number of points
    for(int k=0;k<n-1;k++)  // n-1 cycles of interpolation
    {
        for(int i=0;i<n-k-1;i++)  //interpolate all the lines, whose count decreases by 1 after each cycle of interpolation
        {
            q[i].first = lerp(u,q[i].first,q[i+1].first); //stores the x-coordinate of the point that divides the line points q[i].first & q[i+1].first in (t:1-t)
            q[i].second = lerp(u,q[i].second,q[i+1].second); //stores the y-coordinate of the point that divides the line points q[i].first & q[i+1].first in (t:1-t)
        }
    }
    return q[0];    // the coordinate of the point on the curve which divides the curve into (t:1-t)
}

void bezierDeCas::draw_curve(vector<pair<float,float> > points)
{
    Draw dw;                        // object of the the draw class
    pair <float, float> p0,p1;
    p0 = Bezier(0.00000,points);    // first point of the line to be drawn
    for(float t=0.00;t<=1.00;t+=0.001)
    {
        p1 = Bezier(t,points);      // the point on the curve which divides the curve into (t:1-t)
        dw.drawLine(p0.first,720-p0.second,p1.first,720-p1.second); // draw the line between p0 & p1
        p0 = p1;
    }
}
