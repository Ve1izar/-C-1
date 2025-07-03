#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}

	Point& operator ++() {
		++x;
		++y;
		return *this;
	}
	Point& operator --() {
		--x;
		--y;
		return *this;
	}

	friend bool operator>(const Point& a, const Point& b) {
		double distA = sqrt(a.x * a.x + a.y * a.y);
		double distB = sqrt(b.x * b.x + b.y * b.y);
		return distA > distB;
	}

	friend bool operator<(const Point& a, const Point& b) {
		double distA = sqrt(a.x * a.x + a.y * a.y);
		double distB = sqrt(b.x * b.x + b.y * b.y);
		return distA < distB;
	}

	void operator!() {
		x = -x;
		y = -y;
	}

	void Print() const {
		cout << "(" << x << ", " << y << ")" << endl;
	}

	~Point() {}
};
