// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 09chapter_05exercise_ver2.cpp
// Предполагается, что у нас есть класс employee (работник) и производные от него
// классы manager (управленец), scientist (ученый) и laborer (рабочий), созданные
// в примере employ.cpp главы 9. Требуется добавить в эту модель базы данных
// работников данные по вознаграждению и периоду выплат этого вознаграждения.

// Пояснение к примеру employ.cpp главы 9:
// моделируем базу данных работников, используя наследование

// В задании к данному упражнению Лафоре указывает два пути решения поставленной
// задачи. Поэтому я написал две программы, реализующих эти пути. В этом файле
// реализован второй путь (ver2): создать класс compensation (вознаграждение) и
// добавить в него нужные поля. Создать три новых класса: manager2, scientist2,
// laborer2 и с помощью множественного наследования сделать их производными от
// класса compensation и, соответственно, от оригинальных классов manager,
// scientist и laborer.

// Второй путь решения задачи считается более соответствующим духу объектно-
// ориентированного программирования (ООП), так как в старые классы изменений
// не вносится, функциональность к нашей модели базы данных работников добавляется
// только путем создания новых классов с наследованием от старых.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int LEN = 80; // максимальная длина строковых переменных

class employee // работник (остается без изменений)
{
private:
	wchar_t name[LEN];    // фамилия работника
	unsigned long number; // номер работника
public:
	void getdata()
	{
		wcout << L"\n Введите фамилию: "; wcin >> name;
		wcout << L" Введите номер: "; wcin >> number;
	}
	void putdata() const
	{
		wcout << L"\n Фамилия: " << name;
		wcout << L"\n Номер: " << number;
	}
};

class compensation // вознаграждение (новый класс)
{
private:
	enum period_type {почасовая, еженедельная, ежемесячная};
	period_type period;  // период выплат вознаграждения
	double compensation; // сумма вознаграждения
public:
	void getdata()
	{
		wcout << L" Введите период выплат ('ч' почасовая, 'н' еженедельная, 'м' ежемесячная): ";
		wchar_t ch; wcin >> ch;
		switch (ch)
		{
		case L'ч': period = почасовая; break;
		case L'н': period = еженедельная; break;
		case L'м': period = ежемесячная; break;
		default: period = почасовая;
		}
		wcout << L" Введите сумму вознаграждения: "; wcin >> compensation;
	}
	void putdata() const
	{
		wcout << L"\n Период выплат: ";
		switch (period)
		{
		case почасовая: wcout << L"почасовая"; break;
		case еженедельная: wcout << L"еженедельная"; break;
		case ежемесячная: wcout << L"ежемесячная"; break;
		}
		wcout << L"\n Сумма вознаграждения: " << compensation;
	}
};

class manager : public employee // управленец (остается без изменений)
{
private:
	wchar_t title[LEN]; // наименование должности, например, «вице-президент»
	double dues;        // сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee::getdata();
		wcout << L" Введите должность: "; wcin >> title;
		wcout << L" Введите сумму взносов в гольф-клуб: "; wcin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Должность: " << title;
		wcout << L"\n Сумма взносов в гольф-клуб: " << dues;
	}
};

class manager2 : public manager, public compensation // управленец2 (новый класс)
{
public:
	void getdata()
	{
		manager::getdata();
		compensation::getdata();
	}
	void putdata() const
	{
		manager::putdata();
		compensation::putdata();
	}
};

class scientist : public employee // ученый (остается без изменений)
{
private:
	int pubs; // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		wcout << L" Введите количество публикаций: "; wcin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Количество публикаций: " << pubs;
	}
};

class scientist2 : public scientist, public compensation // ученый2 (новый класс)
{
public:
	void getdata()
	{
		scientist::getdata();
		compensation::getdata();
	}
	void putdata() const
	{
		scientist::putdata();
		compensation::putdata();
	}
};

class laborer : public employee // рабочий (остается без изменений)
	{ };

class laborer2 : public laborer, public compensation // рабочий2 (новый класс)
{
public:
	void getdata()
	{
		laborer::getdata();
		compensation::getdata();
	}
	void putdata() const
	{
		laborer::putdata();
		compensation::putdata();
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	manager2 m1, m2;
	scientist2 s1;
	laborer2 l1;

	// получим от пользователя информацию о нескольких работниках
	wcout << L"Ввод информации о первом управленце";   m1.getdata();
	wcout << L"\nВвод информации о втором управленце"; m2.getdata();
	wcout << L"\nВвод информации о первом ученом";     s1.getdata();
	wcout << L"\nВвод информации о первом рабочем";    l1.getdata();

	// выведем полученную информацию на экран
	wcout << L"\nИнформация о первом управленце"; m1.putdata();
	wcout << L"\nИнформация о втором управленце"; m2.putdata();
	wcout << L"\nИнформация о первом ученом";     s1.putdata();
	wcout << L"\nИнформация о первом рабочем";    l1.putdata();
	wcout << endl;

	return 0;
}