// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englen.cpp
// наследование на примере класса, представляющего английские меры длины

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

// перечисление для хранения знака в классе DistSign
enum posneg {pos, neg};

class Distance // длина в английской системе (базовый класс)
{
protected:        // ЗАМЕТЬТЕ: не может быть private для базового класса
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
		wcout << L"Введите число футов: "; wcin >> feet;
		wcout << L"Введите число дюймов: "; wcin >> inches;
	}
	void showdist() const // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
};

// Производный класс от базового класса Distance, представляющего длину в английской
// системе. Добавлен знак интервала, теперь интервалы могут быть как положительными,
// что подразумевалось в базовом классе, так и отрицательными.
class DistSign : public Distance
{
private:
	posneg sign; // может быть pos (положительным) или neg (отрицательным)
public:
	// конструктор без аргументов
	DistSign() : Distance()
		{ sign = pos; }
	// конструктор с двумя или тремя аргументами
	DistSign(int ft, float in, posneg sg = pos) : Distance(ft, in)
		{ sign = sg; }
	void getdist() // ввод полей с клавиатуры
	{
		Distance::getdist(); // вызов метода getdist базового класса
		wchar_t ch;          // запрос знака
		wcout << L"Введите знак (+ или -): "; wcin >> ch;
		sign = (ch == L'+') ? pos : neg;
	}
	void showdist() const // вывод полей на экран
	{
		// вывод всей информации, включая знак
		wcout << ((sign == pos) ? L"(+)" : L"(-)");
		Distance::showdist();
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	DistSign alpha;                       // конструктор без аргументов
	alpha.getdist();                      // получим данные от пользователя

	DistSign beta(11, 6.25);              // конструктор с двумя аргументами

	DistSign gamma(100, 5.5, neg);        // конструктор с тремя аргументами
	
	wcout << L"\nA = "; alpha.showdist(); // выведем на экран все интервалы
	wcout << L"\nB = "; beta.showdist();
	wcout << L"\nC = "; gamma.showdist(); wcout << endl;

	return 0;
}