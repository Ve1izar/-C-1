#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int ROWS = 4, COLS = 3;

	int arr[ROWS][COLS] = {
		{-5, 13, 7},
		{0, -18, 12},
		{19, 3, 6},
		{8, -1, 15}
	};
    
        
    //cout << "Введіть елементи масиву 4x3:\n";
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        cin >> arr[i][j];
    //    }
    //}


    int maxWidth = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int len = to_string(arr[i][j]).length();
            if (len > maxWidth) {
                maxWidth = len;
            }
        }
    }

    int cellWidth = maxWidth + 4;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            string num = to_string(arr[i][j]);
            int padding = (cellWidth - num.length()) / 2;
            cout << string(padding, ' ') << num << string(cellWidth - num.length() - padding, ' ');
        }
        cout << endl;
    }

    int NotZero = 0, Zero = 0, ModLess12 = 0, Positive = 0;
    int Mod6_1 = 0, minElem = arr[0][0], maxElem = arr[0][0];
    long long productPositive = 1, productNegative = 1, sumNegative = 0;
    bool hasPositive = false, hasNegative = false;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int value = arr[i][j];

            if (value != 0) NotZero++;
            else Zero++;

            if (value < 12 && value > -12) ModLess12++;
            if (value > 0) Positive++;

            if (value > 0) {
                productPositive *= value;
                hasPositive = true;
            }
            if (value < 0) {
                productNegative *= value;
                hasNegative = true;
            }

            if (value % 6 == 1) Mod6_1++;

            if (value < minElem) minElem = value;
            if (value > maxElem) maxElem = value;

            if (value < 0) sumNegative += value;
        }
    }

    cout << "\n1. Кількість ненульових елементів: " << NotZero;
    cout << "\n2. Кількість нульових елементів: " << Zero;
    cout << "\n3. Кількість елементів, |x| < 12: " << ModLess12;
    cout << "\n4. Кількість додатних елементів: " << Positive;
    cout << "\n5. Добуток додатних елементів: " << (hasPositive ? productPositive : 0);
    cout << "\n6. Добуток від’ємних елементів: " << (hasNegative ? productNegative : 0);
    cout << "\n7. Кількість елементів, що дають залишок 1 при /6: " << Mod6_1;
    cout << "\n8. Мінімальний елемент: " << minElem;
    cout << "\n9. Максимальний елемент: " << maxElem;
    cout << "\n10. Сума від’ємних елементів: " << sumNegative << endl;

    return 0;
}
