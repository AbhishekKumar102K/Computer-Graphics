#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>


///CLASS THAT IS USED TO DRAW THE EXIT GATE AT TWO EXITS OF THE AUDITORIUM
class Exitgate{

    public:

        ///Function that draws two rectangles at the appropriate position so as to represent the exit gates near the stage
            void draw_exitgate();

};


