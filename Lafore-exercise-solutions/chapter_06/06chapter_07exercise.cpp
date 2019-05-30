// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_07exercise.cpp
// создать класс angle, представляющий широту или долготу координаты точки
// в морской навигации

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

class angle // класс, представляющий широту или долготу координаты точки в морской навигации
{
private:
	int degrees;   // число градусов (1 градус = 60 минут)
	float minutes; // число минут (вместо секунд — разбивка на десятичные части минут)
	wchar_t dirLetter; // символ направления (N или S для широты; Е или W для долготы)
public:
	// конструктор с аргументами
	angle(int d, float m, wchar_t dl) : degrees(d), minutes(m), dirLetter(dl)
		{ }
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wcout << L"Введите число градусов, минут и символ направления: ";
		wcin >> degrees >> minutes >> dirLetter;
	}
	// константный метод выводит значения полей на экран
	void display() const
		{ wcout << degrees << L'\xB0' << fixed << setprecision(1) << minutes << L"\' " << dirLetter; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	wchar_t ch; // для ответа пользователя на вопрос о выходе из цикла
	angle latitude(17, 31.5, L'S'), // создание двух объектов класса angle
		  longitude(149, 34.8, L'W');

	// выводим значения созданных объектов на экран
	wcout << L"Координаты гавани города Папеэте на острове Таити:\n";
	wcout << L"широта: "; latitude.display();
	wcout << L", долгота: "; longitude.display();
	wcout << endl;

	// циклически просим пользователя ввести координаты точек для морской навигации
	// и отображаем введенные координаты точек на экране
	do {
		wcout << L"\nШирота. "; latitude.get();
		wcout << L"Долгота. "; longitude.get();
		wcout << L"Вы ввели следующие координаты точки в морской навигации:\n";
		wcout << L"широта: "; latitude.display();
		wcout << L", долгота: "; longitude.display();
		wcout << endl;

		wcout << L"\nПродолжить ввод координат? (д/н) "; wcin >> ch;
	} while (ch != L'н'); // выход из цикла, если пользователь ответил "нет"

	return 0;
}