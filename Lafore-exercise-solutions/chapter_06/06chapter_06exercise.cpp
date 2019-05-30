// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_06exercise.cpp
// расширить класс employee (работник), созданный в упражнении 4 главы 6,
// двумя полями (дата приема на работу и должность) и переписать соответственно
// методы класса (см. упражнение 7 главы 4)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

// должность сотрудника (перечисление) (из упражнения 6 главы 4)
enum etype { рабочий, секретарь, менеджер, бухгалтер, директор, исследователь };

class date // класс, представляющий дату (из упражнения 5 главы 6)
{
private:
	int day;   // день
	int month; // месяц
	int year;  // год
public:
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wchar_t slash; // для косой черты
		wcout << L"Введите день, месяц и год через косую черту (/): ";
		wcin >> day >> slash >> month >> slash >> year;
	}
	// константный метод выводит значения полей на экран
	void display() const
		{ wcout << day << L"/" << month << L"/" << year; }
};

class employee // класс, представляющий работника
{
private:
	int number;     // номер работника
	float salary;   // зарплата работника в рублях
	etype position; // должность
	date begdate;   // дата приема на работу
public:
	// метод (прототип) для получения данных класса от пользователя с клавиатуры
	void get();
	// константный метод (прототип) выводит значения полей на экран
	void display() const;
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	employee emp1, emp2, emp3; // создание трех объектов класса employee

	// получаем с клавиатуры информацию о трех работниках
	wcout << L"Введите данные трех работников:\n";
	emp1.get();
	emp2.get();
	emp3.get();

	// вывод информации о каждом из сотрудников на экран
	wcout << L"\nИнформация о работниках компании:\n"
		  << setw(5)  << L"Номер"     << setw(9)  << L"Зарплата"
		  << setw(14) << L"Должность" << setw(12) << L"Дата приема" << endl;
	emp1.display();
	emp2.display();
	emp3.display();

	return 0;
}

// метод для получения данных класса от пользователя с клавиатуры
void employee::get()
{
	wchar_t ch; // первая буква должности
	wcout << L"Введите номер работника, зарплату, первую букву должности: ";
	wcin >> number >> salary >> ch;
	wcout << L"Дата приема. ";
	begdate.get();
	switch (ch)
	{
	case L'р': position = рабочий; break;
	case L'с': position = секретарь; break;
	case L'м': position = менеджер; break;
	case L'б': position = бухгалтер; break;
	case L'д': position = директор; break;
	case L'и': position = исследователь; break;
	default: position = рабочий; // при указании неверной буквы
	}
}

// константный метод выводит значения полей на экран
void employee::display() const
{
	wcout << setw(5) << number << setw(9) << fixed << setprecision(2) << salary;
	switch (position)
	{
	case рабочий: wcout << setw(14) << L"рабочий"; break;
	case секретарь: wcout << setw(14) << L"секретарь"; break;
	case менеджер: wcout << setw(14) << L"менеджер"; break;
	case бухгалтер: wcout << setw(14) << L"бухгалтер"; break;
	case директор: wcout << setw(14) << L"директор"; break;
	case исследователь: wcout << setw(14) << L"исследователь"; break;
	}
	wcout << L" "; begdate.display(); wcout << endl;
}