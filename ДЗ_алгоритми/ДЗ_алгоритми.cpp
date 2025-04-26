#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

double power(double base, int exponent) {
    if (exponent == 0)
        return 1;
    else if (exponent > 0)
        return base * power(base, exponent - 1);
    else 
        return 1 / power(base, -exponent);
}

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}


int main()
{
	setlocale(LC_ALL, "ukr");

    //1
    int arr1[] = { 5, 2, 9, 1, 7, 6, 8, 0, 3, 4 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    quickSort(arr1, 0, size1 - 1);

    cout << "Відсортований масив: ";
    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";

    return 0;

    //2
    double a;
    int b;
    cout << "Введіть число: ";
    cin >> a;
    cout << "Введіть степінь: ";
    cin >> b;
    cout << a << "^" << b << " = " << power(a, b) << endl;

	//3
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int num;
    cout << "Введіть число для пошуку: ";
    cin >> num;

    int index = binarySearch(arr, 0, size - 1, num);

    if (index != -1)
        cout << "Число знайдено на індексі: " << index << endl;
    else
        cout << "Число не знайдено у масиві.\n";

}