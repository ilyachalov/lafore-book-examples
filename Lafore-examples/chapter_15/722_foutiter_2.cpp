// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// foutiter_2.cpp
// демонстрирует применение объекта класса ostream_iterator к файлам

// Я добавил к программе из учебника Лафоре вывод в файл фразы "Содержимое
// списка: ". Для вывода в файл букв русского алфавита в кодировке UTF-8
// я добавил определение константы utf8_locale и связывание этой константы
// с потоком outfile с помощью метода imbue. Также для работы с соответствующим
// фасетом локали потребовалось подключить заголовочный файл <codecvt>. Для
// вывода в файл символов-цифр и букв латинского алфавита этого всего
// не требуется.

#include <fstream>
// #include <algorithm> // не понадобился
#include <list>         // для работы с контейнером list
#include <iterator>     // для работы с классом ostream_iterator
#include <codecvt>      // для работы с фасетом codecvt_utf8 локали
using namespace std;

int main()
{
	int arr[] = { 11, 21, 31, 41, 51 };
	list<int> theList;

	for (int j = 0; j < 5; j++)                   // перенесём массив в список
		theList.push_back(arr[j]);

	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при сохранении в файл в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	                                              // создаём файловый объект
	wofstream outfile(L"Вывод с помощью итератора.dat");
	outfile.imbue(utf8_locale);                   // связываем поток с локалью

	                                              // итератор потока вывода
	ostream_iterator<int, wchar_t> ositer(outfile, L" ");

	outfile << L"Содержимое списка: ";
	copy(theList.begin(), theList.end(), ositer); // вывод списка в файл
	
	return 0;
}