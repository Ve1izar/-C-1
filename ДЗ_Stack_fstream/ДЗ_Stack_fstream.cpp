#include <iostream>
#include <fstream>
using namespace std;


class Stack
{
    enum { EMPTY = -1 };

    char* arr;
    int maxSize;
    int topIndex;

    void Resize()
    {
        int newSize = maxSize * 2;

        char* newArr = new char[newSize];

        for (int i = 0; i <= topIndex; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        maxSize = newSize;
    }

public:
    Stack(int size = 10) : maxSize(size), topIndex(EMPTY)
    {
        arr = new char[maxSize];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool IsFull() const
    {
        return topIndex == maxSize - 1;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }

    void Push(char value)
    {
        if (IsFull())
        {
            Resize();
        }
        arr[++topIndex] = value;
    }

    char Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
        return 0;
    }

    char Peek() const
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
        return 0;
    }

    int GetSize() const
    {
        return topIndex + 1;
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    void Print() const
    {
        if (IsEmpty())
        {
            cout << "Стек пустий." << endl;
            return;
        }
        cout << "Елементи: ";
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void SaveToFile(const string& filename) const
    {
        ofstream outFile(filename, ios::binary);
        if (!outFile)
        {
            cerr << "Не вдалося відкрити файл для запису." << endl;
            return;
        }
        outFile.write(reinterpret_cast<const char*>(&topIndex), sizeof(topIndex));
        outFile.write(arr, (topIndex + 1) * sizeof(char));
        outFile.close();
	}
    
    void LoadFromFile(const string& filename)
    {
        ifstream inFile(filename, ios::binary);
        if (!inFile)
        {
            cerr << "Не вдалося відкрити файл для читання." << endl;
            return;
        }
        inFile.read(reinterpret_cast<char*>(&topIndex), sizeof(topIndex));
        if (topIndex >= maxSize)
        {
            delete[] arr;
            maxSize = topIndex + 1;
            arr = new char[maxSize];
        }
        inFile.read(arr, (topIndex + 1) * sizeof(char));
        inFile.close();
	}
};

int main()
{
    setlocale(LC_ALL, "ukr");

    Stack st(4);
    int choice;
    char value;
    string filename = "stack_data.bin";

    do
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Додати елемент у стек\n";
        cout << "2. Видалити елемент зі стеку\n";
        cout << "3. Подивитися останній елемент\n";
        cout << "4. Вивести всі елементи\n";
        cout << "5. Показати розмір стеку\n";
        cout << "6. Очистити стек\n";
        cout << "7. Зберегти у файл\n";
        cout << "8. Завантажити з файлу\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введіть символ: ";
            cin >> value;
            st.Push(value);
            break;
        case 2:
            cout << "Видалено: " << st.Pop() << endl;
            break;
        case 3:
            cout << "Останній елемент: " << st.Peek() << endl;
            break;
        case 4:
            st.Print();
            break;
        case 5:
            cout << "Розмір стеку: " << st.GetSize() << endl;
            break;
        case 6:
            st.Clear();
            cout << "Стек очищено.\n";
            break;
        case 7:
            st.SaveToFile(filename);
            break;
        case 8:
            st.LoadFromFile(filename);
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір!" << endl;
        }
    } while (choice != 0);


}