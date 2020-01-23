// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englio.cpp
// перегрузка операторов вставки (<<) и извлечения (>>) для реализации
// вывода на экран и ввода с клавиатуры объектов класса Distance

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Distance // интервал (длина) в английской системе мер
{
private:
	int feet;     // футы (1 фут = 12 дюймов)
	float inches; // дюймы
public:
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
		{ }
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	friend wistream& operator>>(wistream& s, Distance& d);
	friend wostream& operator<<(wostream& s, Distance& d);
};

// получение интервала от пользователя
// с помощью перегрузки оператора извлечения (>>)
wistream& operator>>(wistream& s, Distance& d)
{
	wcout << L"\nВведите футы: "; s >> d.feet;
	wcout << L"Введите дюймы: "; s >> d.inches;
	return s;
}

// вывод интервала на экран
// с помощью перегрузки оператора вставки (<<)
wostream& operator<<(wostream& s, Distance& d)
{
	s << d.feet << L"\'-" << d.inches << L'\"';
	return s;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance dist1, dist2;            // определим два интервала
	Distance dist3(11, 6.25);         // определим и инициализируем dist3

	wcout << L"Введите два интервала:\n";
	wcin >> dist1 >> dist2;           // получим два интервала от пользователя
	                                  // и выведем все три интервала на экран
	wcout << L"\ndist1 = " << dist1 << L"\ndist2 = " << dist2;
	wcout << L"\ndist3 = " << dist3 << endl;
	
	return 0;
}