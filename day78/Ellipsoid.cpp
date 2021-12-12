#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

double PI = (double)(22/7);

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


class Ellipsoid : Shape{
private:
    double a,b,c;
    string shape;
public:
    Ellipsoid(int x, int y, int z){
        this->a = x;
        this->b = y;
        this->c = z;
    }
    string getColor() const;
    virtual double getSurfaceArea(){
        return  4 * PI * pow((pow(a * b, 1.6) + pow(a * c, 1.6) + pow(b * c, 1.6))/ 3, 0.625);
    }
    virtual double getVolume(){
        return ((double)(4/3))*PI*(this->a)*(this->b)*(this->c);
    }
    virtual void printInfo(ostream &) const = 0;
    void setColor(const string &);
    friend ostream& operator << (ostream &, const Shape &);
};


class Sphere : Shape{
private:
    double r;
    string shape;
public:
    Sphere(double x){
        this->r = x;
    }
    string getColor() const;
    virtual double getSurfaceArea(){
        return  4 * PI * pow(r,2);
    }
    virtual double getVolume(){
        return ((double)(4/3))*PI*pow(r,3);
    }
    virtual void printInfo(ostream &) const = 0;
    void setColor(const string &);
    friend ostream& operator << (ostream &, const Shape &);
};


double getLargetVolumeRedObjectIndex(ShapePtr p[], int size){
    double mx_Volume = 0;
    for(int i=0; i<size; i++){
        if(p[i]->getColor() == "Red"){
            double curr_Volume = p[i]->getVolume();
            if(curr_Volume > mx_Volume){
                mx_Volume = curr_Volume;
            }
        }
    }
return mx_Volume;
}

int main()
{
    Ellipsoid e1;
    Ellipsoid e2(1.8, 1.1, 3.5, "Blue");
    cout << "e1 is " << e1 << endl;
    cout << "e2 is " << e2 << endl;
 
    e1.setColor("Yellow");
    e1.setSemiAxis1(1.2);
    e1.setSemiAxis2(1.6);
    e1.setSemiAxis3(1.8);
    cout << "e1 is modified to " << e1 << endl;

    Sphere s1;
    Sphere s2(2.4, "Red");
    cout << "s1 is " << s1 << endl;
    cout << "s2 is " << s2 << endl;

    s1.setColor("Orange");
    s1.setRadius(0.75);
    cout << "s1 is modified to " << s1 << endl;

    s1.setSemiAxis1(0.5);
    cout << "s1 is modified again to " << s1 << endl;

    s1.setSemiAxis2(0.3);
    cout << "s1 is modified again to " << s1 << endl;

    s1.setSemiAxis1(0.2);
    cout << "s1 is modified again to " << s1 << endl;

    //Create an array of Shape pointers and populate the array
    srand(time(0));
    const int size = 5 + rand() % 5;
    ShapePtr *p = new ShapePtr[size];
    string color[] = {"Red", "Green", "Blue", "Yellow", "Orange"};
    for (int i = 0; i < size; i++)
    {
        if (rand() % 2 == 0)
            p[i] = new Ellipsoid(rand()%3+1.1, rand()%3+1.2, rand()%3+1.3, color[rand()%5]);
        else
            p[i] = new Sphere(rand()%3+1.4, color[rand()%5]);
    }

    //Print the elements of the array
    for (int i = 0; i < size; i++)
        cout << "The object at index " << i << " is " << *(p[i]) << endl;

    //Compute the index of the largest-volume Red colored object among the Red colored elements of the array
    //If there is no any Red colored element in the array, then the function must return -1
    int index = getLargetVolumeRedObjectIndex(p, size);
    if (index == -1)
        cout << "There is no any Red colored object in the array." << endl;
    else
        cout << "The largest volume Red colored object is " << *(p[index]) << endl;

    //Delete dynamically allocated memory
    for (int i = 0; i < size; i++)
        delete p[i];
    delete[]p;

    system("Pause");
    return 0;
}