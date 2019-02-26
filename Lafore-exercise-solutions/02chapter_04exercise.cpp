// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_04exercise.cpp
// вывести на экран любимое стихотворение
// для разбиения на строчки использовать подходящую управляющую последовательность

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wchar_t newline = L'\n'; // подходящая управляющая последовательность

	wcout << L"Это джаз декабря. Это джаз" << newline;
	wcout << L"наступившей зимы, чей мотив" << newline;
	wcout << L"обозначил излом моих фраз" << newline;
	wcout << L"и издерганность рифм." << newline << newline;
	wcout << L"(c) -- отрывок из стихотворения Дианы Эфендиевой --" << newline;

	return 0;
}