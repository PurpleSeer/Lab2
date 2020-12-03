#include <iostream>
#include <conio.h>

using namespace std;

class Point {
protected:
    int x, y;
public:
    Point() {
        cout << "Point\n";
        x = 0;
        y = 0;
    }
    Point(int x,int y) {
        cout << "Point(int x,int y)\n";
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) {
        cout << "Point(const Point &p)\n";
        x = p.x;
        y = p.y;
    }
    ~Point() {
        cout << x <<" ,"<< y<<" ";
        cout << "~Point()\n";
    }
    void move(int dx, int dy) {
        x = x + dx;;
        y = y + dy;
    }
    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
}

class ColoredPoint : public Point{
protected:
    int color;
public:
    ColoredPoint() : Point() {
        cout << "ColoredPoint\n";
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x,y) {
        cout << "ColoredPoint(int x,int y)\n";
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) {
        cout << "ColoredPoint(const Point &p)\n";
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {
        cout << x << ", " << y <<", color="<<color<< " ";
        cout << "~ColoredPoint()\n";
    }
    void change_color(int new_color) {
        color = new_color;
    }
};

int main()
{
    {
        Point p;
        Point p2(10, 20);
        Point p3(p2);
    }

    _getch();
    cout << "\n\n";
    
    Point* p4 = new Point;
    Point* p5 = new Point(10, 20);
    Point* p6 = new Point(*p5);
    p4->reset();
    p4->move(10, 10);
    delete p4;
    delete p5;
    delete p6;

    _getch();
    cout << "\n\n";

    {
        ColoredPoint cp;
        ColoredPoint cp2(10, 20, 32);
        ColoredPoint cp3(cp2);
    }

    _getch();
    cout << "\n\n";

    Point* cp4 = new ColoredPoint();
    delete cp4;
    ColoredPoint* cp5 = new ColoredPoint;
    ColoredPoint* cp6 = new ColoredPoint(10, 20, 32);
    ColoredPoint* cp7 = new ColoredPoint(*cp6);
    delete cp5;
    delete cp6;
    delete cp7;

    _getch();
    return 0;
}
