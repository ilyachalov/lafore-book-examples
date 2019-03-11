// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// badelse.cpp
// неправильное сопоставление else и if во вложенных ветвлениях

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

	int a, b, c;
	wcout << L"Введите числа a, b и с: \n";
	wcin >> a >> b >> c;
	if (a == b)
		if (b == c)
			wcout << L"a, b, и с равны\n";
	else // этот блок на самом деле относится ко второму if, а не к первому!
		 // в результате программа отработает не так, как планировал автор
		wcout << L"а и b не равны\n";

	return 0;
}