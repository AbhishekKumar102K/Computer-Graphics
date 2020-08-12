#pragma once
#include<iostream>
#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "chair.h"
#include "stairs.h"
#include "audi.h"
#include "exitgate.h"
#include "blender_objects.h"
#include "reader.h"
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
using namespace std;


Reader obj1, obj2, obj3;

float anglex = 0,angley=0,anglez=0,pan_z=0,pan_x=0,pan_y=0;
float rate_pan=-2,rate_angle = 2, lx=0.0,ly=0.0,lz=-1.0;

///Initializes the window color as black and calls load() and draw1() functions for each object imported from blender.
///It also enables GL_DEPTH_TEST which causes the viewer to see objects nearer to him over those far from him.
void init()
{
	glClearColor(0,0,0,0);
	AllocConsole();
    freopen( "CON", "wt", stdout );
    freopen( "CON", "wt", stderr );

    obj1.load("speakers.obj");

    obj2.load("mic.obj");

    obj3.load("podium.obj");

	glEnable(GL_DEPTH_TEST);

}

///Defines what to do when the window is resized.
///
///Initialzes the viewport with the dimensions given.
///Switches to Projection Matrix. Replaces the current matrix with identity matrix and calls
///Perspective function to initialize the canonical view volume with appropriate parameters
///@parma w The new width of the window
///@parma h The new height of the window
void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,1.0f,0.1f,5000);
	glMatrixMode(GL_MODELVIEW);
}

float rx = 0, ry = 0, rz = 0,cpz=0,cpx=0,cpy=0;
///Assigns values to various variables based on keyboard keydown input
///which is used to navigate about the scene
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
		pan_z = 0;
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

///Defines objects of various classes whose member function
///are to be used to display the various objects in the scene.
///It also takes care of the matrices needed to navigate around
///the scene
void display()
{
    Chair ch;                       //object of the class Chair
    Exitgate eg;                    //object of the class Exitgate
    Stairs strs;                    //object of the class Stairs
    Blender_imp bimp;               //object of the class Blender_imp
    Audi aud;                       //object of the class Audi
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);               //Clears the input buffer and depth buffer
	glLoadIdentity();               //Loads the identity matrix to the matrix stack


	glRotatef(anglex,1,0,0);        //Rotation about x axis by anglex degrees
	glRotatef(angley,0,1,0);        //Rotation about y axis by angley degrees
	glRotatef(anglez,0,0,1);        //Rotation about z axis by anglez degrees

	glTranslatef(0,-60,420);        //Initial coordinates
	glTranslatef(pan_x,pan_y,pan_z);//Coordinates of the point after moving


	aud.draw_audi();
	strs.draw_stairs();
    eg.draw_exitgate();


    //Placing the chairs in the auditorium using for loops
	int c =1,n=7;
	for(int j=0;j<40;j++)
	{
		for(int i=0;i<7;i++)
		{
			ch.draw_chair(0+i*20,15+5*j,-253+18*j);
			ch.draw_chair(0-i*20,15+5*j,-253+18*j);

		}
	}

	for(int j=0;j<40;j++)
	{
		for(int i=0;i<n-2;i++)
		{
			ch.draw_chair(180+20*i+c*2,15+5*j,-253+18*j);
			ch.draw_chair(-(180+20*i+c*2),15+5*j,-253+18*j);
			if(c%4==0)
			{
				n++;
				c=1;
			}
		}
		c++;
	}


	bimp.make_mic(0,50,-450,obj2);                      //displays the mic
	bimp.make_speakers(200,280,-410,90,0,90,2,obj1);    //displays the front speaker
	bimp.make_speakers(-200,280,-410,90,0,90,2,obj1);   //displays the front speaker
	bimp.make_speakers(340,230,-150,90,198,0,1,obj1);   //displays the side speaker
	bimp.make_speakers(-340,230,-150,90,198,0,1,obj1);  //displays the side speaker
	bimp.make_speakers(420,300,90,90,198,0,1,obj1);     //displays the side speaker
	bimp.make_speakers(-420,300,90,90,198,0,1,obj1);    //displays the side speaker
	bimp.make_podium(-150,66,-450,obj3);                //displays the podium
	glutSwapBuffers();
	glFlush();



}



///Causes the display function to be called 60 times per second.
///Hence keeps the frame rate of the animation to be 60fps.
///This function also takes care of the keyboard input and changes in the related
///values.
void timer(int)
{
	glutPostRedisplay();                //Calls the display function again
	glutTimerFunc(1000/60,timer,0);     //waits for 1/60th of a second
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

///Initializes the display modes and creates a window with appropriate position and size
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG Assignment 2");
	init();
	cout<<system("dir");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutMainLoop();
	return 0;
};

