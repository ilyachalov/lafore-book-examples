// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_11exercise.cpp
// Модифицировать калькулятор из упражнения 12 главы 5:
// заменить структуру fraction (обыкновенная дробь) на класс (см. упражнение 9 главы 6)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class fraction // класс, представляющий обыкновенную дробь
{
private:
	int num; // числитель
	int den; // знаменатель
public:
	// конструктор без аргументов
	fraction()
		{ }
	// конструктор с двумя аргументами
	fraction(int n, int d) : num(n), den(d)
		{ }
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wchar_t slash; // для косой черты
		wcout << L"Введите обыкновенную дробь (в формате числитель/знаменатель): ";
		wcin >> num >> slash >> den;
	}
	// константный метод выводит поля объекта класса на экран
	void display() const
	{
		wcout << L"Результат операции: " << num << L'/' << den << endl;
	}
	// метод для сложения двух обыкновенных дробей
	void add(fraction f1, fraction f2)
	{
		num = f1.num * f2.den + f2.num * f1.den;
		den = f1.den * f2.den;
		lowterms();
	}
	// метод для нахождения разности двух обыкновенных дробей
	void sub(fraction f1, fraction f2)
	{
		num = f1.num * f2.den - f2.num * f1.den;
		den = f1.den * f2.den;
		lowterms();
	}
	// метод для умножения двух обыкновенных дробей
	void mul(fraction f1, fraction f2)
	{
		num = f1.num * f2.num;
		den = f1.den * f2.den;
		lowterms();
	}
	// метод для нахождения результата от деления одной обыкновенной дроби на другую
	void div(fraction f1, fraction f2)
	{
		num = f1.num * f2.den;
		den = f1.den * f2.num;
		lowterms();
	}
	// метод (прототип) для сокращения дроби до несократимого вида
	void lowterms();
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	fraction fr1, fr2, fr3; // для хранения обыкновенных дробей
	wchar_t oper;           // знак операции
	wchar_t ch;             // для ответа на вопрос о продолжении работы программы
	
	do {
		fr1.get(); // получим от пользователя первую обыкновенную дробь
		wcout << L"Введите знак операции (+, -, *, /): "; wcin >> oper;
		fr2.get(); // получим от пользователя вторую обыкновенную дробь

		switch (oper)
		{
		case '+':
			fr3.add(fr1, fr2); fr3.display(); break;
		case '-':
			fr3.sub(fr1, fr2); fr3.display(); break;
		case '*':
			fr3.mul(fr1, fr2); fr3.display(); break;
		case '/':
			fr3.div(fr1, fr2); fr3.display(); break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

		wcout << L"Выполнить еще одну операцию (д/н) ? "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}

// метод для сокращения дроби до несократимого вида
void fraction::lowterms()
{
	long tnum, tden, // две временные переменные для хранения числителя и знаменателя
		 temp,       // временная переменная для хранения значения при обмене
		 gcd;        // наибольший общий делитель, который нужно найти (greatest common divisor)

	tnum = labs(num); // возьмем значения числителя и знаменателя по модулю
	tden = labs(den); // (заголовочный файл cmath для функции labs не понадобился)
	
	if (tden == 0) // проверка знаменателя на 0
		{ cout << "Недопустимый знаменатель!"; exit(1); }
	else if (tnum == 0) // проверка числителя на 0
		{ num = 0; den = 1; return;	}

	// нахождение наибольшего общего делителя (Алгоритм Евклида)
	while (tnum != 0)
	{
		// добьемся, чтобы числитель был больше
		if (tnum < tden)                               // если числитель меньше знаменателя,
			{ temp = tnum; tnum = tden; tden = temp; } // меняем их местами
		
		tnum = tnum - tden;
	}
	gcd = tden;

	num = num / gcd; // делим числитель и знаменатель на
	den = den / gcd; // полученный наибольший общий делитель
}