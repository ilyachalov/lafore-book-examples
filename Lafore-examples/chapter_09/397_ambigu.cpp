// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ambigu.cpp
// демонстрация неопределенности при множественном наследовании

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class A
{
public:
	void show()
		{ wcout << L"Класс A\n"; }
};

class B
{
public:
	void show()
		{ wcout << L"Класс B\n"; }
};

class C : public A, public B
	{ };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	C objC;         // объявляем объект класса C

	// objC.show(); // ошибка: неопределенность — программа не скомпилируется
	objC.A::show(); // так можно
	objC.B::show(); // так можно

	return 0;
}