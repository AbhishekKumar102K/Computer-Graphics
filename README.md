# Computer-Graphics
Contains Computer Graphics projects and assignments using C++ and OpenGL Glut libraries

For each of the below mentioned projects(except Bezier curve), you can find an HTML file containing an in depth analysis of the algorithm used, issues in coding and the results.
The path for each of the file looks like 

## IMPLEMENTATION OF A TIDY TREE DRAWING USING TR ALGORITHM

**Overview**

For this project, we used lines(to draw the edges) and circles(to represent a node) to draw the binary tree. For this, we used the Bresenham's Midpoint Line and circle drawing algorithm. We modified the circle drawing algorithm by adding an offset to both the x and y coordinate to draw the circles at any other location than the origin. This program has two different ways of taking input from the user.
We have implemented TR algorithm after going through the given research paper. It contains two functions, namely setup() and Petrify().
The setup() function assigns threads and offsets to each node and the Petrify() function assigns X-coordinate to each node.

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/Tree%20Drawing/Exercise%204%20(HTML%20Doc)/3.png">

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/Tree%20Drawing/Exercise%204%20(HTML%20Doc)/10.png">



## 3D Scene 

**Overview**

In this project we have tried to create a 3D scene of an Auditorium using OpenGL Transformations, matrix stack operations, and 3D viewing pipeline. We have also used Blender to create objects like Speakers, Mic and Podium and then exported them into our scene.

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/3D%20Scene/HTML%20File/Seats.PNG">

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/3D%20Scene/HTML%20File/Stage.PNG">



## Bezier Curves of degree n

**Overview**

In this project we have implemented drawing of a bezier curve of degree n. We can add control points using the left click and remove the existing control points by right clicking on the points. We can also drag the points by hovering over the control points and selecting them to move them around.

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/Bezier%20Curves/Snapshot/snapshot.jpg">


## Radiosity Project

**Overview**

This algorithm computes the radiosity of each face using the Hemicube method(for calculating the form-factor). It then interpolates the vertex colors by taking the average across all the neighbouring faces to give an aesthetically pleasing scene.

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/Radiosity%20Project/Documentation%20of%20Results/Iopen.jpeg">

<img src = "https://github.com/AbhishekKumar102K/Computer-Graphics/blob/master/Radiosity%20Project/Documentation%20of%20Results/Iroom.jpeg">


## Team Members:
1. Abhishek Kumar
2. Shubham Asopa (https://github.com/sammyasopa)

