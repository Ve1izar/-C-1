#include <iostream>
#include <string>
using namespace std;

template<typename T>
class PriorityQueue
{
private:
    struct Element
    {
        T value;
        int priority;
    };

    Element* arr;
    int size;

public:
    PriorityQueue() : arr(nullptr), size(0) {}

    ~PriorityQueue()
    {
        delete[] arr;
    }

    void Enqueue(T value, int priority)
    {
        int index = 0;
        while (index < size && arr[index].priority >= priority)
            index++;

        Element* temp = new Element[size + 1];

        for (int i = 0; i < index; i++)
            temp[i] = arr[i];

        temp[index] = { value, priority };

        for (int i = index; i < size; i++)
            temp[i + 1] = arr[i];

        delete[] arr;
        arr = temp;
        size++;
    }

    T Dequeue()
    {
        if (IsEmpty()) throw out_of_range("Черга порожня");

        T value = arr[0].value;
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
        return value;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    void Print() const
    {
        if (IsEmpty())
        {
            cout << "[Черга порожня]" << endl;
            return;
        }

        cout << "Черга друку:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "- " << arr[i].value.filename
                << " (" << arr[i].value.position
                << "), пріоритет: " << arr[i].priority << endl;
        }
    }
};
struct Document
{
    string filename;
    string position;

    void Print() const
    {
        cout << "Файл: " << filename << " | Посада: " << position << endl;
    }
};

int getPriorityByPosition(const string& position)
{
    if (position == "гість") return 1;
    if (position == "адміністратор") return 2;
    if (position == "менеджер") return 3;
    if (position == "директор") return 4;
    return 0;
}

int main()
{   
{
    setlocale(LC_ALL, "ukrainian");

    PriorityQueue<Document> printerQueue;
    int choice;

    while (true)
    {
        cout << "\n===== Меню принтера =====\n";
        cout << "1. Додати документ у чергу\n";
        cout << "2. Виконати друк\n";
        cout << "3. Переглянути чергу\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            Document doc;
            cout << "Введіть ім'я файлу: ";
            getline(cin, doc.filename);
            cout << "Введіть посаду (гість, адміністратор, менеджер, директор): ";
            getline(cin, doc.position);
            int pr = getPriorityByPosition(doc.position);

            if (pr == 0)
            {
                cout << "Невідома посада. Документ не додано.\n";
            }
            else
            {
                printerQueue.Enqueue(doc, pr);
                cout << "Документ успішно додано.\n";
            }
        }
        else if (choice == 2)
        {
            if (printerQueue.IsEmpty())
            {
                cout << "Черга порожня. Немає що друкувати.\n";
            }
            else
            {
                Document doc = printerQueue.Dequeue();
                cout << "=== Друкується документ ===\n";
                doc.Print();
            }
        }
        else if (choice == 3)
        {
            printerQueue.Print();
        }
        else if (choice == 0)
        {
            cout << "Завершення програми...\n";
            break;
        }
        else
        {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
