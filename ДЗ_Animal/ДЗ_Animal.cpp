#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    int weight;
    string species;
    string habitat;
    int speed;
    int lifespan;

public:
    Animal() : name(""), age(0), weight(0), species(""), habitat(""), speed(0), lifespan(0) {}
    Animal(string n, int a, int w, string s, string h, int sp, int l)
        : name(n), age(a), weight(w), species(s), habitat(h), speed(sp), lifespan(l) {
    }

    virtual void Show() const {
        cout << "Назва: " << name
            << "\nВік: " << age
            << "\nВага: " << weight
            << "\nВид: " << species
            << "\nСередовище проживання: " << habitat
            << "\nШвидкість: " << speed
            << " км/год"
            << "\nТривалість життя: " << lifespan << " років" << endl;
    }

    virtual void Move() const {
        cout << name << " рухається зі швидкістю " << speed << " км/год." << endl;
    }

    virtual void Say() const {
        cout << name << " видає звук." << endl;
    }

    virtual ~Animal() = default;
};

class Bird : public Animal {
protected:
    double wingspan;
public:
    Bird(string n, int a, int w, string s, string h, int sp, int l, double ws)
        : Animal(n, a, w, s, h, sp, l), wingspan(ws) {
    }

    void Show() const override {
        Animal::Show();
        cout << "Розмах крил: " << wingspan << " м" << endl;
    }

    void Move() const override {
        cout << name << " летить зі швидкістю " << speed << " км/год." << endl;
    }
};

class Reptile : public Animal {
protected:
    bool isVenomous;
public:
    Reptile(string n, int a, int w, string s, string h, int sp, int l, bool venom)
        : Animal(n, a, w, s, h, sp, l), isVenomous(venom) {
    }

    void Show() const override {
        Animal::Show();
        cout << "Отруйний: " << (isVenomous ? "Так" : "Ні") << endl;
    }
};

class Fish : public Animal {
protected:
    bool isSaltwater;
public:
    Fish(string n, int a, int w, string s, string h, int sp, int l, bool salt)
        : Animal(n, a, w, s, h, sp, l), isSaltwater(salt) {
    }

    void Show() const override {
        Animal::Show();
        cout << "Тип води: " << (isSaltwater ? "Солона" : "Прісна") << endl;
    }

    void Move() const override {
        cout << name << " пливе зі швидкістю " << speed << " км/год." << endl;
    }
};

class Eagle : public Bird {
public:
    Eagle(string n, int a, int w)
        : Bird(n, a, w, "Орел", "Гори", 160, 20, 2.3) {
    }

    void Say() const override {
        cout << name << " видає порнизливий звук" << endl;
    }
};

class Crocodile : public Reptile {
public:
    Crocodile(string n, int a, int w)
        : Reptile(n, a, w, "Плазун", "Річка", 25, 70, false) {
    }

    void Say() const override {
        cout << name << " шипить" << endl;
    }
};

class Shark : public Fish {
public:
    Shark(string n, int a, int w)
        : Fish(n, a, w, "Акула", "Океан", 50, 30, true) {
    }

    void Say() const override {
        cout << name << " мовчить" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    Eagle eagle("Беркут", 5, 6);
    Crocodile croc("Нілський крокодил", 12, 500);
    Shark shark("Біла акула", 8, 1200);

    cout << "=== Інформація про тварин ===\n\n";

    eagle.Show();
    eagle.Move();
    eagle.Say();

    cout << "\n";
    croc.Show();
    croc.Move();
    croc.Say();

    cout << "\n";
    shark.Show();
    shark.Move();
    shark.Say();

    return 0;
}
