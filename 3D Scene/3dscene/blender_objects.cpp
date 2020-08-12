#include "blender_objects.h"
#include "reader.h"

//FUNCTION THAT DRAWS THE SPEAKERS BY CALLING THE Draw() function on the speakers.obj obj
void Blender_imp::make_speakers(int x, int y, int z, int ax, int ay, int az, int scale, Reader obj)
{
	glColor3f(0.1,0.1,0.1);         //rgb color of the speakers
	glTranslatef(x,y,z);            //Translate the origin to the body center of the speaker i.e (x,y,z)
	glRotatef(ay,0,1,0);            //Rotation about y axis
	glRotatef(ax,1,0,0);            //Rotation about x axis
	glRotatef(az,0,0,1);            //Rotation about z axis
	obj.draw(scale);                //Call the draw function to draw the object
	glRotatef(-az,0,0,1);           //Rotation back about z axis
	glRotatef(-ax,1,0,0);           //Rotation back about x axis
	glRotatef(-ay,0,1,0);           //Rotation back about y axis
	glTranslatef(-x,-y,-z);         //Translate the origin back to the initial position i.e (-x,-y,-z)
}

//FUNCTION THAT DRAWS THE SPEAKERS BY CALLING THE Draw() function on the mic.obj obj
void Blender_imp::make_mic(int x, int y, int z, Reader obj)
{
	glColor3f(0,0,0);               //rgb color of the mic
	glTranslatef(x,y,z);            //Translate the origin to the body center of the mic i.e (x,y,z)
	glRotatef(-90,0,1,0);           //Rotate -90 degrees about y axis
	obj.draw(1);                    //Call the draw function to draw the object
	glRotatef(90,0,1,0);            //Rotate back the object 90 degrees about y axis
	glTranslatef(-x,-y,-z);         //Translate the origin back to the initial position i.e (-x,-y,-z)
}

//FUNCTION THAT DRAWS THE SPEAKERS BY CALLING THE Draw() function on the podium.obj obj
void Blender_imp::make_podium(int x, int y, int z, Reader obj)
{
	glColor3f(54/256.0,34/256.0,4/256.0);        //rgb color of the mic
	glTranslatef(x,y,z);                         //Translate the origin to the body center of the podium i.e (x,y,z)
	glRotatef(90,0,1,0);                         //Rotate -90 degrees about y axis
    obj.draw(4);                                 //Call the draw function to draw the object
	glRotatef(-90,0,1,0);                        //Rotate back the object 90 degrees about y axis
	glTranslatef(-x,-y,-z);                      //Translate the origin back to the initial position i.e (-x,-y,-z)
}


