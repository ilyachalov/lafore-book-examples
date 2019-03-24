// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_01exercise.cpp
// программа, переводящая галлоны в кубические футы

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

	float gallons, ft3;

	wcout << L"Введите число галлонов: "; wcin >> gallons;
	ft3 = gallons / 7.481F;
	wcout << L"В кубических футах это будет " << ft3 << endl;

	return 0;
}
