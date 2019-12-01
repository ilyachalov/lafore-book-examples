// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// xofxref.cpp
// копирующий конструктор: X(X&)

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class alpha
{
private:
	int data;
public:
	alpha()                   // конструктор без аргументов
		{ }
	alpha(int d)              // конструктор с одним аргументом
		{ data = d; }
	alpha(alpha& a)           // копирующий конструктор
	{
		data = a.data;
		wcout << L"Вызван копирующий конструктор\n";
	}
	void display()            // вывод данных объекта класса на экран
		{ wcout << data; }
	void operator= (alpha& a) // перегрузка операции присваивания
	{
		data = a.data;
		wcout << L"Вызвана операция присваивания\n";
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	alpha a1(37);
	alpha a2;

	a2 = a1;                         // вызывается перегруженная операция присваивания
	wcout << L"a2 = "; a2.display(); // выведем на экран значение переменной a2
	wcout << endl;

	alpha a3(a1);                    // вызывается копирующий конструктор
	// alpha a3 = a1;                // аналог предыдущей строки с альтернативным синтаксисом
	wcout << L"a3 = "; a3.display(); // выведем на экран значение переменной a3
	wcout << endl;

	return 0;
}