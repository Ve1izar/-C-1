#include <iostream>
#include <fstream>
using namespace std;

// Реалізуйте клас «Точка». Необхідно зберігати координати x, y, z в змінних-членах класу. 
// Реалізуйте функціїчлени класу для введення даних, виведення даних, реалізуйте аксесор для доступу до змінних-членів, 
// реалізуйте збереження в файл і завантаження даних з файлу.

class Point {
private:
    int x, y, z;

public:

    void PrintInfo() {
        cout << "Координати\n" << "X: " << x << "\nY: " << y << "\nZ: " << z << endl;
    }

    void InitPoint()
    {
        cout << "Enter X: "; cin >> x;
        cout << "Enter Y: "; cin >> y;
        cout << "Enter Z : "; cin >> z;
    }

	void SetCoordinates(int newX, int newY, int newZ) {
		x = newX;
		y = newY;
		z = newZ;
	}

	void GetCoordinates(int& xOut, int& yOut, int& zOut) const {
		xOut = x;
		yOut = y;
		zOut = z;
	}

	void SaveToFile(const char* filename) const {
		ofstream out(filename);
		if (!out) {
			cout << "Помилка відкриття файлу для запису.\n";
			return;
		}
		out << x << " " << y << " " << z << endl;
		out.close();
		cout << "Дані збережено у текстовий файл.\n";
	}

	void LoadFromFile(const char* filename) {
		ifstream in(filename);
		if (!in) {
			cout << "Файл не знайдено або не вдалося відкрити.\n";
			return;
		}
		in >> x >> y >> z;
		in.close();
		cout << "Дані завантажено з текстового файлу.\n";
	}
};

int main()
{
	setlocale(LC_ALL, "ukrainian");

	Point p;

	const char* filename = "points.txt";

	
	int choice;
	do {
		cout << "\n----------- Menu -----------\n";
		cout << "1. Показати точку\n";
		cout << "2. Задати точку\n";
		cout << "3. Зберегти у файл\n";
		cout << "4. Завантажити з файлу\n";
		cout << "0. Вийти\n";
		cout << "Ваш вибір: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			p.PrintInfo();
			break;
		case 2:
			p.InitPoint();
			break;
		case 3:
			p.SaveToFile(filename);
			break;
		case 4:
			p.LoadFromFile(filename);
			break;
		case 0:
			cout << "Завершення роботи..." << endl;
			break;
		default:
			cout << "Невірний вибір!" << endl;
		}

	} while (choice != 0);

    return 0;
}