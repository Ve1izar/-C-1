#include "Vector.h"

int main() {
    setlocale(LC_ALL, "ukrainian");
    Point p1(3, 4);
    Point p2(1, 2);

    cout << "Точка 1: "; p1.Print();
    cout << "Точка 2: "; p2.Print();

    cout << "\nПорівняння (>): " << (p1 > p2 ? "p1 далі від (0,0)" : "p2 далі від (0,0)") << endl;

    cout << "\nПрефіксний ++ для p1: ";
    ++p1;
    p1.Print();

    cout << "\nПрефіксний -- для p2: ";
    --p2;
    p2.Print();

    cout << "\nІнверсія p1 (!): ";
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