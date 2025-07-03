#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Vector {
private:
    Point* points;
    int countPoint;

public:
    Vector() : points(nullptr), countPoint(0) {}

    Vector(const Vector& other) {
        countPoint = other.countPoint;
        if (countPoint > 0) {
            points = new Point[countPoint];
            for (int i = 0; i < countPoint; ++i) {
                points[i] = other.points[i];
            }
        }
        else {
            points = nullptr;
        }
    }

    Vector(Vector&& other) noexcept {
        points = other.points;
        countPoint = other.countPoint;
        other.points = nullptr;
        other.countPoint = 0;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] points;

            countPoint = other.countPoint;
            if (countPoint > 0) {
                points = new Point[countPoint];
                for (int i = 0; i < countPoint; ++i) {
                    points[i] = other.points[i];
                }
            }
            else {
                points = nullptr;
            }
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] points;

            points = other.points;
            countPoint = other.countPoint;

            other.points = nullptr;
            other.countPoint = 0;
        }
        return *this;
    }

    void Add(const Point& p) {
        Point* newPoints = new Point[countPoint + 1];
        for (int i = 0; i < countPoint; ++i) {
            newPoints[i] = points[i];
        }
        newPoints[countPoint] = p;

        delete[] points;
        points = newPoints;
        ++countPoint;
    }

    void Print() const {
        cout << "Vector має " << countPoint << " точок:" << endl;
        for (int i = 0; i < countPoint; ++i) {
            cout << i + 1 << ": ";
            points[i].Print();
        }
    }

    ~Vector() {
        delete[] points;
    }
};
