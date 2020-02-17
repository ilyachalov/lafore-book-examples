// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 12chapter_01exercise.cpp
// Имеется класс Distance (интервал в английских мерах длины) из примера
// 233_englcon.cpp 6-й главы. Требуется с помощью цикла из функции main примера
// 561_diskfun.cpp текущей (12-й) главы получить от пользователя множество
// значений класса Distance и добавить их к записанным в файл ранее, затем
// считать из этого файла все записанные в него значения и отобразить их на экране.

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	int feet;     // футы
	float inches; // дюймы
public:
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
		{ }
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	void getdist() // ввод полей с клавиатуры
	{
		wcout << L"\n введите число футов: "; wcin >> feet;
		wcout << L" введите число дюймов: "; wcin >> inches;
	}
	void showdist() // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t ch;                    // для ответа пользователя (д/н)
	Distance dist;                 // создать объект класса Distance
	fstream file;                  // создать поток и для записи, и для чтения
								   // открыть файл для дозаписи
	file.open(L"группа объектов.dat", ios::app | ios::out | ios::in | ios::binary);

	do // получим данные объектов от пользователя и запишем в файл
	{
		wcout << L"Введите данные интервала:";
		dist.getdist();            // получить данные одного объекта
								   // записать их в файл
		file.write(reinterpret_cast<char*>(&dist), sizeof(dist));
		wcout << L"\nПродолжить ввод (д/н)? ";
		wcin >> ch; wcout << endl;
	} while (ch == L'д');          // выход по 'н'

	file.seekg(0);                 // поставить указатель позиции на начало файла
								   // считать данные о первом интервале
	file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
	int count = 0;
	while (!file.eof())            // выход из цикла по EOF (конец файла)
	{
		wcout << L"Интервал " << ++count << L": ";    // вывести данные интервала на экран
		dist.showdist(); wcout << endl;
		// считать данные следующего интервала
		file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
	}

	return 0;
}