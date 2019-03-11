// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// chcnt2.cpp
// подсчет числа слов и символов в строке

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <conio.h> // для функции _getwche не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int chcount = 0;
	int wdcount = 1;     // пробел между двумя словами
	wchar_t ch;
	wcout << L"Введите строку: ";
	while ((ch=_getwche()) != L'\r') // цикл, пока не будет нажата клавиша Enter
	{
		if (ch == L' ')  // если символ является пробелом,
			wdcount++;   // то инкрементируем число слов
		else             // в противном случае
			chcount++;   // инкрементируем число символов
	}
	// вывод результатов на экран
	wcout << L"\nCлов: " << wdcount << endl;
	wcout << L"Букв: " << chcount << endl;

	return 0;
}