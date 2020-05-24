// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// xdist2.cpp
// применение исключений (с аргументами) в классе Distance

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <string>
using namespace std;

class Distance       // класс отрезка в английских мерах длины
{
private:
	int feet;        // футы (1 фут = 12 дюймов)
	float inches;    // дюймы (не может быть равно или больше 12.0)
public:
	class InchesEx                  // класс исключения
	{
	public:
		wstring origin; // для имени функции, в которой произошла ошибка
		float iValue;   // для ошибочного количества дюймов

		InchesEx(wstring ori, float in) // конструктор с двумя аргументами
		{
			origin = ori; // сохраняем имя функции, в которой произошла ошибка
			iValue = in;  // сохраняем ошибочное количество дюймов
		}
	};
	
	Distance()                      // конструктор (без аргументов)
		{ feet = 0; inches = 0.0; }
	
	Distance(int ft, float in)      // конструктор (с двумя аргументами)
	{
		if (in >= 12.0)             // если количество дюймов слишком большое,
									// генерировать исключение
			throw InchesEx(L"конструктор (с двумя аргументами)", in);
		feet = ft;
		inches = in;
	}
	
	void getdist()                  // получить длину отрезка от пользователя
	{
		wcout << L"\nВведите футы: "; wcin >> feet;
		wcout << L"Введите дюймы: "; wcin >> inches;
		if (inches >= 12.0)         // если количество дюймов слишком большое,
									// генерировать исключение
			throw InchesEx(L"метод getdist()", inches);
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
	catch (Distance::InchesEx ix)   // обработчик исключения
	{
		wcout << L"\nОшибка инициализации в функции: " << ix.origin
			<< L".\n Введенное количество дюймов " << ix.iValue
			<< L" слишком большое.";
	}
	
	wcout << endl;
	
	return 0;
}