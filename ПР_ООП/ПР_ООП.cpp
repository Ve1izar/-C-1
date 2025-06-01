#include <iostream>
#include <fstream>
#include <string>	
using namespace std;

//Створити клас Rectangle, який буде описувати прямокутник.Клас містить розміри : ширина, висота, символ, який відображатиме прямокутник на екрані та координати розміщення.Для збереження координат створити структуру Coord, яка міститиме Х та У координату.
//Клас повинен містити наступні конструктори :
//Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
//Параметризований конструктор, який приймає один параметр «розмір» та ініціалізує ним ширину та висоту
//Параметризований конструктор, який приймає два параметри «ширину» та «висоту», які являються розмірами об'єкта
//Та наступні методи :
//Вивід фігури на екран, відповідного розміру, символом та у відповідних координатах
//Зміна розміру прямокутника.Метод приймає два парметри : 1 зміна висоти, 2 ширини
//Переміщення прямокутника.Метод приймає два парметри : 1 величина переміщення по осі Х, 2 по осі Ү
//Методи повинні включати перевірку на коректність даних(від'ємна ширина, координати і тд). Створити екземпляр об'єкту та протестувати написаті методи.


class Rectangle {
private:
	int width;
	int height;
	char symbol;
	struct Coord {
		int x;
		int y;
	} position;
public:
	
	Rectangle() : width(5), height(3), symbol('-'), position{ 0, 0 } {}
	
	Rectangle(int size) : width(size), height(size), symbol('*'), position{ 0, 1 } {
		if (size <= 0) {
			cout << "Розмір повинен бути додатнім. Використано дефолтний розмір.\n";
			width = height = 5;
		}
	}
	
	Rectangle(int w, int h) : width(w), height(h), symbol('+'), position{ 2, 1 } {
		if (w <= 0 || h <= 0) {
			cout << "Ширина та висота повинні бути додатніми. Використано дефолтні розміри.\n";
			width = height = 5;
		}
	}
	void Draw() const {
		for (int i = 0; i < position.y; i++) cout << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < position.x; j++) cout << ' ';
			for (int j = 0; j < width; j++) cout << symbol;
			cout << endl;
		}
	}
	void Resize(int newWidth, int newHeight) {
		if (newWidth > 0 && newHeight > 0) {
			width = newWidth;
			height = newHeight;
		}
		else {
			cout << "Ширина та висота повинні бути додатніми.\n";
		}
	}
	void Move(int dx, int dy) {
		position.x += dx;
		position.y += dy;
		if (position.x < 0) position.x = 0;
		if (position.y < 0) position.y = 0;
	}

};


int main()
{
	setlocale(LC_ALL, "ukrainian");

	Rectangle rect1;
	rect1.Draw();

	Rectangle rect2(4);
	rect2.Draw();

	Rectangle rect3(6, 3);
	rect3.Draw();
	rect3.Resize(8, 5);
	rect3.Move(2, 1);
	rect3.Draw();
	return 0;
    
}

