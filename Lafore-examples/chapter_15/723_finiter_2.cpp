// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// finiter_2.cpp
// демонстрирует применение объекта класса istream_iterator к файлам

// Я добавил к программе из учебника Лафоре получение из файла фразы "Содержимое
// списка: ". Для получения из файла букв русского алфавита в кодировке UTF-8
// я добавил определение константы utf8_locale и связывание этой константы
// с потоком infile с помощью метода imbue. Также для работы с соответствующим
// фасетом локали потребовалось подключить заголовочный файл <codecvt>. Для
// получения из файла символов-цифр и букв латинского алфавита этого всего
// не требуется.

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <list>         // для работы с контейнером list
#include <fstream>
// #include <algorithm> // не понадобился
#include <iterator>     // для работы с классами istream_iterator
                        // и ostream_iterator
#include <string>       // для работы с классом wstring
#include <codecvt>      // для работы с фасетом codecvt_utf8 локали
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	list<int> iList;                       // пустой список

	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при чтении из файла в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	                                       // создаём входной файловый объект
	                                       // (этот файл должен уже существовать)
	wifstream infile(L"Вывод с помощью итератора.dat");
	infile.imbue(utf8_locale);             // связываем наш поток с нужной локалью

	wstring str;                           // получим из файла infile фразу
	infile >> str; wcout << str << L" ";   // "Содержимое "
	infile >> str; wcout << str << L" ";   // "списка: "

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