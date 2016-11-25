#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
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

#endif
