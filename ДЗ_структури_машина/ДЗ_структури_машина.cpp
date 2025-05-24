#include <iostream>
#include <cstring>
using namespace std;

union CarNumber {
    int num;        // П’ятизначний номер
    char word[9];   // Слово до 8 символів + '\0'
};

struct Car {
    char color[20];
    char model[30];
    bool isWordNumber; // true — word, false — num
    CarNumber number;
};

void FillCar(Car& car)
{
    cout << "Введіть колір: ";
    cin.getline(car.color, 20);

    cout << "Введіть модель: ";
    cin.getline(car.model, 30);

    cout << "Номер у вигляді: 1 - п’ятизначне число, 2 - слово: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Введіть п’ятизначний номер: ";
        cin >> car.number.num;
        cin.ignore();
        car.isWordNumber = false;
    }
    else {
        cout << "Введіть слово (до 8 символів): ";
        cin.getline(car.number.word, 9);
        car.isWordNumber = true;
    }
}

void PrintCar(const Car& car)
{
    cout << "\nМодель: " << car.model << endl;
    cout << "Колір: " << car.color << endl;
    cout << "Номер: ";
    if (car.isWordNumber)
        cout << car.number.word << endl;
    else
        cout << car.number.num << endl;
    cout << "------------------------------" << endl;
}

void EditCar(Car& car)
{
    cout << "\nРедагування машини:\n";
    FillCar(car);
}

void PrintAllCars(Car cars[], int size)
{
    for (int i = 0; i < size; i++) {
        PrintCar(cars[i]);
    }
}

void SearchCar(Car cars[], int size)
{
    cout << "Пошук за номером:\n";
    cout << "Тип номера: 1 - число, 2 - слово: ";
    int type;
    cin >> type;
    cin.ignore();

    bool found = false;

    if (type == 1) {
        int num;
        cout << "Введіть номер: ";
        cin >> num;
        cin.ignore();

        for (int i = 0; i < size; i++) {
            if (!cars[i].isWordNumber && cars[i].number.num == num) {
                PrintCar(cars[i]);
                found = true;
            }
        }
    }
    else {
        char word[9];
        cout << "Введіть слово: ";
        cin.getline(word, 9);

        for (int i = 0; i < size; i++) {
            if (cars[i].isWordNumber && strcmp(cars[i].number.word, word) == 0) {
                PrintCar(cars[i]);
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Машину не знайдено.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "ukr");

    const int SIZE = 10;
    Car cars[SIZE];

    int count = 0;
    int choice;

    do {
        cout << "\n=== Меню ===\n";
        cout << "1. Додати нову машину\n";
        cout << "2. Редагувати машину\n";
        cout << "3. Показати всі машини\n";
        cout << "4. Пошук за номером\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            if (count < SIZE) {
                FillCar(cars[count]);
                count++;
            }
            else {
                cout << "Масив заповнений!\n";
            }
            break;
        case 2: {
            int idx;
            cout << "Введіть індекс машини [0.." << count - 1 << "]: ";
            cin >> idx;
            cin.ignore();
            if (idx >= 0 && idx < count)
                EditCar(cars[idx]);
            else
                cout << "Неправильний індекс!\n";
            break;
        }
        case 3:
            PrintAllCars(cars, count);
            break;
        case 4:
            SearchCar(cars, count);
            break;
        case 0:
            cout << "Завершення програми...\n";
            break;
        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
