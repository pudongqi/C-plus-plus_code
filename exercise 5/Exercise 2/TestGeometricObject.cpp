#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
#include <iostream>
using namespace std;

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
