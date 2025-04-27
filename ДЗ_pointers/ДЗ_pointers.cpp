#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <iomanip>
#include <Windows.h>
using namespace std;


void FillArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100;
    }
}

void ShowArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void MinusToZero(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0) arr[i] = 0;
    }
}

void FillArr(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        *(matrix + i) = rand() % 100;
    }
}

void ShowArr(int* matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << *(matrix + i * cols + j);
        }
        cout << endl;
    }
}

void SwapFirstSecond(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        swap(*(matrix + i * cols + 0), *(matrix + i * cols + 1));
    }
}


int main()
{
    //   1.Дано три числа. Оголосити ссилки на ці числа. 
    // Отримати добуток трьох заданих чисел, середє арифметичне, найменше з них, 
    // користуючись непрямим доступом до чисел (через ссилку) 
    int a, b, c;
    int minnum;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    int& la = a;
    int& lb = b;
    int& lc = c;

    if (la < lb && la < lc) minnum = la;
    else if (lb < la && lb < lc) minnum = lb;
    else minnum = lc;

    cout << "Добуток чисел: " << la * lb * lc << endl;
    cout << "Середнє арифметичне: " << (la + lb + lc) / 3.0 << endl;
    cout << "Найменшим із чисел є: " << minnum;

    cout << endl;

    // 2.Написати функцію, яка замінює всі від’ємні елементи переданого масиву нулями. (pointers)
    const int size = 10;
    int arr[size] = { -10, 16, 18, 3, -1, -18, 7, -8, 11, 10 };
    // FillArr(arr, size);
    ShowArr(arr, size);
    MinusToZero(arr, size);
    ShowArr(arr, size);

    cout << endl;

    // 3.Написать функцію (або шаблон), яка приймає дві ссилки на змінні і 
    // виконує обмін значень. За допомогою написаної функції поміняти місцями 
    // у матриці перший та другий стовпці.
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел

    const int rows = 4;
    const int cols = 3;
    int matrix[rows][cols];

    FillArr(&matrix[0][0], rows, cols);
    ShowArr(&matrix[0][0], rows, cols);

    cout << endl;

    SwapFirstSecond(&matrix[0][0], rows, cols);

    ShowArr(&matrix[0][0], rows, cols);

    return 0;
}