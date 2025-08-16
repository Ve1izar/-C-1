#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
    string name;
    string surname;
    int age;
    void Print() const {
        cout << "Ім'я: " << name << "\nПрізвище: " << surname << "\nВік: " << age << endl;
    }
};

class Aspirant : public Student {
    public:
    string thesisTopic;
    void Print() const {
        Student::Print();
        cout << "\nТема дисертації: " << thesisTopic << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ukrainian");

	Student student1;
	Aspirant aspirant1;

	student1.name = "Омелько";
    student1.surname = "Кайдаш";
    student1.age = 19;

	aspirant1.name = "Лаврін";
    aspirant1.surname = "Кайдаш";
    aspirant1.age = 21;
	aspirant1.thesisTopic = "Вивчення впливу кліматичних змін на сільське господарство";

	cout << "Студент:\n";
    student1.Print();
	cout << endl;
    cout << "Аспірант:\n";
    aspirant1.Print();
}

