#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>


///CLASS THAT IS USED TO DRAW THE LIGHT ON THE CEILING
class Light{

    public:
        ///This Function draws blue colored squares at the appropriate positions on the ceiling
            void draw_light();

};
