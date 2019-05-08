// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_03exercise.cpp
// написать функцию zeroSmaller, обнуляющую меньшее из двух чисел

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

void zeroSmaller(int& n1, int& n2); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int num1, num2; // для первого и второго числа
	
	wcout << L"Введите первое число: "; wcin >> num1;
	wcout << L"Введите второе число: "; wcin >> num2;
	zeroSmaller(num1, num2);
	wcout << L"Первое число после работы функции: " << num1 << endl;
	wcout << L"Второе число после работы функции: " << num2 << endl;

	return 0;
}

// функция обнуляет меньшее из двух чисел
// (если числа равны, функция ничего не делает)
void zeroSmaller(int& n1, int& n2)
{
	if (n1 < n2)
		n1 = 0;
	else if (n1 > n2)
		n2 = 0;
}