#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T value;
    Node* next;
    Node* previous;
    Node(T value, Node* next, Node* previous) :value(value), next(next), previous(previous) {}
};

template<typename T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List<T>& other) : head(nullptr), tail(nullptr)
    {
        Node<T>* current = other.head;
        while (current != nullptr)
        {
            AddToTail(current->value);
            current = current->next;
        }
    }

    ~List()
    {
        Clear();
    }

    void AddToHead(T value)
    {
        Node<T>* newNode = new Node<T>(value, head, nullptr);
        if (head)
            head->previous = newNode;
        else
            tail = newNode;
        head = newNode;
    }

    void AddToTail(T value)
    {
        Node<T>* newNode = new Node<T>(value, nullptr, tail);
        if (tail)
            tail->next = newNode;
        else
            head = newNode;
        tail = newNode;
    }

    void DeleteFromHead()
    {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        if (head)
            head->previous = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void DeleteFromTail()
    {
        if (!tail) return;
        Node<T>* temp = tail;
        tail = tail->previous;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
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

    void Clear()
    {
        Node<T>* current = head;
        while (current)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void Print() const
    {
        Node<T>* current = head;
        while (current)
        {
            current->value.Print();
            cout << " ";
            current = current->next;
        }
        cout << endl;
    }

    void PrintReverse() const
    {
        Node<T>* current = tail;
        while (current)
        {
            current->value.Print();
            cout << " ";
            current = current->previous;
        }
        cout << endl;
    }

    int Size() const
    {
        int count = 0;
        Node<T>* current = head;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

struct Vagon {
    string type;
	int number;
    int capacity;
    void Print() const
    {
        cout << "Тип вагону: " << type << ", Місткість: " << capacity << endl;
    }
};

class Train
{
private:
    string model;
    int countVagons;
    List<Vagon> vagons;

public:
    Train(string model, int countVagons) : model(model), countVagons(countVagons) {}
    void AddVagonHead(const Vagon& vagon)
    {
        vagons.AddToHead(vagon);
    }

    void AddVagonTail(const Vagon& vagon)
    {
        vagons.AddToTail(vagon);
    }

    void DelVagonHead(const Vagon& vagon)
    {
        vagons.DeleteFromHead();
    }

    void DelVagonTail(const Vagon& vagon)
    {
        vagons.DeleteFromTail();
    }
   
    void Show() const
    {
        cout << "Модель: " << model << ", К-кість вагонів: " << countVagons << endl;
        vagons.Print();
    }
    int GetCountVagons() const
    {
        return countVagons;
	}

};


int main()
{
    setlocale(LC_ALL, "ukrainian");

    Train train("Express", 5);
    train.AddVagonHead({ "Passenger1", 1, 100 });
    train.AddVagonTail({ "Freight", 2, 200 });
    train.AddVagonHead({ "Luxury1", 3, 50 });
    train.AddVagonHead({ "Passenger2", 1, 100 });
    train.AddVagonTail({ "Luxury2", 3, 50 });
	train.Show(); //Passenger2, Luxury1, Passenger1, Freight, Luxury2

	train.DelVagonHead({ "Passenger2", 1, 100 });
	train.Show(); //Luxury1, Passenger1, Freight, Luxury2

    cout << "Загальна кількість вагонів: " << train.GetCountVagons() << endl;

    Train copiedTrain = train;
    copiedTrain.Show();


	return 0;
}
