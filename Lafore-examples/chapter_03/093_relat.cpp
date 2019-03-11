// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// relat.cpp
// применение операций отношения

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int numb;
	wcout << L"Введите число: ";
	wcin >> numb;
	wcout << L"numb<10 равно  " << (numb < 10)  << endl;
	wcout << L"numb>10 равно  " << (numb > 10)  << endl;
	wcout << L"numb==10 равно " << (numb == 10) << endl;

	return 0;
}