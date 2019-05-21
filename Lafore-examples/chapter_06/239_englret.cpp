// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englret.cpp
// возвращение функцией объекта класса Distance

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
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
		wcout << L"Введите число футов: "; wcin >> feet;
		wcout << L"Введите число дюймов: "; wcin >> inches;
	}
	void showdist() // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
	Distance add_dist(Distance); // сложение (прототип функции)
};

// сложение данного объекта с объектом d, возврат суммы, тоже объекта
Distance Distance::add_dist(Distance d)
{
	Distance temp;                   // временная переменная
	temp.inches = inches + d.inches; // сложение дюймов
	if (temp.inches >= 12.0)         // если сумма дюймов больше или равна 12.0,
	{                                // то уменьшаем ее на
		temp.inches -= 12.0;         // 12.0 и увеличиваем
		temp.feet = 1;               // число футов на 1
	}
	temp.feet += feet + d.feet;      // сложение футов
	return temp;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	// определение двух длин с конструктором без аргументов
	Distance dist1, dist3;
	// определение и инициализация длины с конструктором с аргументами
	Distance dist2(11, 6.25);
	
	dist1.getdist(); // ввод dist1 пользователем

	dist3 = dist1.add_dist(dist2); // dist3 = dist1 + dist2

	// вывод всех длин на экран
	wcout << L"dist1 = "; dist1.showdist();
	wcout << L"\ndist2 = "; dist2.showdist();
	wcout << L"\ndist3 = "; dist3.showdist();
	wcout << endl;

	return 0;
}