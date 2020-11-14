#include <iostream>

class Point{
    friend int compareX(const Point &p1, const Point &p2);
    friend int compareY(const Point &p1, const Point &p2);
    friend int compareXY(const Point &p1, const Point &p2);
    friend void directions(const Point &p1, const Point &p2, int(*f)(const Point &, const Point &));

    public:
    Point();
    Point(double x, double y);
    Point(const char* name, double x, double y);
    Point(const Point &p1);
    Point(Point &&p1);
    ~Point();
    double getX(); 
    double getY();
    char* getName(); 
    void changeName(const char* name);
    void fullPrint();
    void move(double x, double y);

    private:
    char* _name;
    double _x;
    double _y;
};

    int compareX(const Point &p1, const Point &p2);
    int compareY(const Point &p1, const Point &p2);
    int compareXY(const Point &p1, const Point &p2);
    void directions(const Point &p1, const Point &p2, int(*f) (const Point &, const Point &));
