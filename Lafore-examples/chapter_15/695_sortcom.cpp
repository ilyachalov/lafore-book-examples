// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sortcom.cpp
// сортирует массив строк с помощью пользовательской функции сравнения

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
// #include <string> // для функции wcscmp не понадобился
#include <algorithm> // для алгоритма sort
using namespace std;

// тестовый массив строк
const wchar_t* names[] = { L"Сергей", L"Татьяна", L"Елена", L"Дмитрий",
                           L"Михаил", L"Владимир" };

// объявление пользовательской функции
bool alpha_comp(const wchar_t*, const wchar_t*);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	sort(names, names + 6, alpha_comp); // сортировка строк в массиве
	                                    // по алфавиту (по возрастанию)

	for (int j = 0; j < 6; j++)         // вывод массива на экран
		wcout << names[j] << endl;
	
	return 0;
}

// пользовательская функция: возвращает true, если s1 < s2
bool alpha_comp(const wchar_t* s1, const wchar_t* s2)
{
	return (wcscmp(s1, s2) < 0) ? true : false;
}