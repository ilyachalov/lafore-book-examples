// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_01exercise.cpp
// Написать программу с использованием структуры, позволяющей хранить раздельно
// три части телефонного номера

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct phone      // номер телефона, состоящий из трех частей
{
	int citycode; // код города (3 цифры)
	int nstation; // номер телефонной станции (3 цифры)
	int nabonent; // номер абонента (4 цифры)
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	phone ph1, ph2; // создание двух структурных переменных типа phone

	// инициализация первой структурной переменной ph1
	ph1 = {212, 767, 8900};

	// инициализация второй структурной переменной ph2
	wcout << L"Введите код города, номер станции и номер абонента:\n";
	wcin >> ph2.citycode >> ph2.nstation >> ph2.nabonent;

	// вывод содержимого обеих переменных на экран
	wcout << L"Мой номер: (" << ph1.citycode << L") " << ph1.nstation << L"-" << ph1.nabonent << endl;
	wcout << L"Ваш номер: (" << ph2.citycode << L") " << ph2.nstation << L"-" << ph2.nabonent << endl;

	return 0;
}