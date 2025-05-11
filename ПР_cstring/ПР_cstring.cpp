#include <iostream>
#include <cstring>

using namespace std;

int MyStrLen(const char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int main()
{
    // 1.Вводиться рядок. Яких букв у рядку більше ’а’ чи ’о’ ?
    char string[255];
    int a, o = 0;

    cout << "Введіть рядок: ";
    cin.getline(string, 255);

    for (int i = 0; i < strlen(string) + 1; i++) {
        if (string[i] == 'a' || string[i] == 'A') a++;
        else if (string[i] == 'o' || string[i] == 'O') o++;
    }

    if (a < o) cout << "о більше ніж а";
    else if (o < a) cout << "а більше ніж о";
    else cout << "Неможливо визначити";

    cout << endl;

    // 2.Вводиться рядок. Порахувати кількість латинських букв, цифр та пробілів у рядку.
    int letters = 0, numbers = 0, spaces = 0;

    for (int i = 0; i < strlen(string) + 1; i++) {
        if (isalpha(string[i])) letters++;
        else if (isdigit(string[i])) numbers++;
        else if (isspace(string[i])) spaces++;
    }

    cout << "У рядку є " << letters << " літер, " << numbers << " цифр та " << spaces << " пробілів";
    // 3.Дано рядок. Замінити у рядку всі великі букви на малі і навпаки.
    int choice;
    while (true) {
        cout << "1 - змінити всі літери у рядку на малі \n2- змінити всі літери у рядку на великі\n0 - вийти\n";
        cin >> choice;
        switch (choice) {
        case 1:
            for (int i = 0; i < strlen(string) + 1; i++) {
                string[i] = tolower(string[i]);
            }
            cout << string << endl;
            break;

        case 2:
            for (int i = 0; i < strlen(string) + 1; i++) {
                string[i] = toupper(string[i]);
            }
            cout << string << endl;
            break;

        case 0:
            return 0;

        default:
            cout << "Невірний вибір!\n";
        }
    }


    // 4.Написати функцію, яка отримує рядок і повертає довжину рядка. 
    // Без використання функції strlen()
    cout << "Довжина рядка: " << MyStrLen(string) << endl;
    return 0;
}