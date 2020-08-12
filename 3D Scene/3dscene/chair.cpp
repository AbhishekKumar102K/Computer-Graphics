#include "chair.h"
#include "cuboid.h"

Cuboid c1;          //Object of the class Cuboid, used to call the draw_cbd function


//This function makes a chair(using multiple cuboids) with center of back rest at (x,y,z).
void Chair::draw_chair(int x, int y, int z){


    glTranslatef(x,y,z);

	//back support
	c1.draw_cbd(15,16,2,0,0,0,0,0,0.502);

	//base
	c1.draw_cbd(15,2,10,0,-7,-5,0,0,0.502);

	//hand rest
	c1.draw_cbd(2,1,10,8.5,0,-5,0,0,0);
	c1.draw_cbd(2,1,10,-8.5,0,-5,0,0,0);

	//Chair_support
	c1.draw_cbd(2,8,2,-8.5,-3.5,0,0,0,0);
	c1.draw_cbd(2,8,2,8.5,-3.5,0,0,0,0);

	glTranslatef(-x,-y,-z);

}





