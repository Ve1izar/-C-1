#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // 1
    // int a, b, c;
    // cout << "Введіть значення сторін трикутника: ";
    // cin >> a >> b >> c;

    // if (a == b == c) {
    //     cout << "Трикутник є рівностороннім" << endl;
    // }
    // else if (a == b || b == c || a == c) {
    //     cout << "Трикутник є рівнобедреним" << endl;

    // }
    // else if ((pow(a,2) == pow(b,2) + pow(c,2)) || (pow(c,2) == pow(a,2) + pow(b,2) ) || (pow(b,2) == pow(a,2) + pow(c,2))) {
    //     cout << "Трикутник є прямокутним" << endl;

    // }
    // else {
    //     cout << "Трикутник є різностороннім" << endl;
    // }

    // 2
    // int a, b, c, x, y, z;
    // cout << "Введіть висоту, довжину та ширину цегли: ";
    // cin >> a >> b >> c;

    // cout << "Введіть висоту, довжину та ширину отвору: ";
    // cin >> x >> y >> z;

    // double volume_brick = a*b*c;
    // double volume_hole = x*y*z;

    // if (volume_brick <= volume_hole && (a <= x && b <= y)) {
    //     cout << "Цегла пройде в отвір" << endl;

    // }
    // else {
    //     cout << "Цегла не пройде" << endl; 
    // }

    // 3
    // int a, b, c;
    // cout << "Введіть 3 числа: ";
    // cin >> a >> b >> c;

    // int i = 0;

    // if (a > 0) {
    //     i+=1; 
    // }
    // if (b > 0) {
    //     i+=1; 
    // }
    // if (c > 0) {
    //     i+=1;
    // }

    // switch (i) {
    //     case 3:
    //         cout << "Всі числа є додатними" << endl;
    //         break;
    //     case 0:
    //         cout << "Нема додатних чисел" << endl;
    //         break;
    //     default:
    //         cout << "Із 3 чисел всього " << i << " додатні" << endl;
    //         break;
    // }

    // 4
    // int a;
    // cout << "Введіть число: ";
    // cin >> a;

    // if (2<=a<=5 && -1<=a<=1) {
    // cout << "Число в межах відрізків [2, 5] та [-1, 1]" << endl;
    // }
    // else {
    //     cout << "Число за межами відрізків [2, 5] та [-1, 1]" << endl;
    // }
    // 5
    // int a,b,c;
    // cout << "Введіть три числа: ";
    // cin >> a >> b >> c;

    // if (a == b == c) {
    //     cout << "Всі числа рівні" << endl;
    // }
    // else {
    //     cout << "Числа не рівні" << endl;
    // }

    // 1
    // int a,b,c,d;
    // cout << "Введіть сторони прямокутника: ";
    // cin >> a >> b >> c >> d;

    // if (a == b == c == d) {
    //     cout << "Прямокутник є квадратом" << endl;
    // }
    // else {
    //     cout << "Прямокутник не є квадратом" << endl;
    // }

    // 2
    // int age;
    // cout << "Введіть вік дитини: ";
    // cin >> age;
    // if (age >= 3 && age < 6) {
    //     cout << "Дитина може відвідувати дитсадок" << endl;
    // } else if (age >= 6 && age <= 17) {
    //     cout << "Дитина може ходити до школи" << endl;
    // } else if (age < 3) {
    //     cout << "Дитині замало років для відвідування дитсадку" << endl;

    // 3
    // int a,b,c;
    // cout << "Введіть три числа: ";
    // cin >> a >> b >> c;
    // if ((a<0 && b<0)||(a<0 && c<0)||(c<0 && b<0)) {
    //     cout << "Рівно два числа є від'ємними" << endl;
    // }
    // else {
    //     cout << "Нема рівно двох від'ємних чисел" << endl;
    // }

    // 4
    // int a;
    // cout << "Введіть число: ";
    // cin >> a;

    // if (2<=a<=5 && -1<=a<=1) {
    // cout << "Число в межах відрізків [2, 5] та [-1, 1]" << endl;
    // }
    // else {
    //     cout << "Число за межами відрізків [2, 5] та [-1, 1]" << endl;
    // }

    // 5
    // int a,b,c;
    // cout << "Введіть три числа: ";
    // cin >> a >> b >> c;

    // if (a == b || a == c || b == c) {
    //     cout << "Рівно два числа рівні" << endl;
    // }
    // else {
    //     cout << "Числа не рівні" << endl;
    // }

    // 6
    // int a,b,c;
    // cout << "Введіть три числа: ";
    // cin >> a >> b >> c;
    // if (a%2 != 0 && b%2 != 0 && c%2 != 0) {
    //     cout << "Всі числа є непарними" << endl;
    // }
    // else {
    //     cout << "Не всі числа є непарними" << endl;
    // }

    // if () {
    //     cout << "Всі числа рівні" << endl;
    // }
    // else {
    //     cout << "Числа не рівні" << endl;
    // }

    // 7
    // int a, b;
    // cout << "Введіть 2 числа: ";
    // cin >> a >> b;

    // if (a != b) {
    //     int temp = a;
    //     a = b;
    //     b = temp;
    // }
    // cout << "Поміняні місцями: " << a << " " << b << endl;

    // 8
    // int num;
    // cout << "Введіть трицифрове число: ";
    // cin >> num;
    // if (num > 100 && num < 999) {
    //     int first = num / 100;
    //     int middle = num / 10 % 10;
    //     int last = num % 10;
    //     int sum = first + middle + last;
    //     cout << "Сума цифер у числі " << num << " = " << sum << endl;
    //     cout << first << "  " << last << endl;
    // } else {
    //     cout << "Число не відповідає вимогам" << endl;
    // }

    // 9
    // int h, m, s;
    // cout << "Enter time (гг мм сс): ";
    // cin >> h >> m >> s;
    // if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
    //     cout << "Уоречтний час" << endl;
    // } else {
    //     cout << "Некоректний час" << endl;
    // }

    // 10
    // int hour;
    // cout << "Введіть годину: ";
    // cin >> hour;
    // if (hour >= 0 && hour < 6) {
    //     cout << "Good night" << endl;
    // } else if (hour >= 6 && hour < 12) {
    //     cout << "Good morning" << endl;
    // } else if (hour >= 12 && hour < 18) {
    //     cout << "Good day" << endl;
    // } else if (hour >= 18 && hour < 24) {
    //     cout << "Good evening" << endl;
    // } else {
    //     cout << "Некоректна година" << endl;
    // }

    // 11
    int x, y, z;
    cout << "Введіть 3 числа: ";
    cin >> x >> y >> z;
    int min = x;
    if (y < min) min = y;
    if (z < min) min = z;
    cout << "Мінімальне число: " << min << endl;

    return 0;
}