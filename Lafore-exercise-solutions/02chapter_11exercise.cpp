// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_11exercise.cpp
// вывести на экран заданную таблицу с выравниванием колонок по левому краю
// с помощью манипуляторов setiosflags(ios::left) и setw

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипуляторов setiosflags и setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout << setiosflags(ios::left)
		<< setw(16) << L"Фамилия" << setw(16) << L"Имя" << setw(16) << L"Адрес" << setw(16) << L"Город" << endl
		<< "-----------------------------------------------------------------" << endl
		<< setw(16) << L"Петров" << setw(16) << L"Василий" << setw(16) << L"Кленовая 16" << setw(16) << L"Санкт-Петербург" << endl
		<< setw(16) << L"Иванов" << setw(16) << L"Сергей" << setw(16) << L"Осиновая 3" << setw(16) << L"Находка" << endl
		<< setw(16) << L"Сидоров" << setw(16) << L"Иван" << setw(16) << L"Березовая 21" << setw(16) << L"Калининград" << endl;

	return 0;
}