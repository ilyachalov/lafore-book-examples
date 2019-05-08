// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_08exercise.cpp
// написать функцию swap, обменивающую значениями два своих аргумента типа int,
// при этом изменяться должны значения переменных из вызывающей программы

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

void swap(int& n1, int& n2); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int num1, num2; // для двух чисел
	
	wcout << L"Введите два числа (через пробел): "; wcin >> num1 >> num2;
	swap(num1, num2);
	wcout << L"Меняю эти числа местами: " << num1 << L" " << num2 << endl;

	return 0;
}

// функция меняет местами значения двух заданных переменных
void swap(int& n1, int& n2)
{
	int temp;
	temp = n1; n1 = n2; n2 = temp;
}