#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Time
{
    short h, m, s;

    friend ostream& operator<<(ostream& os, const Time& t)
    {
        os << (t.h < 10 ? "0" : "") << t.h << ":"
            << (t.m < 10 ? "0" : "") << t.m << ":"
            << (t.s < 10 ? "0" : "") << t.s;
        return os;
    }

    friend istream& operator>>(istream& is, Time& t)
    {
        char ch;
        is >> t.h >> ch >> t.m >> ch >> t.s;
        return is;
    }

    bool operator<(const Time& other) const
    {
        if (h != other.h) return h < other.h;
        if (m != other.m) return m < other.m;
        return s < other.s;
    }
};

class Train
{
private:
    int number;
    Time departureTime;
    string destination;

public:
    Train(int num = 0, Time t = { 0,0,0 }, string dest = "")
        : number(num), departureTime(t), destination(dest) {
    }

    int getNumber() const { return number; }
    Time getTime() const { return departureTime; }
    string getDestination() const { return destination; }

    void setTime(const Time& t) { departureTime = t; }

    friend ostream& operator<<(ostream& os, const Train& tr)
    {
        os << tr.number << " "
            << tr.departureTime.h << " " << tr.departureTime.m << " " << tr.departureTime.s << " "
            << tr.destination;
        return os;
    }

    friend istream& operator>>(istream& is, Train& tr)
    {
        is >> tr.number >> tr.departureTime.h >> tr.departureTime.m >> tr.departureTime.s;
        is.ignore();
        getline(is, tr.destination);
        return is;
    }

    void Print() const
    {
        cout << "Потяг №" << number
            << " | Час відправлення: " << departureTime
            << " | Станція призначення: " << destination << endl;
    }
};

class Railway
{
    vector<Train> trains;

public:
    void AddTrain()
    {
        int num;
        Time t;
        string dest;

        cout << "Введіть номер потяга: ";
        cin >> num;
        cout << "Введіть час (год:хв:сек): ";
        cin >> t;
        cin.ignore();
        cout << "Введіть станцію призначення: ";
        getline(cin, dest);

        trains.push_back(Train(num, t, dest));
    }

    void ShowAll() const
    {
        if (trains.empty())
        {
            cout << "Список порожній.\n";
            return;
        }
        for (const auto& tr : trains)
            tr.Print();
    }

    void ShowByNumber(int num) const
    {
        for (const auto& tr : trains)
        {
            if (tr.getNumber() == num)
            {
                tr.Print();
                return;
            }
        }
        cout << "Потяг із номером " << num << " не знайдено.\n";
    }

    void EditTime(int num)
    {
        for (auto& tr : trains)
        {
            if (tr.getNumber() == num)
            {
                Time t;
                cout << "Введіть новий час (год:хв:сек): ";
                cin >> t;
                tr.setTime(t);
                cout << "Час оновлено.\n";
                return;
            }
        }
        cout << "Потяг із номером " << num << " не знайдено.\n";
    }

    void SortByTime()
    {
        for (size_t i = 0; i < trains.size(); i++)
        {
            for (size_t j = 0; j + 1 < trains.size() - i; j++)
            {
                if (trains[j + 1].getTime() < trains[j].getTime())
                {
                    Train tmp = trains[j];
                    trains[j] = trains[j + 1];
                    trains[j + 1] = tmp;
                }
            }
        }
        cout << "Список відсортовано за часом відправлення.\n";
    }

    void ShowByDestination(const string& dest) const
    {
        bool found = false;
        for (const auto& tr : trains)
        {
            if (tr.getDestination() == dest)
            {
                tr.Print();
                found = true;
            }
        }
        if (!found)
            cout << "Немає потягів до станції " << dest << ".\n";
    }

    void SaveToFile(const string& filename) const
    {
        ofstream out(filename);
        if (!out)
        {
            cerr << "Помилка відкриття файлу для запису.\n";
            return;
        }
        for (const auto& tr : trains)
            out << tr << endl;
        cout << "Дані збережено у файл.\n";
    }

    void LoadFromFile(const string& filename)
    {
        ifstream in(filename);
        if (!in)
        {
            cerr << "Помилка відкриття файлу для читання.\n";
            return;
        }
        trains.clear();
        Train tr;
        while (in >> tr)
            trains.push_back(tr);
        cout << "Дані завантажено з файлу.\n";
    }
};

int main()
{
    setlocale(LC_ALL, "ukr");

    Railway rw;
    int choice;

    do
    {
        cout << "1. Додати потяг\n";
        cout << "2. Вивести всі потяги\n";
        cout << "3. Вивести інформацію по потягу (за номером)\n";
        cout << "4. Редагувати час відправлення (за номером)\n";
        cout << "5. Відсортувати список за часом\n";
        cout << "6. Показати потяги за станцією призначення\n";
        cout << "7. Записати у файл\n";
        cout << "8. Зчитати з файлу\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rw.AddTrain();
            break;
        case 2:
            rw.ShowAll();
            break;
        case 3:
        {
            int num;
            cout << "Введіть номер потяга: ";
            cin >> num;
            rw.ShowByNumber(num);
            break;
        }
        case 4:
        {
            int num;
            cout << "Введіть номер потяга: ";
            cin >> num;
            rw.EditTime(num);
            break;
        }
        case 5:
            rw.SortByTime();
            break;
        case 6:
        {
            string dest;
            cin.ignore();
            cout << "Введіть станцію призначення: ";
            getline(cin, dest);
            rw.ShowByDestination(dest);
            break;
        }
        case 7:
            rw.SaveToFile("trains.txt");
            break;
        case 8:
            rw.LoadFromFile("trains.txt");
            break;
        case 0:
            cout << "Вихід\n";
            break;
        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
