// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// replay.cpp
// запоминание и вывод на экран информации, введенной пользователем

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int age[4];
	
	for (int j = 0; j < 4; j++)
	{
		wcout << L"Введите возраст: ";
		wcin >> age[j];
	}
	
	for (int j = 0; j < 4; j++)
		wcout << L"Вы ввели: " << age[j] << endl;

	return 0;
}