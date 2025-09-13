#include <iostream>
#include <stdexcept>
using namespace std;

class MyClass
{
public:
    MyClass() = default;
    MyClass(const MyClass& other) = delete;
    ~MyClass() = default;
};

class Stack
{
    enum { EMPTY = -1 };

    int* arr;
    int maxSize;
    int topIndex;
public:

    Stack() = delete;

    Stack(int size) : maxSize(size), arr(nullptr), topIndex(EMPTY)
    {
        if (size <= 0)
            throw invalid_argument("Розмір стеку має бути > 0");

        arr = new int[size];
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

    void Push(int value)
    {
        if (IsFull())
            throw overflow_error("Стек заповнений");

        arr[++topIndex] = value;
    }

    int Pop()
    {
        if (IsEmpty())
            throw underflow_error("Стек пустий");

        return arr[topIndex--];
    }

    int Peek() const
    {
        if (IsEmpty())
            throw underflow_error("Стек пустий");

        return arr[topIndex];
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    int GetSize() const
    {
        return topIndex + 1;
    }

    void Print() const
    {
        if (IsEmpty())
            throw underflow_error("Нічого вивести");

        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    
    Stack st(60);
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    cout << "Size : " << st.GetSize() << endl;
    st.Print();
    cout << "Last element  : " << st.Peek() << endl;

    while (!st.IsEmpty())
    {
        cout << "Delete element : " << st.Pop() << endl;
    }
    cout << "Size : " << st.GetSize() << endl;



}