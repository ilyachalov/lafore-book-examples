// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englconv.cpp
// перевод длины из объекта класса Distance в метры (значение типа float) и обратно

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	const float MTF; // коэффициент перевода метров в футы
	                 // (1 метр = MTF футов)
	int feet;        // футы
	float inches;    // дюймы
public:
	// конструктор без параметров
	Distance() : feet(0), inches(0.0), MTF(3.280833F)
		{ }
	// конструктор с одним параметром, переводящий метры в футы и дюймы
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;   // переводим в футы
		feet = int(fltfeet);            // берем число полных футов
		inches = 12 * (fltfeet - feet); // остаток — это дюймы
	}
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F)
		{ }
	void getdist() // ввод полей с клавиатуры
	{
		wcout << L"Введите число футов: "; wcin >> feet;
		wcout << L"Введите число дюймов: "; wcin >> inches;
	}
	void showdist() const // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
	// оператор перевода в метры из футов и дюймов
	operator float() const
	{
		float fracfeet = inches / 12;         // переводим дюймы в футы
		fracfeet += static_cast<float>(feet); // добавляем целые футы
		return fracfeet / MTF;                // переводим в метры
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	float mtrs; // для хранения длины в метрах
	
	// используется конструктор с одним параметром, переводящий метры в футы и дюймы
	Distance dist1 = 2.35F; // 2.35 метров
	// выведем значение объекта dist1 в футах и дюймах, эквивалентное 2.35 метрам
	wcout << L"dist1 = "; dist1.showdist();

	// ЯВНО используем оператор перевода в метры
	mtrs = static_cast<float>(dist1);
	// и выведем результат
	wcout << L"\ndist1 = " << mtrs << L" метров";

	Distance dist2(5, 10.25); // используем конструктор с двумя параметрами

	// НЕЯВНО используем оператор перевода в метры
	mtrs = dist2;
	// и выведем результат
	wcout << L"\ndist2 = " << mtrs << L" метров" << endl;

	// dist2 = mtrs; // а вот это ошибка – так делать нельзя

	return 0;
}