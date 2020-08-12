#pragma once
#include <math.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include<conio.h>
#include <vector>
#include "draw.h"
#include "bezier_decas.h"
using namespace std;


//Global Points for x and y coordinates
vector <pair<float,float> > points;

///Vector to check if the mouse is hovering over a point.
///Contains boolean values of hover for each point in the vector points.
vector <bool> hover;

///Variable to check if any point on the screen is selected (hovered)
bool selected = false;

///Vector to check if a point has to move with the cursor.
///Contains boolean values for each point in the vector points.
vector <bool> move_point;



///Initiate values for display
void init(void)
{
	glClearColor(1.0, 1.0, 0.5, 0.0f); //Light blue color for background
	glPointSize(5.0);                  //Point size = 5.0
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
 	gluOrtho2D(0,1280,0,720);           //Set up ortho-graphics matrix
}


///Function that checks if the cursor is hovering over a point and consequently assigns values to the hover and move_point vectors
///
///@param x X-Coordinate of the position of the cursor
///@param y Y-Coordinate of the position of the cursor
void MouseHover(int x, int y)
{
    for(int i=0;i<points.size();i++)
    {
        if(abs(points[i].first-x) < 5 && abs(points[i].second-y) < 5)       //If the distance between center of a point and mouse position
        {                                                                   //is less than 5 pixels, then set it as selected.
            hover[i]=true;
        }
        else
            hover[i] = false;

        if(move_point[i])
        {                                                                   //If move_point is true for any point, assign it
            points[i].first = x;                                            //the new cursor position in each frame till it is
            points[i].second = y;                                           //true.
        }
    }
}

///Function that checks if a mouse button is pressed
///
///@param button Which button on the mouse is pressed
///@param state If the mouse button is pressed/released
///@param x X-Coordinate of the position of the cursor
///@param y Y-Coordinate of the position of the cursor
void MouseButton(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)                  //If any button is pressed
    {
        if(selected)                        //If any point is selected i.e. has cursor hovering on it
        {
            if(button == GLUT_RIGHT_BUTTON) //If right mouse button is clicked
            {
                for(int i=0;i<points.size();i++)            //DELETE THE SELECTED POINT
                {
                    if(hover[i]==true)                      //Check which point is hovered on by the cursor
                    {
                        points.erase(points.begin()+i);     //Erase that point from points, hover and move_point vectors
                        hover.erase(hover.begin()+i);       //so that it is not iterated again in the next frame.
                        move_point.erase(move_point.begin()+i);
                        break;
                    }
                }
            }
            if(button == GLUT_LEFT_BUTTON)              //If the Left Mouse Button is clicked
            {
                for(int i=0;i<points.size();i++)        //MOVE THE SELECTED POINT
                {
                    if(hover[i]==true)                  //Check which point is hovered on by the cursor
                    {                                   //For that point, negate the move_point value
                        move_point[i] = !move_point[i]; //i.e. If it was false; assign it true and vice versa.
                    }
                }
            }

        }
        else                                        //If no point is selected
        {
            if(button == GLUT_LEFT_BUTTON)          //If the Left Mouse Button is clicked
            {                                       //ADD A POINT
                points.push_back(make_pair(x,y));   //Push_back or add the coordinates of the cursor to all the vectors,
                hover.push_back(false);             //points, hover and move_points, thereby adding it to the list of points to be
                move_point.push_back(false);        //iterated through the next frame onwards.
            }
        }
    }

}


void timer(int)
{
    selected = false;                   //no point is selected by default
	glutPostRedisplay();                //Calls the display function again
	glutTimerFunc(1000/60,timer,0);     //waits for 1/60th of a second
	glutPassiveMotionFunc(MouseHover);
	glutMouseFunc(MouseButton);
}

///Display Function that creates the scene and calls the appropriate drawing functions to draw the bezier curve.
void display()
{
    bezierDeCas bdc;                //object of the class bezierDeCas
    Draw dw;                        //object of the class Draw
	glClear(GL_COLOR_BUFFER_BIT);
	if(points.size()>1)             //only start drawing if the number of points is greater than 1
        bdc.draw_curve(points);
    for(int i=0;i<points.size();i++)//Draws dots at all the points on the screen so that they're visible and controllable
    {
        dw.drawDot(points[i].first,points[i].second,hover[i]==false,0,hover[i]==true);      //Draws selected point in blue color and others in red
        selected = selected | hover[i];         //make selected true even if one points is selected
    }

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1280,0,720);
	glMatrixMode(GL_MODELVIEW);
}

//Function to intialize all values
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(0,0);
	cout<<"COMPUTER GRAPHICS - ASSIGNMENT 3\n\n";
	cout<<"This program is used to implement the De-Casteljau's Algorithm for drawing Bezier Curves. \n";
	cout<<"Instead of using recursion, we used Dynamic Programming to implement this algorithm because the recursion \n";
	cout<<"approach takes an exponential number of function calls and is very inefficient and time consuming.\n\n\n";
	cout<<"Instructions : \n";
	cout<<"1)Left click - To add a point\n";
	cout<<"2)Right click - To delete the selected point\n";
	cout<<"3)Left click and drag - To move the selected point\n\n";
    cout<<"Press any key to continue . . . \n\n\n";
	cout<<"--------------THANK YOU--------------";
    getch();
	glutCreateWindow("Bernstein Bezier");
	init();



 	glutDisplayFunc(display);
 	glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
	glutMainLoop();
	return 0;
}
