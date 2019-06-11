// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// days.cpp
// показ количества дней с начала года и до введенной даты

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

	int month, day, total_days;
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	wcout << L"Введите месяц (от 1 до 12): ";
	wcin >> month;
	wcout << L"Введите день (от 1 до 31): ";
	wcin >> day;
	
	total_days = day;
	for (int j = 0; j < month - 1; j++)
		total_days += days_per_month[j];
	
	wcout << L"Общее число дней с начала года: " << total_days << endl;

	return 0;
}