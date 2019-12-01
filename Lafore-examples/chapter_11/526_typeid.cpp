// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// typeid.cpp
// пример использования функции typeid
// (возможность RTTI в компиляторе должна быть включена)

// В среде «Visual Studio Community 2017» возможность RTTI включается и выключается
// с помощью ключа компилятора /GR. По умолчанию эта возможность включена.

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
//#include <typeinfo> // для функции typeid не понадобился
using namespace std;

class Base
{
	virtual void virtFunc() // нужна для возможности использования typeid
		{ }
};

class Derv1 : public Base
	{ };

class Derv2 : public Base
	{ };

void displayName(Base* pB)
{
	wcout << L"Указатель на объект класса \"";   // вывести на экран имя класса,
	wcout << typeid(*pB).name() << L'"' << endl; // на объект которого указывает pB
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	Base* pBase = new Derv1;
	displayName(pBase); // «Указатель на объект класса "class Derv1"»

	pBase = new Derv2;
	displayName(pBase); // «Указатель на объект класса "class Derv2"»

	return 0;
}