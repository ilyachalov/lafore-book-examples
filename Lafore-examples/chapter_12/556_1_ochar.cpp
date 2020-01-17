// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ochar.cpp
// вывод в файл посимвольно

// я добавил в программу две строки для работы с локалью, чтобы можно было
// записать в файл русские буквы в кодировке UTF-8

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
#include <string>    // для работы с классом wstring
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// #include <locale> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при сохранении в файл в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	wstring str = L"\"Время — великий учитель, но, увы, "
	               "оно убивает своих учеников.\"\n(Гектор Берлиоз)";

	wofstream outfile(L"тестовый файл.txt"); // создать выходной файл
	outfile.imbue(utf8_locale);              // связываем наш поток с нужной локалью
	
	for (int j = 0; j < str.size(); j++) // каждый символ заданной строки
		outfile.put(str[j]);             // записать в файл

	wcout << L"Файл записан\n";

	return 0;
}