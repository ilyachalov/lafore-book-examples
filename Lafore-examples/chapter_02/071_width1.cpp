// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// width1.cpp
// демонстрирует необходимость применения манипулятора setw

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	long pop1 = 4789426, pop2 = 274124, pop3 = 9761;
	wcout << L"Город " << L"Нас." << endl
		  << L"Москва " << pop1 << endl
		  << L"Киров " << pop2 << endl
		  << L"Угрюмовка " << pop3 << endl;

	return 0;
}
