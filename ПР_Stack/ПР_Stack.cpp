#include <iostream>
using namespace std;


//class MyClass
//{
//public:
//    MyClass() = default;
//    MyClass(const MyClass& other) = delete;
//    ~MyClass() = default;
//};
//
//class Stack
//{
//    enum { EMPTY = -1 };
//
//    char* arr;
//    int maxSize;
//    int topIndex;
//public:
//
//    Stack() = delete;
//    Stack(int size) :maxSize(size)
//    {
//        arr = new char[size];
//        topIndex = EMPTY;
//    }
//    ~Stack()
//    {
//        if (arr != nullptr)
//            delete[]arr;
//    }
//
//    bool IsFull()
//    {
//        return topIndex == maxSize - 1;
//    }
//    bool Push(char value)
//    {
//        if (!IsFull())
//        {
//
//            arr[++topIndex] = value;
//            return true;
//        }
//        return false;
//    }
//    bool IsEmpty()
//    {
//        return topIndex == EMPTY;
//    }
//    char Pop()
//    {
//        if (!IsEmpty())
//        {
//            return arr[topIndex--];
//        }
//        return '\0';
//    }
//    void Clear()
//    {
//        topIndex = EMPTY;
//    }
//    char Peek()
//    {
//        if (!IsEmpty())
//        {
//
//            return arr[topIndex];
//        }
//        return 0;
//    }
//    int GetSize()
//    {
//        return topIndex + 1;
//    }
//    void Print()
//    {
//        for (int i = 0; i <= topIndex; i++)
//        {
//            cout << arr[i] << " ";
//        }cout << endl;
//    }
//};
//
//int main()
//{
//    Stack st(60);
//    st.Push('b');
//    st.Push('c');
//    st.Push('A');
//    st.Push('g');
//    st.Push('F');
//    st.Push('H');
//    cout << "Size : " << st.GetSize() << endl;
//    st.Print();
//    cout << "Останній елемент: " << st.Peek() << endl;
//
//    while (!st.IsEmpty())
//    {
//        cout << "Видалено елемент: " << st.Pop() << endl;
//    }
//    cout << "Size : " << st.GetSize() << endl;
//
//}

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
};

int main()
{
    Stack st(4);
    st.Push('b');
    st.Push('c');
    st.Push('A');
    st.Push('g');
    st.Push('F');
    st.Push('H');
    cout << "Size : " << st.GetSize() << endl;
    st.Print();
    cout << "Last element  : " << st.Peek() << endl;

    while (!st.IsEmpty())
    {
        cout << "Delete element : " << st.Pop() << endl;
    }
    cout << "Size : " << st.GetSize() << endl;

}