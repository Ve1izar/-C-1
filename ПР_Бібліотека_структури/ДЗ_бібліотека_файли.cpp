#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Book {
	int id;
	char name[50];
	char author[100];
	char genre[50];
	char publisher[100];
	float price;
};

const int MAX_BOOKS = 100;

// Показ однієї книги
void Show(Book b) {
	cout << "ID: " << b.id << endl;
	cout << "Name : " << b.name << endl;
	cout << "Genre : " << b.genre << endl;
	cout << "Author : " << b.author << endl;
	cout << "Publisher : " << b.publisher << endl;
	cout << "Price : " << b.price << endl;
	cout << "_______________________________\n";
}

// Показ усіх книг
void ShowAllBooks(Book books[], int size) {
	for (int i = 0; i < size; i++) {
		Show(books[i]);
	}
}

void SearchByName(Book books[], int size, char name[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(books[i].name, name) == 0) {
			Show(books[i]);
		}
	}
}

void SearchByAuthor(Book books[], int size, char author[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(books[i].author, author) == 0) {
			Show(books[i]);
		}
	}
}

void SearchByGenre(Book books[], int size, char genre[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(books[i].genre, genre) == 0) {
			Show(books[i]);
		}
	}
}

void SearchByPublisher(Book books[], int size, char publisher[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(books[i].publisher, publisher) == 0) {
			Show(books[i]);
		}
	}
}

void ChangeData(Book& b) {
	cout << "Редагування книги з ID: " << b.id << endl;
	cout << "Нова назва: ";
	cin.getline(b.name, 50);
	cout << "Новий автор: ";
	cin.getline(b.author, 100);
	cout << "Новий жанр: ";
	cin.getline(b.genre, 50);
	cout << "Нове видавництво: ";
	cin.getline(b.publisher, 100);
	cout << "Нова ціна: ";
	cin >> b.price;
	cin.ignore();
	cout << "Книгу оновлено!" << endl;
}

void AddBook(Book books[], int& size) {
	if (size >= MAX_BOOKS) {
		cout << "Неможливо додати більше книг." << endl;
		return;
	}
	Book b;
	b.id = size + 1;
	cout << "Назва: ";
	cin.getline(b.name, 50);
	cout << "Автор: ";
	cin.getline(b.author, 100);
	cout << "Жанр: ";
	cin.getline(b.genre, 50);
	cout << "Видавництво: ";
	cin.getline(b.publisher, 100);
	cout << "Ціна: ";
	cin >> b.price;
	cin.ignore();
	books[size] = b;
	size++;
	cout << "Книгу додано!" << endl;
}

void SaveToFile(Book books[], int size, const char* filename) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cout << "Помилка збереження у файл.\n";
		return;
	}
	out.write((char*)&size, sizeof(int));
	out.write((char*)books, sizeof(Book) * size);
	out.close();
	cout << "Дані збережено до файлу.\n";
}

void LoadFromFile(Book books[], int& size, const char* filename) {
	ifstream in(filename, ios::binary);
	if (!in) {
		cout << "Файл не знайдено.\n";
		return;
	}
	in.read((char*)&size, sizeof(int));
	in.read((char*)books, sizeof(Book) * size);
	in.close();
	cout << "Дані завантажено з файлу.\n";
}

int main() {
	setlocale(LC_ALL, "ukr");
	Book books[MAX_BOOKS];
	int size = 0;

	const char* filename = "books.txt";

	int choice;
	char input[100];

	do {
		cout << "\n----------- Menu -----------\n";
		cout << "1. Показати всі книжки\n";
		cout << "2. Пошук за назвою\n";
		cout << "3. Пошук за автором\n";
		cout << "4. Пошук за жанром\n";
		cout << "5. Пошук за видавництвом\n";
		cout << "6. Редагувати запис\n";
		cout << "7. Додати нову книгу\n";
		cout << "8. Зберегти у файл\n";
		cout << "9. Завантажити з файлу\n";
		cout << "0. Вийти\n";
		cout << "Ваш вибір: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			ShowAllBooks(books, size);
			break;
		case 2:
			cout << "Назва: ";
			cin.getline(input, 50);
			SearchByName(books, size, input);
			break;
		case 3:
			cout << "Автор: ";
			cin.getline(input, 100);
			SearchByAuthor(books, size, input);
			break;
		case 4:
			cout << "Жанр: ";
			cin.getline(input, 50);
			SearchByGenre(books, size, input);
			break;
		case 5:
			cout << "Видавництво: ";
			cin.getline(input, 100);
			SearchByPublisher(books, size, input);
			break;
		case 6:
		{
			int id;
			cout << "ID для редагування: ";
			cin >> id;
			cin.ignore();
			bool found = false;
			for (int i = 0; i < size; i++) {
				if (books[i].id == id) {
					ChangeData(books[i]);
					found = true;
					break;
				}
			}
			if (!found)
				cout << "Книгу з таким ID не знайдено." << endl;
			break;
		}
		case 7:
			AddBook(books, size);
			break;
		case 8:
			SaveToFile(books, size, filename);
			break;
		case 9:
			LoadFromFile(books, size, filename);
			break;
		case 0:
			cout << "Завершення роботи..." << endl;
			break;
		default:
			cout << "Невірний вибір!" << endl;
		}

	} while (choice != 0);

	return 0;
}
