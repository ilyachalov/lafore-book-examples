// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_02exercise.cpp
// написать функцию power, возводящую число в степень

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

double power(double n, int p = 2); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	double number; // число для возведения в степень
	int pow;       // степень
	
	wcout << L"Введите число: "; wcin >> number;
	wcout << L"Введите степень: "; wcin >> pow;
	wcout << L"Результат возведения числа в степень: " << power(number, pow) << endl;
	wcout << L"Результат, если степень не указана: " << power(number) << endl;

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