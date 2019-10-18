// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// newstr.cpp
// использование оператора new для выделения памяти под строку
// на примере класса String из 323_strplus.cpp главы 8

// для использования небезопасной функции wcscpy
#define _CRT_SECURE_NO_WARNINGS

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cstring> // для функций wcscpy и wcslen не понадобился
using namespace std;

class String // класс, представляющий строку (массив символов)
{
private:
	wchar_t* str;            // указатель на строку
public:
	String(const wchar_t* s) // конструктор с одним параметром
	{
		int length = wcslen(s);        // вычисляем длину строки
		str = new wchar_t[length + 1]; // выделяем необходимую память
		wcscpy(str, s);                // копируем строку
	}
	~String() // деструктор
	{
		wcout << L"Удаляем строку.\n";
		delete[] str;                  // освобождаем память
	}
	void display() const     // вывод строки на экран
		{ wcout << str << endl; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	String s1 = L"Тише едешь — дальше будешь.";
	wcout << L"s1 = ";
	s1.display();

	return 0;
}