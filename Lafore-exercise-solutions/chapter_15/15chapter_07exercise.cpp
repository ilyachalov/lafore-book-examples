// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 15chapter_07exercise.cpp
// Имеется программа из примера 739_plusair.cpp этой (15-й) главы. В этой
// программе вычисляется сумма объектов класса airtime, представляющих время
// вылета и прибытия самолетов в аэропорту, с помощью варианта алгоритма
// accumulate с 4-мя аргументами. Объекты класса airtime изначально получаем
// от пользователя и храним в списке. Требуется переписать эту программу так,
// чтобы в ней использовался вариант алгоритма accumulate с 3-мя аргументами.

// Задание оказалось очень легко выполнить: достаточно подкорректировать
// всего лишь одну строку.

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <list>         // для работы с контейнером list
#include <numeric>      // для алгоритма accumulate
using namespace std;

class airtime // класс: время вылета и прибытия самолетов в аэропорту
{
private:
	int hours;   // часы (от 0 до 23 включительно)
	int minutes; // минуты (от 0 до 59 включительно)
public:
	airtime() : hours(0), minutes(0)        // конструктор по умолчанию
		{ }
	                                        // конструктор с двумя аргументами
	airtime(int h, int m) : hours(h), minutes(m)
		{ }
	void display() const                    // вывод на экран
		{ wcout << hours << L':' << minutes; }
	void get()                              // получение данных у пользователя
	{
		wchar_t dummy;
		wcout << L"\nВведите время (формат 12:59): ";
		wcin >> hours >> dummy >> minutes;
	}
	                                        // перегрузка операции + («сложение»)
	airtime operator+ (const airtime right) const
	{
		int temph = hours + right.hours;    // складываем поля объектов-параметров
		int tempm = minutes + right.minutes;
		if (tempm >= 60)                    // проверяем наличие переноса
			{ temph++; tempm -= 60; }
		return airtime(temph, tempm);       // возвращаем сумму
	}
	                                        // перегрузка операции == («равно»)
	bool operator== (const airtime& at2) const
		{ return (hours == at2.hours) && (minutes == at2.minutes); }
	                                        // перегрузка операции < («меньше»)
	bool operator< (const airtime& at2) const
		{ return (hours < at2.hours) ||
			(hours == at2.hours && minutes < at2.minutes); }
	                                        // перегрузка операции != («не равно»)
	bool operator!= (const airtime& at2) const
		{ return !(*this == at2); }
	                                        // перегрузка операции > («больше»)
	bool operator> (const airtime& at2) const
		{ return !(*this < at2) && !(*this == at2); }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t answer;
	airtime temp, sum;
	list<airtime> airlist;                  // список объектов класса airtime

	do {                                    // получим значения объектов
		temp.get();                         // класса airtime от пользователя
		airlist.push_back(temp);            // и поместим их в список
		wcout << L"Продолжить (д/н)? ";
		wcin >> answer;
	} while (answer != L'н');
	                                        // вычислим сумму объектов в списке
	// sum = accumulate(airlist.begin(), airlist.end(), airtime(0, 0), plus<airtime>());
	sum = accumulate(airlist.begin(), airlist.end(), airtime(0, 0));

	// Отмечу, что для выполнения задания понадобилось лишь убрать четвертый
	// аргумент из вызова алгоритма. Закомментированная строка — это то, что
	// было, а за нею написана новая, исправленная, строка.

	wcout << L"\nСумма = ";
	sum.display();                          // выведем сумму на экран

	wcout << endl;
	
	return 0;
}