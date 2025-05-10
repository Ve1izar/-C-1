#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int** CreateMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}

void FillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100;
}

void ShowMatrix(int** matrix, int rows, int cols) {
    cout << "\nВигляд матриці:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

void DeleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int** AddRowToStart(int** matrix, int& rows, int cols) {
    int** newMatrix = new int* [rows + 1];
    newMatrix[0] = new int[cols];
    for (int j = 0; j < cols; j++)
        newMatrix[0][j] = rand() % 100;
    for (int i = 0; i < rows; i++)
        newMatrix[i + 1] = matrix[i];
    delete[] matrix;
    rows++;
    return newMatrix;
}

int** DeleteRowFromStart(int** matrix, int& rows) {
    if (rows <= 0) return nullptr;
    int** newMatrix = new int* [rows - 1];
    for (int i = 1; i < rows; i++)
        newMatrix[i - 1] = matrix[i];
    delete[] matrix[0];
    delete[] matrix;
    rows--;
    return newMatrix;
}

int** DeleteRowByPosition(int** matrix, int& rows, int pos) {
    if (pos < 0 || pos >= rows) return matrix;
    int** newMatrix = new int* [rows - 1];
    for (int i = 0, k = 0; i < rows; i++) {
        if (i == pos) {
            delete[] matrix[i];
            continue;
        }
        newMatrix[k++] = matrix[i];
    }
    delete[] matrix;
    rows--;
    return newMatrix;
}

int** AddColByPosition(int** matrix, int rows, int& cols, int pos) {
    if (pos < 0 || pos > cols) return matrix;
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols + 1];
        for (int j = 0; j < pos; j++)
            newRow[j] = matrix[i][j];
        newRow[pos] = rand() % 100;
        for (int j = pos; j < cols; j++)
            newRow[j + 1] = matrix[i][j];
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    cols++;
    return matrix;
}

int** AddColToStart(int** matrix, int rows, int& cols) {
    return AddColByPosition(matrix, rows, cols, 0);
}

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(0));


    int rows = 4, cols = 5;
    int** matrix = CreateMatrix(rows, cols);
    FillMatrix(matrix, rows, cols);

    int choice;
    do {
        ShowMatrix(matrix, rows, cols);
        cout << "Menu:\n";
        cout << "1. Додати рядок на початок\n";
        cout << "2. Видалити рядок з початку\n";
        cout << "3. Видалити рядок з місця\n";
        cout << "4. Додати рядок на місце\n";
        cout << "5. Додати стовбець на початок\n";
        cout << "0. Вийтиt\n";
        cout << "Вибір: ";
        cin >> choice;

        int pos;
        switch (choice) {
        case 1:
            matrix = AddRowToStart(matrix, rows, cols);
            break;
        case 2:
            matrix = DeleteRowFromStart(matrix, rows);
            break;
        case 3:
            cout << "Введіть який рядок видалити: ";
            cin >> pos;
            matrix = DeleteRowByPosition(matrix, rows, pos);
            break;
        case 4:
            cout << "Введіть де додати стовбець: ";
            cin >> pos;
            matrix = AddColByPosition(matrix, rows, cols, pos);
            break;
        case 5:
            matrix = AddColToStart(matrix, rows, cols);
            break;
        case 0:
            break;
        default:
            cout << "Хибний вибір\n";
        }
    } while (choice != 0);

    DeleteMatrix(matrix, rows);
    return 0;
}
