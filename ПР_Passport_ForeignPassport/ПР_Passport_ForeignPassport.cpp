#include <iostream>
#include <string>
using namespace std;

class Passport {
	string name;
	string surname;
	int age;
	string patronymic;
	string passportNumber;
	string citizenship;
public:
	Passport(string n, string s, int a, string p, string num, string c)
		: name(n), surname(s), age(a), patronymic(p), passportNumber(num), citizenship(c) {
	}
	void Print() const {
		cout << "Ім'я: " << name << "\nПрізвище: " << surname << "\nВік: " << age << "\nПо батькові: " << patronymic << "\nНомер паспорта: " << passportNumber << "\nГромадянство: " << citizenship << endl;
	}
};

class ForeignPassport : public Passport {
	string visa;
	string foreignpassportNumber;
public:
	ForeignPassport(string n, string s, int a, string p, string num, string c, string v, string fpn)
		: Passport(n, s, a, p, num, c), visa(v), foreignpassportNumber(fpn){
	}
	void Print() const {
		Passport::Print();
		cout << "Віза: " << visa << "\nНомер закордонного паспорта: " << foreignpassportNumber << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ukrainian");

	Passport passport("Влад", "Мельник", 30, "Микитович", "AB1234567", "Україна");
	ForeignPassport foreignPassport("Петро", "Петров", 28, "Петрович", "XY9876543", "Україна", "Шенген", "AB1234567");

	cout << "Паспорт:\n";
	passport.Print();
	cout << endl;
	cout << "Закордонний паспорт:\n";
	foreignPassport.Print();
}