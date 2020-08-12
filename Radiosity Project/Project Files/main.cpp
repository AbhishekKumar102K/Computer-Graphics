#pragma once
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<fstream>
#include "triple.h"
#include "Scene.h"
#include<math.h>

using namespace std;

float anglex = 0,angley=0,anglez=0,pan_z=-2,pan_x=0,pan_y=0;
float rate_pan=-1,rate_angle = 2, lx=0.0,ly=0.0,lz=-1.0;
float rx = 0, ry = 0, rz = 0,cpz=0,cpx=0,cpy=0;
int ch;


///Initializes the object of the class Scene
Scene scene;

///Initiate values for display
void init(int a)
{
	glClearColor(0,0,0,0);              //Black background color

    glEnable(GL_DEPTH_TEST);            //To enable Z-Buffer
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    /*To load the roomobj file*/
    if(a==1)
        scene.loadFromOBJFile("C:/Users/abhis/OneDrive/Documents/Computer Graphics OpenGL/Glut/New folder (2)/25thapril/radiosity_final1/roomopen_bigcube2.obj");
    else
        scene.loadFromOBJFile("C:/Users/abhis/OneDrive/Documents/Computer Graphics OpenGL/Glut/New folder (2)/25thapril/radiosity_final1/room_lit7.obj");

    scene.calculateFormFactors();           //Calculates form factors for the scene
    scene.calculateRadiosities();           //Called calculateRadiosities() twice as light emitting objects may be stored after the
    scene.calculateRadiosities();           //non emitting ones in the faces array. And since radiosity is calculated in an
    scene.calculateRadiosities();           //increasing index fashion, we need to call it again to incorporate the light effect.

    scene.interpolate();                    //Interpolates color of every vertex based on the number of faces it is a part of
}

///Assigns values to various variables based on keyboard key down input
///
///@param key char value of the key pressed
///@param x X coordinate of the cursor
///@param y Y coordinate of the cursor
void keyboard(unsigned char key, int x, int y)
{

	if(key=='d')
	{
		ry = rate_angle;             //Add to angley
	}
	else if(key=='a')
	{
		ry = -rate_angle;            //Add to angley
	}
	else if(key=='s')
	{
		rx = rate_angle;             //Add to anglex
	}
	else if(key=='w')
	{
		rx = -rate_angle;            //Add to anglex
	}
	else if(key=='q')
	{
		rz = rate_angle;            //Add to anglez
	}
	else if(key=='e')
	{
		rz = -rate_angle;           //Add to anglez
	}
	else if(key=='r')      //Reset position
	{
		anglex = 0;
		angley = 0;
		anglez = 0;
		pan_x = 0;
		pan_y = 0;
		pan_z = -2;
	}
	else if(key=='o')
		cpy = rate_pan;            //Move upwards
	else if(key=='l')
		cpy = -rate_pan;            //Move downwards
	else if(key=='k')
	{
		cpx = sin((angley*M_PI/180.0)-M_PI/2.0)*rate_pan;            //Pan left
		cpz = -cos((angley*M_PI/180.0)-M_PI/2.0)*rate_pan;
	}
	else if(key==';')
	{
		cpx = sin((angley*M_PI/180.0)+M_PI/2.0)*rate_pan;            //Pan right
		cpz = -cos((angley*M_PI/180.0)+M_PI/2.0)*rate_pan;
	}
	else if(key=='=')
	{
		cpx = lx*rate_pan;                                            //Move inwards
		cpz = lz*rate_pan;
	}
	else if(key=='-')
	{
		cpx = -lx*rate_pan;                                           //Move backwards
		cpz = -lz*rate_pan;
	}
	else
	{
		rx = ry = rz = 0;

	}

}

///Assigns values to various variables based on keyboard key release input
///
///@param key char value of the key pressed
///@param x X coordinate of the cursor
///@param y Y coordinate of the cursor
void keyboard_up(unsigned char key, int x, int y)
{

	if(key=='d' || key=='a')
	{
		ry = 0;                             //Stop change in angley
	}
	else if(key=='w' || key=='s')
	{
		rx = 0;                             //Stop change in anglex
	}
	else if(key=='q' || key=='e')
	{
		rz = 0;                             //Stop change in anglez
	}
	else if(key=='o' || key=='l')           //Stop change in pany
	{
		//cpx = 0;
		//cpz = 0;
		cpy = 0;
	}
	else if(key=='k' || key==';')           //Stop panning
	{
		cpx = 0;
		cpz = 0;
	}
	else if(key=='-' || key=='=')           //Stop moving inwards and backwards
	{
		cpx = 0;
		cpz = 0;
	}
	else
	{
		rx = ry = rz = cpx = cpy = cpz = 0;     //Change nothing if no key is pressed
	}

}


///Display Function that creates the scene and calls the render() function that draws the faces on to the window.
///Also takes care of the transformation matrices required to navigate about the scene.
void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);               //Clears the input buffer and depth buffer
	glLoadIdentity();               //Loads the identity matrix to the matrix stack


	glRotatef(anglex,1,0,0);        //Rotation about x axis by anglex degrees
	glRotatef(angley,0,1,0);        //Rotation about y axis by angley degrees
	glRotatef(anglez,0,0,1);        //Rotation about z axis by anglez degrees

	glTranslatef(pan_x,pan_y,pan_z);//Coordinates of the point after moving

    scene.render();                 //draws all the faces with the color assigned by vertexColors


    glEnd();
	glutSwapBuffers();
	glFinish();



}

///Sets up the viewport and initializes the perspective matrix with appropriate values of near and far plane
void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,1.0f,0.1f,5000);
	glMatrixMode(GL_MODELVIEW);
}


///Calls the display function 60 times a second, thereby, making fps = 60
///This leads to smooth motion of navigation
///All the changes in rotation and translation matrix variables are also made here as they need to be checked in each frame
void timer(int)
{
	glutPostRedisplay();                //Calls the display function again
	glutTimerFunc(1000/60,timer,0);     //waits for 1/60th of a second

	if(ch==2)
    {
        glutKeyboardFunc(keyboard);         //Keyboard down event
        glutKeyboardUpFunc(keyboard_up);    //Keyboard up event

        anglex += rx;                       //rotation about x axis by rx degrees anti clockwise(rx may be negative)
        angley += ry;                       //rotation about y axis by ry degrees anti clockwise(ry may be negative)
        anglez += rz;                       //rotation about z axis by rz degrees anti clockwise(rz may be negative)
        lx = sin(angley*M_PI/180.0);        //component of direction facing vector about x axis
        lz = -cos(angley*M_PI/180.0);       //component of direction facing vector about z axis
        pan_x += cpx;                       //translate along x axis by cpx (cpx may be negative)
        pan_y += cpy;                       //translate along x axis by cpy (cpy may be negative)
        pan_z += cpz;                       //translate along x axis by cpz (cpz may be negative)

        if(anglex>360.0)
            anglex = anglex-360.0;          //to avoid large angles
        if(angley>360.0)
            angley = angley-360.0;
        if(anglez>360.0)
            anglez = anglez-360.0;
    }
}

///Main function that calls all the functions needed to execute the program properly
int main(int argc, char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(800,800);

	cout<<"COMPUTER GRAPHICS PROJECT - IMPLEMENTATION OF RADIOSITY (Modeling the Interaction of Light Between Diffuse Surfaces)\n\n";
	cout<<"Press 1) to load the scene as in the research paper (non navigable)\n";
	cout<<"Press 2) to load a custom scene we created - navigable(This may take a while \n\t to load due to large number of faces) \n";
	cout<<"Pitch :  Use W and S\n";
	cout<<"Yaw :  Use A and D\n";
	cout<<"Roll :  Use Q and E\n";
	cout<<"Pan :  Use O,K,L and ; \n";
	cout<<"Lift/Drop :  Use - and =\n";

	cin>>ch;


	glutCreateWindow("Project Radiosity");
	init(ch);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutMainLoop();
	return 0;
};

