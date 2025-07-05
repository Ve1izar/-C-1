#include <iostream>
using namespace std;

template<typename T_type>
class Array
{
    T_type* arr;
    int size;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    Array(int size)
    {
        this->size = size;
        arr = new T_type[size]{};
    }

    Array(const initializer_list<T_type> list)
    {
        this->size = list.size();
        arr = new T_type[size];
        int i = 0;
        for (T_type elem : list)
        {
            arr[i++] = elem;
        }
    }

    void Fill(const initializer_list<T_type> list)
    {
        if (arr != nullptr)
            delete[] arr;
        this->size = list.size();
        arr = new T_type[size];
        int i = 0;
        for (T_type elem : list)
        {
            arr[i++] = elem;
        }
    }

    void Print()const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int GetSize() const { return size; }

    T_type Get(int index) const { return arr[index]; }

    void Set(int index, T_type value) { arr[index] = value; }

    ~Array()
    {
        if (arr != nullptr)
            delete[] arr;
    }
};


template<typename T_type>
T_type FindMin(const Array<T_type>& arr)
{
    T_type min = arr.Get(0);
    for (int i = 1; i < arr.GetSize(); i++)
    {
        if (arr.Get(i) < min)
            min = arr.Get(i);
    }
    return min;
}

template<typename T_type>
T_type FindMax(const Array<T_type>& arr)
{
    T_type max = arr.Get(0);
    for (int i = 1; i < arr.GetSize(); i++)
    {
        if (arr.Get(i) > max)
            max = arr.Get(i);
    }
    return max;
}

template<typename T_type>
void Sort(Array<T_type>& arr)
{
    int size = arr.GetSize();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr.Get(j) > arr.Get(j + 1))
            {
                T_type temp = arr.Get(j);
                arr.Set(j, arr.Get(j + 1));
                arr.Set(j + 1, temp);
            }
        }
    }
}

template<typename T_type>
int BinarySearch(const Array<T_type>& arr, T_type value)
{
    int left = 0;
    int right = arr.GetSize() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr.Get(mid) == value)
            return mid;
        else if (arr.Get(mid) < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

template<typename T_type>
void Replace(Array<T_type>& arr, int index, T_type value)
{
    if (index >= 0 && index < arr.GetSize())
    {
        arr.Set(index, value);
    }
    else
    {
        cout << "Індекс поза межами масиву" << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "ukr");
    int static_arr[5] = { 1,2,3,4,5 };
    int* dynam_arr = new int[5] {10, 11, 12, 13, 14};

    Array<int> arr(10);
    arr.Print();

    Array<int> newArr({ 14, 15, 16, 17, 18, 19, 20, 21, 25 });
    newArr.Print();

    newArr.Fill({ 1, 2, 3 });
    newArr.Print();

    cout << endl;

    Array<int> arr1 = { 5, 2, 8, 1, 3 };

    arr1.Print();

    cout << "min: " << FindMin(arr1) << endl;
    cout << "max: " << FindMax(arr1) << endl;

    Sort(arr1);
    cout << "Відсортований масив: ";
    arr1.Print();

    int index = BinarySearch(arr1, 3);
    cout << "Індекс елемента зі значенням 3: " << index << endl;

    Replace(arr1, 1, 99);
    cout << "Заміна другого елемента на 99: ";
    arr1.Print();

    delete[] dynam_arr;
    return 0;
}
