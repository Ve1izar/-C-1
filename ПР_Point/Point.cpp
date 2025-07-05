#include "Vector.h"

int main() {
    setlocale(LC_ALL, "ukrainian");
    Point p1(3, 4);
    Point p2(1, 2);

    cout << "����� 1: "; p1.Print();
    cout << "����� 2: "; p2.Print();

    cout << "\n��������� (>): " << (p1 > p2 ? "p1 ��� �� (0,0)" : "p2 ��� �� (0,0)") << endl;

    cout << "\n���������� ++ ��� p1: ";
    ++p1;
    p1.Print();

    cout << "\n���������� -- ��� p2: ";
    --p2;
    p2.Print();

    cout << "\n������� p1 (!): ";
    !p1;
    p1.Print();

    Vector vec;

    vec.Add(p1);
    vec.Add(p2);

    cout << "\nVector:" << endl;
    vec.Print();

    return 0;
    return 0;
}