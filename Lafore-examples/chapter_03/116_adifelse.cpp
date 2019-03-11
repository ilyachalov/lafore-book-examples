// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// adifelse.cpp
// приключенческая игра с применением ветвления if...else

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
	while (dir != L'\r')             // пока не будет нажата клавиша Enter
	{
		wcout << L"\nВаши координаты: " << x << L", " << y;
		wcout << L"\nВыберите направление (с, ю, в, з): ";
		dir = _getwche();            // ввод символа
		if (dir == L'с')             // движение на север
			y++;
		else
			if (dir == L'ю')         // движение на юг
				y--;
			else
				if (dir == L'в')     // движение на восток
					x++;
				else
					if (dir == L'з') // движение на запад
						x--;
	}                                // конец цикла while

	return 0;
}                                    // конец функции main()