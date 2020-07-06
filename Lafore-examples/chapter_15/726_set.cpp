// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// set.cpp
// множество, хранящее строковые объекты (класса wstring)

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
	
	                                // массив строковых объектов
	wstring names[] = { L"Хуанита", L"Роберт", L"Мэри", L"Аманда", L"Мария" };
	                                // инициализируем множество массивом
	set<wstring, less<wstring>> nameSet(names, names + 5);
	                                // итератор для множества
	set<wstring, less<wstring>>::iterator iter;

	nameSet.insert(L"Иветта");      // вставка элементов
	nameSet.insert(L"Ларри");
	nameSet.insert(L"Роберт");      // никакого эффекта: такой элемент уже имеется
	nameSet.insert(L"Барри");
	nameSet.erase(L"Мэри");         // удаление элемента
	                                // вывести на экран размер множества
	wcout << L"Размер = " << nameSet.size() << endl;
	iter = nameSet.begin();         // вывести на экран элементы множества
	while (iter != nameSet.end())
		wcout << *iter++ << L'\n';

	wstring searchName;             // получение искомого имени от пользователя
	wcout << L"\nВведите искомое имя: ";
	wcin >> searchName;
	                                // поиск соответствующего запросу имени
	iter = nameSet.find(searchName);
	if (iter == nameSet.end())
		wcout << L"Имя " << searchName << L" ОТСУТСТВУЕТ во множестве.";
	else
		wcout << L"Имя " << *iter << L" ПРИСУТСТВУЕТ во множестве.";

	wcout << endl;
	
	return 0;
}