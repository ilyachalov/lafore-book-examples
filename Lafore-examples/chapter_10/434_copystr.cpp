// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// copystr.cpp
// копирование одной строки в другую с помощью указателей

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	void copystr(wchar_t*, const wchar_t*); // прототип функции
	const wchar_t* str1 = L"Победа над собой — величайшая из побед.";
	wchar_t str2[80];      // пустая строка

	copystr(str2, str1);   // вызов функции для копирования строки str1 в str2
	wcout << str2 << endl; // и показываем результат

	return 0;
}

// функция для копирования строки src в строку dest
void copystr(wchar_t* dest, const wchar_t* src)
{
	while (*src)           // пока не встретим конец строки src (нулевой символ)
		*dest++ = *src++;  // копируем строку src посимвольно в строку dest
	*dest = L'\0';         // заканчиваем строку dest нулевым символом
}