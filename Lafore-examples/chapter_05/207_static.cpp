// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// static.cpp
// демонстрирует статические локальные переменные

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

float getavg(float); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	float data = 1, avg;
	
	while (data != 0)
	{
		wcout << L"Введите число: ";
		wcin >> data;
		avg = getavg(data);
		wcout << L"Среднее значение: " << avg << endl;
	}

	return 0;
}

// функция находит среднее арифметическое всех введенных значений
float getavg(float newdata)
{
	static float total = 0; // инициализация статических
	static int count = 0;   // переменных при первом вызове
	count++;                // увеличение счетчика
	total += newdata;       // добавление нового значения к сумме
	return total / count;   // возврат нового среднего значения
}