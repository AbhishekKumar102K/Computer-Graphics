#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>

///CLASS THAT IS USED TO DRAW THE EXIT GATE AT TWO EXITS OF THE AUDITORIUM
class Cuboid{

    public:
        ///Functions that draws a cuboid with body center at (x,y,z) and with dimensions a x b x c and rgb color value (red,green,blue)
        ///
        ///@param a X-dimension length of the cuboid
        ///@param b Y-dimension length of the cuboid
        ///@param c Z-dimension length of the cuboid
        ///@param x X-coordinate of the center of the cuboid
        ///@param y Y-coordinate of the center of the cuboid
        ///@param z Z-coordinate of the center of the cuboid
        ///@param red Red value of the rgb color code
        ///@param green Green value of the rgb color code
        ///@param blue Blue value of the rgb color code
            void draw_cbd(float a, float b, float c, float x, float y, float z, float red, float green, float blue);

};

