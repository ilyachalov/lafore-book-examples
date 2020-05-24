// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// xdist.cpp
// применение исключений в классе Distance

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Distance       // класс отрезка в английских мерах длины
{
private:
	int feet;        // футы (1 фут = 12 дюймов)
	float inches;    // дюймы (не может быть равно или больше 12.0)
public:
	class InchesEx { };             // класс исключения
	
	Distance()                      // конструктор (без аргументов)
		{ feet = 0; inches = 0.0; }
	
	Distance(int ft, float in)      // конструктор (с двумя аргументами)
	{
		if (in >= 12.0)             // если количество дюймов слишком большое,
			throw InchesEx();       // генерировать исключение
		feet = ft;
		inches = in;
	}
	
	void getdist()                  // получить длину отрезка от пользователя
	{
		wcout << L"\nВведите футы: "; wcin >> feet;
		wcout << L"Введите дюймы: "; wcin >> inches;
		if (inches >= 12.0)         // если количество дюймов слишком большое,
			throw InchesEx();       // генерировать исключение
	}
	
	void showdist()                 // вывод на экран длины отрезка
		{ wcout << feet << L"\'-" << inches << L'\"'; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	try
	{
		Distance dist1(17, 3.5);    // конструктор (с двумя аргументами)
		Distance dist2;             // конструктор (без аргументов)
		dist2.getdist();            // получить длину отрезка от пользователя
		                            // вывести на экран длины отрезков
		wcout << L"\ndist1 = "; dist1.showdist();
		wcout << L"\ndist2 = "; dist2.showdist();
	}
	catch (Distance::InchesEx)      // поймать исключения
	{
		wcout << L"\nОшибка инициализации: количество дюймов превышает предельно "
			"допустимое!";
	}
	
	wcout << endl;
	
	return 0;
}