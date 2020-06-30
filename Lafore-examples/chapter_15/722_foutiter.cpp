// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// foutiter.cpp
// демонстрирует применение объекта класса ostream_iterator к файлам

#include <fstream>
// #include <algorithm> // не понадобился
#include <list>         // для работы с контейнером list
#include <iterator>     // для работы с классом ostream_iterator
using namespace std;

int main()
{
	int arr[] = { 11, 21, 31, 41, 51 };
	list<int> theList;

	for (int j = 0; j < 5; j++)                   // перенесём массив в список
		theList.push_back(arr[j]);
	                                              // создаём файловый объект
	wofstream outfile(L"Вывод с помощью итератора.dat");
	                                              // итератор потока вывода
	ostream_iterator<int, wchar_t> ositer(outfile, L" ");

	copy(theList.begin(), theList.end(), ositer); // вывод списка в файл
	
	return 0;
}