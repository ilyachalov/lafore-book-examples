// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// statfunc.cpp
// статические функции и нумерация объектов класса

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
using namespace std;

class gamma
{
private:
	static int total; // счетчик объектов класса (только объявление)
	int id;           // номер объекта
public:
	gamma()  // конструктор без аргументов
	{
		total++;    // увеличить счетчик объектов
		id = total; // номер объекта — это текущее значение счетчика объектов
	}
	~gamma() // деструктор
	{
		total--;    // уменшить счетчик объектов
		wcout << L"Удален объект с номером " << id << endl;
	}
	static void showtotal() // статическая функция
		{ wcout << L"Всего объектов: " << total << endl; }
	void showid()           // нестатическая функция
		{ wcout << L"Номер объекта: " << id << endl; }
};

int gamma::total = 0; // счетчик объектов класса (определение)

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	gamma g1;
	gamma::showtotal();

	gamma g2, g3;
	gamma::showtotal();

	g1.showid();
	g2.showid();
	g3.showid();
	wcout << L"---------- конец программы ----------\n";

	return 0;
}