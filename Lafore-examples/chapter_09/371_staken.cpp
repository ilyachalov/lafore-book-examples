// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// staken.cpp
// перегрузка функций базового и производного классов

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;
// #include <process.h> // для функции exit не понадобился

class Stack                   // класс, реализующий стек (базовый класс)
{
protected:                    // ЗАМЕТЬТЕ: не может быть private для базового класса
	// enum { MAX = 3 };      // немного нестандартный синтаксис
	static const int MAX = 3; // количество элементов в массиве
	                          // (одна константа для всех объектов, статическая)
	int st[MAX];              // стек в виде массива
	int top;                  // вершина стека
public:
	Stack()                   // конструктор
		{ top = -1; }
	void push(int var)        // поместить в стек
		{ st[++top] = var; }
	int pop()                 // взять из стека
		{ return st[top--]; }
};

class Stack2 : public Stack   // класс, реализующий стек (производный класс)
{
public:
	void push(int var)        // поместить в стек
	{
		if (top >= MAX - 1)   // если стек полон, то ошибка
			{ wcout << L"\nОшибка: стек полон!\n"; exit(1); }
		Stack::push(var);     // вызов метода push класса Stack
	}
	int pop()                 // взять из стека
	{
		if (top < 0)          // если стек пуст, то ошибка
			{ wcout << L"\nОшибка: стек пуст!\n"; exit(1); }
		return Stack::pop();  // вызов метода pop класса Stack
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Stack2 s1;

	s1.push(11); // поместим в стек несколько чисел
	s1.push(22);
	s1.push(33);
	// s1.push(44); // будет получена ошибка переполнения стека

	wcout << s1.pop() << endl; // заберем числа из стека
	wcout << s1.pop() << endl;
	wcout << s1.pop() << endl;
	// wcout << s1.pop() << endl; // будет получена ошибка, так как стек уже пуст

	return 0;
}