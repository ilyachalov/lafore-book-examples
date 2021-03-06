﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 15chapter_11exercise_2.cpp
// Я решил немного изменить условия этого упражнения из учебника Лафоре.
// Пусть имеется текстовый файл, содержащий текст в кодировке UTF-8, а не целые
// числа, разделенные пробелом, как было в изначальном условии упражнения.

// Требуется написать программу, которая получает от пользователя имя исходного
// файла (о котором сказано выше) и имя файла назначения. После этого программа
// должна в цикле while скопировать все символы из исходного файла в файл
// назначения с помощью входного и выходного итераторов.

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>  // для работы со стандартными потоками wcin и wcout
#include <string>    // для работы с классом wstring
#include <fstream>   // для работы с файловыми потоками
#include <iterator>  // для потоковых итераторов istream_iterator
                     // и ostream_iterator
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	// переключение стандартного потока ошибок в формат Юникода
	_setmode(_fileno(stderr), _O_U16TEXT);

	// получим от пользователя имена исходного файла и файла назначения
	wstring iname, oname; // имена файлов
	wcout << L"Введите имя исходного файла: ";
	getline(wcin, iname);
	wcout << L"Введите имя файла назначения: ";
	getline(wcin, oname);

	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при чтении (записи) из/в файл в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	// откроем исходный файл для чтения
	wifstream infile(iname);   // входной поток
	infile.imbue(utf8_locale); // связываем наш поток с нужной локалью
	if (!infile)
		{ wcerr << L"Не получается открыть исходный файл для чтения\n"; exit(1); }

	// проверим, существует ли файл назначения; если существует, спросим о продолжении работы
	wifstream testf(oname); // откроем файл назначения для чтения
	if (testf)
	{
		wchar_t answer;
		wcout << L"Файл назначения с таким именем уже существует! Продолжить работу? (д/н) ";
		wcin >> answer;
		if (answer == L'н')
			{ wcerr << L"Работа программы прервана пользователем\n"; exit(1); }
	}

	// откроем файл назначения для записи
	wofstream outfile(oname);   // выходной поток
	outfile.imbue(utf8_locale); // связываем наш поток с нужной локалью
	if (!outfile)
		{ wcerr << L"Не получается открыть файл назначения для записи\n"; exit(1); }

	// создаем нужные потоковые итераторы
	noskipws(infile); // если этого не сделать, то по умолчанию istream_iterator
	                  // игнорирует (пропускает) пробельные символы
	istream_iterator<wchar_t, wchar_t> is_iter(infile);  // итератор входного потока
	istream_iterator<wchar_t, wchar_t> end_of_stream;    // итератор конца входного потока
	ostream_iterator<wchar_t, wchar_t> os_iter(outfile); // итератор выходного потока

	// копируем символы из исходного файла в файл назначения
	while (is_iter != end_of_stream)
		*os_iter++ = *is_iter++;
	
	wcout << L"Копирование выполнено успешно" << endl;

	return 0;
}