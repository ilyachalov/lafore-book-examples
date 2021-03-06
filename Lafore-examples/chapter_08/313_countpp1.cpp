﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// countpp1.cpp
// увеличение переменной операцией ++ (префиксный инкремент)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Counter                 // класс, реализующий счетчик
{
private:
	unsigned int count;       // значение счетчика
public:
	Counter() : count(0)      // конструктор
		{ }
	unsigned int get_count()  // получение значения счетчика
		{ return count; }
	void operator++ ()        // увеличить значение
		{ ++count; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	// определение двух объектов класса Counter (счетчик)
	// с инициализацией (благодаря конструктору)
	Counter c1, c2;
	
	wcout << L"c1 = " << c1.get_count();   // вывод значений двух счетчиков на экран
	wcout << L"\nc2 = " << c2.get_count();

	++c1; // увеличиваем на 1 счетчик c1
	++c2; // увеличиваем на 1 счетчик c2
	++c2; // увеличиваем на 1 счетчик c2
	
	wcout << L"\nc1 = " << c1.get_count(); // вывод значений двух счетчиков на экран
	wcout << L"\nc2 = " << c2.get_count();
	wcout << endl;

	return 0;
}