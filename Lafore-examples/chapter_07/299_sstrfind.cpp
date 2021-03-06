﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sstrfind.cpp
// поиск подстрок с помощью стандартного класса string

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <string> // для стандартного класса string в языке C++
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	// строка, в которой производится поиск
	wstring s1 = L"В лесу родилась елочка, в лесу она росла.";
	// для результата поиска
	int n;

	// поиск подстроки "елочка" в строке s1;
	// n — индекс первого символа найденной подстроки в массиве символов s1
	// (при этом нужно помнить, что нумерация символов начинается с 0, поэтому
	// индекс, к примеру, 17-го символа в строке будет равен 16);
	// если подстрока не найдена, функция find возвратит значение wstring::npos,
	// которое равно -1
	n = s1.find(L"елочка");
	wcout << L"Подстрока \"елочка\" найдена: " << n << endl;

	// поиск первого вхождения в строку s1 любого из символов заданной подстроки "умка"
	n = s1.find_first_of(L"умка");
	wcout << L"Первое вхождение любого символа из подстроки \"умка\": " << n << endl;

	// поиск первого вхождения в строку s1 любого символа не из
	// заданной подстроки "абвгдАБВГД"
	n = s1.find_first_not_of(L"абвгдАБВГД");
	wcout << L"Первое вхождение символа не из подстроки \"абвгдАБВГД\": " << n << endl;

	return 0;
}