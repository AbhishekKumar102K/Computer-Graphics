//reader.cpp
#include <GL/freeglut.h>
#include <fstream>
#include<iostream>
#include "reader.h"

using namespace std;


//Initialize all vertices as (0,0,0)
Reader::Reader()
{
    for(int i = 0; i < 5000; i++ ) {
        vertex[i].x = 0;
        vertex[i].y = 0;
        vertex[i].z = 0;
    }

}

Reader::~Reader()
{

}

void Reader::load(char* filename)
{
    ifstream file;
    file.open(filename,ios::in);

    string str;

    while(!file.eof()) //while we are still in the file
    {
        getline(file,str); //move one line down
        if(str[0] == 'v') break; //if we have a vertex line, stop
    }

    int v = 0;

    while(str[0] == 'v') { //while we encounter a 'v'

        int i = 0;

        while(true)
        {
            //x-coord of the vertex
            while(str[i] == ' ' )
            {
                i++; //move a space over
            }
            i++;
            i++;
            int j = i, k = i;
            while(str[i] != ' ') {
                i++;
                k = i;
            }
            vertex[v].x = atof(str.substr(j, k-j).c_str());     //string to float

            //moving on to the y-coord

            while(str[i] == ' ' ) {
                i++;
            }

            int q = i, w = i;
            while(str[i] != ' ' ) {
                i++;
                w = i;
            }
            vertex[v].y = atof(str.substr(q, w-q).c_str());     //string to float


            //moving on to the z-coord
            while(str[i] == ' ' ) {
                i++;
            }

            int a = i, s = i;
            while(str[i] != '\0' ) {
                i++;
                s = i;
            }
            vertex[v].z = atof(str.substr(a, s-a).c_str());     //string to float

            break;
        }
        v++;
        getline(file, str);     //read next line in the file
    }

    while(true)
    {
        getline(file, str);//move one line down
        if(str[0] == 'f' ) {//if we have a face line, stop
            break;
        }
    }

    int i = 0,j=0,k=0;


	    while(str[0]=='f')      //while we encounter a 'f'
	    {
	       	while(str[i] == 'f') i++;


	        while(str[i] == ' ') i++;
	        j = i, k = i;

	        while(str[i] != ' ') {
	            i++;
	            k = i;
	        }

	        int one = atof(str.substr(j, k - j).c_str());      //string to float, first vertex

	        i +=1;

	        j = i;
	        k = i;

	        while(str[i] != ' ') {
	            i++;
	            k = i;
	        }

			int two = atof(str.substr(j, k - j).c_str());       //string to float, second vertex

	        i+=1;

	        j = i;
	        k = i;

	        while(str[i] != '\0') {
	            i++;
	            k = i;
	        }

	        int three = atof(str.substr(j, k - j).c_str());     //string to float, third vertex


			faces[f][0] = one;
			faces[f][1] = two;
			faces[f][2] = three;

	        f++;

	        getline(file, str);         //read next line
	        i = 0;
	    }


}


void Reader::draw(int scale)
{
	for(int i=0;i<f;i++)
	{
		glBegin(GL_TRIANGLES);
		glVertex3f(scale*vertex[faces[i][0] - 1].x, scale*vertex[faces[i][0] - 1].y, scale*vertex[faces[i][0] - 1].z);
		glVertex3f(scale*vertex[faces[i][1] - 1].x, scale*vertex[faces[i][1] - 1].y, scale*vertex[faces[i][1] - 1].z);
		glVertex3f(scale*vertex[faces[i][2] - 1].x, scale*vertex[faces[i][2] - 1].y, scale*vertex[faces[i][2] - 1].z);
		glEnd();
	}
}
