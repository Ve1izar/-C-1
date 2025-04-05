#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void showCube(int length, int width) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cout << "#";
        }
        cout << endl;
    }
    cout << endl;
}

void showCube(int length, int width, char symbol) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cout << symbol;
        }
        cout << endl;
    }
    cout << endl;
}

int checkYear(int year) {
    if (year % 4 == 0 || ((year % 100 == 0) && (year % 400 != 0))) {
        return true;
    }
    else return false;
    cout << endl;
}

void arrayFiller(int arr[], const int size, int range) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void averageFinder(int arr[], const int size) {
    int counter = 0;
    int summ = 0;
    for (int i = 0; i < size; i++) {
        summ += arr[i];
        counter += 1;
    }
    cout << "Середнє арифметичне масиву = " << summ / counter;
    cout << endl;
}

void arrayReverse(int arr[], const int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int fact(int x) {
    unsigned long result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }

    return result;
}

void Initialize(int array[], const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // 0–99
    }
}

void Initialize(double array[], const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 10000) / 100.0; // 0.00–99.99
    }
}

void Initialize(char array[], const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 33 + rand() % 94; // Символи ASCII: ! до ~
    }
}

template <typename T>
void PrintArray(T array[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //// 1
    //showCube(3, 4);

    //// 2
    //showCube(5, 3, '$');

    //// 3    
    //bool checker = checkYear(2095);
    //if (checker) cout << "Рік високосний";
    //else cout << "Рік не високоснний";
    //cout << endl;

    //// 4
    //int num;
    //cout << "введіть число, факторіал якого необхідно знайти: ";
    //cin >> num;
    //cout << endl << "факторіалом числа " << num << " є " << fact(num) << endl;

    //// 5
    ////srand(time(0));
    //const int size = 6;
    //int arr1[size];
    //arrayFiller(arr1, size, 35);

    //// 6
    //int arr2[size] = { -4, 7, 11, 4, 0, -1 };
    //averageFinder(arr2, size);

    //// 7
    //arrayReverse(arr2, size);

    // 8 
    const int size = 10;

    int intArr[size];
    double doubleArr[size];
    char charArr[size];

    Initialize(intArr, size);
    Initialize(doubleArr, size);
    Initialize(charArr, size);

    cout << "Масив цілих: ";
    PrintArray(intArr, size);

    cout << "Масив дробових: ";
    PrintArray(doubleArr, size);

    cout << "Масив символів: ";
    PrintArray(charArr, size);

    return 0;
}