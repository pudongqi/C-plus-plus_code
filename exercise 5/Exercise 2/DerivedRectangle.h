#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeometricObject.h"

class Rectangle: public GeometricObject
{
private:
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(double width, double height, string& color, bool filled);
    double getWidth();
    void setWidth(double width);
    double getHeight();
    void setHeight(double height);
    double getArea();
    double getPerimeter();
    string toString();
};

#endif
