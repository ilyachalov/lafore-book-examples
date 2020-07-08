﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 15chapter_02exercise.cpp
// Требуется написать программу, которая применяет алгоритм sort к массиву
// слов, введенных пользователем, и выводит результат на экран. Для вставки
// слов в массив требуется применить метод push_back, а для вывода массива
// слов на экран — операцию [] и метод size.

// Так как речь идет о методах push_back и size, то понятно, что для хранения
// слов должен использоваться не обычный массив, а какой-то контейнер. Например,
// вектор.

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <algorithm> // для алгоритма sort
#include <vector>    // для контейнера vector
#include <string>    // для класса wstring
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	vector<wstring> vect; // массив-вектор слов
	wstring word;         // для слов, получаемых от пользователя
	wchar_t answer;       // символ для ответа пользователя (д/н)

	// получим от пользователя слова и поместим их в массив-вектор
	do {
		wcout << L"Введите слово: ";
		wcin >> word;
		vect.push_back(word);
		wcout << L"Ещё? (д/н) ";
		wcin >> answer;
	} while (answer != L'н');

	// применим алгоритм сортировки (по возрастанию) к массиву-вектору слов
	sort(vect.begin(), vect.end());

	// выведем отсортированный массив-вектор слов на экран
	wcout << L"\nОтсортированный массив: ";
	for (int j = 0; j < vect.size(); j++)
		wcout << endl << vect[j];

	wcout << endl;

	return 0;
}