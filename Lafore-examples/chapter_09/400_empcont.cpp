// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// empcont.cpp
// включение объектов классов в другие классы

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <string> // для работы со строками wstring
using namespace std;

class student // студент (сведения об образовании)
{
private:
	wstring school; // название учебного заведения
	wstring degree; // уровень полученного образования
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

class employee // работник
{
private:
	wstring name;         // фамилия работника
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

class manager // управленец (включает в качестве полей объекты классов «работник» и «студент»)
{
private:
	wstring title; // наименование должности, например, «вице-президент»
	double dues;   // сумма взносов в гольф-клуб
	employee emp;  // включение объекта класса «работник»
	student stu;   // включение объекта класса «студент»
public:
	void getdata()
	{
		emp.getdata();
		wcout << L" Введите должность: "; wcin >> title;
		wcout << L" Введите сумму взносов в гольф-клуб: "; wcin >> dues;
		stu.getedu();
	}
	void putdata() const
	{
		emp.putdata();
		wcout << L"\n Должность: " << title;
		wcout << L"\n Сумма взносов в гольф-клуб: " << dues;
		stu.putedu();
	}
};

class scientist // ученый (включает в качестве полей объекты классов «работник» и «студент»)
{
private:
	int pubs;     // количество публикаций
	employee emp; // включение объекта класса «работник»
	student stu;  // включение объекта класса «студент»
public:
	void getdata()
	{
		emp.getdata();
		wcout << L" Введите количество публикаций: "; wcin >> pubs;
		stu.getedu();
	}
	void putdata() const
	{
		emp.putdata();
		wcout << L"\n Количество публикаций: " << pubs;
		stu.putedu();
	}
};

class laborer // рабочий (включает в качестве поля объект класса «работник»)
{
private:
	employee emp; // включение объекта класса «работник»
public:
	void getdata()
		{ emp.getdata(); }
	void putdata() const
		{ emp.putdata(); }
};

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