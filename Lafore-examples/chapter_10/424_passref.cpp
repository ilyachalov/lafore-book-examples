// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// passref.cpp
// передача аргумента в функцию по ссылке

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	void centimize(double&); // прототип функции

	double var = 10.0;       // значение переменной var равно 10 (дюймов)
	wcout << L"var = " << var << L" дюймов" << endl;
	
	centimize(var);          // переведем дюймы в сантиметры
	wcout << L"var = " << var << L" сантиметра" << endl;

	return 0;
}

// функция для перевода дюймов в сантиметры
void centimize(double& v)
{
	v *= 2.54;               // v — это то же самое, что и var
}