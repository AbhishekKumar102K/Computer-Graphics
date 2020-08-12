//reader.h

#ifndef READER_H
#define READER_H

#define MAX_VERT 100000

///STRUCTURE THAT STORES THE (X,Y,Z) COORDINATES OF THE VERTEX
struct Vertex {

    float x;
    float y;
    float z;

};


///CLASS THAT CALCULATES AND STORES THE INFORMATION ABOUT THE VERTICES AND TRIANGULAR FACES OF THE IMPORTED OBJ FILE
class Reader {
    private:
        ///An array of objects of the structure Vertex that is used to store the Vertex coordinates
        Vertex vertex[5000];
        int f=0, faces[6000][3];


    public:
        ///Constructor of the Class that initializes all the vertex coordinates as 0
        Reader();
        ~Reader();

        ///A function that reads the obj file line by line till first character is 'v' (meaning vertex)
        ///and stores all the vertex coordinates
        ///into the array Vertex indexed by the Vertex rank in the file and then
        ///reads the obj file line by line for all lines starting with 'f' (meaning faces)
        ///and stores the faces information(which vertex to be used)
        ///into the array faces[][]
        ///@param filename Path of the obj file to be loaded
        void load(char* filename);


        ///A function that draws triangles by iterating through the faces[][] array that was created by
        ///reading the obj file
        ///
        /// @param scale A number that is multiplied by each vertex coordinate to scale the object
        /// accordingly as per our required size.
        void draw(int scale);


};

#endif

