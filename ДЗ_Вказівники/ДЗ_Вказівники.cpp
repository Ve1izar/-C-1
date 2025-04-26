#include <iostream>
using namespace std;

void findMax(int* a, int* b) {
    if (*a > *b)
        cout << "Більше число: " << *a << endl;
    else
        cout << "Більше число: " << *b << endl;
}

void checkSign(int* a) {
    if (*a > 0)
        cout << "Число позитивне." << endl;
    else if (*a < 0)
        cout << "Число негативне." << endl;
    else
        cout << "Число нуль." << endl;
}

void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculator(double* a, double* b, char* operation) {
    switch (*operation) {
    case '+': cout << "Результат: " << (*a) + (*b) << endl; break;
    case '-': cout << "Результат: " << (*a) - (*b) << endl; break;
    case '*': cout << "Результат: " << (*a) * (*b) << endl; break;
    case '/':
        if (*b != 0)
            cout << "Результат: " << (*a) / (*b) << endl;
        else
            cout << "Ділення на нуль неможливе!" << endl;
        break;
    default: cout << "Невідома операція." << endl;
    }
}

int sumArray(int* arr, int size) {
    int sum = 0;
    int* end = arr + size;

    for (int* p = arr; p < end; p++) {
        sum += *p;
    }
    return sum;
}

int main()
{
    //1
    int x = 5, y = 10;
    findMax(&x, &y);

    //2
    int num;
    cout << "Введіть число для визначення знаку: ";
    cin >> num;
    checkSign(&num);

    //3
    cout << "До обміну: x = " << x << ", y = " << y << endl;
    swapNumbers(&x, &y);
    cout << "Після обміну: x = " << x << ", y = " << y << endl;

    //4
    double a, b;
    char op;
    cout << "Введіть два числа і операцію (+, -, *, /): ";
    cin >> a >> b >> op;
    calculator(&a, &b, &op);

    //5
    const int size = 5;
    int arr[size] = { 1, 2, 3, 4, 5 };
    cout << "Сума елементів масиву: " << sumArray(arr, size) << endl;

    return 0;
}