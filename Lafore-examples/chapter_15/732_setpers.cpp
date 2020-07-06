// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// setpers.cpp
// использует мультимножество для хранения объектов класса person

// #pragma warning (disable:4786) // для работы с мультимножеством
                                  // (только для компиляторов Microsoft)
                                  // эта директива не понадобилась

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <set>          // для работы с контейнером set
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
	// конструктор по умолчанию
	person() : lastName(L"пусто"), firstName(L"пусто"), phoneNumber(0)
		{ }
	// конструктор с тремя аргументами
	person(wstring lana, wstring fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
		{ }
	friend bool operator< (const person&, const person&);
	friend bool operator== (const person&, const person&);
	// вывод на экран данных о человеке
	void display() const
	{
		wcout << endl << setiosflags(ios::left) << setw(13) << lastName
			<< setw(9) << firstName << L"телефон: " << phoneNumber;
	}
};

// оператор < («меньше») для класса person
bool operator< (const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}

// оператор == («равно») для класса person
bool operator== (const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	// создадим объекты класса person
	person pers1(L"Довилль", L"Уильям", 8435150);
	person pers2(L"Макдональд", L"Стейси", 3327563);
	person pers3(L"Бартосски", L"Питер", 6946473);
	person pers4(L"Кунгфу", L"Брюс", 4157300);
	person pers5(L"Веллингтон", L"Джон", 9207404);
	person pers6(L"Макдональд", L"Аманда", 8435150);
	person pers7(L"Фредерикс", L"Роджер", 7049982);
	person pers8(L"Макдональд", L"Стейси", 7764987);
	// мультимножество объектов класса person
	multiset<person, less<person>> persSet;
	// итератор этого мультимножества
	multiset<person, less<person>>::iterator iter;

	// занесём объекты класса person в мультимножество
	persSet.insert(pers1);
	persSet.insert(pers2);
	persSet.insert(pers3);
	persSet.insert(pers4);
	persSet.insert(pers5);
	persSet.insert(pers6);
	persSet.insert(pers7);
	persSet.insert(pers8);

	wcout << L"Число записей: " << persSet.size();

	// выведем на экран содержимое мультимножества
	iter = persSet.begin();
	while (iter != persSet.end())
		(*iter++).display();

	// получим у пользователя фамилию и имя искомого человека
	wstring searchLastName, searchFirstName;
	wcout << L"\n\nВведите фамилию искомого человека: ";
	wcin >> searchLastName;
	wcout << L"Введите его имя: ";
	wcin >> searchFirstName;

	// создадим объект класса person с полученными фамилией и именем
	person searchPerson(searchLastName, searchFirstName, 0);

	// сосчитаем количество людей с такими фамилией и именем
	int cntPersons = persSet.count(searchPerson);
	wcout << L"Число людей с такими фамилией и именем: " << cntPersons;

	// выведем на экран все записи, отвечающие запросу
	iter = persSet.lower_bound(searchPerson);
	while (iter != persSet.upper_bound(searchPerson))
		(*iter++).display();

	wcout << endl;
	
	return 0;
}