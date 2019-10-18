// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englref.cpp
// разыменование указателя, возвращаемого оператором new

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Distance // класс, представляющий интервал в английских мерах длины
{
private:
	int feet;     // футы (1 фут = 12 дюймов)
	float inches; // дюймы
public:
	void getdist()        // получение длины интервала от пользователя
	{
		wcout << L"Введите футы: "; wcin >> feet;
		wcout << L"Введите дюймы: "; wcin >> inches;
	}
	void showdist() const // вывод на экран длины интервала
	{
		wcout << feet << L"\'-" << inches << L'\"';
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance& dist = *(new Distance); // выделяем память под объект класса Distance,
	                                  // затем с помощью операции разыменования (*)
	                                  // получаем сам объект и создаем для обращения
	                                  // к нему псевдоним (ссылку) dist

	dist.getdist();         // получаем доступ к членам объекта
	dist.showdist();        //     через операцию точки
	wcout << endl;

	return 0;
}