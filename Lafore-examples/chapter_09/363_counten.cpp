// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// counten.cpp
// наследование от класса Counter

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
	unsigned int get_count()  // получение значения счетчика
		{ return count; }
	Counter operator++ ()     // увеличить значение счетчика (префиксная форма)
		{ return Counter(++count); }
};

class CountDn : public Counter // производный класс
{
public:
	Counter operator-- ()     // уменьшить значение счетчика (префиксная форма)
		{ return Counter(--count); }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	CountDn c1;                            // определение объекта c1 класса CountDn
	wcout << L"c1 = " << c1.get_count();   // вывод значения счетчика c1 на экран

	++c1; ++c1; ++c1;                      // трижды увеличим счетчик c1
	wcout << L"\nc1 = " << c1.get_count(); // выведем результат на экран
	
	--c1; --c1;                            // дважды уменьшим счетчик c1
	wcout << L"\nc1 = " << c1.get_count(); // выведем результат на экран

	wcout << endl;

	return 0;
}