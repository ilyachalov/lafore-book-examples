// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_05exercise.cpp
// Создать структуру, представляющую дату, и выполнить с структурной
// переменной такого типа указанные в описании упражнения операции.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct date // дата
{
	int day;   // день
	int month; // месяц
	int year;  // год
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	date d; // структурная переменная типа date
	wchar_t slash; // для косой черты

	// получим с клавиатуры день, месяц, год и сохраним в структурной переменной
	wcout << L"Введите день, месяц и год через косую черту (/): ";
	wcin >> d.day >> slash >> d.month >> slash >> d.year;

	// вывод даты на экран
	wcout << L"Вы ввели дату: " << d.day << L"/" << d.month << L"/" << d.year << endl;

	return 0;
}