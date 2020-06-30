// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// outiter.cpp
// демонстрирует применение объекта класса ostream_iterator

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
// #include <algorithm> // не понадобился
#include <list>         // для работы с контейнером list
#include <iterator>     // для работы с классом ostream_iterator
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int arr[] = { 10, 20, 30, 40, 50 };
	list<int> theList;

	for (int j = 0; j < 5; j++)                   // перенесём массив в список
		theList.push_back(arr[j]);
	                                              // итератор потока вывода:
	// ostream_iterator<int> ositer(cout, ", ");         // вариант из книги
	ostream_iterator<int, wchar_t> ositer(wcout, L", "); // исправленный вариант

	// Тут требуется пояснение. Класс ostream_iterator — шаблонный и ему можно
	// задать несколько параметров. В книге Лафоре задан один параметр — <int>,
	// а второй не задан; в этом случае вторым параметром подразумевается тип
	// char, это тип символов для потока вывода. У нас же потоком вывода является
	// wcout, поэтому второй параметр указываем явно — wchar_t.

	wcout << L"Содержимое списка: ";
	copy(theList.begin(), theList.end(), ositer); // вывод списка на экран

	wcout << endl;
	
	return 0;
}