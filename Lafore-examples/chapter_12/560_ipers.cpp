// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ipers.cpp
// чтение объекта класса person из файла

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

class person // класс, представляющий человека
{
protected:
	wchar_t name[80]; // имя человека
	short age;        // и его возраст
public:
	void showData()   // вывести данные объекта на экран
	{
		wcout << L"Имя: " << name << endl;
		wcout << L"Возраст: " << age << endl;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	person pers;     // создать объект класса person
	                 // создать входной поток (связанный с файлом)
	ifstream infile(L"человек.dat", ios::binary);
	                 // чтение из файла объекта класса person
	infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	pers.showData(); // вывести данные объекта класса person на экран

	return 0;
}