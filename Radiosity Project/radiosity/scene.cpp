#pragma once
#include "Scene.h"
#include "triple.h"
#include<iostream>
#include <GL/freeglut.h>
#include <fstream>
#include <sstream>

using namespace std;
// Load the scene from an '.obj' file (all faces should be triangles)
void Scene::loadFromOBJFile(char* filename) {

    ifstream file(filename);

    char c;
    triple vertex;            //Vertex vector
    triple face;              // Face Vector
    int index[3];           // Triangle's vertex indices
    triple Emission;          // Intensity of light source
    triple Reflectivity;      //  this is the material "color"
    long faceIndex = 0;     // Number of faces

    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        ss>>c;

        string name;
        switch (c) {
        case 'o':
            /*  this marks the start of a new object */
            ss>>name;
            /*  assign proper colors according to the object */
            if (name.find("Back") != string::npos) {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.8,triple(217/256.0,241/256.0,255/256.0));// light blue
            }
            else if (name.find("Left") != string::npos) {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.8,triple(217/256.0,241/256.0,255/256.0));// light blue
            }
            else if (name.find("Right") != string::npos) {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.8,triple(217/256.0,241/256.0,255/256.0));// light blue
            }
            else if (name.find("Top") != string::npos) {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.6,triple(1.0, 1.0, 1.00000));            // light blue
            }
            else if (name.find("Bottom") != string::npos) {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.6,triple(1.0, 1.0, 1.00000));            // light blue
            }
            else if (name.find("Stand")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.9,triple(0.5,0.24,0));                   // dark-brown
            }
             else if (name.find("Window") != string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity = vecScalarMul(0.45,triple(0.9,0.9,0.9));                  // gray
            }
             else if (name.find("Sphere")!= string::npos)
            {
                Emission = vecScalarMul(12,triple(1,1,1));                              //hemispherical emitting light source
                Reflectivity =  vecScalarMul(0,triple(1,1,1));                          //white
            }
            else if (name.find("FalseCeiling") != string::npos) {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting                                 //
                Reflectivity =  vecScalarMul(0.7,triple(0.17, 0.4, 0.6));               // Royal Blue
            }
            else if (name.find("Sill")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0,0,0);                                          // black
            }
            else if (name.find("Seat")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0.0,0.0,1.0);                                    // Blue
            }
            else if (name.find("Table")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  vecScalarMul(0.4,triple(0.5,0/256.0,0.1250));           // crimson red
            }

            else if (name.find("Tvstand")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0,0,0);                                          // black
            }
            else if (name.find("Cylinder")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0.6,0.3,0.0);                                    // Dark-Brown
            }
            else if (name.find("Text")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(2,0,0);                                          // Red
            }
            else if (name.find("Plane.000")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0,0,1);                                          // Red
            }
            else if (name.find("Plane.001")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(1,0,0);                                          // Red
            }
            else if (name.find("Plane.002")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0.84,0.84,0.84);                                          // Red
            }
            else if (name.find("Plane.003")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0.84,0.84,0.84);                                          // Red
            }
            else if (name.find("Plane.004")!= string::npos)
            {
                Emission = vecScalarMul(0,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(0.54,0.54,0.54);                                          // Red
            }
            else if (name.find("Cube.001")!= string::npos)
            {
                Emission = vecScalarMul(100,triple(1,1,1));                               // non emitting
                Reflectivity =  triple(1,0,0);                                          // Red
            }
            break;

        case 'v':
            // read a vertex
            ss>>vertex.x;
            ss>>vertex.y;
            ss>>vertex.z;
            vertices.push_back(vertex);
            // initial vertex colors for debugging
            vertexColors.push_back(Reflectivity);
            break;

        case 'f':
            // read a triangle's vertex indices
            ss>>index[0];
            ss>>index[1];
            ss>>index[2];
            face = triple(index[0]-1, index[1]-1, index[2]-1);
            faces.push_back(face);
            faceEmissions.push_back(Emission);                  // Face Emission vector
            faceReflectivities.push_back(Reflectivity);         // Face Reflectivity vector
            {
                triple rgb = face2Pixel(faceIndex);               //Maps face index to a unique color value
                faceColorCodes.push_back(rgb);                  //Stores all the unique color codes
            }
            faceIndex++;
            break;
        default:
            break;
        }
    }

    file.close();

    facesCommonVertex();    //Populate the vector 'FcV' with the neighboring face data for each vertex
    CalcNormals();          //Calculate Normal Vector
    triple r(0.5, 0.5, 0.5);  // initialize radiosities to 0.5
    radiosities = vector<triple> (faces.size(), r);   //store radiosities of each face/
}

//Populate the vector 'FcV' with the neighboring face data for each vertex
void Scene::facesCommonVertex()
{
    FcV = vector< vector<int> >(vertices.size());

    for (int i = 0; i<faces.size(); i++)        //for each face
    {
        triple face = faces[i];                   //face = current face
        // add this face to the list of faces for all three vertices
        FcV[face.x].push_back(i);
        FcV[face.y].push_back(i);
        FcV[face.z].push_back(i);
    }
}
// Render the scene using colors interpolated across faces
void Scene::render()
{
    for (int fi=0;fi<faces.size(); fi++) // Rendering each face into the scene
    {
        triple face =  faces[fi];             //face = Current face
        triple v1 = vertices[face.x];         //first vertex of the triangular face
        triple v2 = vertices[face.y];         //second vertex of the triangular face
        triple v3 = vertices[face.z];         //third vertex of the triangular face

        triple c1 = vertexColors[face.x];     //Color of the first vertex assigned by the interpolate function
        triple c2 = vertexColors[face.y];     //Color of the second vertex assigned by the interpolate function
        triple c3 = vertexColors[face.z];     //Color of the third vertex assigned by the interpolate function


        glBegin(GL_TRIANGLES);                  // Drawing all faces with the final interpolated values of each vertex
            glColor3f(c1.x, c1.y, c1.z);        // This is done because when different vertices of a polygon are colored
            glVertex3f(v1.x, v1.y, v1.z);       // differently, the color of the face of the polygon becomes a gradient
            glColor3f(c2.x, c2.y, c2.z);        // of all the vertex color values
            glVertex3f(v2.x, v2.y, v2.z);
            glColor3f(c3.x, c3.y, c3.z);
            glVertex3f(v3.x, v3.y, v3.z);
        glEnd();
    }
}

// Calculates the normals for each face
void Scene::CalcNormals () {
    for (int i=0;i<faces.size();i++)            //for each face
    {
        triple v1 = vertices[faces[i].x];         //first vertex of the triangular face
        triple v2 = vertices[faces[i].y];         //second vertex of the triangular face
        triple v3 = vertices[faces[i].z];         //third vertex of the triangular face

        triple normal = cross(vecSub(v2,v1), vecSub(v3,v2));      //Cross product of two vectors results in a perpendicular vector
        normal.normalize();                                     //Converts the normal to a unit vector
        faceNormals.push_back(normal);                          //Add this unit normal to the list of normals of faces
    }
}

//Calculates the form factors for all face-pairs
void Scene::calculateFormFactors()
{
    /*Initialize the form factors 2d square matrix having dimensions (faces.size() x faces.size())*/
    formFactors = vector<vector<float> > (faces.size(), vector<float>(faces.size(), 0.0));

    for (int f=0; f<faces.size(); f++) {            //For all faces
        int pixelCount[MAX_FACES] = {0};            //Initializing pixel count of all faces' projections as 0

        triple face = faces[f];                       //Current face

        /*Centroid is (x+y+z)/3  */
        triple centroid =  vecScalarMul(0.333333f,(vecAdd(vecAdd(vertices[face.x],vertices[face.y]), vertices[face.z])));

        /* the new basis for the coordinate system around the centroid */
        /* n is the normal; d1, d2 are orthogonal unit vectors on the plane of the face */
        triple n = faceNormals[f];                    //normal of the current face
        triple d1, d2;

        /* find vertex farthest from centroid */
        triple a = vecSub(vertices[face.x], centroid);        //vector from centroid to first vertex
        triple b =   vecSub(vertices[face.y], centroid);      //vector from centroid to first vertex
        triple c =  vecSub(vertices[face.z], centroid);       //vector from centroid to first vertex
        d1 = longestVector(a,b,c);
        d1.normalize();                                     //convert d1 to a unit vector
        d2 =  cross(n, d1);                                 //d2 = n x d1 as d2 is perpendicular to both d1 and n


        float left, right, bottom, top;
        triple eye = centroid;
        triple lookat, up;

        for (int i = 1; i <= 5; i++)
        {
            if (i == 1)
            { /* setup view for face 1 (top) */
                left = -0.5;
                right = 0.5;
                bottom = -0.5;
                top = 0.5;
                lookat = vecAdd(centroid, n);
                up = d2;
            }
            else if (i == 2)
            { /* setup view for face 2 (left) */
                left = -0.5;
                right = 0.5;
                bottom = 0;
                top = 0.5;
                lookat = vecAdd(centroid, d1);
                up = n;
            }
            else if (i == 3)
            { /* setup view for face 3 (right) */
                left = -0.5;
                right = 0.5;
                bottom = 0;
                top = 0.5;
                lookat = vecSub(centroid,d1);
                up = n;
            }
            else if (i == 4)
            { /* setup view for face 4 (back) */
                left = -0.5;
                right = 0.5;
                bottom = 0;
                top = 0.5;
                lookat = vecSub(centroid,d2);
                up = n;
            }
            else if (i == 5)
            { /* setup view for face 5 (front) */
                left = -0.5;
                right = 0.5;
                bottom = 0;
                top = 0.5;
                lookat = vecAdd(centroid,d2);
                up = n;
            }

            /* setup viewport */
            int w = (right - left) * HEMICUBE_RESOLUTION;       //HEMICUBE_RESOLUTION is the Number of pixels per unit length
            int h = (top - bottom) * HEMICUBE_RESOLUTION;
            glViewport(0, 0, w, h);

            /* setup the hemicube's side as a viewplane */
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glEnable(GL_DEPTH_TEST);
            glFrustum(left, right, bottom, top, 0.5, 1000);     //Set up the perspective matrix with appropriate dimensions
            gluLookAt(eye.x, eye.y, eye.z, lookat.x, lookat.y, lookat.z, up.x, up.y, up.z);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();


            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // rasterize entire scene onto this face of the hemicube
            renderColorCoded();                                 //Renders the scene with encoded colors of the faces

            GLubyte *buffer = new GLubyte[w * h * 3];           //Initialize an empty buffer to read the pixels (RGB) of the rendered frame
                                                                //Number of pixels = w*h for each of R,G,B. Therefore, total size = w*h*3

            glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, buffer); //get the contents from frame buffer

            /* count number of lit pixels for each face */
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {

                    //value of color is non (0,0,0) for any pixel that is filled as no face was encoded to (0,0,0)
                    triple color(buffer[(y*w+x)*3], buffer[(y*w+x)*3+1], buffer[(y*w+x)*3+2]);

                    int face_index = pixel2Face(color);         //Map the color back to the face_index
                    if (face_index==-1) {
                        continue; // empty pixel
                    }
                    pixelCount[face_index]++;                   //Number of pixels lit by the projection of the face at index = face_index
                }
            }

            delete buffer;                                      //Delete the buffer once appropriate number of pixels are counted
        }
        /* end of for loop, pixels now counted on all 5 sides of hemicube */

        int totalPixels = 3 * HEMICUBE_RESOLUTION * HEMICUBE_RESOLUTION;        //Surface area of hemicube = 3a^2

        /* compute form factors */
        for (int k=0; k<faces.size(); k++)          //for each face
        {
            if (k == f)                             //Form factor with itself = 0
            {
                formFactors[f][k] = 0;              //formFactors[i][i] = 0
                continue;
            }
            float factor = pixelCount[k]/(float) totalPixels;       //Ratio of pixels lit by the projection of the faces to the total number of pixels
            formFactors[f][k] = factor;                             //Assign this value to the form factor between face f and k
        }
    }
}

//Renders the scene with a unique color code for each face
void Scene::renderColorCoded()
{
    for (int fi = 0; fi < faces.size(); fi++)
    {                                                       //for each face
        triple face =  faces[fi];                             //face = current face
        triple v1 = vertices[face.x];                         //first vertex of the triangular face
        triple v2 = vertices[face.y];                         //second vertex of the triangular face
        triple v3 = vertices[face.z];                         //third vertex of the triangular face


        triple color = faceColorCodes[fi];                    //Color mapped to the face_index
        glColor3ub(color.x, color.y, color.z);              //Set the draw color as the encoded color
        glBegin(GL_TRIANGLES);                              //Draw the triangular face with this color
            glVertex3f(v1.x, v1.y, v1.z);
            glVertex3f(v2.x, v2.y, v2.z);
            glVertex3f(v3.x, v3.y, v3.z);
        glEnd();
    }
}

//Function that maps the face_index to a unique color based on the face_index
triple Scene::face2Pixel(int f)
{
    triple rgb;  //to store the rgb value of the color
    f = f + 1; //0 based indexing of faces
    rgb.x = f % 256;
    rgb.y = f/256;
    rgb.z = f/(256*256);
    return rgb;
}

//Function that maps back the unique encoded color to the face_index
int Scene::pixel2Face (triple color)
{
    return color.x + color.y*256 + color.z*256*256 - 1;         //returns -1 for input (0,0,0)
}

//Function that calculates the net radiosities of all the faces
void Scene::calculateRadiosities()
{
    for (int i=0; i<faces.size();i++)           //For each face
    {
        radiosities[i] = faceEmissions[i];      //Initialize the radiosity of the face as the emission value of the face
        for (int j=0; j<faces.size(); j++)      //Iterate through all the faces again
        {
            //From the Formula derived in the research paper
            radiosities[i].add(vecMul(vecScalarMul(formFactors[j][i], faceReflectivities[i]), radiosities[j]));     //bj = ej + pj*Sum(bj*fij)
        }
    }
}


//Function that interpolates the value of all the vertices based on the number of faces it is a part of, and returns the average
//color of all those faces
void Scene::interpolate()
{
    for (int vi = 0; vi < vertices.size(); vi++)            //For all vertices
    {
        vector<int> nearFaces = FcV[vi];                    //nearfaces contains the indices of all the faces that share the current vertex
        triple color(0,0,0);                                //Initialize color of the vertex as black
        for (int fi = 0; fi < nearFaces.size(); fi++)       //For each face in nearFace
        {
            color.add(radiosities[nearFaces[fi]]);          //Add the radiosity of the face to color
        }
        color = vecScalarMul((1/(float)nearFaces.size()),color);       //Divide the color by the number of faces surrounding the current vertex
        vertexColors[vi] = color;                           //taking average of colors of all the faces that the vertex is a part of

    }
}


