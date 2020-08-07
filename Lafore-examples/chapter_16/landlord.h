// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// landlord.h
// заголовочный файл для landlord.cpp — содержит объявления классов и т.п.
// (интерфейс библиотеки классов)

// #pragma warning (disable:4786) // для множеств (только компиляторы microsoft)
                                  // не понадобилось

#include <iostream>
#include <vector>    // для контейнера vector
#include <set>       // для контейнера set
#include <string>    // для класса wstring
#include <algorithm> // для алгоритма sort
#include <numeric>   // для алгоритма accumulate
#include <iomanip>   // для манипулятора setw
using namespace std;

//////////////////// глобальные функции ////////////////////////////////////////
void getaLine(wstring& inStr); // получение строки текста
wchar_t getaChar();            // получение символа

//////////////////// класс tenant (жилец) //////////////////////////////////////
class tenant
{
private:
	wstring name;  // имя и фамилия жильца
	int aptNumber; // номер квартиры жильца
	
	// здесь могут быть поля с дополнительной информацией о жильце
	// (телефон и т.п.)

public:
	tenant(wstring n, int aNo);
	~tenant();
	int getAptNumber();
	
	// для множества (контейнер set): порядок элементов
	friend bool operator< (const tenant&, const tenant&);

	friend bool operator== (const tenant&, const tenant&);
	
	// для вывода объекта класса в выходной поток
	friend wostream& operator<< (wostream&, const tenant&);
};

//////////////////// класс compareTenants //////////////////////////////////////
class compareTenants // функциональный объект — сравнивает объекты класса tenant
{
public:
	bool operator() (tenant*, tenant*) const;
};

//////////////////// класс tenantList //////////////////////////////////////////
class tenantList
{
private:
	// множество указателей на объекты класса tenant (жилец)
	set<tenant*, compareTenants> setPtrsTens;
	set<tenant*, compareTenants>::iterator iter;
public:
	~tenantList();              // деструктор (освобождает память, занятую ранее
	                            // под элементы множества (объекты класса tenant))
	void insertTenant(tenant*); // внесение жильца во множество (список жильцов)
	int getAptNo(wstring);      // возвращает номер квартиры по имени жильца
	void display();             // вывод списка жильцов на экран
};

//////////////////// класс tenantInputScreen ///////////////////////////////////
class tenantInputScreen
{
private:
	tenantList* ptrTenantList;
	wstring tName;
	int aptNo;
public:
	tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
		{ }
	void getTenant();
};

//////////////////// класс rentRow /////////////////////////////////////////////
// одна строка таблицы арендных плат: номер квартиры и 12 месячных плат
class rentRow
{
private:
	int aptNo;
	float rent[12];
public:
	rentRow(int);             // конструктор с одним аргументом
	void setRent(int, float); // записать плату за один месяц
	float getSumOfRow();      // возвратить сумму плат из одной строки
	
	// для множества (контейнер set): порядок элементов
	friend bool operator< (const rentRow&, const rentRow&);

	friend bool operator== (const rentRow&, const rentRow&);
	
	// для вывода объекта класса в выходной поток
	friend wostream& operator<< (wostream&, const rentRow&);
};

//////////////////// класс compareRows /////////////////////////////////////////
class compareRows // функциональный объект — сравнивает объекты класса rentRow
{
public:
	bool operator() (rentRow*, rentRow*) const;
};

//////////////////// класс rentRecord //////////////////////////////////////////
class rentRecord // таблица арендных плат
{
private:
	// множество указателей на объекты класса rentRow (по одному на жильца)
	set<rentRow*, compareRows> setPtrsRR;
	set<rentRow*, compareRows>::iterator iter;
public:
	~rentRecord();
	void insertRent(int, int, float);
	void display();
	float getSumOfRents(); // возвратить сумму всех арендных плат в таблице
};

//////////////////// класс rentInputScreen /////////////////////////////////////
class rentInputScreen
{
private:
	tenantList* ptrTenantList;
	rentRecord* ptrRentRecord;
	
	wstring renterName;
	float rentPaid;
	int month;
	int aptNo;
public:
	rentInputScreen(tenantList* ptrTL, rentRecord* ptrRR) :
		ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
		{ }
	void getRent(); // получить арендную плату одного жильца за один месяц
};

//////////////////// класс expense /////////////////////////////////////////////
class expense // расход
{
public:                      // public — это не ошибка! в дальнейшем в программе
	int month, day;          // поля данного класса будут использоваться другими
	wstring category, payee; // классами напрямую
	float amount;

	expense()
		{ }
	expense(int m, int d, wstring c, wstring p, float a) :
		month(m), day(d), category(c), payee(p), amount(a)
		{ }

	// для множества (контейнер set): порядок элементов
	friend bool operator< (const expense&, const expense&);

	friend bool operator== (const expense&, const expense&);
	
	// для вывода объекта класса в выходной поток
	friend wostream& operator<< (wostream&, const expense&);
};

//////////////////// класс compareDates ////////////////////////////////////////
class compareDates // функциональный объект — сравнивает расходы по дате
{
public:
	bool operator() (expense*, expense*) const;
};

//////////////////// класс compareCategories ///////////////////////////////////
class compareCategories // функциональный объект — сравнивает расходы по категории
{
public:
	bool operator() (expense*, expense*) const;
};

//////////////////// класс expenseRecord ///////////////////////////////////////
class expenseRecord // список расходов
{
private:
	// вектор указателей на объекты класса expense (расход)
	vector<expense*> vectPtrsExpenses;
	vector<expense*>::iterator iter;
public:
	~expenseRecord();
	void insertExp(expense*);
	void display();
	float displaySummary(); // используется классом annualReport (годовой отчет)
};

//////////////////// класс expenseInputScreen //////////////////////////////////
class expenseInputScreen
{
private:
	expenseRecord* ptrExpenseRecord;
public:
	expenseInputScreen(expenseRecord*);
	void getExpense();
};

//////////////////// класс annualReport ////////////////////////////////////////
class annualReport // годовой отчет
{
private:
	rentRecord* ptrRR;
	expenseRecord* ptrER;
	float expenses, rents;
public:
	annualReport(rentRecord*, expenseRecord*);
	void display();
};

//////////////////// класс userInterface ///////////////////////////////////////
class userInterface // интерфейс для работы пользователя с программой
{
private:
	tenantList* ptrTenantList;
	tenantInputScreen* ptrTenantInputScreen;
	rentRecord* ptrRentRecord;
	rentInputScreen* ptrRentInputScreen;
	expenseRecord* ptrExpenseRecord;
	expenseInputScreen* ptrExpenseInputScreen;
	annualReport* ptrAnnualReport;
	wchar_t ch;
public:
	userInterface();
	~userInterface();
	void interact();
};