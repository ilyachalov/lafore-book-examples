// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// newintro.cpp
// знакомство с оператором new

// для использования небезопасной функции wcscpy
#define _CRT_SECURE_NO_WARNINGS

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cstring> // для функций wcslen, wcscpy не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	const wchar_t* str = L"Дурная голова ногам покоя не дает.";
	int len = wcslen(str);      // вычислим длину строки str

	wchar_t* ptr;               // создадим указатель на строку
	ptr = new wchar_t[len + 1]; // выделим память: строка + нулевой символ

	wcscpy(ptr, str);           // скопируем строку str в ptr

	wcout << L"ptr = " << ptr << endl; // покажем строку, на которую указывает ptr

	delete[] ptr;               // освободим выделенную память

	return 0;
}