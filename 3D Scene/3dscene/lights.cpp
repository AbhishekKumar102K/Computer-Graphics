#include "lights.h"

//CLASS THAT IS USED TO DRAW THE LIGHT ON THE CEILING
void Light::draw_light()
{
    glColor4f(163/256,215/256.0,227/256.0,0.4);
    glBegin(GL_QUADS);
    for(int x=-140;x<=140;x+=140)
    {
        for(int z=-400;z<=540;z+=90)
        {
            int d = 5;

            glVertex3f(x+d,330+(200*((z+d+420)/1200.0))-1,z+d);
            glVertex3f(x-d,330+(200*((z+d+420)/1200.0))-1,z+d);
            glVertex3f(x-d,330+(200*((z-d+420)/1200.0))-1,z-d);
            glVertex3f(x+d,330+(200*((z-d+420)/1200.0))-1,z-d);

        }
    }

    for(int x=220, z = -400;x<=580;x+=40,z+=120)
    {
            int d = 5;
        for(int j=-1;j<=1;j+=2)
        {
            glVertex3f(j*(x+d),330+(200*((z+d+420)/1200.0))-1,z+d);
            glVertex3f(j*(x-d),330+(200*((z+d+420)/1200.0))-1,z+d);
            glVertex3f(j*(x-d),330+(200*((z-d+420)/1200.0))-1,z-d);
            glVertex3f(j*(x+d),330+(200*((z-d+420)/1200.0))-1,z-d);
        }
    }

    glEnd();
}

