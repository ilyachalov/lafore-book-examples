// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ostrstr.cpp
// программа записывает форматированные данные в память

// вместо устаревшего заголовочного файла <strstream>, содержащего определения
// устаревших классов ostrstream, istrstream и strstream в этой программе мы
// будем использовать заголовочный файл <sstream>, содержащий определения
// шаблонов классов basic_istringstream (в т.ч. класс wistringstream),
// basic_ostringstream (в т.ч. класс wostringstream) и basic_stringstream
// (в т.ч. класс wstringstream)

// устаревший класс ostrstream работает с буфером в памяти, представляющим из себя
// массив типа char; wostringstream же работает со строкой класса wstring

// для объекта устаревшего класса ostrstream требовалось заканчивать ввод в буфер
// в памяти (массив типа char) нулевым символом '\0' (нуль-терминированная строка);
// для объекта же класса wostringstream этого не требуется, так как строка класса
// wstring не требует завершения нулевым символом

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <sstream>
#include <iomanip>   // для функций setiosflags и setprecision
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wchar_t ch = L'ы';                  // тестовые данные (в т.ч. и русские буквы)
	int j = 77;
	double d = 67890.12345;
	wchar_t str1[] = L"Kafka";
	wchar_t str2[] = L"Фрейд";

	wostringstream omem;                // создадим потоковый объект
	
	omem << L"ch = " << ch << endl      // вставим форматированные данные
	     << L"j = " << j << endl        // в потоковый объект
	     << setiosflags(ios::fixed)     // формат числа с десятичной запятой,
	     << setprecision(2)             // в числе два знака после запятой
	     << L"d = " << d << endl
	     << L"str1 = " << str1 << endl
	     << L"str2 = " << str2 << endl;

	wcout << omem.str();                // выведем форматированные данные на экран
	
	return 0;
}