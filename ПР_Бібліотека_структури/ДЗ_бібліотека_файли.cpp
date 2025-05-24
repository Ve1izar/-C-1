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

// ����� ���� �����
void Show(Book b) {
	cout << "ID: " << b.id << endl;
	cout << "Name : " << b.name << endl;
	cout << "Genre : " << b.genre << endl;
	cout << "Author : " << b.author << endl;
	cout << "Publisher : " << b.publisher << endl;
	cout << "Price : " << b.price << endl;
	cout << "_______________________________\n";
}

// ����� ��� ����
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
	cout << "����������� ����� � ID: " << b.id << endl;
	cout << "���� �����: ";
	cin.getline(b.name, 50);
	cout << "����� �����: ";
	cin.getline(b.author, 100);
	cout << "����� ����: ";
	cin.getline(b.genre, 50);
	cout << "���� �����������: ";
	cin.getline(b.publisher, 100);
	cout << "���� ����: ";
	cin >> b.price;
	cin.ignore();
	cout << "����� ��������!" << endl;
}

void AddBook(Book books[], int& size) {
	if (size >= MAX_BOOKS) {
		cout << "��������� ������ ����� ����." << endl;
		return;
	}
	Book b;
	b.id = size + 1;
	cout << "�����: ";
	cin.getline(b.name, 50);
	cout << "�����: ";
	cin.getline(b.author, 100);
	cout << "����: ";
	cin.getline(b.genre, 50);
	cout << "�����������: ";
	cin.getline(b.publisher, 100);
	cout << "ֳ��: ";
	cin >> b.price;
	cin.ignore();
	books[size] = b;
	size++;
	cout << "����� ������!" << endl;
}

void SaveToFile(Book books[], int size, const char* filename) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cout << "������� ���������� � ����.\n";
		return;
	}
	out.write((char*)&size, sizeof(int));
	out.write((char*)books, sizeof(Book) * size);
	out.close();
	cout << "��� ��������� �� �����.\n";
}

void LoadFromFile(Book books[], int& size, const char* filename) {
	ifstream in(filename, ios::binary);
	if (!in) {
		cout << "���� �� ��������.\n";
		return;
	}
	in.read((char*)&size, sizeof(int));
	in.read((char*)books, sizeof(Book) * size);
	in.close();
	cout << "��� ����������� � �����.\n";
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
		cout << "1. �������� �� ������\n";
		cout << "2. ����� �� ������\n";
		cout << "3. ����� �� �������\n";
		cout << "4. ����� �� ������\n";
		cout << "5. ����� �� ������������\n";
		cout << "6. ���������� �����\n";
		cout << "7. ������ ���� �����\n";
		cout << "8. �������� � ����\n";
		cout << "9. ����������� � �����\n";
		cout << "0. �����\n";
		cout << "��� ����: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			ShowAllBooks(books, size);
			break;
		case 2:
			cout << "�����: ";
			cin.getline(input, 50);
			SearchByName(books, size, input);
			break;
		case 3:
			cout << "�����: ";
			cin.getline(input, 100);
			SearchByAuthor(books, size, input);
			break;
		case 4:
			cout << "����: ";
			cin.getline(input, 50);
			SearchByGenre(books, size, input);
			break;
		case 5:
			cout << "�����������: ";
			cin.getline(input, 100);
			SearchByPublisher(books, size, input);
			break;
		case 6:
		{
			int id;
			cout << "ID ��� �����������: ";
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
				cout << "����� � ����� ID �� ��������." << endl;
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
			cout << "���������� ������..." << endl;
			break;
		default:
			cout << "������� ����!" << endl;
		}

	} while (choice != 0);

	return 0;
}
