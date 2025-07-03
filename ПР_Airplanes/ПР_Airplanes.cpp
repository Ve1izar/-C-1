#include <iostream>
#include <string>
using namespace std;

class Airplane {
private:
    string model;
    string type;
    int passengers;
    int maxpassengers;

public:

    Airplane() : model(""), type(""), passengers(0), maxpassengers(0) {}

    Airplane(string m, string t, int p, int maxP)
        : model(m), type(t), passengers(p), maxpassengers(maxP) {
    }

    void Print() const {
        cout << "\nМодель : " << model << "\nТип : " << type << "\nКількість пасажирів : " << passengers << "\nПасажиромісткість : " << maxpassengers << endl;
    }

    Airplane& operator ++() {
        if (passengers < maxpassengers) passengers++;
        else    cout << "У салоні вже максимальна кількість пасажирів.\n";
        return *this;
    }

    Airplane& operator --() {
        if (passengers > 0) passengers--;
        else cout << "У салоні немає пасажирів.\n";
        return *this;
    }

    void operator()(int add) {
        if (passengers + add <= maxpassengers) {
            passengers += add;
        }
        else {
            cout << "Неможливо додати " << add << " пасажирів. Перевищено ліміт.\n";
        }
    }

    friend bool operator ==(const Airplane& first, const Airplane& second);
    friend bool operator >(const Airplane& first, const Airplane& second);

    operator string() const {
        return model;
    }

    friend ostream& operator<<(ostream& out, const Airplane& a) {
        out << "Модель: " << a.model << "\nТип: " << a.type
            << "\nПасажири: " << a.passengers
            << "\nМакс. пасажири: " << a.maxpassengers << "\n";
        return out;
    }

    friend istream& operator>>(istream& in, Airplane& a) {
        cout << "Введіть модель: ";
        getline(in >> ws, a.model);
        cout << "Введіть тип: ";
        getline(in, a.type);
        cout << "Введіть кількість пасажирів: ";
        in >> a.passengers;
        cout << "Введіть макс. кількість пасажирів: ";
        in >> a.maxpassengers;
        return in;
    }
};

bool operator ==(const Airplane& first, const Airplane& second) {
    return first.type == second.type;
}

bool operator >(const Airplane& first, const Airplane& second) {
    return first.maxpassengers > second.maxpassengers;
}


int main()
{
    setlocale(LC_ALL, "ukr");

    Airplane a1("Boeing 737", "Пасажирський", 80, 120);
    Airplane a2("Airbus A320", "Пасажирський", 100, 150);
    Airplane a3("C-130 Hercules", "Військовий", 20, 92);

    cout << "Літаки:\n";
    a1.Print();
    a2.Print();
    a3.Print();

    cout << "\nПеревірка рівності типів:\n";
    if (a1 == a2) cout << "Літаки одного типу.\n";
    else cout << "Літаки різного типу.\n";

    if (a1 == a3) cout << "Літаки одного типу.\n";
    else cout << "Літаки різного типу.\n";

    cout << "\nЗбільшення кількості пасажирів у a1 (++)\n";
    ++a1;
    a1.Print();

    cout << "\nЗменшення пасажирів (--)\n";
    --a1;
    a1.Print();

    cout << "\nСпроба додати 50 пасажирів через оператор (): \n";
    a1(50);
    a1.Print();

    cout << "Порівняння a2 > a3:\n";
    if (a2 > a3) cout << "Airbus A320 вміщає більше пасажирів, ніж C-130.\n";
    else cout << "C-130 вміщає більше або стільки ж пасажирів, як Airbus A320.\n";


    cout << "\nТест перетворення до string:\n";
    string modelStr = string(a1);
    cout << "Модель літака: " << modelStr << endl;

    cout << "\nТест ostream << :\n";
    cout << a1;

    cout << "\nТест istream >> :\n";
    cin >> a2;
    cout << "\nВведений літак:\n";
    cout << a2;

    return 0;
}
