// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// salemon.cpp
// показ таблицы продаж с помощью двумерного массива

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипуляторов setiosflags, setprecision, setw
using namespace std;

const int DISTRICTS = 4; // количество отделов
const int MONTHS = 3;    // количество месяцев работы отделов

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int d, m;
	double sales[DISTRICTS][MONTHS];
	
	// ввод данных от пользователя в двумерный массив
	for (d = 0; d < DISTRICTS; d++)
		for (m = 0; m < MONTHS; m++)
		{
			wcout << L"Введите объем продаж для отдела " << d + 1;
			wcout << L", за месяц " << m + 1 << L": ";
			wcin >> sales[d][m];
		}

	// вывод полученных выше данных в форме таблицы
	wcout << L"\n\n";
	wcout << L"                        Месяц\n";       // перед словом 24 пробела
	wcout << L"                1         2         3"; // перед цифрами 16, 9 и 9 пробелов
	for (d = 0; d < DISTRICTS; d++)
	{
		wcout << L"\nОтдел " << d + 1;
		for (m = 0; m < MONTHS; m++)
			wcout << setiosflags(ios::fixed)     // нормальный неэкспоненциальный вид
			      << setiosflags(ios::showpoint) // всегда показывать десятичную точку
			      << setprecision(2)             // два знака после запятой
			      << setw(10)                    // ширина вывода в 10 символов (всё целиком)
			      << sales[d][m];                // само число
	}
	wcout << endl;

	return 0;
}