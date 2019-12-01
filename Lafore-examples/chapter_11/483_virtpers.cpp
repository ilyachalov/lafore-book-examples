// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// virtpers.cpp
// виртуальные функции и класс person

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class person // класс, представляющий человека
{
protected:
	wchar_t name[40]; // имя человека
public:
	void getName()       // получение от пользователя данных объекта
		{ wcout << L" Введите имя: "; wcin >> name; }
	void putName() const // вывод на экран данных объекта
		{ wcout << L"Имя: " << name; }
	virtual void getData() = 0;       // чистый виртуальный метод
	virtual bool isOutstanding() = 0; // чистый виртуальный метод
};

class student : public person // класс, представляющий студента
{
private:
	float gpa; // средний балл (по-английски «grade point average»)
public:
	void getData() // получение от пользователя данных студента
	{
		person::getName();
		wcout << L" Введите средний балл студента: "; wcin >> gpa;
	}
	bool isOutstanding()
		{ return (gpa > 3.5) ? true : false; }
};

class professor : public person // класс, представляющий профессора
{
private:
	int numPubs; // число публикаций
public:
	void getData() // получение от пользователя данных профессора
	{
		person::getName();
		wcout << L" Введите число публикаций профессора: "; wcin >> numPubs;
	}
	bool isOutstanding()
		{ return (numPubs > 100) ? true : false; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	person* persPtr[100]; // массив указателей на объекты класса person
	int n = 0;            // количество людей в списке
	wchar_t choice;

	do {
		wcout << L"Вводим студента или профессора? (с/п): "; wcin >> choice;
		if (choice == L'с')             // поместить новый объект-студент
			persPtr[n] = new student;   //     в массив
		else                            // поместить новый объект-профессор
			persPtr[n] = new professor; //     в массив
		persPtr[n++]->getData();        // получим данные персоны у пользователя
		wcout << L" Ввести следующего? (д/н): "; wcin >> choice;
	} while (choice == L'д'); // цикл выполняется, пока ответ «да»
	wcout << endl;

	for (int j = 0; j < n; j++)               // вывести для всех персон из списка
	{
		persPtr[j]->putName();                // их имена, при этом
		if (persPtr[j]->isOutstanding())      // отметить тех, кто
			wcout << L" (достоин поощрения)"; // достоин поощрения
		wcout << endl;
	}

	return 0;
}