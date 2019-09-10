// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// diamond.cpp
// демонстрация неопределенности при множественном наследовании в форме ромба

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class A
{
public:
	void func()
		{ wcout << L"Класс A\n"; }
};

class B : public A
	{ };

class C : public A
	{ };

class D : public B, public C
	{ };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	D objD; // объявляем объект класса D
	
	// objD.func(); // ошибка: неопределенность — программа не скомпилируется

	// objD.A::func(); // ошибка
	objD.B::func(); // так можно
	objD.C::func(); // так можно

	return 0;
}