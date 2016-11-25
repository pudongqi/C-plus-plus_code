#include "DerivedCircle.h"

const double Pi = acos(-1.0);

Circle::Circle()
{
    radius = 1.0;
}

Circle::Circle(double radius)
{
    setRadius(radius);
}

Circle::Circle(double radius, string& color, bool filled)
{
    this -> radius = radius;
    setColor(color);
    setFilled(filled);
}

double Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(double radius)
{
    this -> radius = radius;
}

double Circle::getArea()
{
    return this -> radius * this -> radius * Pi;
}

double Circle::getPerimeter()
{
    return 2 * radius * Pi;
}

double Circle::getDiameter()
{
    return 2 * radius;
}

string Circle::toString()
{
    return "Circle object";
}
