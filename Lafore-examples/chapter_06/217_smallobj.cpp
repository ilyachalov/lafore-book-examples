// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// smallobj.cpp
// демонстрирует простой небольшой объект

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class smallobj          // определение класса
{
private:
	int somedata;       // поле класса
public:
	void setdata(int d) // метод класса, изменяющий значение поля
	{ somedata = d; }
	void showdata()     // метод класса, отображающий значение поля
	{ wcout << L"Значение поля равно " << somedata << endl; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	smallobj s1, s2;  // определение двух объектов класса smallobj

	s1.setdata(1066); // вызовы метода setdata()
	s2.setdata(1776);
	s1.showdata();    // вызовы метода showdata()
	s2.showdata();

	return 0;
}