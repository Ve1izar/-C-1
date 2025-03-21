#include <iostream>

using namespace std;


int main() {
    // ДЗ 1 
    // Завдання 1
    int a, sum = 0;
    cout << "Введіть число a: ";
    cin >> a;

    for (int i = a; i <= 500; i++) {
        sum += i;
    }
    cout << "Сума від " << a << " до 500 = " << sum << endl;

    // Завдання 2
    int x, y, result = 1;
    cout << "\nВведіть два числа x і y: ";
    cin >> x >> y;

    for (int i = 0; i < y; i++) {
        result *= x;
    }
    cout << x << " у степені " << y << " = " << result << endl;

    // Завдання 3
    int sum2 = 0;
    for (int i = 1; i <= 1000; i++) {
        sum2 += i;
    }
    cout << "\nСереднє арифметичне від 1 до 1000 = " << sum2 / 1000.0 << endl;

    // Завдання 4
    int a2, product = 1;
    cout << "\nВведіть число a (1 <= a <= 20): ";
    cin >> a2;

    for (int i = a2; i <= 20; i++) {
        product *= i;
    }
    cout << "Добуток чисел від " << a2 << " до 20 = " << product << endl;

    // Завдання 5
    int k;
    cout << "\nВведіть номер варіанта k: ";
    cin >> k;

    cout << "Таблиця множення для " << k << ":\n";
    for (int i = 1; i <= 10; i++) {
        cout << k << " * " << i << " = " << (k * i) << endl;
    }

    // ДЗ 2
    // Завдання 1
    int count1 = 0;
    for (int i = 100; i <= 999; i++) {
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;
        if (a == b || b == c || a == c) {
            count1++;
        }
    }
    cout << "Кількість чисел з двома однаковими цифрами: " << count1 << endl;

    // Завдання 2
    int count2 = 0;
    for (int i = 100; i <= 999; i++) {
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;
        if (a != b && b != c && a != c) {
            count2++;
        }
    }
    cout << "Кількість чисел з різними цифрами: " << count2 << endl;

    // Завдання 3
    int num3;
    cout << "\nВведіть ціле число: ";
    cin >> num3;
    int result3 = 0, multiplier = 1;
    while (num3 != 0) {
        int digit = num3 % 10;
        if (digit != 3 && digit != 6) {
            result3 = digit * multiplier + result3;
            multiplier *= 10;
        }
        num3 /= 10;
    }
    cout << "Число після видалення 3 і 6: " << result3 << endl;

    // Завдання 4
    int A4;
    cout << "\nВведіть число A: ";
    cin >> A4;
    cout << "Числа B, що задовольняють умову: ";
    for (int B = 1; B * B <= A4; B++) {
        if (A4 % (B * B) == 0 && A4 % (B * B * B) != 0) {
            cout << B << " ";
        }
    }
    cout << endl;

    // Завдання 5
    int A5;
    cout << "\nВведіть число A: ";
    cin >> A5;
    int sum5 = 0, temp = A5;
    while (temp != 0) {
        sum5 += temp % 10;
        temp /= 10;
    }
    if (sum5 * sum5 * sum5 == A5 * A5) {
        cout << "Так, куб суми цифр дорівнює A^A." << endl;
    }
    else {
        cout << "Ні, куб суми цифр НЕ дорівнює A^A." << endl;
    }

    // Завдання 6
    int num6;
    cout << "\nВведіть число: ";
    cin >> num6;
    cout << "Число ділиться без залишку на: ";
    for (int i = 1; i <= num6; i++) {
        if (num6 % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Завдання 7
    int num7a, num7b;
    cout << "\nВведіть два числа: ";
    cin >> num7a >> num7b;
    cout << "Спільні дільники: ";
    for (int i = 1; i <= min(num7a, num7b); i++) {
        if (num7a % i == 0 && num7b % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;


    return 0;
}
