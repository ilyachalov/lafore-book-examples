// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// linesin.cpp
// ввод нескольких строк

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int MAX = 2000; // максимальная длина строки
wchar_t str[MAX];     // сама строка

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	// ввод строки
	wcout << L"Введите строку:\n";
	wcin.get(str, MAX, L'$');
	
	// показ результата
	wcout << L"Вы ввели:\n" << str << endl;

	return 0;
}