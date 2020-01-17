// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// iline.cpp
// чтение строк, содержащих пробелы, из файла

// я добавил в программу две строки для работы с локалью, чтобы можно было
// читать русские буквы из файла в кодировке UTF-8

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// #include <locale> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при чтении из файла в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	const int MAX = 80;  // размер буфера
	wchar_t buffer[MAX]; // буфер для символов

	wifstream infile(L"тестовый файл.txt"); // создать поток, связанный с нужным файлом
	infile.imbue(utf8_locale);              // связываем наш поток с нужной локалью
	
	while (!infile.eof()) // пока не достигнут конец файла,
	{
		infile.getline(buffer, MAX); // извлечь строку из файла
		wcout << buffer << endl;     // и вывести ее на экран
	}

	return 0;
}