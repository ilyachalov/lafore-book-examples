// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_07exercise.cpp
// перегрузить функцию power, возводящую число в степень, так,
// чтобы кроме аргумента типа double она могла принять аргументы с
// типами wchar_t, int, long и float

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

double power(double n, int p = 2); // прототипы функций
double power(wchar_t n, int p = 2);
double power(int n, int p = 2);
double power(long n, int p = 2);
double power(float n, int p = 2);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	double number_d;  // числа разных типов для возведения в степень
	wchar_t number_w;
	int number_i;
	long number_l;
	float number_f;
	int pow;          // степень
	
	wcout << L"Введите четыре числа (через пробел): ";
	wcin >> number_d >> number_i >> number_l >> number_f;
	// для типа wchar_t считываем только один символ
	wcout << L"Введите символ (для типа wchar_t): "; number_w = _getwche();
	wcout << L"\nВведите степень: "; wcin >> pow;
	wcout << L"Результаты возведения четырех чисел в степень: "
		<< power(number_d, pow) << L" " << power(number_i, pow) << L" "
		<< power(number_l, pow) << L" " << power(number_f, pow)	<< endl;
	wcout << L"Результат возведения в степень (для типа wchar_t): " << power(number_w, pow) << endl;
	wcout << L"Результаты, если степень не указана: "
		<< power(number_d) << L" " << power(number_i) << L" "
		<< power(number_l) << L" " << power(number_f) << endl;
	wcout << L"Результат, если степень не указана (для типа wchar_t): " << power(number_w) << endl;

	return 0;
}

// функция возводит число n в степень p (по умолчанию степень равна 2)
// работает, если степень p представляет собой целое неотрицательное число (включая ноль)
double power(double n, int p)
{
	double res = 1;
	for (int i = 1; i <= p; i++)
		res = res * n;
	return res;
}

// функция возводит число n в степень p (по умолчанию степень равна 2)
// работает, если степень p представляет собой целое неотрицательное число (включая ноль)
// -------------------------------------------------
// ЗАМЕЧАНИЕ: в случае, когда основание для возведения в степень представляет из себя значение
// типа wchar_t, в степень возводится десятичный код символа в Юникоде
double power(wchar_t n, int p)
{
	double res = 1;
	for (int i = 1; i <= p; i++)
		res = res * n;
	return res;
}

// функция возводит число n в степень p (по умолчанию степень равна 2)
// работает, если степень p представляет собой целое неотрицательное число (включая ноль)
double power(int n, int p)
{
	double res = 1;
	for (int i = 1; i <= p; i++)
		res = res * n;
	return res;
}

// функция возводит число n в степень p (по умолчанию степень равна 2)
// работает, если степень p представляет собой целое неотрицательное число (включая ноль)
double power(long n, int p)
{
	double res = 1;
	for (int i = 1; i <= p; i++)
		res = res * n;
	return res;
}

// функция возводит число n в степень p (по умолчанию степень равна 2)
// работает, если степень p представляет собой целое неотрицательное число (включая ноль)
double power(float n, int p)
{
	double res = 1;
	for (int i = 1; i <= p; i++)
		res = res * n;
	return res;
}