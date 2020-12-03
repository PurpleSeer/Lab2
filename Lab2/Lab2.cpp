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

int main()
{
    {
    Point p;
    Point p2(10, 20);
    Point p3(p2);
    }   
    
    Point* p4 = new Point;
    Point* p5 = new Point(10, 20);
    Point* p6 = new Point(*p5);

    delete p4;
    delete p5;
    delete p6;
    
    Point* p7 = new Point(1, 2);
    p7->reset();
    p7->move(10, 10);
    delete p7;

    _getch();
    return 0;
}
