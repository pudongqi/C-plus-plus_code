#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

class Circle: public GeometricObject
{
private:
    double radius;
public:
    Circle();
    Circle(double);
    Circle(double radius, string& color, bool filled);
    double getRadius();
    void setRadius(double radius);
    double getArea();
    double getPerimeter();
    double getDiameter();
    string toString();
};


#endif
