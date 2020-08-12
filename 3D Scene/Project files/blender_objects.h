#include<windows.h>
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include "reader.h"
#include<GL/gl.h>


///CLASS THAT IS USED TO DISPLAY THE OBJECTS IMPORTED FROM BLENDER
class Blender_imp{

    public:

            ///This function draws the speakers at required coordinates and angle by calling the Reader class object
            ///that loads the "speakers.obj" file
            ///
            ///@param x X-coordinate of the center of the object imported
            ///@param y Y-coordinate of the center of the object imported
            ///@param z Z-coordinate of the center of the object imported
            ///@param ax Angle to be rotated about x-axis
            ///@param ay Angle to be rotated about y-axis
            ///@param az Angle to be rotated about z-axis
            ///@param obj Reader file object that loads the "speakers.obj" file
            void make_speakers(int x, int y, int z, int ax, int ay, int az, int, Reader obj);


             ///This function draws the podium at required coordinates and angle by calling the Reader class object
            ///that loads the "podium.obj" file
            ///
            ///@param x X-coordinate of the center of the object imported
            ///@param y Y-coordinate of the center of the object imported
            ///@param z Z-coordinate of the center of the object imported
            ///@param obj Reader file object that loads the "podium.obj" file
            void make_podium(int x, int y, int z, Reader obj);


             ///This function draws the mic at required coordinates and angle by calling the Reader class object
            ///that loads the "mic.obj" file
            ///
            ///@param x X-coordinate of the center of the object imported
            ///@param y Y-coordinate of the center of the object imported
            ///@param z Z-coordinate of the center of the object imported
            ///@param obj Reader file object that loads the "mic.obj" file
            void make_mic(int x, int y, int z, Reader obj);


};


