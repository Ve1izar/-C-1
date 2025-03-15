#include <iostream>
#include <math.h>
#include <Windows.h>
    using namespace std;

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        // 1
        double inch;
        const double inch_to_cm = 2.54;
        cout << "Вхідними даними є:\n" << "Діагональ телевізора (inch) --> ";
        cin >> inch;
        cout << "---------------------\n" << "Вихідні дані:\n" << "Діагональ телевізора: " << inch * inch_to_cm << endl;
        // 2
        double foodpd;
        const double d_in_month = 30;
        cout << "\nВхідними даними є:\n" << "Витрата корму за 1 день (г) --> ";
        cin >> foodpd;
        cout << "---------------------\n" << "Вихідні дані:\n" << "Обсяг корму на 30 днів: " << (foodpd * d_in_month) / 1000.0 << endl;


        // 1
        int a, b, c;
        cout << "Введіть 3 числа: ";
        cin >> a >> b >> c;
        cout << "Сума: " << a + b + c << endl;

        // 2
        double x, y;
        cout << "Введіть 2 числа: ";
        cin >> x >> y;
        cout << "Середнє арифметичне: " << (x + y) / 2 << endl;

        // 3
        double km;
        cout << "Введіть кількість кілометрів: ";
        cin >> km;
        cout << "В метрах: " << km * 1000 << endl;

        // 4
        const double price1 = 10.5, price2 = 20.0, price3 = 15.75, price4 = 30.25;
        int quantity1, quantity2, quantity3, quantity4;
        cout << "Введіть кількість кожного із 4 продуктів: ";
        cin >> quantity1 >> quantity2 >> quantity3 >> quantity4;
        double totalCost = (price1 * quantity1) + (price2 * quantity2) + (price3 * quantity3) + (price4 * quantity4);
        cout << "Загальна вартість: " << totalCost << endl;

        // 5
        double num;
        cout << "Введіть число: ";
        cin >> num;
        cout << "Квадрат даного числа: " << pow(num, 2) << endl;

        // 6
        const int minutesInDay = 1440;
        int days;
        cout << "Введіть кількість днів: ";
        cin >> days;
        cout << "Ця кількість днів у хвилинах: " << days * minutesInDay << endl;

        return 0;
    }