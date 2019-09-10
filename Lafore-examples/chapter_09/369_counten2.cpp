// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// counten2.cpp
// конструкторы в производном классе

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Counter                 // класс, реализующий счетчик (базовый класс)
{
protected:                    // ЗАМЕТЬТЕ: не private!
	unsigned int count;       // значение счетчика
public:
	Counter() : count(0)      // конструктор без аргументов
		{ }
	Counter(int c) : count(c) // конструктор с одним аргументом
		{ }
	unsigned int get_count() const // получение значения счетчика
		{ return count; }
	Counter operator++ ()     // увеличить значение счетчика (префиксная форма)
		{ return Counter(++count); }
};

class CountDn : public Counter  // производный класс
{
public:
	CountDn() : Counter()       // конструктор без параметров
		{ }
	CountDn(int c) : Counter(c) // конструктор с одним параметром
		{ }
	CountDn operator-- ()       // уменьшить значение счетчика (префиксная форма)
		{ return CountDn(--count); }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	CountDn c1;                            // определение двух объектов
	CountDn c2(100);                       // класса CountDn

	wcout << L"c1 = " << c1.get_count();   // вывод их значений на экран
	wcout << L"\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;                      // трижды увеличим счетчик c1
	wcout << L"\nc1 = " << c1.get_count(); // выведем результат на экран
	
	--c2; --c2;                            // дважды уменьшим счетчик c2
	wcout << L"\nc2 = " << c2.get_count(); // выведем результат на экран

	CountDn c3 = --c2;                     // создаем переменную c3 на основе c2
	wcout << L"\nc3 = " << c3.get_count(); // выведем результат на экран

	wcout << endl;

	return 0;
}