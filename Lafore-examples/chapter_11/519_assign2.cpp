// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// assign2.cpp
// возвращение копии объекта, на который указывает указатель this

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class alpha
{
private:
	int data;
public:
	alpha()                     // конструктор без аргументов
		{ }
	alpha(int d)                // конструктор с одним аргументом
		{ data = d; }
	void display()              // вывод данных объекта класса на экран
		{ wcout << data << endl; }
	alpha& operator= (alpha& a) // перегрузка операции присваивания
	{
		data = a.data;          // то, что раньше делалось автоматически
		wcout << L"Вызвана операция присваивания\n";
		return *this;           // возвратим копию текущего объекта
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	alpha a1(37);
	alpha a2, a3;

	a3 = a2 = a1;                    // вызывается перегруженная операция присваивания, дважды
	wcout << L"a2 = "; a2.display(); // выведем на экран значение переменной a2
	wcout << L"a3 = "; a3.display(); // выведем на экран значение переменной a3

	return 0;
}