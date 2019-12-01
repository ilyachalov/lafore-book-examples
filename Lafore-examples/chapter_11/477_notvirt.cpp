// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// notvirt.cpp
// доступ к обычным (не виртуальным) методам через указатели

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class Base                     // базовый класс
{
public:
	void show()                // обычный метод
	{ wcout << L"Базовый\n"; }
};

class Derv1 : public Base      // производный класс 1
{
public:
	void show()
	{ wcout << L"Произв1\n"; }
};

class Derv2 : public Base      // производный класс 2
{
public:
	void show()
	{ wcout << L"Произв2\n"; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Derv1 dv1;   // объект производного класса 1
	Derv2 dv2;   // объект производного класса 2
	Base* ptr;   // указатель на базовый класс

	ptr = &dv1;  // адрес dv1 сохранить в указатель
	ptr->show(); // выполнить show()

	ptr = &dv2;  // адрес dv2 сохранить в указатель
	ptr->show(); // выполнить show()

	return 0;
}