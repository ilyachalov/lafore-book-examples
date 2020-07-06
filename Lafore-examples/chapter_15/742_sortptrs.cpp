// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sortptrs.cpp
// сортирует объекты класса person в списке с указателями на эти объекты

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <vector>       // для работы с контейнером vector
#include <algorithm>    // для алгоритмов sort и for_each
#include <string>       // для работы с классом wstring
#include <iomanip>      // для манипулятора setw
using namespace std;

class person // класс, представляющий запись о человеке в телефонной книге
{
private:
	wstring lastName;  // фамилия
	wstring firstName; // имя
	long phoneNumber;  // телефонный номер
public:
	// конструктор без аргументов
	person() : lastName(L"пусто"), firstName(L"пусто"), phoneNumber(0L)
		{ }
	// конструктор с тремя аргументами
	person(wstring lana, wstring fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
		{ }
	friend bool operator< (const person&, const person&);
	friend bool operator== (const person&, const person&);

	void display() const   // вывод на экран данных о человеке
	{
		wcout << endl << setiosflags(ios::left) << setw(13) << lastName
			<< setw(9) << firstName << L"телефон: " << phoneNumber;
	}

	long get_phone() const // вернуть номер телефона
		{ return phoneNumber; }
};

// оператор < («меньше»), перегруженный для класса person
bool operator< (const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}

// оператор == («равно»), перегруженный для класса person
bool operator== (const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}

// функциональный объект для сравнения объектов класса person по указателям на них
class comparePersons
{
public:
	bool operator() (const person* ptrP1, const person* ptrP2) const
		{ return *ptrP1 < *ptrP2; }
};

// функциональный объект для вывода на экран объекта класса person по указателю
class displayPerson
{
public:
	void operator() (const person* ptrP) const
		{ ptrP->display(); }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	vector<person*> vectPtrsPers;   // вектор указателей на объекты класса person
	                                // создадим объекты класса person
	person* ptrP1 = new person(L"Кунгфу", L"Брюс", 4157300);
	person* ptrP2 = new person(L"Довилль", L"Уильям", 8435150);
	person* ptrP3 = new person(L"Веллингтон", L"Джон", 9207404);
	person* ptrP4 = new person(L"Бартосски", L"Питер", 6946473);
	person* ptrP5 = new person(L"Фредерикс", L"Роджер", 7049982);
	person* ptrP6 = new person(L"Макдональд", L"Стейси", 7764987);

	vectPtrsPers.push_back(ptrP1);  // занесём указатели на объекты в вектор
	vectPtrsPers.push_back(ptrP2);
	vectPtrsPers.push_back(ptrP3);
	vectPtrsPers.push_back(ptrP4);
	vectPtrsPers.push_back(ptrP5);
	vectPtrsPers.push_back(ptrP6);
	                                // 1. выведем объекты из вектора на экран
	for_each(vectPtrsPers.begin(), vectPtrsPers.end(), displayPerson());

	                                // отсортируем указатели в векторе
	sort(vectPtrsPers.begin(), vectPtrsPers.end());
	wcout << L"\n\nОтсортированы указатели:";
	                                // 2. выведем объекты из вектора на экран
	for_each(vectPtrsPers.begin(), vectPtrsPers.end(), displayPerson());

	                                // отсортируем объекты по указателям на них
	sort(vectPtrsPers.begin(), vectPtrsPers.end(), comparePersons());
	wcout << L"\n\nОтсортированы персоны:";
	                                // 3. выведем объекты из вектора на экран
	for_each(vectPtrsPers.begin(), vectPtrsPers.end(), displayPerson());

	while (!vectPtrsPers.empty())
	{
		delete vectPtrsPers.back(); // освобождаем память из-под объекта
		vectPtrsPers.pop_back();    // удаляем указатель на этот объект из вектора
	}

	wcout << endl;
	
	return 0;
}