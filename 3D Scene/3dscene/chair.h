#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>

///CLASS THAT IS USED TO DRAW A CHAIR BY CALLING THE draw_cbd() FUNCTION MULTIPLE TIMES
class Chair{

    public:
        ///This function makes a chair(using multiple cuboids) with center of back rest at (x,y,z).
        ///
        ///@param x X-coordinate of the center of the back rest
        ///@param y Y-coordinate of the center of the back rest
        ///@param z Z-coordinate of the center of the back rest

            void draw_chair(int x, int y, int z);

};

