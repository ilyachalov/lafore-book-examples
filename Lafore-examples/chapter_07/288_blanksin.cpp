// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// blanksin.cpp
// ввод строки с пробелами

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

	const int MAX = 80; // максимальная длина строки
	wchar_t str[MAX];   // сама строка

	// ввод строки
	wcout << L"Введите строку: ";
	wcin.get(str, MAX);
	
	// показ результата
	wcout << L"Вы ввели: " << str << endl;

	return 0;
}