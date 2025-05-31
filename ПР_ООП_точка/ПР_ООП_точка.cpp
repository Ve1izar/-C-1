#include <iostream>
#include <fstream>
#include <string>	
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

//Реалізуйте клас «Студент».Необхідно зберігати в змінних - членах класу : ПІБ, дату народження, контактний телефон, місто, країну, 
//назву навчального закладу, місто та країну(де знаходиться навчальний заклад), номер групи.Реалізуйте функції - члени класу для введення даних, 
//виведення даних, реалізуйте аксесор для доступу до окремих змінних - членів.

class Student {
private:
	string name;
	string birthDate;
	string phone;
	string city;
	string country;
	string school;
	string cityofschool;
	string countryofschool;
	string groupNumber;

public:

	void PrintInfo() const {
		cout << "\n--- Інформація про студента ---\n";
		cout << "ПІБ: " << name << "\n";
		cout << "Дата народження: " << birthDate << "\n";
		cout << "Телефон: " << phone << "\n";
		cout << "Місто: " << city << ", " << country << "\n";
		cout << "Навчальний заклад: " << school << " (" << cityofschool << ", " << countryofschool << ")\n";
		cout << "Номер групи: " << groupNumber << "\n";
	}

	void InitStudent() {
		cin.ignore();
		cout << "Введіть ПІБ: "; getline(cin, name);
		cout << "Введіть дату народження (ДД.ММ.РРРР): "; getline(cin, birthDate);
		cout << "Введіть контактний телефон: "; getline(cin, phone);
		cout << "Введіть місто: "; getline(cin, city);
		cout << "Введіть країну: "; getline(cin, country);
		cout << "Введіть назву навчального закладу: "; getline(cin, school);
		cout << "Введіть місто навчального закладу: "; getline(cin, cityofschool);
		cout << "Введіть країну навчального закладу: "; getline(cin, countryofschool);
		cout << "Введіть номер групи: "; getline(cin, groupNumber);
	}

	void Setter(const string& newName, const string& newBD, const string& newP,
		const string& newCity, const string& newCountry,
		const string& newSchool, const string& newCityOS,
		const string& newCountryOS, const string& newGN) {
		name = newName;
		birthDate = newBD;
		phone = newP;
		city = newCity;
		country = newCountry;
		school = newSchool;
		cityofschool = newCityOS;
		countryofschool = newCountryOS;
		groupNumber = newGN;
	}

	void Getter(string& NameOut, string& BDOut, string& POut,
		string& CityOut, string& CountryOut,
		string& SchoolOut, string& CityOSOut,
		string& CountryOSOut, string& GNOut) const {
		NameOut = name;
		BDOut = birthDate;
		POut = phone;
		CityOut = city;
		CountryOut = country;
		SchoolOut = school;
		CityOSOut = cityofschool;
		CountryOSOut = countryofschool;
		GNOut = groupNumber;
	}

	void SaveToFile(ofstream& out) const {
		out << name << "\n"
			<< birthDate << "\n"
			<< phone << "\n"
			<< city << "\n"
			<< country << "\n"
			<< school << "\n"
			<< cityofschool << "\n"
			<< countryofschool << "\n"
			<< groupNumber << "\n";
	}

	void LoadFromFile(ifstream& in) {
		getline(in, name);
		getline(in, birthDate);
		getline(in, phone);
		getline(in, city);
		getline(in, country);
		getline(in, school);
		getline(in, cityofschool);
		getline(in, countryofschool);
		getline(in, groupNumber);
	}
};

int main()
{
	setlocale(LC_ALL, "ukrainian");

	const int MAX = 100;
	Student students[MAX];
	int count = 0;
	string filename = "students.txt";

	int choice;
	do {
		cout << "\n----------- Меню -----------\n";
		cout << "1. Додати студента\n";
		cout << "2. Показати всіх студентів\n";
		cout << "3. Зберегти у файл\n";
		cout << "4. Завантажити з файлу\n";
		cout << "0. Вийти\n";
		cout << "Ваш вибір: ";
		cin >> choice;

		switch (choice) {
		case 1:
			if (count < MAX) {
				students[count].InitStudent();
				count++;
			}
			else {
				cout << "Досягнуто максимальну кількість студентів!\n";
			}
			break;
		case 2:
			if (count == 0) {
				cout << "Список порожній.\n";
			}
			else {
				for (int i = 0; i < count; i++) {
					cout << "\nСтудент #" << i + 1 << ":";
					students[i].PrintInfo();
				}
			}
			break;
		case 3: {
			ofstream out(filename);
			if (!out) {
				cout << "Помилка відкриття файлу для запису.\n";
			}
			else {
				out << count << "\n";
				for (int i = 0; i < count; i++) {
					students[i].SaveToFile(out);
				}
				out.close();
				cout << "Дані збережено у файл.\n";
			}
			break;
		}
		case 4: {
			ifstream in(filename);
			if (!in) {
				cout << "Файл не знайдено.\n";
			}
			else {
				in >> count;
				in.ignore(); // Пропускаємо символ нового рядка після числа
				for (int i = 0; i < count; i++) {
					students[i].LoadFromFile(in);
				}
				in.close();
				cout << "Дані завантажено з файлу.\n";
			}
			break;
		}
		case 0:
			cout << "Завершення роботи...\n";
			break;
		default:
			cout << "Невірний вибір!\n";
		}

	} while (choice != 0);

	//Point p;

	//const char* filename = "points.txt";

	//
	//int choice;
	//do {
	//	cout << "\n----------- Menu -----------\n";
	//	cout << "1. Показати точку\n";
	//	cout << "2. Задати точку\n";
	//	cout << "3. Зберегти у файл\n";
	//	cout << "4. Завантажити з файлу\n";
	//	cout << "0. Вийти\n";
	//	cout << "Ваш вибір: ";
	//	cin >> choice;
	//	cin.ignore();

	//	switch (choice) {
	//	case 1:
	//		p.PrintInfo();
	//		break;
	//	case 2:
	//		p.InitPoint();
	//		break;
	//	case 3:
	//		p.SaveToFile(filename);
	//		break;
	//	case 4:
	//		p.LoadFromFile(filename);
	//		break;
	//	case 0:
	//		cout << "Завершення роботи..." << endl;
	//		break;
	//	default:
	//		cout << "Невірний вибір!" << endl;
	//	}

	//} while (choice != 0);

    return 0;
}