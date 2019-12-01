// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// dyncast1.cpp
// использование динамического приведения типов для идентификации класса объекта
// (возможность RTTI в компиляторе должна быть включена)

// В среде «Visual Studio Community 2017» возможность RTTI включается и выключается
// с помощью ключа компилятора /GR. По умолчанию эта возможность включена.

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
//#include <typeinfo> // для операции dynamic_cast не понадобился
using namespace std;

class Base
{
	virtual void vertFunc() // нужна для динамического приведения типов
		{ }
};

class Derv1 : public Base
	{ };

class Derv2 : public Base
	{ };

// проверка, указывает ли указатель pUnknown на объект класса Derv1
// (параметр pUnknown указывает на объект неизвестного класса,
// производный от класса Base)
bool isDerv1(Base* pUnknown)
{
	Derv1* pDerv1;
	if (pDerv1 = dynamic_cast<Derv1*>(pUnknown))
		return true;
	else
		return false;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	Derv1* d1 = new Derv1;
	Derv2* d2 = new Derv2;

	if (isDerv1(d1))
		wcout << L"d1 — объект класса Derv1\n";
	else
		wcout << L"d1 — не объект класса Derv1\n";

	if (isDerv1(d2))
		wcout << L"d2 — объект класса Derv1\n";
	else
		wcout << L"d2 — не объект класса Derv1\n";

	return 0;
}