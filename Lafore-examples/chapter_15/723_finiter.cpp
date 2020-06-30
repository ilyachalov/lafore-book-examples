// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// finiter.cpp
// демонстрирует применение объекта класса istream_iterator к файлам

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <list>         // для работы с контейнером list
#include <fstream>
// #include <algorithm> // не понадобился
#include <iterator>     // для работы с классами istream_iterator
                        // и ostream_iterator
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	list<int> iList;                       // пустой список

	                                       // создаём входной файловый объект
	                                       // (этот файл должен уже существовать)
	wifstream infile(L"Вывод с помощью итератора.dat");

	                                       // итераторы потока ввода:
	istream_iterator<int, wchar_t> file_iter(infile); // файл
	istream_iterator<int, wchar_t> end_of_stream;     // eos (конец потока)

	                                       // копируем из infile в iList
	copy(file_iter, end_of_stream, back_inserter(iList));

	                                       // вывести на экран содержимое iList
	ostream_iterator<int, wchar_t> ositer(wcout, L"--");
	copy(iList.begin(), iList.end(), ositer);

	wcout << endl;
	
	return 0;
}