#pragma once


class Draw
{
    public:
    ///FUNCTION TO ILLUMINATE PIXELS BY 8-WAY SYMMETRY.
    ///
    ///If pixel (x,y) is illuminated, then (x,-y),(-x,y),(-x,-y),(y,x),(y,-x),(-y,x) and (-y,-x) are also illuminated, since a circle is symmetric
    ///about the lines y = x and y = -x
    ///@param x X coordinate of the pixel to be illuminated
    ///@param y Y coordinate of the pixel to be illuminated
    ///@param xoff X coordinate of the centre of the circle
    ///@param yoff Y coordinate of the centre of the circle
    void Draw_Circle(int x, int y, int xoff, int yoff);


    ///FUNCTION TO DRAW A LINE BETWEEN TWO POINTS USING BRESENHAM'S LINE DRAWING ALGORITHM FOR SLOPE <=1.
    ///
    ///Here, slope is <=1, therefore illuminate one pixel per column. Thus, increment x by 1 in each iteration of the while loop
    ///@param x1 X coordinate of the first point
    ///@param y1 Y coordinate of the first point
    ///@param x2 X coordinate of the second point
    ///@param y2 Y coordinate of the second point
    void draw_line1(int x1, int y1, int x2, int y2);

    ///FUNCTION TO DRAW A LINE BETWEEN TWO POINTS USING BRESENHAM'S LINE DRAWING ALGORITHM FOR SLOPE > 1.
    ///
    ///Here, slope is > 1, therefore illuminate one pixel per row. Thus, increment y by 1 in each iteration of the while loop
    ///@param x1 X coordinate of the first point
    ///@param y1 Y coordinate of the first point
    ///@param x2 X coordinate of the second point
    ///@param y2 Y coordinate of the second point
    void draw_line2(int x1, int y1, int x2, int y2);


    ///TO DECIDE WHICH FUNCTION TO CALL(draw_line1 or draw_line2) BASED ON SLOPE.
    ///
    ///If slope is <=1, call draw_line1(), else call draw_line2()
    ///@param x1 X coordinate of the first point
    ///@param y1 Y coordinate of the first point
    ///@param x2 X coordinate of the second point
    ///@param y2 Y coordinate of the second point
    void line(int x1, int y1, int x2, int y2);


    ///BRESEMHAM'S CIRCLE DRAWING ALGORITHM TO DRAW A CIRCLE WITH RADIUS R, CENTRE AT (XOFF,YOFF).
    ///
    ///Draws an arc 1/8 of the circle in the first quadrant, calls Draw_Circle() to illuminate 7 other points in the remaining quadrants
    ///@param xoff X coordinate of the centre of the circle
    ///@param yoff Y coordinate of the centre of the circle
    ///@param r radius of the circle to be drawn
    void printCircle(int xoff, int yoff, int r);

};

