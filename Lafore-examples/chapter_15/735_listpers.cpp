// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// listpers.cpp
// использует список для хранения объектов класса person

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <list>         // для работы с контейнером list
// #include <algorithm> // не понадобился
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
	friend bool operator!= (const person&, const person&);
	friend bool operator> (const person&, const person&);
	
	void display() const   // вывод на экран данных о человеке
	{
		wcout << endl << setiosflags(ios::left) << setw(13) << lastName
			<< setw(9) << firstName << L"телефон: " << phoneNumber;
	}
	
	long get_phone() const // вернуть номер телефона
		{ return phoneNumber; }
};

// оператор == («равно»), перегруженный для класса person
bool operator== (const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}

// оператор < («меньше»), перегруженный для класса person
bool operator< (const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}

// оператор != («не равно»), перегруженный для класса person
bool operator!= (const person& p1, const person& p2)
	{ return !(p1 == p2); }

// оператор > («больше»), перегруженный для класса person
bool operator> (const person& p1, const person& p2)
	{ return !(p1 < p2) && !(p1 == p2); }

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	list<person> persList;        // список объектов класса person
	list<person>::iterator iter1; // итератор для этого списка
	                              // занесём объекты в список
	persList.push_back(person(L"Довилль", L"Уильям", 8435150));
	persList.push_back(person(L"Макдональд", L"Стейси", 3327563));
	persList.push_back(person(L"Бартосски", L"Питер", 6946473));
	persList.push_back(person(L"Кунгфу", L"Брюс", 4157300));
	persList.push_back(person(L"Веллингтон", L"Джон", 9207404));
	persList.push_back(person(L"Макдональд", L"Аманда", 8435150));
	persList.push_back(person(L"Фредерикс", L"Роджер", 7049982));
	persList.push_back(person(L"Макдональд", L"Стейси", 7764987));

	wcout << L"Число записей: " << persList.size();

	// выведем на экран содержимое списка
	iter1 = persList.begin();
	while (iter1 != persList.end())
		(*iter1++).display();

	// 1. Поиск одного или нескольких человек с заданными фамилией и именем

	// получим у пользователя фамилию и имя искомого человека
	wstring searchLastName, searchFirstName;
	wcout << L"\n\nВведите фамилию искомого человека: ";
	wcin >> searchLastName;
	wcout << L"Введите его имя: ";
	wcin >> searchFirstName;

	// создадим объект класса person с полученными фамилией и именем
	person searchPerson(searchLastName, searchFirstName, 0L);

	// поищем в списке первое вхождение искомого объекта
	iter1 = find(persList.begin(), persList.end(), searchPerson);

	// поищем в списке следующие вхождения искомого объекта
	if (iter1 != persList.end())
	{
		wcout << L"Есть такой человек (такие люди) в списке:";
		do
		{
			(*iter1).display(); // выведем на экран найденный объект
			++iter1;            // поищем следующее вхождение
			iter1 = find(iter1, persList.end(), searchPerson);
		} while (iter1 != persList.end());
	}
	else
		wcout << L"Человек с такими фамилией и именем отсутствует в списке.";

	// 2. Поиск одного или нескольких человек с заданным телефонным номером

	// получим у пользователя искомый телефонный номер
	wcout << L"\n\nВведите номер телефона (формат 1234567): ";
	long sNumber;
	wcin >> sNumber;

	// пройдём по списку телефонных номеров
	bool found_one = false;
	for (iter1 = persList.begin(); iter1 != persList.end(); ++iter1)
	{
		// сравним искомый телефонный номер с очередным из списка
		if (sNumber == (*iter1).get_phone())
		{
			if (!found_one)
			{
				wcout << L"Есть человек (или несколько) с таким номером телефона:";
				found_one = true;
			}
			(*iter1).display(); // выведем на экран найденный объект
		}
	}

	if (!found_one)
		wcout << L"Человек с таким номером телефона отсутствует в списке.";

	wcout << endl;
	
	return 0;
}