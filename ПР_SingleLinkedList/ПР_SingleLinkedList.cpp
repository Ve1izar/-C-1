#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T value;
    Node* next;
    Node(T value, Node* next) :value(value), next(next) {}
};

template<typename T>
class List
{
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}

    ~List()
    {
        Clear();
    }

    void AddToHead(T value)
    {
        Node<T>* newNode = new Node<T>(value, head);
        head = newNode;
    }

    void AddToTail(T value)
    {
        Node<T>* newNode = new Node<T>(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T>* current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
    }

    T getElement(int pos)
    {
        Node<T>* current = head;
        int i = 0;
        while (current != nullptr)
        {
            if (i == pos) return current->value;
            current = current->next;
            i++;
        }
        throw out_of_range("Invalid position");
    }

    T operator[](int pos)
    {
        return getElement(pos);
    }

    void DeleteFromTail()
    {
        if (!head) return;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* current = head;
        while (current->next->next)
            current = current->next;

        delete current->next;
        current->next = nullptr;
    }

    void DeleteFromHead()
    {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void Clear()
    {
        Node<T>* current;
        while (head)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    //Для List
    /*void Print() const
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }*/
    // Для Vector
    void Print() const
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            current->value.Print();
            cout << " ";
            current = current->next;
        }
        cout << endl;
    }


};

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    void Print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class Vector {
private:
    int size;
    List<Point> points;

public:
    Vector() : size(0) {}

    void AddToHead(const Point& p) {
        points.AddToHead(p);
        size++;
    }

    void AddToTail(const Point& p) {
        points.AddToTail(p);
        size++;
    }

    void DeleteFromHead() {
        points.DeleteFromHead();
        if (size > 0) size--;
    }

    void DeleteFromTail() {
        points.DeleteFromTail();
        if (size > 0) size--;
    }

    void Print() const {
        cout << "Vector contains " << size << " point(s): ";
        points.Print();
    }

    int GetSize() const {
        return size;
    }
};



int main()
{
    setlocale(LC_ALL, "ukr");
 //   List<int> l;
 //   for (int i = 0; i < 10; i++)
 //   {
 //       l.AddToHead(i);
 //   }
 //   //l.Print();
 //   l.AddToTail(100);
 //   //l.AddToTail(200);
 //   //l.AddToTail(300);
 //   l.Print();
 //  /* cout << "Element pos 3 : " << l.getElement(3) << endl;
 //   cout << "Element pos 3 : " << l[3] << endl;*/

	//cout << "Видалення з кінця: " << endl;
 //   l.DeleteFromTail();
 //   l.Print();
 //   cout << "Видалення з початку: " << endl;
 //   l.DeleteFromHead();
 //   l.Print();

    Vector v;
    v.AddToTail(Point(1, 2));
    v.AddToHead(Point(3, 4));
    v.AddToTail(Point(5, 6));

    v.Print();

    v.DeleteFromHead();
    v.Print();

    v.DeleteFromTail();
    v.Print();

    return 0;
}