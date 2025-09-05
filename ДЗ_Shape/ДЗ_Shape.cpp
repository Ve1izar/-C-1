#include <iostream>
#include <string>
using namespace std;

struct Point {
    double x, y;
    Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
};

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void Show() const = 0;
    virtual ~Shape() = default;
};

class Line : public Shape {
private:
    Point start, end;
public:
    Line(Point s, Point e) : Shape("Лінія"), start(s), end(e) {}
    void Show() const override {
        cout << name << " (" << start.x << ", " << start.y << ")" << ", (" << end.x << ", " << end.y << ")" << endl;
    }
    ~Line() override = default;
};

class Rectangle : public Shape {
private:
    Point topLeft;
    double width, height;
public:
    Rectangle(Point tl, double w, double h): Shape("Прямокутник"), topLeft(tl), width(w), height(h) {
    }
    void Show() const override {
        cout << name << ": Верхній лівий кут (" << topLeft.x << ", " << topLeft.y << ")" << ", Ширина = " << width << ", Висота = " << height << endl;
    }
    ~Rectangle() override = default;
};

class Polyline : public Shape {
private:
    Point* points;
    int count;
public:
    Polyline(Point* pts, int n) : Shape("Ламана"), count(n) {
        points = new Point[n];
        for (int i = 0; i < n; i++) {
            points[i] = pts[i];
        }
    }
    void Show() const override {
        cout << name << ": ";
        for (int i = 0; i < count; i++) {
            cout << "(" << points[i].x << ", " << points[i].y << ")";
            if (i < count - 1) cout << ", ";
        }
        cout << endl;
    }
    ~Polyline() override {
        delete[] points;
    }
};


int main()
{
    setlocale(LC_ALL, "ukr");

    Line l(Point(0, 0), Point(5, 5));
    Rectangle r(Point(2, 2), 6, 4);

    Point pts[] = { Point(0,0), Point(1,2), Point(3,1), Point(4,4) };
    Polyline pl(pts, 4);

    l.Show();
    r.Show();
    pl.Show();
}