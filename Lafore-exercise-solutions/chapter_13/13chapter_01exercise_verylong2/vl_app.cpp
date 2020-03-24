// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// vl_app.cpp
// вычисление факториала с помощью класса verylong, который представляет
// очень длинное целое число, и тестирование добавленных арифметических операций

#include "verylong.h" // заголовочный файл с описателем класса verylong

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	unsigned long numb, j;
	verylong fact = 1;           // инициализируем переменную класса verylong

	wcout << L"Введите число: ";
	wcin >> numb;                // получим от пользователя число типа long int
	
	for (j = numb; j > 0; j--)   // вычислим факториал полученного числа
		fact = fact * j;
	wcout << L"Факториал = ";
	fact.putvl();                // выведем результат
	wcout << endl;

	// ТЕСТИРОВАНИЕ ВСЕХ ОПЕРАЦИЙ

	verylong s, s1, s2;

	wcout << L"\nВведите первое число: "; s1.getvl();
	wcout << L"Введите второе число: "; s2.getvl();
	s = s1 + s2;
	wcout << L"Их сумма: "; s.putvl();
	s = s1 - s2;
	wcout << L"\nИх разность: "; s.putvl();
	s = s1 * s2;
	wcout << L"\nИх произведение: "; s.putvl();
	s = s1 / s2;
	wcout << L"\nРезультат целочисленного деления: "; s.putvl();
	s = s1 % s2;
	wcout << L"\nОстаток от целочисленного деления: "; s.putvl();
	wcout << endl;

	return 0;
}