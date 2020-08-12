#include "cuboid.h"

//Function that draws a cuboid with body center at (x,y,z) and with dimensions a x b x c and rgb color value (red,green,blue)
void Cuboid::draw_cbd(float a, float b, float c, float x, float y, float z, float red, float green, float blue)
{
    glTranslatef(x,y,z);

	glBegin(GL_QUADS);

	//front
    glColor3f(red,green,blue);
    glVertex3f(-a/2.0,b/2.0,c/2.0);
    glVertex3f(-a/2.0,-b/2.0,c/2.0);
    glVertex3f(a/2.0,-b/2.0,c/2.0);
    glVertex3f(a/2.0,b/2.0,c/2.0);

    //back
    glVertex3f(a/2.0,b/2.0,-c/2.0);
    glVertex3f(a/2.0,-b/2.0,-c/2.0);
    glVertex3f(-a/2.0,-b/2.0,-c/2.0);
    glVertex3f(-a/2.0,b/2.0,-c/2.0);

    //right
    glVertex3f(a/2.0,b/2.0,c/2.0);
    glVertex3f(a/2.0,-b/2.0,c/2.0);
    glVertex3f(a/2.0,-b/2.0,-c/2.0);
    glVertex3f(a/2.0,b/2.0,-c/2.0);

    //left
    glVertex3f(-a/2.0,b/2.0,-c/2.0);
    glVertex3f(-a/2.0,-b/2.0,-c/2.0);
    glVertex3f(-a/2.0,-b/2.0,c/2.0);
    glVertex3f(-a/2.0,b/2.0,c/2.0);

    //top
    glVertex3f(-a/2.0,b/2.0,-c/2.0);
    glVertex3f(-a/2.0,b/2.0,c/2.0);
    glVertex3f(a/2.0,b/2.0,c/2.0);
    glVertex3f(a/2.0,b/2.0,-c/2.0);

    //bottom
    glVertex3f(-a/2.0,-b/2.0,-c/2.0);
    glVertex3f(-a/2.0,-b/2.0,c/2.0);
    glVertex3f(a/2.0,-b/2.0,c/2.0);
    glVertex3f(a/2.0,-b/2.0,-c/2.0);

    glEnd();
    glTranslatef(-x,-y,-z);
}

