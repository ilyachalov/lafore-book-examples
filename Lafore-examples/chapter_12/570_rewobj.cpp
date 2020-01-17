// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// rewobj.cpp
// объекты класса person выполняют файловый ввод/вывод

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

class person // класс, представляющий человека (персону)
{
protected:
	wchar_t name[40]; // фамилия человека
	int age;          // и его возраст
public:
	void getData()          // получает от пользователя данные объекта
	{
		wcout << L"\n Введите фамилию: "; wcin >> name;
		wcout << L" Введите возраст: "; wcin >> age;
	}
	void showData()         // выводит данные объекта на экран
	{
		wcout << L"\n Фамилия: " << name;
		wcout << L"\n Возраст: " << age;
	}
	void diskIn(int);       // читает объект из файла
	void diskOut();         // записывает объект в конец файла
	static int diskCount(); // возвращает число человек в файле
};

// метод читает из файла данные о человеке с номером pn
void person::diskIn(int pn)
{
	ifstream infile;                         // создать поток
	infile.open(L"Файл с данными о людях.dat", ios::binary); // открыть его
	infile.seekg(pn * sizeof(person));       // сдвиг файлового указателя
	                                         // на данные человека с номером pn
	infile.read((char*)this, sizeof(*this)); // чтение данных об одном человеке
}

// метод записывает объект в конец файла
void person::diskOut()
{
	ofstream outfile;                          // создать поток
	                                           // открыть его
	outfile.open(L"Файл с данными о людях.dat", ios::app | ios::binary);
	outfile.write((char*)this, sizeof(*this)); // записать в него
}

// метод возвращает число человек в файле
int person::diskCount()
{
	ifstream infile;
	infile.open(L"Файл с данными о людях.dat", ios::binary);
	infile.seekg(0, ios::end); // перейти в позицию 0 байт от конца файла
	                           // вычислить число человек в файле
	return (int)infile.tellg() / sizeof(person);
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	person p;   // создать пустой объект класса person
	wchar_t ch;

	do { // запись в файл полученных от пользователя данных по людям
		wcout << L"Введите данные человека:";
		p.getData();             // получить данные
		p.diskOut();             // записать на диск
		wcout << L"Продолжить (д/н)? ";
		wcin >> ch;
	} while (ch == L'д');        // цикл до ввода пользователем 'н' (нет)

	int n = person::diskCount(); // сколько человек в файле?
	wcout << L"В файле " << n << L" человек(а)\n";
	for (int j = 0; j < n; j++)  // для каждого из них
	{
		wcout << L"\nПерсона " << j;
		p.diskIn(j);             // прочитать объект из файла
		p.showData();            // вывести его данные на экран
	}
	wcout << endl;

	return 0;
}