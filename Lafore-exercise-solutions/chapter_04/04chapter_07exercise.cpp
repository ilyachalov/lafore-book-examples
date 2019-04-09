// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_07exercise.cpp
// Создать структуру, представляющую работника, из четырех полей:
// номер работника, его зарплата в рублях, должность и дата принятия на работу.
// Запросить у пользователя данные на троих работников, сохранить их в структурную
// переменную и вывести эти данные на экран.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипуляторов setw и setprecision
using namespace std;

// должность работника (перечисление)
enum etype { рабочий, секретарь, менеджер, бухгалтер, директор, исследователь };

struct date // дата
{
	int day;   // день
	int month; // месяц
	int year;  // год
};

struct employee // работник
{
	int number;     // номер работника
	float salary;   // зарплата в рублях
	etype position; // должность
	date begdate;   // дата принятия на работу
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	employee emp1, emp2, emp3; // создание трех структурных переменных типа employee
	wchar_t ch;                // первая буква должности
	wchar_t slash;             // для косой черты

	// получаем с клавиатуры информацию о трех работниках...
	wcout << L"Введите данные трех работников\n";
	wcout << L"(пример ввода: 5 45237.34 д 25/3/2019)\n";
	wcout << L"(должности: рабочий, секретарь, менеджер, бухгалтер, директор, исследователь)\n";

	// ...о первом работнике
	wcout << L"Номер работника, зарплата, первая буква должности, дата принятия на работу:\n";
	wcin >> emp1.number >> emp1.salary >> ch
		 >> emp1.begdate.day >> slash >> emp1.begdate.month >> slash >> emp1.begdate.year;
	switch (ch)
	{
	case L'р': emp1.position = рабочий; break;
	case L'с': emp1.position = секретарь; break;
	case L'м': emp1.position = менеджер; break;
	case L'б': emp1.position = бухгалтер; break;
	case L'д': emp1.position = директор; break;
	case L'и': emp1.position = исследователь; break;
	default: emp1.position = рабочий; // при указании неверной буквы
	}

	// ...о втором работнике
	wcout << L"Номер работника, зарплата, первая буква должности, дата принятия на работу:\n";
	wcin >> emp2.number >> emp2.salary >> ch
		 >> emp2.begdate.day >> slash >> emp2.begdate.month >> slash >> emp2.begdate.year;
	switch (ch)
	{
	case L'р': emp2.position = рабочий; break;
	case L'с': emp2.position = секретарь; break;
	case L'м': emp2.position = менеджер; break;
	case L'б': emp2.position = бухгалтер; break;
	case L'д': emp2.position = директор; break;
	case L'и': emp2.position = исследователь; break;
	default: emp2.position = рабочий; // при указании неверной буквы
	}

	// ...о третьем работнике
	wcout << L"Номер работника, зарплата, первая буква должности, дата принятия на работу:\n";
	wcin >> emp3.number >> emp3.salary >> ch
		 >> emp3.begdate.day >> slash >> emp3.begdate.month >> slash >> emp3.begdate.year;
	switch (ch)
	{
	case L'р': emp3.position = рабочий; break;
	case L'с': emp3.position = секретарь; break;
	case L'м': emp3.position = менеджер; break;
	case L'б': emp3.position = бухгалтер; break;
	case L'д': emp3.position = директор; break;
	case L'и': emp3.position = исследователь; break;
	default: emp3.position = рабочий; // при указании неверной буквы
	}

	// вывод информации о каждом из работников на экран...
	wcout << L"\nИнформация о работниках компании:\n"
		  << setw(5)  << L"Номер"     << setw(9)  << L"Зарплата"
		  << setw(14) << L"Должность" << setw(12) << L"Дата приема" << endl;

	// ...о первом работнике
	wcout << setw(5) << emp1.number << setw(9) << fixed << setprecision(2) << emp1.salary;
	switch (emp1.position)
	{
	case рабочий: wcout << setw(14) << L"рабочий"; break;
	case секретарь: wcout << setw(14) << L"секретарь"; break;
	case менеджер: wcout << setw(14) << L"менеджер"; break;
	case бухгалтер: wcout << setw(14) << L"бухгалтер"; break;
	case директор: wcout << setw(14) << L"директор"; break;
	case исследователь: wcout << setw(14) << L"исследователь"; break;
	}
	wcout << L" " << emp1.begdate.day << L"/" << emp1.begdate.month << L"/" << emp1.begdate.year << endl;

	// ...о втором работнике
	wcout << setw(5) << emp2.number << setw(9) << fixed << setprecision(2) << emp2.salary;
	switch (emp2.position)
	{
	case рабочий: wcout << setw(14) << L"рабочий"; break;
	case секретарь: wcout << setw(14) << L"секретарь"; break;
	case менеджер: wcout << setw(14) << L"менеджер"; break;
	case бухгалтер: wcout << setw(14) << L"бухгалтер"; break;
	case директор: wcout << setw(14) << L"директор"; break;
	case исследователь: wcout << setw(14) << L"исследователь"; break;
	}
	wcout << L" " << emp2.begdate.day << L"/" << emp2.begdate.month << L"/" << emp2.begdate.year << endl;

	// ...о третьем работнике
	wcout << setw(5) << emp3.number << setw(9) << fixed << setprecision(2) << emp3.salary;
	switch (emp3.position)
	{
	case рабочий: wcout << setw(14) << L"рабочий"; break;
	case секретарь: wcout << setw(14) << L"секретарь"; break;
	case менеджер: wcout << setw(14) << L"менеджер"; break;
	case бухгалтер: wcout << setw(14) << L"бухгалтер"; break;
	case директор: wcout << setw(14) << L"директор"; break;
	case исследователь: wcout << setw(14) << L"исследователь"; break;
	}
	wcout << L" " << emp3.begdate.day << L"/" << emp3.begdate.month << L"/" << emp3.begdate.year << endl;

	return 0;
}