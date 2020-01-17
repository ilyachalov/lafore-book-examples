// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// diskfun.cpp
// запись в файл на диске и чтение из него множества объектов

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

class person // класс, представляющий человека
{
protected:
	wchar_t name[80]; // имя человека
	int age;          // и его возраст
public:
	void getData()    // получение от пользователя данных объекта
	{
		wcout << L"\n введите имя: "; wcin >> name;
		wcout << L" введите возраст: "; wcin >> age;
	}
	void showData()   // вывести данные объекта на экран
	{
		wcout << L"\n Имя: " << name;
		wcout << L"\n Возраст: " << age;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t ch;                    // для ответа пользователя (д/н)
	person pers;                   // создать объект класса person
	fstream file;                  // создать поток и для записи, и для чтения
	                               // открыть файл для дозаписи
	file.open(L"группа объектов.dat", ios::app | ios::out | ios::in | ios::binary);
	
	do // получим данные объекта от пользователя и запишем в файл
	{
		wcout << L"\nВведите данные человека:";
		pers.getData();            // получить данные одного объекта
		                           // записать их в файл
		file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
		wcout << L"\nПродолжить ввод (д/н)? ";
		wcin >> ch;
	} while (ch == L'д');          // выход по 'н'

	file.seekg(0);                 // поставить указатель позиции на начало файла
	                               // считать данные о первом человеке
	file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	while (!file.eof())            // выход из цикла по EOF (конец файла)
	{
		wcout << L"\nПерсона:";    // вывести данные человека на экран
		pers.showData();
		                           // считать данные следующего человека
		file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	}
	wcout << endl;

	return 0;
}