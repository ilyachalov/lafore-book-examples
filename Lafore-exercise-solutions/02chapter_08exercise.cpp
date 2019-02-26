// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_08exercise.cpp
// модифицировать пример с применением манипулятора setw из 2-й главы так,
// чтобы разделяющие символы в столбцах таблицы были не пробелами, а точками
// для этого применить манипулятор setfill

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для использования setw и setfill
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	long pop1 = 8425785, pop2 = 47, pop3 = 9761;
	wcout << setfill(L'.') << setw(9) << L"Город" << setw(12) << L"Население" << endl
	      << setw(9) << L"Москва" << setw(12) << pop1 << endl
		  << setw(9) << L"Киров" << setw(12) << pop2 << endl
		  << setw(9) << L"Угрюмовка" << setw(12) << pop3 << endl;

	return 0;
}