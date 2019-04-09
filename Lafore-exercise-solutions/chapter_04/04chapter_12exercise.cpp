// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_12exercise.cpp
// Программа-калькулятор, выполняющая четыре арифметических действия над
// обыкновенными дробями (вида a/b). Для хранения дробей использовать
// структуру.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct fraction // обыкновенная дробь
{
	int num; // числитель
	int den; // знаменатель
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	fraction f1, f2; // для хранения обыкновенных дробей
	wchar_t slash;   // знак дроби
	wchar_t oper;    // знак операции
	wchar_t ch;      // для ответа на вопрос о продолжении работы программы
	
	do {
		wcout << L"Введите первую дробь, знак операции и вторую дробь: ";
		wcin >> f1.num >> slash >> f1.den >> oper >> f2.num >> slash >> f2.den;

		switch (oper)
		{
		case '+':
			wcout << L"Результат операции: "
				  << f1.num * f2.den + f1.den * f2.num << L"/" << f1.den * f2.den << endl;
			break;
		case '-':
			wcout << L"Результат операции: "
				  << f1.num * f2.den - f1.den * f2.num << L"/" << f1.den * f2.den << endl;
			break;
		case '*':
			wcout << L"Результат операции: " << f1.num * f2.num << L"/" << f1.den * f2.den << endl;
			break;
		case '/':
			wcout << L"Результат операции: " << f1.num * f2.den << L"/" << f1.den * f2.num << endl;
			break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

		wcout << L"Выполнить еще одну операцию (д/н) ? "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}