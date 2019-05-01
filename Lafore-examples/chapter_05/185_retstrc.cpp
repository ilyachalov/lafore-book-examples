// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// retstrc.cpp
// демонстрирует возвращение функцией структурной переменной

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;
	float inches;
};

Distance addengl(Distance, Distance); // прототипы функций
void engldisp(Distance);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance d1, d2, d3; // три структурные переменные
	
	// ввод значения d1
	wcout << L"Введите число футов: "; wcin >> d1.feet;
	wcout << L"Введите число дюймов: "; wcin >> d1.inches;
	// ввод значения d2
	wcout << L"Введите число футов: "; wcin >> d2.feet;
	wcout << L"Введите число дюймов: "; wcin >> d2.inches;
	
	d3 = addengl(d1, d2); // d3 равно сумме d1 и d2
	
	wcout << endl;
	engldisp(d1); wcout << L" + "; // вывод всех длин
	engldisp(d2); wcout << L" = ";
	engldisp(d3); wcout << endl;

	return 0;
}

//--------------------------------------------------------
// функция addengl()
// складывает два значения типа Distance и возвращает сумму
Distance addengl(Distance dd1, Distance dd2)
{
	Distance dd3;                         // переменная для хранения будущей суммы
	dd3.inches = dd1.inches + dd2.inches; // сложение дюймов
	dd3.feet = 0;                         // с заемом;
	if (dd3.inches >= 12.0)               // если число дюймов больше 12.0,
	{                                     // то уменьшаем число дюймов
		dd3.inches -= 12.0;               // на 12.0 и увеличиваем
		dd3.feet++;                       // число футов на 1
	}
	dd3.feet += dd1.feet + dd2.feet;      // сложение футов
	return dd3;                           // возврат значения
}

//--------------------------------------------------------
// функция engldisp()
// отображает поля структурной переменной Distance
void engldisp(Distance dd)
{
	wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}