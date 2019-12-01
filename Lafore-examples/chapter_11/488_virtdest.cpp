// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// virtdest.cpp
// тест невиртуальных и виртуальных деструкторов

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class Base                     // базовый класс
{
public:
	~Base()                    // невиртуальный деструктор
	// virtual ~Base()         // виртуальный деструктор
		{ wcout << L"Часть объекта (базовый класс) удалена\n"; }
};

class Derv : public Base       // производный класс
{
public:
	~Derv()
		{ wcout << L"Часть объекта (производный класс) удалена\n"; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Base* pBase = new Derv;
	delete pBase;

	return 0;
}