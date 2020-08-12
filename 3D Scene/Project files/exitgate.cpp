#include "exitgate.h"
//FUNCTION THAT DRAWS THE EXIT GATES
void Exitgate::draw_exitgate()
{

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-272.0,0.0,-381.0);
    glVertex3f(-272.0,100.0,-381.0);
    glVertex3f(-297.0,100.0,-300.0);
    glVertex3f(-297.0,0.0,-300.0);


    glVertex3f(272.0,0.0,-381.0);
    glVertex3f(272.0,100.0,-381.0);
    glVertex3f(297.0,100.0,-300.0);
    glVertex3f(297.0,0.0,-300.0);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(271.0,0.0,-390.0);
    glVertex3f(271.0,100.0,-390.0);
    glVertex3f(301.0,100.0,-300.0);
    glVertex3f(301.0,0.0,-300.0);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(271.0,0.0,-390.0);
    glVertex3f(271.0,100.0,-390.0);
    glVertex3f(301.0,100.0,-300.0);
    glVertex3f(301.0,0.0,-300.0);
    glEnd();

}
