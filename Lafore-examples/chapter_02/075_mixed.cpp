// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// mixed.cpp
// использование смешанных выражений

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int count = 7;
	float avgWeight = 155.5F;
	double totalWeight = count * avgWeight;
	wcout << L"Вес равен " << totalWeight << endl;

	return 0;
}
