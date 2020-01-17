// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// empl_io.cpp
// вывод в файл (чтение из файла) объектов класса employee (вернее, производных от него)
// (программа работает с объектами разных размеров, так как объекты производных
// от employee классов имеют разные размеры)

// В среде «Visual Studio Community 2017» возможность RTTI включается и выключается
// с помощью ключа компилятора /GR. По умолчанию эта возможность включена.

// При записи объектов в файл и чтении объектов из файла я сделал поправку на
// скрытое поле __vfptr, автоматически добавляемое компилятором незаметно для
// программиста. __vfptr — это указатель на таблицу виртуальных методов, его
// размер составляет sizeof(void*) байтов. Это решение не универсально, то есть
// подходит не для всех компиляторов/операционных систем.

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <fstream>      // для файлового ввода/вывода
#include <iostream>
// #include <typeinfo>  // для функции typeid не понадобился
using namespace std;
// #include <process.h> // для функции exit не понадобился

const int LEN = 32;     // максимальная длина фамилий и наименования должности
const int MAXEM = 100;  // максимальное число работников
                        // типы работников
enum employee_type { tmanager, tscientist, tlaborer };

class employee // класс, представляющий работника (базовый класс)
{
private:
	wchar_t name[LEN];        // фамилия работника
	unsigned long number;     // номер работника
	static int n;             // текущее число работников
	static employee* arrap[]; // массив указателей на работников
public:
	virtual void getdata()
	{
		wcin.ignore(10, L'\n');
		wcout << L" Введите фамилию: "; wcin >> name;
		wcout << L" Введите номер: "; wcin >> number;
	}
	virtual void putdata() const
	{
		wcout << L"\n Фамилия: " << name;
		wcout << L"\n Номер: " << number;
	}
	virtual employee_type get_type(); // получить тип работника
	static void add();                // добавить работника
	static void display();            // вывести на экран данные всех работников
	static void read();               // чтение всех объектов из файла в память
	static void write();              // запись всех объектов из памяти в файл
};

// статические поля класса employee
int employee::n;                  // текущее число работников
employee* employee::arrap[MAXEM]; // массив указателей на работников

class manager : public employee // управленец (производный класс)
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

class scientist : public employee // ученый (производный класс)
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

class laborer : public employee // рабочий (производный класс)
	{ };

// добавить работника в список, хранящийся в оперативной памяти
void employee::add()
{
	wchar_t ch;
	wcout << L"'м' для добавления менеджера"
	         L"\n'у' для добавления ученого"
	         L"\n'р' для добавления рабочего"
	         L"\nВаш выбор: ";
	wcin >> ch;
	switch (ch)
	{                      // создать объект указанного типа (класса)
	case L'м': arrap[n] = new manager; break;
	case L'у': arrap[n] = new scientist; break;
	case L'р': arrap[n] = new laborer; break;
	default: wcout << L"\nНеизвестный тип работника\n"; return;
	}
	arrap[n++]->getdata(); // получить данные работника от пользователя
}

// вывести на экран данные всех работников
void employee::display()
{
	for (int j = 0; j < n; j++)
	{
		wcout << (j + 1);             // вывести номер (в списке) работника
		switch (arrap[j]->get_type()) // вывести тип работника
		{
		case tmanager: wcout << L". Тип: менеджер"; break;
		case tscientist: wcout << L". Тип: ученый"; break;
		case tlaborer: wcout << L". Тип: рабочий"; break;
		default: wcout << L". Неизвестный тип";
		}
		arrap[j]->putdata();          // вывести данные работника
		wcout << endl;
	}
}

// возвращает тип текущего работника
employee_type employee::get_type()
{
	if (typeid(*this) == typeid(manager))
		return tmanager;
	else if (typeid(*this) == typeid(scientist))
		return tscientist;
	else if (typeid(*this) == typeid(laborer))
		return tlaborer;
	else
		{ wcerr << L"\nНеправильный тип работника"; exit(1); }
	return tmanager;
}

// записывает все объекты, хранящиеся в памяти, в файл
void employee::write()
{
	int size;                      // размер объекта-работника
	wcout << L"Идет запись в файл " << n << L" работников.\n";
	ofstream ouf;                  // создать выходной поток
	employee_type etype;           // тип работника
	                               // открыть выходной поток в двоичном режиме
	ouf.open(L"Работники.dat", ios::trunc | ios::binary);
	if (!ouf)
		{ wcout << L"\nНе получается открыть файл\n"; return; }
	for (int j = 0; j < n; j++)    // для каждого работника в списке
	{                              // получить его тип
		etype = arrap[j]->get_type();
		                           // записать тип работника в файл
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)             // вычислить размер объекта-работника,
		{                          // зависящий от типа работника
		case tmanager: size = sizeof(manager); break;
		case tscientist: size = sizeof(scientist); break;
		case tlaborer: size = sizeof(laborer); break;
		}                          // записать работника в файл
		
		// ouf.write((char*)(arrap[j]), size);
		ouf.write((char*)(arrap[j]) + sizeof(void*), size - sizeof(void*));
		
		if (!ouf)
			{ wcout << L"\nНе получается записать работника в файл\n"; return; }
	}
}

// читает данные всех объектов из файла в память
void employee::read()
{
	int size;                      // размер объекта-работника
	employee_type etype;           // тип работника
	ifstream inf;                  // создать входной поток
	                               // открыть входной поток в двоичном режиме
	inf.open(L"Работники.dat", ios::binary);
	if (!inf)
		{ wcout << L"\nНе получается открыть файл\n"; return; }
	n = 0;                         // пока в памяти работников нет
	while (true)
	{                              // прочитать из файла тип следующего работника
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())             // если достигли конца файла, выйти из цикла
			break;
		if (!inf)                  // ошибка чтения из файла типа работника
			{ wcout << L"\nНе получается прочитать из файла тип работника\n"; return; }
		switch (etype)
		{                          // записать в память новый пустой объект-работник
		case tmanager:             // корректного типа (класса), вычислить его размер
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default: wcout << L"\nНеизвестный тип работника в файле\n"; return;
		}                          // прочитать данные из файла в этот объект-работник
		
		// inf.read((char*)arrap[n], size);
		inf.read((char*)arrap[n] + sizeof(void*), size - sizeof(void*));
		
		if (!inf)                  // ошибка, но не ошибка конца файла
			{ wcout << L"\nНе получается прочитать из файла данные работника\n"; return; }
		n++;                       // счетчик работников
	}
	wcout << L"Прочитано из файла " << n << L" работников\n";
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	// переключение стандартного потока ошибок в формат Юникода
	_setmode(_fileno(stderr), _O_U16TEXT);

	wchar_t ch; // символ для выбора пользователя

	while (true)
	{
		wcout << L"'д' — добавление сведений о работнике"
		         L"\n'в' — вывести на экран сведения всех работников"
		         L"\n'з' — записать данные всех работников в файл"
		         L"\n'п' — прочитать данные всех работников из файла"
		         L"\n'к' — конец (выход из программы)"
		         L"\nВаш выбор: ";
		wcin >> ch;
		switch (ch)
		{
		case L'д':           // добавить работника в список в памяти
			employee::add(); break;
		case L'в':           // вывести на экран сведения всех работников
			employee::display(); break;
		case L'з':           // запись всех работников из памяти в файл
			employee::write(); break;
		case L'п':           // чтение всех работников из файла в память
			employee::read(); break;
		case L'к': exit(0);  // выход из программы
		default: wcout << L"\nНеизвестная команда";
		}
	}

	return 0;
}