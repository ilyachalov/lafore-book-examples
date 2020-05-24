// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// xstak2.cpp
// демонстрация двух обработчиков исключений

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int MAX = 3;   // в стеке максимум 3 целых числа

class Stack
{
private:
	int st[MAX];            // стек: массив целых чисел
	int top;                // индекс вершины стека
public:
	class Full { };         // класс исключения
	class Empty { };        // класс исключения
	
	Stack()                 // конструктор
		{ top = -1; }
	
	void push(int var)      // метод: внести число в стек
	{
		if (top >= MAX - 1) // если стек уже полон,
			throw Full();   // сгенерировать исключение Full,
		st[++top] = var;    // иначе внести число в стек
	}
	
	int pop()               // метод: взять число из стека
	{
		if (top < 0)        // если стек уже пуст,
			throw Empty();  // сгенерировать исключение Empty,
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
	catch (Stack::Full)                      // обработчик исключения Full
	{
		wcout << L"Исключение: стек уже полон" << endl;
	}
	catch (Stack::Empty)                     // обработчик исключения Empty
	{
		wcout << L"Исключение: стек уже пуст" << endl;
	}
	
	return 0;
}