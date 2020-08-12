#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <set>
#include "triple.h"

#define HEMICUBE_RESOLUTION 128
#define MAX_FACES 8192

using namespace std;

///Contains the functions needed to calculate the final radiosity values of the faces
class Scene
{
    public:
        Scene() { }

        /// Load the scene from an '.obj' file (all faces should be triangles)
        void loadFromOBJFile (char* filename);

        /// Calculates the form factors for all face-pairs
        void calculateFormFactors ();

        /// Runs one iteration of evaluating the radiosity equations for each face
        void calculateRadiosities ();

        /// Render the scene using colors interpolated across faces
        void render();

        /// Render the scene with a unique color code for each face
        void renderColorCoded();

        /// Calculate the normals for each face
        void CalcNormals();

        /** Populate the vector 'FcV' with the neighbouring face data for each vertex */
        void facesCommonVertex ();

        /// Interpolates the vertex colors based on surrounding face radiosities
        void interpolate ();

        /// Get the color encoding for a given face
        triple face2Pixel (int face);

        /// Get the face index from a given color encoding
        int pixel2Face (triple rgb);

    protected:
        /// Vertices, faces and normals
        vector<triple> vertices;
        vector<triple> faces;
        vector<triple> faceNormals;

        /// A map of each vertex's neighbouring faces
        vector< vector<int> > FcV;

        /// The list of emission factors for each face
        vector<triple> faceEmissions;

        /// The list of (color) reflectivities for each face
        vector<triple> faceReflectivities;

        /// An array of unique color codes for each face, used when rasterizing onto the hemicube
        vector<triple> faceColorCodes;

        /// A 2-D array of formfactors "F" for the faces
        vector<vector<float> > formFactors;

        /// The radiosities "H" for each face
        vector<triple> radiosities;

        /// Vertex colors after radiosity computation and interpolation across faces
        vector<triple> vertexColors;
};

#endif

