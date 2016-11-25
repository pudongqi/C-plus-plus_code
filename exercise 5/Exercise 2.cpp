#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

class GeometricObject
{
private:
    string color;
    bool filled;
public:
    GeometricObject();
    GeometricObject(string& color, bool filled);
    string getColor();
    void setColor(string& color);
    bool isFilled();
    void setFilled(bool filled);
    string toString();
};

GeometricObject::GeometricObject()
{
    color = "white";
    filled = false;
}

GeometricObject::GeometricObject(string& color, bool filled)
{
    this -> color = color;
    this -> filled = filled;
}

string GeometricObject::getColor()
{
    return color;
}

void GeometricObject::setColor(string& color)
{
    this->color = color;
}

bool GeometricObject::isFilled()
{
    return filled;
}

void GeometricObject::setFilled(bool filled)
{
    this->filled = filled;
}

string GeometricObject::toString()
{
    return "Geometric Object";
}

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

int main()
{
    string color;
    color = "black";
    GeometricObject object;
    object.setColor(color);
    object.setFilled(false);
    cout << object.toString() << endl;
    cout << " color: " << object.getColor() << endl;
    bool temp = object.isFilled();
    if(temp == 1)
        cout << " filled: " << "Yes" << endl;
    else cout << " filled: " << "No" << endl;

    color = "yellow";
    Circle circle(3);
    circle.setColor(color);
    circle.setFilled(true);
    cout << circle.toString()<< endl;
    cout << " color: " << circle.getColor() << endl;
    temp = circle.isFilled();
    if(temp == 1)
        cout << " filled: " << "Yes" << endl;
    else cout << " filled: " << "No" << endl;
    cout << " radius: " << circle.getRadius() << endl;
    cout << " area: " << circle.getArea() << endl;
    cout << " perimeter: " << circle.getPerimeter() << endl;

    color = "green";
    Rectangle rectangle(3, 3);
    rectangle.setColor(color);
    rectangle.setFilled(true);
    cout << rectangle.toString()<< endl;
    cout << " color: " << circle.getColor();
    temp = rectangle.isFilled();
    if(temp == 1)
        cout << " filled: " << "Yes" << endl;
    else cout << " filled: " << "No" << endl;
    cout << " width: " << rectangle.getWidth() << endl;
    cout << " height: " << rectangle.getHeight() << endl;
    cout << " area: " << rectangle.getArea() << endl;
    cout << " perimeter: " << rectangle.getPerimeter() << endl;

    return 0;
}
