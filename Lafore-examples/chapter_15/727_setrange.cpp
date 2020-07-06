// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// setrange.cpp
// тестирует работу с диапазонами во множестве

// #pragma warning (disable:4786) // для работы со множествами
                                  // (только для компиляторов Microsoft)
                                  // эта директива не понадобилась

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <set>          // для работы с контейнером set
#include <string>       // для работы с классом wstring
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	                                // множество объектов класса wstring
	set<wstring, less<wstring>> organic;
	                                // итератор множества
	set<wstring, less<wstring>>::iterator iter;

	organic.insert(L"Курин");       // вставляем во множество элементы,
	organic.insert(L"Ксантин");     // представляющие из себя названия
	organic.insert(L"Курарин");     // органических химических соединений
	organic.insert(L"Меламин");
	organic.insert(L"Цианамид");
	organic.insert(L"Фенол");
	organic.insert(L"Афродин");
	organic.insert(L"Имидазол");
	organic.insert(L"Цинхонин");
	organic.insert(L"Пальмитамид");
	organic.insert(L"Цианамид");

	iter = organic.begin();         // выводим множество на экран
	while (iter != organic.end())
		wcout << *iter++ << L'\n';

	wstring lower, upper;           // выводим значения из диапазона на экран
	wcout << L"\nВведите диапазон (пример: А Ксб): ";
	wcin >> lower >> upper;
	iter = organic.lower_bound(lower);
	while (iter != organic.upper_bound(upper))
		wcout << *iter++ << L'\n';
	
	return 0;
}