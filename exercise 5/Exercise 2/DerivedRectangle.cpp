#include "DerivedRectangle.h"

Rectangle::Rectangle()
{
    width = 1.0;
    height = 1.0;
}

Rectangle::Rectangle(double width, double height)
{
    setWidth(width);
    setHeight(height);
}

Rectangle::Rectangle(double width, double height, string& color, bool filled)
{
    setWidth(width);
    setHeight(height);
    setColor(color);
    setFilled(filled);
}

double Rectangle::getWidth()
{
    return width;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

double Rectangle::getHeight()
{
    return height;
}

void Rectangle::setHeight(double height)
{
  this->height = height;
}

double Rectangle::getArea()
{
  return width * height;
}

double Rectangle::getPerimeter()
{
  return 2 * (width + height);
}

string Rectangle::toString()
{
  return "Rectangle object";
}
