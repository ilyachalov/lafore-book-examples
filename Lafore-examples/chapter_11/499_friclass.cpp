// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// friclass.cpp
// дружественные классы

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class alpha
{
private:
	int data1;
public:
	alpha() : data1(99) { } // конструктор без аргументов
	friend class beta;      // дружественный класс
};

class beta
{                           // все методы этого класса имеют доступ
public:                     // к скрытым данным класса alpha
	void func1(alpha a) { wcout << L"data1 = " << a.data1 << endl; }
	void func2(alpha a) { wcout << L"data1 = " << a.data1 << endl; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	alpha a;
	beta b;

	b.func1(a);
	b.func2(a);

	return 0;
}