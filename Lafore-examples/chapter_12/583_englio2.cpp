// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englio2.cpp
// перегрузка операторов вставки (<<) и извлечения (>>) для реализации
// вывода в файл (или на экран) и чтения из файла (или с клавиатуры от
// пользователя) объектов класса Distance

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <fstream>
#include <iostream>
using namespace std;

class Distance // интервал (длина) в английской системе мер
{
private:
	int feet;     // футы (1 фут = 12 дюймов)
	float inches; // дюймы
public:
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
		{ }
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	friend wistream& operator>>(wistream& s, Distance& d);
	friend wostream& operator<<(wostream& s, Distance& d);
};

// получение интервала из файла (или с клавиатуры от пользователя)
// с помощью перегрузки оператора извлечения (>>)
wistream& operator>>(wistream& s, Distance& d)
{
	wchar_t dummy; // заглушка для символов ('), (-) и (")
	s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
	return s;
}

// вывод интервала в файл (или на экран)
// с помощью перегрузки оператора вставки (<<)
wostream& operator<<(wostream& s, Distance& d)
{
	s << d.feet << L"\'-" << d.inches << L'\"';
	return s;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t ch;
	Distance dist1;
	wofstream ofile;              // создать выходной поток
	ofile.open(L"Интервалы.dat"); // и открыть его, связав с нужным файлом

	do {
		wcout << L"\nВведите интервал: ";
		wcin >> dist1;            // получить интервал от пользователя с клавиатуры
		ofile << dist1;           // и записать его в выходной поток
		wcout << L"Ещё (д/н)? ";
		wcin >> ch;
	} while (ch != L'н');
	ofile.close();                // закрыть выходной поток

	wifstream ifile;              // создать входной поток
	ifile.open(L"Интервалы.dat"); // и открыть его, связав с нужным файлом

	wcout << L"\nСодержимое файла:\n";
	while (true)
	{
		ifile >> dist1;           // прочитать интервал из потока
		if (ifile.eof())          // по достижении конца файла выйти из цикла
			break;
		wcout << L"Расстояние = " << dist1 << endl; // вывести интервал на экран
	}
	
	return 0;
}