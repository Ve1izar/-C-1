#include <iostream>
#include <cstring>
using namespace std;

// Завдання 1. Розробіть програму «Бібліотека». Створіть
// структуру «Книга» (назва, автор, видавництво, жанр,
// рік видання, price).
// Створіть масив з 10 книг. Реалізуйте для нього такі 
// можливості:

// ■ Редагувати книгу;(ChangeData)
// ■ Друк усіх книг;(Show);
// ■ Пошук книг за автором;
// ■ Пошук книги за назвою;
// ■ Пошук книги за видавництвом
// ■ Пошук книги за жанром

struct Book {
	int id;
	char name[50];
	char author[100];
	char genre[50];
	char publisher[100];
	float price;

};

void Show(Book b)
{
	cout << "Name : " << b.name << endl;
	cout << "Genre : " << b.genre << endl;
	cout << "Author : " << b.author << endl;
	cout << "Publisher : " << b.publisher << endl;
	cout << "Price : " << b.price << endl;
	cout << endl << "_______________________________" << endl;
}

void ShowAllBooks(Book books[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Show(books[i]);
	}
}

void SearchByName(Book books[], int size, char name[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].name, name) == 0)
		{
			Show(books[i]);
		}
	}
}

void SearchByAuthor(Book books[], int size, char author[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].author, author) == 0)
		{
			Show(books[i]);
		}
	}
}

void SearchByGenre(Book books[], int size, char genre[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].genre, genre) == 0)
		{
			Show(books[i]);
		}
	}
}

void SearchByPublisher(Book books[], int size, char publisher[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].publisher, publisher) == 0)
		{
			Show(books[i]);
		}
	}
}

void ChangeData(Book& b)
{
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

	cout << "Книгу успішно оновлено!" << endl;
}


int main()
{
	setlocale(LC_ALL, "ukr");

	const int size = 20;
	Book books[size]{
		{1, "1984", "George Orwell", "Dystopian", "Penguin Books", 199.99},
		{2, "Animal Farm", "George Orwell", "Satire", "Penguin Books", 149.50},
		{3, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", "Bloomsbury", 299.99},
		{4, "Harry Potter and the Chamber of Secrets", "J.K. Rowling", "Fantasy", "Bloomsbury", 279.50},
		{5, "The Hobbit", "J.R.R. Tolkien", "Fantasy", "HarperCollins", 189.99},
		{6, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", "HarperCollins", 349.90},
		{7, "To Kill a Mockingbird", "Harper Lee", "Fiction", "J.B. Lippincott & Co.", 199.00},
		{8, "The Great Gatsby", "F. Scott Fitzgerald", "Classic", "Scribner", 149.95},
		{9, "Moby-Dick", "Herman Melville", "Adventure", "Harper & Brothers", 179.75},
		{10, "Pride and Prejudice", "Jane Austen", "Romance", "Penguin Books", 159.25},
		{11, "Sense and Sensibility", "Jane Austen", "Romance", "Penguin Books", 169.35},
		{12, "Brave New World", "Aldous Huxley", "Dystopian", "Chatto & Windus", 189.60},
		{13, "Fahrenheit 451", "Ray Bradbury", "Science Fiction", "Ballantine Books", 199.80},
		{14, "Dune", "Frank Herbert", "Science Fiction", "Chilton Books", 299.99},
		{15, "A Game of Thrones", "George R.R. Martin", "Fantasy", "Bantam Books", 259.45},
		{16, "A Clash of Kings", "George R.R. Martin", "Fantasy", "Bantam Books", 269.55},
		{17, "The Catcher in the Rye", "J.D. Salinger", "Fiction", "Little, Brown and Company", 139.99},
		{18, "The Picture of Dorian Gray", "Oscar Wilde", "Philosophical", "Ward, Lock & Co.", 149.75},
		{19, "Dracula", "Bram Stoker", "Horror", "Archibald Constable and Company", 189.95},
		{20, "Frankenstein", "Mary Shelley", "Horror", "Lackington, Hughes, Harding, Mavor & Jones", 199.10}
	};

	char name[50];
	int choice;

	do
	{

		cout << "----------- Menu -----------" << endl;
		cout << "Показати всі книжки      [1] " << endl;
		cout << "Пошук за назвою          [2] " << endl;
		cout << "Пошук за автором         [3] " << endl;
		cout << "Пошук за жанром          [4] " << endl;
		cout << "Пошук за видавництвом    [5] " << endl;
		cout << "Редагувати запис         [6] " << endl;
		cout << "Вийти                    [0] " << endl;
		cin >> choice;
		cin.ignore();
		system("cls");

		switch (choice)
		{
		case 1:
			ShowAllBooks(books, size);
			break;
		case 2:
			cout << "Введіть назву книжки : ";
			cin.getline(name, 50);
			SearchByName(books, size, name);
			break;
		case 3:
			cout << "Введіть автора : ";
			cin.getline(name, 50);
			SearchByAuthor(books, size, name);
			break;
		case 4:
			cout << "Введіть жанр : ";
			cin.getline(name, 50);
			SearchByGenre(books, size, name);
			break;
		case 5:
			cout << "Введіть видавництво : ";
			cin.getline(name, 50);
			SearchByPublisher(books, size, name);
			break;
		case 6:
		{
			int id;
			cout << "Введіть ID книги для редагування: ";
			cin >> id;
			cin.ignore();  // щоб очистити буфер після cin

			bool found = false;
			for (int i = 0; i < size; i++)
			{
				if (books[i].id == id)
				{
					ChangeData(books[i]);
					found = true;
					break;
				}
			}

			if (!found)
			{
				cout << "Книгу з таким ID не знайдено." << endl;
			}
			break;
		}
		case 0:
			cout << "Завершення роботи..." << endl;
			exit(0);

		default:
			break;
		}



	} while (choice != 0);

	return 0;
}