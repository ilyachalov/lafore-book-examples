// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// friend.cpp
// дружественные функции

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class beta; // Объявление класса beta.
            // (Его нужно сделать потому, что данный класс используется
            // в заголовке функции frifunc, используемом в классе alpha,
            // который определяется перед определением класса beta.)

class alpha
{
private:
	int data;
public:
	alpha() : data(3) { }            // конструктор без аргументов
	friend int frifunc(alpha, beta); // дружественная функция (объявление)
};

class beta
{
private:
	int data;
public:
	beta() : data(7) { }             // конструктор без аргументов
	friend int frifunc(alpha, beta); // дружественная функция (объявление)
};

int frifunc(alpha a, beta b)         // дружественная функция (определение)
{
	return(a.data + b.data);
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	alpha aa;
	beta bb;

	wcout << frifunc(aa, bb) << endl; // вызов дружественной функции

	return 0;
}