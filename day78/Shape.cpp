#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;


class Shape
{
private:
    string color;
public:
    Shape();
    Shape(const string &);
    string getColor() const;
    virtual double getSurfaceArea() const = 0;
    virtual double getVolume() const = 0;
    virtual void printInfo(ostream &) const = 0;
    void setColor(const string &);
    friend ostream& operator << (ostream &, const Shape &);
};
typedef Shape* ShapePtr;

Shape::Shape() : color("None"){}
Shape::Shape(const string& c) : color(c) {}
string Shape::getColor() const {return color;}
void Shape::setColor(const string& c) {color = c;}
ostream& operator << (ostream& out, const Shape& s)
{
    s.printInfo(out);
    return out;
}