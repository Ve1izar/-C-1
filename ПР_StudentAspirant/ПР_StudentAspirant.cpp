#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    string surname;
    int age;
public:
    Student() : name(""), surname(""), age(0) {}
    Student(string n, string s, int a) : name(n), surname(s), age(a) {}

    void Print() const {
        cout << "Ім'я: " << name << "\nПрізвище: " << surname << "\nВік: " << age << endl;
    }

    ~Student() = default;
};

class Aspirant : public Student {
    string thesisTopic;
public:
    Aspirant() : Student(), thesisTopic("") {}
    Aspirant(string n, string s, int a, string topic)
        : Student(n, s, a), thesisTopic(topic) {
    }

    void Print(){
        Student::Print();
        cout << "Тема дисертації: " << thesisTopic << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ukrainian");

    Student student1("Омелько", "Кайдаш", 19);
    Aspirant aspirant1("Лаврін", "Кайдаш", 21, "Вивчення впливу кліматичних змін на сільське господарство");

    cout << "Студент:\n";
    student1.Print();

    cout << "\nАспірант:\n";
    aspirant1.Print();

    return 0;
}
