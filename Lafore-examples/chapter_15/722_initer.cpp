// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// initer.cpp
// демонстрирует применение объекта класса istream_iterator

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <list>         // для работы с контейнером list
// #include <algorithm> // не понадобился
#include <iterator>     // для работы с классами istream_iterator
                        // и ostream_iterator
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	list<float> fList(5);                  // неинициализированный список

	wcout << L"Введите 5 вещественных чисел: ";
	                                       // итераторы потока ввода:
	istream_iterator<float, wchar_t> cin_iter(wcin); // wcin
	istream_iterator<float, wchar_t> end_of_stream;  // eos (конец потока)
	                                       // копируем из wcin в fList
	copy(cin_iter, end_of_stream, fList.begin());

	// Пользователю после ввода через пробел пяти вещественных чисел будет
	// необходимо нажать сочетание клавиш Ctrl+Z, чтобы послать в поток ввода
	// wcin символ конца потока. Только после этого необходимо нажать клавишу
	// Enter, чтобы закончить ввод. После этого программа продолжит работу
	// согласно инструкций ниже этого комментария и выведет на экран
	// содержимое списка fList.

	                                       // вывести на экран содержимое fList
	ostream_iterator<float, wchar_t> ositer(wcout, L"--");
	copy(fList.begin(), fList.end(), ositer);

	wcout << endl;
	
	return 0;
}