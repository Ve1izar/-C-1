#include <iostream>
#include <memory>
#include <conio.h>
using namespace std;

int* CreateArr(int size)
{
    int* arr = new int[size];
    return arr;
}

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

int* AddNumber(int* arr, int* size, int number)
{
    (*size)++;
    int* temp = new int[*size];

    for (int i = 0; i < (*size) - 1; i++)
    {
        temp[i] = arr[i];
    }

    temp[(*size) - 1] = number;

    delete[]arr;

    arr = temp;
    return arr;
}

int* DeleteLast(int* arr, int* size, int number)
{
    if (*size <= 0) return nullptr;

    (*size)--;
    int* temp = new int[*size];

    for (int i = 0; i < (*size); i++)
    {
        temp[i] = arr[i];
    }

    delete[]arr;

    arr = temp;
    return arr;
}

int* DeleteFirst(int* arr, int* size, int number)
{
    if (*size <= 0) return nullptr;

    (*size)--;
    int* temp = new int[*size];

    for (int i = 0; i < *size; i++)
    {
        temp[i] = arr[i+1];
    }

    delete[]arr;

    arr = temp;
    return arr;
}

int* DeleteByPosition(int* arr, int* size, int number, int pos)
{
    if(pos < 0 || pos >= *size) return arr;

    (*size)--;
    int* temp = new int[*size];

    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }


    for (int i = pos; i < *size; i++)
    {
        temp[i] = arr[i + 1];
    }

    delete[] arr;
    arr = temp;
    return arr;
}

int* AddByPosition(int* arr, int* size, int number, int pos)
{
    (*size)++;
    int* temp = new int[*size];

    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }

    temp[pos] = number;

    for (int i = pos + 1; i < *size; i++)
    {
        temp[i] = arr[i - 1];
    }

    delete[] arr;
    arr = temp;
    return arr;
}


int main()
{
	setlocale(LC_ALL, "ukr");
    srand(time(0));
    int size = 5;
    int* arr = CreateArr(size);

    FillArr(arr, size);
    ShowArr(arr, size);

    int number, position;
    char choice;

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Додати елемент у кінець\n" << "2. Додати елемент у позицію\n" << "3. Видалити останній елемент\n" << "4. Видалити перший елемент\n" << "5. Видалити за позицією\n" << "6. Показати масив\n" << "0. Вийти\n" << "Вибір: \n";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Введіть число: ";
            cin >> number;
            arr = AddNumber(arr, &size, number);
            break;
        case '2':
            cout << "Введіть число: ";
            cin >> number;
            cout << "Введіть позицію (0-" << size << "): ";
            cin >> position;
            if (position >= 0 && position <= size)
                arr = AddByPosition(arr, &size, number, position);
            else
                cout << "Некоректна позиція!\n";
            break;
        case '3':
            arr = DeleteLast(arr, &size, 0);
            break;
        case '4':
            arr = DeleteFirst(arr, &size, 0);
            break;
        case '5':
            cout << "Введіть позицію для видалення (0-" << size - 1 << "): ";
            cin >> position;
            arr = DeleteByPosition(arr, &size, 0, position);
            break;
        case '6':
            ShowArr(arr, size);
            break;
        case '0':
            break;
        default:
            cout << "Невірний вибір!\n";
        }
    } while (choice != '0');

    delete[] arr;

    return 0;
}
