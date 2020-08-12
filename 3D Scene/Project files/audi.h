#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>


///CLASS THAT IS USED TO MAKE THE BASIC AUDITORIUM FEATURES AND BOUNDARIES
class Audi{

    public:
///This function draws the Auditorium surrounding walls, the stage, stairs to the stage, the screen, and lights on the ceiling
///by calling the required functions.
            void draw_audi();

};

