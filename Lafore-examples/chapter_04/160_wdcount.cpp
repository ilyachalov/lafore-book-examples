// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// wdcount.cpp
// подсчет числа слов в предложении с использованием перечислений

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <conio.h> // для функции _getwche не понадобился
using namespace std;

enum itsaWord { NO, YES }; // NO=0, YES=1

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	itsaWord isWord = NO; // isWord равно YES, когда вводится слово, и NO, когда вводятся пробелы
	wchar_t ch = L'a';    // для считываемого с клавиатуры символа
	int wordcount = 0;    // число слов
	
	wcout << L"Введите предложение: \n";
	do {
		ch = _getwche();               // ввод символа
		if (ch == L' ' || ch == L'\r') // если введен пробел или нажата клавиша Enter,
		{
			if (isWord == YES)         // а до этого вводилось слово,
			{                          // значит, слово закончилось
				wordcount++;           // учет слова
				isWord = NO;           // сброс флага
			}
		}                              // в противном случае
		else                           // ввод слова продолжается
			if (isWord == NO)          // если начался ввод слова,
				isWord = YES;          // то устанавливаем флаг
	} while (ch != L'\r');             // выход по нажатию Enter
	wcout << L"\n--- Число слов: " << wordcount << L" ---\n";

	return 0;
}