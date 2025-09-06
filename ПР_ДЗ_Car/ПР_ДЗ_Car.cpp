#include <iostream>
#include <string>
using namespace std;

class Wheel {
private:
	double radius;
	string type;
public:
	Wheel(double r = 15.0, string t = "Alloy") : radius(r), type(t) {}
	void Show() const {
		cout << "Колесо: Радіус = " << radius << ", Тип = " << type << endl;
	}
	~Wheel() = default;
};

class Engine {
private:
	double power;
	string type;
public:
	Engine(double p = 100.0, string t = "Petrol") : power(p), type(t) {}
	void Show() const {
		cout << "Двигун: Потужність = " << power << " к.с., Тип = " << type << endl;
	}
	~Engine() = default;
};

class Door {
private:
	string position;
public:
	Door(string pos = "передні") : position(pos) {}
	void Show() const {
		cout << "Це " << position << "двері" << endl;
	}
	~Door() = default;
};

class Body {
private:
	string color;
	string type;
public:
	Body(string c = "Червоний", string t = "Седан") : color(c), type(t) {}
	void Show() const {
		cout << "Колір корпуса: " << color << ", Тип: " << type << endl;
	}
	~Body() = default;
};

class Headlight {
private:
	string type;
public:
	Headlight(string t = "LED") : type(t) {}
	void Show() const {
		cout << "Тип фар: " << type << endl;
	}
	~Headlight() = default;
};

class Driver {
private:
	string name;
	string surname;
	int age;
	int experience;
public:
	Driver(string n = "Іван", string s = "Іванов", int a = 30, int e = 5) : name(n), surname(s), age(a), experience(e) {}
	void Show() const {
		cout << "Водій: " << name << " " << surname << ", Вік: " << age << ", Досвід: " << experience << " років" << endl;
	}
	~Driver() = default;
};

class Car {
private:
	Wheel wheels[4];
	Engine engine;
	Door doors[4];
	Body body;
	Headlight headlights[2];
	Driver* driver;

public:
	Car(Wheel w = Wheel(), Engine e = Engine(), Door d = Door(), Body b = Body(), Headlight h = Headlight(), Driver* dr = nullptr) 
		: engine(e), body(b), driver(dr) {
		for (int i = 0; i < 4; i++) {
			wheels[i] = w;
			doors[i] = d;
		}
		for (int i = 0; i < 2; i++) {
			headlights[i] = h;
		}
	}

	void Show() const {
		cout << "Автомобіль:" << endl;
		for (const auto& wheel : wheels) {
			wheel.Show();
		}
		engine.Show();
		for (const auto& door : doors) {
			door.Show();
		}
		body.Show();
		for (const auto& headlight : headlights) {
			headlight.Show();
		}
		if (driver) {
			driver->Show();
		} else {
			cout << "Водій не призначений" << endl;
		}
	}

	~Car() {
		delete driver;
	}
};

int main()
{
	setlocale(LC_ALL, "ukr");

	Car myCar(
		Wheel(16.0, "Steel"),
		Engine(150.0, "Diesel"),
		Door("передні"),
		Body("Синій", "Позашляховик"),
		Headlight("Xenon"),
		new Driver("Петро", "Петров", 40, 15)
	);
	myCar.Show();

	return 0;
}
