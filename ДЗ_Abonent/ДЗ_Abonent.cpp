// Завдання 1 :(практична робота на уроці)
// Створіть додаток «Телефонна книга». Необхідно збері-
// гати дані про абонента (ПІБ, домашній телефон, робочий
// телефон, мобільний телефон, додаткова інформація про
// контакт) всередині відповідного класу(Abonent). Наповніть клас
// змінними-членами, функціями-членами, конструкторами.
// Створити статичну змінну для
// кількості абонентів. Використати делегування конструкторів.
#include <iostream>
#include <string>
using namespace std;

class Abonent {
private:
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string extraInfo;

    static int abonentCount;

public:
    Abonent() : Abonent("Невідомо", "-", "-", "-", "-") {}

    Abonent(const string& fullName, const string& mobilePhone)
        : Abonent(fullName, "-", "-", mobilePhone, "-") {
    }

    Abonent(const string& fullName, const string& homePhone, const string& workPhone, const string& mobilePhone, const string& extraInfo): 
        fullName(fullName),
        homePhone(homePhone),
        workPhone(workPhone),
        mobilePhone(mobilePhone),
        extraInfo(extraInfo)
    {abonentCount++;}

    void printInfo() const {
        cout << endl << "ПІБ: " << fullName << endl;
        cout << "Домашній телефон: " << homePhone << endl;
        cout << "Робочий телефон: " << workPhone << endl;
        cout << "Мобільний телефон: " << mobilePhone << endl;
        cout << "Додаткова інформація: " << extraInfo << endl;
    }

    static int getAbonentCount() {
        return abonentCount;
    }
};

int Abonent::abonentCount = 0;


int main()
{
	setlocale(LC_ALL, "ukr");
    Abonent a1;
    Abonent a2("Іван Петренко", "093125476");
    Abonent a3("Олена Коваль", "123456789", "0969999991", "0671111444", "Повна інформація");

    a1.printInfo();
    a2.printInfo();
    a3.printInfo();

    cout << "Всього абонентів: " << Abonent::getAbonentCount() << endl;
    return 0;
}