#include "cgtree.h"
#include "draw.h"
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<iostream>
#include<time.h>
#include<queue>

///Take minimum separation between two nodes to be 1 unit.
#define minsep 1
using namespace std;

///Initializes the OpenGL window.
///
///Clears the OpenGL color buffer. 
///Sets the pen color to blue. 
///Sets the Point size as 1.5. Calls the inorder() function to draw the circles and lines at the appropriate positions.
void display();

///Defines what to do when the window is resized.
///
///Initialzes the viewport with the dimensions given. Switches to Projection Matrix. Replaces the current matrix with identity matrix and breaks the viewport into
///a specified number of sections
///@parma w The new width of the window
///@parma h The new height of the window
void reshape(int , int);

///Initalizes the window color as white
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}

///Root of the tree
record *root; 		

///Calls all the functions to be executed and asks the user for an input to the menu driver program
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	int n,option,label;
	extreme lmost, rmost;
	label:
	cout<<"Computer Graphics Assignment 1"<<endl;
	cout<<"Abhishek Kumar - 2018A4PS0653H \nShubham Asopa - 2018A7PS0101H\n";
	cout<<endl<<"This program is used to draw Tidy Trees using the TR Algorithm\n\n";
	cout<<"Select input method:\n";
	cout<<"1) Complete Binary Tree with n nodes"<<endl;
	cout<<"2) Custom Input\n";
	cin>>option;
	if(option==1)
	{
		system("cls");
		cout<<"Enter the number of nodes\n";
		cin>>n;
		FormTree(&root,n);
	}
	else if(option == 2)
	{
		system("cls");
		cout<<"Input takes place in the following manner(recursively):\n";
		cout<<"Father -> Left subtree -> Right subtree\n\n";
		cout<<"1) Input a number as the info of the node \n";
		cout<<"2) Input -1 to not add a node at the current position \n";
		cout<<"\nExample input : 	1 2 3 -1 -1 -1 4 -1 -1 \n\n\n";	
		cout<<"This will give us the tree\n\n";
		cout<<"       \t\t                 1    \n";
		cout<<"       \t\t               2   4  \n";
		cout<<"       \t\t             3        \n";
		input(&root,0,root);
	}
	else
	{
		cout<<"Please select 1 or 2";
		Sleep(1000);
		system("cls");
		goto label;
	}
	
	clock_t start = clock();
	setup(root,0,rmost,lmost);
    Petrify(root,0);
    
	glutInitWindowPosition(200,100);
	glutInitWindowSize(1280,720);
	
	glutCreateWindow("Window 1");

	glutDisplayFunc(display);
	
	glutReshapeFunc(reshape);
	init();
	clock_t end = clock();
    double duration = (end-start)/(double)CLOCKS_PER_SEC;
    system("cls");
	cout<<"Time taken  = "<<duration<<endl;	
	glutMainLoop();
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,0,1.0);
	
	glPointSize(1.5);
	glBegin(GL_POINTS);
	
	inorder(root);

	glEnd();	
	glFlush();
}


void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1280,1280,-1440,100);
	glMatrixMode(GL_MODELVIEW);
}
