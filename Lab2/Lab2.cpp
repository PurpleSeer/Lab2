#include <iostream>
#include <conio.h>

using namespace std;

class Point {
protected:
    int x, y;
public:
    Point() { 
        cout << "Создание пустой точки\n";
        x = 0;
        y = 0;
    }
    Point(int x,int y) {
        cout << "Создание точки с координатами\n";
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) {
        cout << "Создание точки копии\n";
        x = p.x;
        y = p.y;
    }
    ~Point() {
        cout << "Удаление точки с координатами:"<<x<<", "<<y<<endl;
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
        cout << "Создание пустой цветной точки\n";
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x,y) {
        cout << "Создание цветной точки с координатами\n";
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) {
        cout << "Создание цветной точки копии\n";
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {
        cout << "Удаление цветной точки с координатами:" << x << ", " << y<< " и цветом: " <<color<<endl;
    }
    void change_color(int new_color) {
        color = new_color;
    }
};

class Section {
protected:
    Point *p1;
    Point *p2;
    int a, b, a2, b2;
public:
    Section() {
        p1 = new Point;
        p2 = new Point;
        cout << "Создание пустого отрезка\n";
    }
    Section(int x, int y,int x2,int y2) {
        p1 = new Point(x, y);
        p2 = new Point(x2, y2);
        cout << "Создание отрезка с координатами\n";
        a = x;b = y;a2 = x2; b2 = y2;
    }
    Section(const Section& s) {
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
        cout << "Создание отрезка копии\n";
    }
    ~Section() {
        cout << "Удаление отрезка с координатами:" << a << ", " << b << ", " << a2 << ", " << b2 << endl;
        delete p1;
        delete p2;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
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
    cout << "\n\n";

    {
        Section s1;
        Section s2(1, 2, 3, 4);
        Section s3(s2);
    }

    _getch();
    cout << "\n\n";

    Section* s4 = new Section;
    Section* s5 = new Section(5, 10, 15, 20);
    Section* s6 = new Section(*s5);
    delete s4;
    delete s5;
    delete s6;

    _getch();
    return 0;
}