#include "stairs.h"

//CLASS THAT IS USED TO DRAW THE STAIRS TO THE STAGE
void Stairs::draw_stairs()
{
    float y1n=0.0,x1n=310,z1n=-270,c1,c2;


    while(z1n<450)
    {
        glBegin(GL_QUADS);
        float yp=y1n,xp=x1n,zp=z1n;
        y1n+=5,z1n+=18,x1n+=6;

        // stairs_Front_Side
        glColor3f(0.2,0.2,0.2);
        glVertex3f(-xp,yp,zp);
        glVertex3f(-xp,y1n,zp);
        glVertex3f(xp,y1n,zp);
        glVertex3f(xp,yp,zp);


        // Stair_Floor
        glColor3f(215.0/256,174.0/256,175.0/256);
        glVertex3f(-xp,y1n,zp);
        glVertex3f(-x1n,y1n,z1n);
        glVertex3f(x1n,y1n,z1n);
        glVertex3f(xp,y1n,zp);
		c1 = zp;
		c2 = xp;
        glEnd();
    }
    glBegin(GL_QUADS);
    glVertex3f(-c2,y1n,c1);
    glVertex3f(c2,y1n,c1);
    glVertex3f(600,y1n,600);
    glVertex3f(-600,y1n,600);
    glEnd();

}

