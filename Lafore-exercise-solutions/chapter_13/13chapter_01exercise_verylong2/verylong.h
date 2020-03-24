// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// verylong.h
// описатель класса очень длинных целых чисел

// для использования небезопасных функций wcscpy, _ltow
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
// #include <string.h> // для функций wcslen, wcscpy, _wcsrev не понадобился
// #include <stdlib.h> // для функции _ltow не понадобился
using namespace std;

const int SZ = 1000; // максимальное число цифр в очень длинных целых числах

class verylong
{
private:
	wchar_t vlstr[SZ]; // массив (строка) для хранения очень длинного целого числа
	int vlen;          // длина очень длинного целого числа, сохраненного в массиве
	bool sign;         // знак числа: true — положительное; false — отрицательное
	verylong natural_addition(const verylong) const;    // прототипы
	verylong natural_subtraction(const verylong) const;
	int cmp(const verylong) const;
	verylong natural_multiplication(const verylong) const;
	verylong natural_division(const verylong, bool) const;
	verylong multdigit(const int) const;                // скрытых
	verylong mult10(const verylong) const;              // функций
public:
	verylong() : vlen(0), sign(true) // конструктор без аргументов
		{ vlstr[0] = L'\0'; }
	verylong(const wchar_t s[SZ])    // конструктор с одним аргументом-строкой
		{ wcscpy(vlstr, s); vlen = wcslen(s); sign = true; }
	verylong(const long n)           // конструктор с одним аргументом-числом
	{
		if (n < 0)                   // определим знак числа
			sign = false;
		else
			sign = true;
		_ltow(abs(n), vlstr, 10);    // преобразуем аргумент в строку
		_wcsrev(vlstr);              // разворот числа в строке (старшие
		                             // разряды станут младшими и наоборот)
		vlen = wcslen(vlstr);        // найдем длину нашего числа в строке
	}
	void putvl() const;              // вывод очень длинного целого числа на экран
	void getvl();                    // получение числа от пользователя
	verylong operator+ (const verylong); // найти сумму очень длинных целых чисел
	verylong operator- (const verylong); // найти разность длинных целых чисел
	verylong operator* (const verylong); // найти произведение таких чисел
	verylong operator/ (const verylong); // найти результат целочисленного деления
	verylong operator% (const verylong); // найти остаток от целочисленного деления
};