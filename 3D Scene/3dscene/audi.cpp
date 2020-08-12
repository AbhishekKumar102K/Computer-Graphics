#include "audi.h"
#include "lights.h"

//FUNCTION THAT IS USED TO MAKE THE BASIC AUDITORIUM FEATURES AND BOUNDARIES
void Audi::draw_audi()
{
    Light l;                        //Object of the class Light used to call the draw_light() function
    l.draw_light();
	glColor3f(0.6,0.6,0.6);
	glBegin(GL_POLYGON);

	//stage
    glVertex3f(200.0,50.0,-600.0);
    glVertex3f(240.0,50.0,-480.0);
    glVertex3f(180.0,50.0,-420.0);
    glVertex3f(-180.0,50.0,-420.0);
    glVertex3f(-240.0,50.0,-480.0);
    glVertex3f(-200.0,50.0,-600.0);
    glEnd();
	glBegin(GL_POLYGON);


	//stage walls
	glColor3f(0.2,0.2,0.2);

    glVertex3f(240.0,0.0,-420.0);
    glVertex3f(240.0,10.0,-420.0);
    glVertex3f(228.0,10.0,-420.0);
    glVertex3f(228.0,20.0,-420.0);
    glVertex3f(216.0,20.0,-420.0);
    glVertex3f(216.0,30.0,-420.0);
    glVertex3f(204.0,30.0,-420.0);
    glVertex3f(204.0,40.0,-420.0);
    glVertex3f(192.0,40.0,-420.0);
    glVertex3f(192.0,50.0,-420.0);
   	glVertex3f(-192.0,50.0,-420.0);
   	glVertex3f(-192.0,40.0,-420.0);
   	glVertex3f(-204.0,40.0,-420.0);
   	glVertex3f(-204.0,30.0,-420.0);
   	glVertex3f(-216.0,30.0,-420.0);
   	glVertex3f(-216.0,20.0,-420.0);
   	glVertex3f(-228.0,20.0,-420.0);
   	glVertex3f(-228.0,10.0,-420.0);
   	glVertex3f(-240.0,10.0,-420.0);
   	glVertex3f(-240.0,0.0,-420.0);
   	glEnd();


    //stage stairs
    glBegin(GL_QUADS);
    for(int i=0;i<=4;i++)
    {
    	for(int j=-1;j<=1;j+=2)
		{
			glColor3f(0.2,0.2,0.2);
			glVertex3f(j*(243.0+3*i),50.0-10*i,-471.0+9*i);
		    glVertex3f(j*(243.0+3*i),40.0-10*i,-471.0+9*i);
		    glVertex3f(j*(192.0+12*i),40.0-10*i,-420.0);
		    glVertex3f(j*(192.0+12*i),50.0-10*i,-420.0);


			glColor3f(0.6,0.6,0.6);
			glVertex3f(j*(240.0+(i*3)),50.0-(i*10),-480.0+9*i);
		    glVertex3f(j*(180.0+12*i),50.0-(i*10),-420.0);
		    glVertex3f(j*(192.0+12*i),50.0-(i*10),-420.0);
		    glVertex3f(j*(243.0+3*i),50.0-(i*10),-471.0+9*i);
		}
 	}




	//front wall
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-200.0,0.0,-600.0);
    glVertex3f(200.0,0.0,-600.0);
    glVertex3f(200.0,300.0,-600.0);
    glVertex3f(-200.0,300.0,-600.0);

    //screen
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-150.0,65.0,-595.0);
    glVertex3f(150.0,65.0,-595.0);
    glVertex3f(150.0,225.0,-595.0);
    glVertex3f(-150.0,225.0,-595.0);

    //back wall with hole for entrance
    glColor3f(245.0/256,242.0/256,218.0/256);
    glVertex3f(600.0,0.0,600.0);
    glVertex3f(-600.0,0.0,600.0);
    glVertex3f(-600.0,200.0,600.0);
    glVertex3f(600.0,200,600.0);

    glVertex3f(600.0,425.0,600.0);
    glVertex3f(-600.0,425.0,600.0);
    glVertex3f(-600.0,500.0,600.0);
    glVertex3f(600.0,500,600.0);

    glVertex3f(600.0,200.0,600.0);
    glVertex3f(100.0,200.0,600.0);
    glVertex3f(100.0,425.0,600.0);
    glVertex3f(600.0,425.0,600.0);

    glVertex3f(-600.0,200.0,600.0);
    glVertex3f(-100.0,200.0,600.0);
    glVertex3f(-100.0,425.0,600.0);
    glVertex3f(-600.0,425.0,600.0);


    //right wall
   	glColor3f(0.300,0.203,0.200);
    glVertex3f(200.0,300.0,-600.0);
    glVertex3f(200.0,0.0,-600.0);
    glVertex3f(600.0,0.0,600.0);
    glVertex3f(600.0,500.0,600.0);


    //left wall
    glVertex3f(-600.0,500.0,600.0);
    glVertex3f(-600.0,0.0,600.0);
    glVertex3f(-200.0,0.0,-600.0);
    glVertex3f(-200.0,300.0,-600.0);


    //ceiling
    glColor3f(211.0/256,211.0/256,211.0/256);
    glVertex3f(-600.0,500.0,600.0);
    glVertex3f(-200.0,300.0,-600.0);
    glVertex3f(200.0,300.0,-600.0);
    glVertex3f(600.0,500.0,600.0);

    //floor
    glColor3f(215.0/256,174.0/256,175.0/256);
    glVertex3f(200.0,0.0,-600.0);
    glVertex3f(600.0,0.0,600.0);
    glVertex3f(-600.0,0.0,600.0);
    glVertex3f(-200.0,0.0,-600.0);


    //room above stage
    glColor3f(0.6,0.6,0.6);


    //front wall
    glVertex3f(260.0,260.0,-420.0);
    glVertex3f(-260.0,260.0,-420.0);
    glVertex3f(-260.0,330.0,-420.0);
    glVertex3f(260.0,330,-420.0);

    //bottom wall
    glVertex3f(200.0,260.0,-600.0);
    glVertex3f(260.0,260.0,-420.0);
    glVertex3f(-260.0,260.0,-420.0);
    glVertex3f(-200,260,-600.0);



    glEnd();

}
