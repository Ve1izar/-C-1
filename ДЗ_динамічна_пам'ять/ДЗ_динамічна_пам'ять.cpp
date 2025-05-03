#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;    

int* CreateArray(int size) {
    return new int[size];
}

void FillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

void ShowArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
	setlocale(LC_ALL, "ukr");
    //1
    int* a = new int(2);
    double* b = new double(3.14);
    float* c = new float(2.5f);

    cout << "Значення змінних:\n";
    cout << "*a = " << *a << endl;
    cout << "*b = " << *b << endl;
    cout << "*c = " << *c << endl;

    double product = (*a) * (*b) * (*c);

    cout << "Добуток = " << product << endl;

    delete a;
    delete b;
    delete c;

    //2
    srand(time(0));

    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int* arr = CreateArray(size);
    FillArray(arr, size);
    cout << "Ваш масив:\n";
    ShowArray(arr, size);

    delete[] arr;

    return 0;
}
