// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// fibo.cpp
// генерирование чисел Фибоначчи с помощью цикла while

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	// граница типа unsigned long
	const unsigned long limit = 4294967295;
	unsigned long next = 0;  // предпоследний член
	unsigned long last = 1;  // последний член
	while (next < limit / 2) // результат не должен быть слишком большим
	{
		wcout << last << L" ";    // вывод последнего члена
		long sum = next + last; // сложение двух последних членов
		next = last;            // обновление предпоследнего
		last = sum;             // и последнего членов
	}
	wcout << endl;

	return 0;
}