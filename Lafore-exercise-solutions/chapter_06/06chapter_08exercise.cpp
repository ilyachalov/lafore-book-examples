// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_08exercise.cpp
// создать класс, умеющий подсчитывать количество своих объектов и нумеровать их

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class objCounter // класс, умеющий подсчитывать количество своих объектов и нумеровать их
{
private:
	int number;       // номер объекта
	static int count; // счетчик объектов класса (статическое поле класса)
public:
	// конструктор без аргументов
	objCounter()
		{ count++; number = count; }
	// константный метод выводит номер объекта на экран
	void displayNumber() const
		{ wcout << L"Мой порядковый номер: " << number << endl; }
};

// инициализация статического поля класса
int objCounter::count = 0;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	objCounter obj1, obj2, obj3; // создание трех объектов класса objCounter

	// вывод порядковых номеров объектов на экран
	obj1.displayNumber();
	obj2.displayNumber();
	obj3.displayNumber();

	return 0;
}