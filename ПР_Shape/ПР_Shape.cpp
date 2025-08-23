#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
    string name;
    string color;
public:
    Shape(string n, string c) : name(n), color(c) {}
    virtual double GetArea() const = 0;
    virtual void Show() const {
        cout << "Форма: " << name << ", Колір: " << color << endl;
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r) : Shape("Коло", c), radius(r) {}
    double GetArea() const override {
        return 3.14159 * radius * radius;
    }
    void Show() const override {
        Shape::Show();
        cout << "Радіус: " << radius << ", Площа: " << GetArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(string c, double w, double h) : Shape("Прямокутник", c), width(w), height(h) {}
    double GetArea() const override {
        return width * height;
    }
    void Show() const override {
        Shape::Show();
        cout << "Ширина: " << width << ", Висота: " << height << ", Площа: " << GetArea() << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(string c, double b, double h) : Shape("Трикутник", c), base(b), height(h) {}
    double GetArea() const override {
        return 0.5 * base * height;
    }
    void Show() const override {
        Shape::Show();
        cout << "Основа: " << base << ", Висота: " << height << ", Площа: " << GetArea() << endl;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(string c, double s) : Shape("Квадрат", c), side(s) {}
    double GetArea() const override {
        return side * side;
    }
    void Show() const override {
        Shape::Show();
        cout << "Сторона: " << side << ", Площа: " << GetArea() << endl;
    }
};

class Trapezoid : public Shape {
private:
    double base1, base2, height;
public:
    Trapezoid(string c, double b1, double b2, double h)
        : Shape("Трапеція", c), base1(b1), base2(b2), height(h) {
    }
    double GetArea() const override {
        return 0.5 * (base1 + base2) * height;
    }
    void Show() const override {
        Shape::Show();
        cout << "Основа 1: " << base1 << ", Основа 2: " << base2
            << ", Висота: " << height << ", Площа: " << GetArea() << endl;
    }
};

class RightTriangle : public Shape {
private:
    double a, b;
public:
    RightTriangle(string c, double x, double y)
        : Shape("Прямокутний трикутник", c), a(x), b(y) {
    }
    double GetArea() const override {
        return 0.5 * a * b;
    }
    void Show() const override {
        Shape::Show();
        cout << "Катет a: " << a << ", Катет b: " << b
            << ", Площа: " << GetArea() << endl;
    }
};

void TestShape(const Shape& s) {
    s.Show();
    cout << "--------------------------" << endl;
}

int main() {

	setlocale(LC_ALL, "ukr");

    Circle c("Червоний", 5);
    Rectangle r("Синій", 4, 6);
    Triangle t("Зелений", 3, 7);
    Square sq("Жовтий", 4);
    Trapezoid tr("Фіолетовий", 6, 10, 5);
    RightTriangle rt("Помаранчевий", 3, 4);

    TestShape(c);
    TestShape(r);
    TestShape(t);
    TestShape(sq);
    TestShape(tr);
    TestShape(rt);

    return 0;
}

