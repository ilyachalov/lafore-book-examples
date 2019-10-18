// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrobjs.cpp
// массив указателей на объекты

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class person // класс, представляющий человека
{
private:
	wchar_t name[40]; // имя человека
public:
	void setName() // получение от пользователя данных объекта
	{
		wcout << L"Введите имя: ";
		wcin >> name;
	}
	void printName() const // вывод на экран данных объекта
	{
		wcout << L"\n Имя: " << name;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	person* persPtr[100]; // массив указателей на объекты класса «человек»
	int n = 0;            // количество людей в массиве
	wchar_t choice;

	// заполним массив объектами класса «человек»
	do
	{
		persPtr[n] = new person;             // создаем новый объект
		persPtr[n]->setName();               // получаем от пользователя имя человека
		n++;                                 // засчитаем нового человека
		wcout << L"Продолжаем ввод (д/н)? "; // спрашиваем, закончен ли ввод
		wcin >> choice;
	} while (choice == L'д');

	// выведем на экран данные всех объектов, введенных ранее
	for (int j = 0; j < n; j++)
	{
		wcout << L"\nДанные человека под номером " << j + 1;
		persPtr[j]->printName();
	}
	wcout << endl;

	return 0;
}