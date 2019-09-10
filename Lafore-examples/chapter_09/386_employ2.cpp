// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// employ2.cpp
// несколько уровней наследования

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int LEN = 80; // максимальная длина строковых переменных

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

class manager : public employee // управленец (производный от класса employee)
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

class scientist : public employee // ученый (производный от класса employee)
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

class laborer : public employee // рабочий (производный от класса employee)
	{ };

class foreman : public laborer // бригадир (производный от класса laborer)
{
private:
	float quotas; // процент выполнения нормы выработки
public:
	void getdata()
	{
		laborer::getdata();
		wcout << L" Введите процент выполнения нормы выработки: "; wcin >> quotas;
	}
	void putdata() const
	{
		laborer::putdata();
		wcout << L"\n Процент выполнения нормы выработки: " << quotas;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	laborer l1;
	foreman f1;

	// получим от пользователя информацию о нескольких работниках
	wcout << L"Ввод информации о первом рабочем";     l1.getdata();
	wcout << L"\nВвод информации о первом бригадире"; f1.getdata();

	// выведем полученную информацию на экран
	wcout << L"\nИнформация о первом рабочем";   l1.putdata();
	wcout << L"\nИнформация о первом бригадире"; f1.putdata();
	wcout << endl;

	return 0;
}