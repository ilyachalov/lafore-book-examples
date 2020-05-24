// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// tempstak2.cpp
// реализация класса, представляющего стек, в виде шаблона
// (методы определяются снаружи спецификации класса)

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int MAX = 100; // размер массива

template <class Type>
class Stack
{
private:
	Type st[MAX];    // стек: массив любого типа
	int top;         // индекс вершины стека
public:
	Stack();             // конструктор
	void push(Type var); // занести число в стек
	Type pop();          // вынуть число из стека
};

template<class Type>
Stack<Type>::Stack()             // конструктор
{
	top = -1;
}

template<class Type>
void Stack<Type>::push(Type var) // занести число в стек
{
	st[++top] = var;
}

template<class Type>
Type Stack<Type>::pop()          // вынуть число из стека
{
	return st[top--];
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Stack<float> s1;                   // s1 — объект класса Stack<float>

	s1.push(1111.1F);                  // занести 3 числа типа float в стек
	s1.push(2222.2F);
	s1.push(3333.3F);
	wcout << L"1: " << s1.pop() << endl; // вынуть 3 числа типа float из стека
	wcout << L"2: " << s1.pop() << endl;
	wcout << L"3: " << s1.pop() << endl;
	
	Stack<long> s2;                    // s2 — объект класса Stack<long>
	
	s2.push(123123123L);               // занести 3 числа типа long в стек
	s2.push(234234234L);
	s2.push(345345345L);
	wcout << L"1: " << s2.pop() << endl; // вынуть 3 числа типа long из стека
	wcout << L"2: " << s2.pop() << endl;
	wcout << L"3: " << s2.pop() << endl;
	
	return 0;
}