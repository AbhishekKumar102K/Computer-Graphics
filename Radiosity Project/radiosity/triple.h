

#ifndef TRIPLE_H
#define TRIPLE_H

#include <cmath>

/** A 3D vector */
/// This represents a 3D vector having three components (x,y,z)
struct triple
{
    float x;
    float y;
    float z;

    /// Initialize all vector elements to zero
    triple () {
        x = 0;
        y = 0;
        z = 0;
    }
    /// Initialize all vector elements to the given values
    triple (float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    ///This function finds the magnitude of the given vector
    float norm()
    {
        return sqrtf (x*x + y*y + z*z);
    }
    ///this function converts the vector into its unit vector.
    triple normalize () {
        float m = norm ();
        x /= m;
        y /= m;
        z /= m;
        return *this;
    }
    ///This function adds two vectors.
    void add(triple b) {
        x += b.x;
        y += b.y;
        z += b.z;
    }

};

/// This function subtract two vectors
///@param v1 is the first vector
///@param v2 is the second vector
inline triple vecSub(triple v1, triple v2)
{
    return triple(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}



/// This function add two vectors
///@param v1 is the first vector
///@param v2 is the second vector
inline triple vecAdd(triple v1, triple v2)
{
    return triple(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}



///This function multiplies a scalar to a vector
/// @param a scalar to be multiplied
/// @param v vector to be multiplied
inline triple vecScalarMul(float a, triple v)
{
    return triple(a*(v.x), a*(v.y), a*(v.z));
}



///This function multiplies two vectors
/// @param a the first vector
/// @param b the second vector
inline triple vecMul(triple a, triple b)
{
    return triple(a.x * b.x, a.y * b.y, a.z * b.z);
}



///This Function takes cross products of two vectors
/// @param v1 the first vector
/// @param v2 the second vector
inline triple cross(triple v1, triple v2) {
    triple out;
    out.x = v1.y * v2.z -v1.z * v2.y;
    out.y = v1.z * v2.x -v1.x * v2.z;
    out.z = v1.x * v2.y -v1.y * v2.x;

    return out;
}



///This function finds the longest vector among the three given vectors
/// @param a the first vector
/// @param b the second vector
/// @param c the third vector
inline triple longestVector (triple a, triple b, triple c) {
    if (a.norm() > b.norm()) {
        if (a.norm() > c.norm())
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else if (b.norm() > c.norm())
    {
        return b;
    }
    else
    {
        return c;
    }
}

#endif

