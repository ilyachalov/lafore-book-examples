// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_12exercise.cpp
// --------------------------------
// Задание к упражнению 12 главы 4:
// программа-калькулятор, выполняющая четыре арифметических действия над
// обыкновенными дробями (вида a/b). Для хранения дробей использовать
// структуру
// --------------------------------
// Задание к упражнению 12 главы 5:
// модифицировать программу из упражнения 12 главы 4 так, чтобы каждая арифметическая
// операция выполнялась с помощью функции

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct fraction // обыкновенная дробь
{
	int num; // числитель
	int den; // знаменатель
};

fraction fadd(fraction, fraction); // прототипы функций
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);
void outFraction(fraction);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	fraction fr1, fr2; // для хранения обыкновенных дробей
	wchar_t slash;     // знак дроби
	wchar_t oper;      // знак операции
	wchar_t ch;        // для ответа на вопрос о продолжении работы программы
	
	do {
		wcout << L"Введите первую дробь, знак операции и вторую дробь: ";
		wcin >> fr1.num >> slash >> fr1.den >> oper >> fr2.num >> slash >> fr2.den;

		switch (oper)
		{
		case '+':
			outFraction(fadd(fr1, fr2)); break;
		case '-':
			outFraction(fsub(fr1, fr2)); break;
		case '*':
			outFraction(fmul(fr1, fr2)); break;
		case '/':
			outFraction(fdiv(fr1, fr2)); break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

		wcout << L"Выполнить еще одну операцию (д/н) ? "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}

// функция возвращает сумму двух обыкновенных дробей
fraction fadd(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.den + f1.den * f2.num;
	f.den = f1.den * f2.den;
	return f;
}

// функция возвращает разность двух обыкновенных дробей
fraction fsub(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.den - f1.den * f2.num;
	f.den = f1.den * f2.den;
	return f;
}

// функция возвращает произведение двух обыкновенных дробей
fraction fmul(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.num;
	f.den = f1.den * f2.den;
	return f;
}

// функция возвращает результат от деления одной обыкновенной дроби на другую
fraction fdiv(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.den;
	f.den = f1.den * f2.num;
	return f;
}

// функция выводит заданную обыкновенную дробь (результат операции) на экран
void outFraction(fraction f)
{
	wcout << L"Результат операции: " << f.num << L"/" << f.den << endl;
}