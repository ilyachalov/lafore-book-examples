// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// empmult.cpp
// множественное наследование

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int LEN = 80; // максимальная длина строковых переменных

class student // студент (сведения об образовании)
{
private:
	wchar_t school[LEN]; // название учебного заведения
	wchar_t degree[LEN]; // уровень полученного образования
public:
	void getedu()
	{
		wcout << L" Введите название учебного заведения: "; wcin >> school;
		wcout << L" Введите уровень полученного образования\n";
		wcout << L" (неполное_высшее, бакалавр, магистр, кандидат_наук): "; wcin >> degree;
	}
	void putedu() const
	{
		wcout << L"\n Учебное заведение: " << school;
		wcout << L"\n Уровень полученного образования: " << degree;
	}
};

class employee // класс, представляющий работника
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

class manager : private employee, private student // управленец
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
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Должность: " << title;
		wcout << L"\n Сумма взносов в гольф-клуб: " << dues;
		student::putedu();
	}
};

class scientist : private employee, private student // ученый
{
private:
	int pubs; // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		wcout << L" Введите количество публикаций: "; wcin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Количество публикаций: " << pubs;
		student::putedu();
	}
};

class laborer : public employee // рабочий
	{ };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	manager m1;
	scientist s1, s2;
	laborer l1;

	// получим от пользователя информацию о нескольких работниках
	wcout << L"Ввод информации о первом управленце"; m1.getdata();
	wcout << L"\nВвод информации о первом ученом";   s1.getdata();
	wcout << L"\nВвод информации о втором ученом";   s2.getdata();
	wcout << L"\nВвод информации о первом рабочем";  l1.getdata();

	// выведем полученную информацию на экран
	wcout << L"\nИнформация о первом управленце"; m1.putdata();
	wcout << L"\nИнформация о первом ученом";     s1.putdata();
	wcout << L"\nИнформация о втором ученом";     s2.putdata();
	wcout << L"\nИнформация о первом рабочем";    l1.putdata();
	wcout << endl;

	return 0;
}