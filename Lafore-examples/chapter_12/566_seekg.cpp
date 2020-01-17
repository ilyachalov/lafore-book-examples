// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// seekg.cpp
// поиск конкретного объекта класса person в файле

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

	person pers;                   // создать объект класса person
	ifstream infile;               // создать входной поток
	                               // связать поток с файлом и открыть его
	infile.open(L"группа объектов.dat", ios::in | ios::binary);

	infile.seekg(0, ios::end);     // установим указатель чтения
	                               // на 0 байт от конца файла
	int endposition = infile.tellg();     // запомним эту позицию
	int n = endposition / sizeof(person); // число объектов, записанных в файл
	wcout << L"\nВ файле содержатся данные " << n << L" персон(ы)";

	wcout << L"\nВведите номер персоны: ";
	wcin >> n;
	                               // вычислим позицию в файле, в которой
	                               // содержится объект с заданным номером
	int position = (n - 1) * sizeof(person);
	infile.seekg(position);        // перейдем в вычисленную позицию
	                               // прочитаем из файла один объект
	infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	pers.showData();               // выведем прочитанный объект на экран
	wcout << endl;

	return 0;
}