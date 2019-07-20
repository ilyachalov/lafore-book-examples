// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// strequal.cpp
// перегрузка операции сравнения «равно» (==) для строк

// для использования небезопасной функции wcscpy
#define _CRT_SECURE_NO_WARNINGS

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;
// #include <string.h> // для функций wcscpy и wcscmp не понадобился

class String // класс, представляющий строку (массив символов)
{
private:
	// enum { SZ = 80 }; // максимальный размер строки (нестандартный синтаксис)
	static const int SZ = 80; // максимальный размер строки
							  // (одна константа для всех объектов, статическая)
	wchar_t str[SZ];          // сама строка
public:
	String() // конструктор без параметров
		{ str[0] = L'\0'; }
	String(const wchar_t s[]) // конструктор с одним параметром
	{
		wcscpy(str, s);
		// wcscpy_s(str, SZ, s); // рекомендуемый более безопасный вариант
	}
	void display() const // показ строки на экране
		{ wcout << str; }
	void get() // получение строки с клавиатуры от пользователя
		{ wcin.get(str, SZ); }
	// оператор проверки на равенство
	bool operator== (String s) const
	{
		return (wcscmp(str, s.str) == 0) ? true : false;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	String s1 = L"да";
	String s2 = L"нет";
	String s3;

	wcout << L"Введите 'да' или 'нет': ";
	s3.get();               // получаем строку от пользователя

	if (s3 == s1)           // сравниваем со строкой "да"
		wcout << L"Вы ввели 'да'\n";
	else
		if (s3 == s2)       // сравниваем со строкой "нет"
			wcout << L"Вы ввели 'нет'\n";
		else
			wcout << L"Следуйте инструкциям!\n";

	return 0;
}