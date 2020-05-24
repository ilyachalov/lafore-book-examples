// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// xstak.cpp
// демонстрация механизма исключений

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int MAX = 3;   // в стеке максимум 3 целых числа

class Stack
{
private:
	int st[MAX];            // стек: целочисленный массив
	int top;                // индекс вершины стека
public:
	class Range             // класс исключения для класса Stack
	{                       // внимание: тело класса пусто
	};
	
	Stack()                 // конструктор
		{ top = -1; }
	
	void push(int var)
	{
		if (top >= MAX - 1) // если стек уже полон,
			throw Range();  // сгенерировать исключение,
		st[++top] = var;    // иначе внести число в стек
	}
	
	int pop()
	{
		if (top < 0)        // если стек уже пуст,
			throw Range();  // сгенерировать исключение,
		return st[top--];   // иначе взять число из стека
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Stack s1;

	try
	{
		s1.push(11);
		s1.push(22);
		s1.push(33);
		// s1.push(44);                      // ошибка: стек уже полон
		wcout << L"1: " << s1.pop() << endl;
		wcout << L"2: " << s1.pop() << endl;
		wcout << L"3: " << s1.pop() << endl;
		wcout << L"4: " << s1.pop() << endl; // ошибка: стек уже пуст
	}
	catch (Stack::Range)                     // обработчик исключения
	{
		wcout << L"Исключение: стек уже полон или уже пуст" << endl;
	}

	wcout << L"Прибыли сюда после захвата исключения (или нормального выхода)" << endl;
	
	return 0;
}