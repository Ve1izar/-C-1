#include <iostream>
#include <cstring>
using namespace std;

struct WashingMachine {
    char brand[50];
    char color[50];
    float width;
    float length;
    float height;
    float power;
    float spin_speed;
    float heating_temperature;
};

struct Iron {
    char brand[50];
    char model[50];
    char color[50];
    float min_temperature;
    float max_temperature;
    bool steam_supply;
    float power;
};

struct Boiler {
    char brand[50];
    char color[50];
    float power;
    float capacity;
    float heating_temperature;
};

void ShowWM(WashingMachine w)
{
    cout << "\n--- Пральна машинка ---\n";
    cout << "Фірма: " << w.brand << endl;
    cout << "Колір: " << w.color << endl;
    cout << "Ширина: " << w.width << " см\n";
    cout << "Довжина: " << w.length << " см\n";
    cout << "Висота: " << w.height << " см\n";
    cout << "Потужність: " << w.power << " Вт\n";
    cout << "Швидкість віджиму: " << w.spin_speed << " об/хв\n";
    cout << "Температура нагріву: " << w.heating_temperature << " °C\n";
}

void ShowIron(Iron i)
{
    cout << "\n--- Праска ---\n";
    cout << "Фірма: " << i.brand << endl;
    cout << "Модель: " << i.model << endl;
    cout << "Колір: " << i.color << endl;
    cout << "Мін. температура: " << i.min_temperature << " °C\n";
    cout << "Макс. температура: " << i.max_temperature << " °C\n";
    cout << "Подача пари: " << (i.steam_supply ? "Так" : "Ні") << endl;
    cout << "Потужність: " << i.power << " Вт\n";
}

void ShowBoiler(Boiler b)
{
    cout << "\n--- Бойлер ---\n";
    cout << "Фірма: " << b.brand << endl;
    cout << "Колір: " << b.color << endl;
    cout << "Потужність: " << b.power << " Вт\n";
    cout << "Обсяг: " << b.capacity << " л\n";
    cout << "Температура нагріву: " << b.heating_temperature << " °C\n";
}

int main()
{
    WashingMachine wm;
    strcpy(wm.brand, "Samsung");
    strcpy(wm.color, "Білий");
    wm.width = 60;
    wm.length = 55;
    wm.height = 85;
    wm.power = 2000;
    wm.spin_speed = 1200;
    wm.heating_temperature = 90;

    Iron iron;
    strcpy(iron.brand, "Philips");
    strcpy(iron.model, "GC2990");
    strcpy(iron.color, "Синій");
    iron.min_temperature = 100;
    iron.max_temperature = 220;
    iron.steam_supply = true;
    iron.power = 2400;

    Boiler boiler;
    strcpy(boiler.brand, "Ariston");
    strcpy(boiler.color, "Сірий");
    boiler.power = 1500;
    boiler.capacity = 80;
    boiler.heating_temperature = 75;

    ShowWM(wm);
    ShowIron(iron);
    ShowBoiler(boiler);

    return 0;
}
