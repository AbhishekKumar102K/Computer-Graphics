#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>

///CLASS THAT IS USED TO DRAW THE STAIRS TO THE STAGE
class Stairs{

    public:
        ///Function that draws the stairs at the required position using while loop
            void draw_stairs();

};

