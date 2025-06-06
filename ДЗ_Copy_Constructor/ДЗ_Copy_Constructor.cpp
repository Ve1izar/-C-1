#include <iostream>
#include <ctime>     // time()
using namespace std;



class Array {
private:
    long* arr;
    int size;

public:
    Array() : arr(nullptr), size(0) {} 

    Array(int n) {
        if (n > 0) {
            size = n;
            arr = new long[size];
            for (int i = 0; i < size; ++i)
                arr[i] = 0;
        }
        else {
            arr = nullptr;
            size = 0;
        }
    }

    Array(const Array& other) {
        size = other.size;
        arr = new long[size];
        for (int i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }

    void FillRandom(int min = 0, int max = 100) {
        if (size == 0) return;
        srand(time(0));
        for (int i = 0; i < size; ++i)
            arr[i] = rand() % (max - min + 1) + min;
    }

    void FillManual() {
        if (size == 0) return;
        cout << "Введіть " << size << " елементів: ";
        for (int i = 0; i < size; ++i)
            cin >> arr[i];
    }

    void FillDefault(long value = 0) {
        if (size == 0) return;
        for (int i = 0; i < size; ++i)
            arr[i] = value;
    }

    void Print() const {
        if (size == 0) {
            cout << "Масив порожній\n";
            return;
        }
        cout << "Масив: ";
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    int GetSize() const {
        return size;
    }

    void Add(long value) {
        long* newArr = new long[size + 1];
        for (int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        newArr[size] = value;
        delete[] arr;
        arr = newArr;
        ++size;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size || size == 0) {
            cout << "Невірний індекс!\n";
            return;
        }
        long* newArr = new long[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index)
                newArr[j++] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        --size;
    }

    void RemoveValue(long value) {
        int index = -1;
        for (int i = 0; i < size; ++i)
            if (arr[i] == value) {
                index = i;
                break;
            }
        if (index != -1)
            RemoveAt(index);
        else
            cout << "Значення не знайдено!\n";
    }

    void SortAscending() {
        for (int i = 0; i < size - 1; ++i)
            for (int j = 0; j < size - i - 1; ++j)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }


    void SortDescending() {
        for (int i = 0; i < size - 1; ++i)
            for (int j = 0; j < size - i - 1; ++j)
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }


    long Min() const {
        if (size == 0) throw runtime_error("Масив порожній!");
        long minVal = arr[0];
        for (int i = 1; i < size; ++i)
            if (arr[i] < minVal) minVal = arr[i];
        return minVal;
    }

    long Max() const {
        if (size == 0) throw runtime_error("Масив порожній!");
        long maxVal = arr[0];
        for (int i = 1; i < size; ++i)
            if (arr[i] > maxVal) maxVal = arr[i];
        return maxVal;
    }

    double Average() const {
        if (size == 0) throw runtime_error("Масив порожній!");
        long sum = 0;
        for (int i = 0; i < size; ++i)
            sum += arr[i];
        return (double)sum / size;
    }

    ~Array() {
        delete[] arr;
    }
};


int main() {
    setlocale(LC_ALL, "ukrainian");

    Array a1(5);
    a1.FillRandom(10, 50);
    a1.Print();

    a1.Add(25);
    cout << "Після додавання 25:\n";
    a1.Print();

    a1.RemoveAt(2);
    cout << "Після видалення елемента з індексом 2:\n";
    a1.Print();

    a1.RemoveValue(25);
    cout << "Після видалення 25:\n";
    a1.Print();

    a1.SortDescending();
    cout << "Відсортовано за спаданням:\n";
    a1.Print();

    cout << "Мінімум: " << a1.Min() << endl;
    cout << "Максимум: " << a1.Max() << endl;
    cout << "Середнє: " << a1.Average() << endl;

    return 0;
}
