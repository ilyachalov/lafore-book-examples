// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// platters.cpp
// применение ветвления switch

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

	int speed;     // скорость вращения грампластинки
	wcout << L"Введите число 33, 45 или 78: ";
	wcin >> speed;  // ввод скорости пользователем
	switch (speed) // действия, зависящие от выбора скорости
	{
	case 33:       // если пользователь ввел 33
		wcout << L"Долгоиграющий формат\n";
		break;
	case 45:       // если пользователь ввел 45
		wcout << L"Формат сингла\n";
		break;
	case 78:       // если пользователь ввел 78
		wcout << L"Устаревший формат\n";
		break;
	}

	return 0;
}