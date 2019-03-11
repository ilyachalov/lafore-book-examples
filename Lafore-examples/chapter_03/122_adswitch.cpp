// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// adswitch.cpp
// приключенческая игра с использованием switch

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <conio.h> // для функции _getwche не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wchar_t dir = L'a';
	int x = 10, y = 10;
	wcout << L"Нажмите Enter для выхода...\n";
	while (dir != L'\r')           // пока не будет нажата клавиша Enter
	{
		wcout << L"\nВаши координаты: " << x << L", " << y;
		wcout << L"\nВыберите направление (с, ю, в, з): ";
		dir = _getwche();          // ввод переменной
		switch (dir)               // switch c переменнной dir
		{
			case L'с': y++; break; // движение на север
			case L'ю': y--; break; // движение на юг
			case L'в': x++; break; // движение на восток
			case L'з': x--; break; // движение на запад
			case L'\r': wcout << L"\nВыход...\n"; break; // нажатие Enter
			default: wcout << L"\nПопробуйте еще";       // нажатие других клавиш
		}                          // конец switch
	}                              // конец цикла while

	return 0;
}                                  // конец функции main()