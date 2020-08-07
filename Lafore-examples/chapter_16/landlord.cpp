// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// landlord.cpp
// реализует ведение учета для нужд владельца многоквартирного дома
// (реализация библиотеки классов)

#include "landlord.h" // интерфейс библиотеки классов (объявления классов и т.д.)

//////////////////// глобальные функции ////////////////////////////////////////

void getaLine(wstring& inStr)  // получение строки текста
{
	wchar_t temp[21];
	wcin.get(temp, 20, L'\n');
	wcin.ignore(20, L'\n');
	inStr = temp;
}

wchar_t getaChar()             // получение символа
{
	wchar_t ch = wcin.get();
	wcin.ignore(80, L'\n');
	return ch;
}

//////////////////// методы класса tenant (жилец) //////////////////////////////

tenant::tenant(wstring n, int aNo) : name(n), aptNumber(aNo)
	{ }

tenant::~tenant()
	{ }

int tenant::getAptNumber()
	{ return aptNumber; }

bool operator< (const tenant& t1, const tenant& t2)
	// { return t1.name < t2.name; }         // вариант Лафоре
	{ return t1.aptNumber < t2.aptNumber; }  // мой вариант

bool operator== (const tenant& t1, const tenant& t2)
	{ return t1.name == t2.name; }           // используется в tenantList::getAptNo

wostream& operator<< (wostream& s, const tenant& t)
	{ s << t.aptNumber << L'\t' << t.name << endl; return s; }

//////////////////// методы класса compareTenants //////////////////////////////

bool compareTenants::operator() (tenant* ptrT1,	tenant* ptrT2) const
	{ return *ptrT1 < *ptrT2; }

//////////////////// методы класса tenantList //////////////////////////////////

tenantList::~tenantList()           // деструктор
{
	while (!setPtrsTens.empty())    // освобождаем память из-под объектов-жильцов,
	{                               // удаляем указатели на них из множества
		iter = setPtrsTens.begin();
		delete *iter;
		setPtrsTens.erase(iter);
	}
}

void tenantList::insertTenant(tenant* ptrT)
{
	setPtrsTens.insert(ptrT); // добавляем жильца в список (множество)
}

int tenantList::getAptNo(wstring tName)  // имя жильца есть в списке?
{
	int aptNo;
	tenant dummy(tName, 0);
	iter = setPtrsTens.begin();
	while (iter != setPtrsTens.end())    // поиск жильца с заданным именем
	{
		aptNo = (*iter)->getAptNumber();
		if (dummy == **iter++)           // в списке?
			return aptNo;                // да
	}
	return -1;                           // нет
}

void tenantList::display()               // вывод списка жильцов на экран
{
	wcout << L"\n№ кв.\tИмя жильца\n-------------------\n";
	if (setPtrsTens.empty())
		wcout << L"*** Нет жильцов ***\n";
	else
	{
		iter = setPtrsTens.begin();
		while (iter != setPtrsTens.end())
			wcout << **iter++;
	}
	wcout << endl;
}

//////////////////// методы класса tenantInputScreen ///////////////////////////

void tenantInputScreen::getTenant()               // получить данные жильца
{
	wcout << L"\nВведите имя и фамилию жильца (Иван Петров): ";
	getaLine(tName);
	wcout << L"Введите номер квартиры жильца (101): ";
	wcin >> aptNo;
	wcin.ignore(80, L'\n');
	tenant* ptrTenant = new tenant(tName, aptNo); // создать жильца
	ptrTenantList->insertTenant(ptrTenant);       // занести в список жильцов
	wcout << endl;
}

//////////////////// методы класса rentRow /////////////////////////////////////

rentRow::rentRow(int an) : aptNo(an)   // конструктор с одним аргументом
	{ fill(&rent[0], &rent[12], 0); }

void rentRow::setRent(int m, float am) // записать плату за один месяц
	{ rent[m] = am; }

float rentRow::getSumOfRow()           // возвратить сумму плат из одной строки
	{ return accumulate(&rent[0], &rent[12], 0); }

bool operator< (const rentRow& t1, const rentRow& t2)
	{ return t1.aptNo < t2.aptNo; }

bool operator== (const rentRow& t1, const rentRow& t2)
	{ return t1.aptNo == t2.aptNo; }

wostream& operator<< (wostream& s, const rentRow& an)
{
	s << an.aptNo << L'\t';            // вывести номер квартиры
	for (int j = 0; j < 12; j++)       // вывести 12 арендных плат
	{
		if (an.rent[j] == 0)
			s << L"  0  ";             // по 2 пробела слева и справа от нуля
		else
			s << an.rent[j] << L"  ";  // два пробела справа от суммы платы

		// Такая система с пробелами подразумевает, что сумма арендной платы
		// может занимать только три знака на экране; в иных случаях программа
		// будет работать, но структура таблицы на экране исказится.
		// (Такой вариант выбран из-за его простоты, так как целью Лафоре
		// являлось не красивое изображение таблиц на экране, а демонстрация
		// этапов разработки программы.)
	}
	s << endl;
	return s;
}

//////////////////// методы класса compareRows /////////////////////////////////

bool compareRows::operator() (rentRow* ptrR1, rentRow* ptrR2) const
	{ return *ptrR1 < *ptrR2; }

//////////////////// методы класса rentRecord //////////////////////////////////

rentRecord::~rentRecord()         // деструктор
{
	while (!setPtrsRR.empty())    // освобождаем память из-под объектов rentRow
	{                             // удаляем указатели на них из множества
		iter = setPtrsRR.begin();
		delete *iter;
		setPtrsRR.erase(iter);
	}
}

void rentRecord::insertRent(int aptNo, int month, float amount)
{
	rentRow searchRow(aptNo);                // временная строка с тем же aptNo
	iter = setPtrsRR.begin();                // ищем во множестве setPtrsRR
	while (iter != setPtrsRR.end())
	{
		if (searchRow == **iter)             // нужный объект rentRow найден?
		{                                    // если да, то
			(*iter)->setRent(month, amount); // запишем плату в найденную строку
			return;                          // и завершим метод
		}
		else
			iter++;
	}                                        // если же нужный rentRow не найден,
	rentRow* ptrRow = new rentRow(aptNo);    // то создадим новый rentRow
	ptrRow->setRent(month, amount);          // запишем плату в него
	setPtrsRR.insert(ptrRow);                // занесем указатель на него
	                                         // во множество
}

void rentRecord::display()
{
	wcout << L"\n№ кв.\tЯнв  Фев  Мар  Апр  Май  Июн  " // месяцы отделяются друг
		<<            L"Июл  Авг  Сен  Окт  Ноя  Дек\n" // от друга 2-мя пробелами
		<< L"---------------------------------"
		<< L"---------------------------------\n";
	if (setPtrsRR.empty())
		wcout << L"*** Нет платежей ***\n";
	else
	{
		iter = setPtrsRR.begin();
		while (iter != setPtrsRR.end())
			wcout << **iter++;
	}
	wcout << endl;
}

float rentRecord::getSumOfRents() // возвратить сумму всех арендных плат в таблице
{
	float sumRents = 0.0;
	iter = setPtrsRR.begin();
	while (iter != setPtrsRR.end())
	{
		sumRents += (*iter)->getSumOfRow();
		iter++;
	}
	return sumRents;
}

//////////////////// методы класса rentInputScreen /////////////////////////////

void rentInputScreen::getRent()
{
	wcout << L"\nВведите имя и фамилию жильца: ";
	getaLine(renterName);
	aptNo = ptrTenantList->getAptNo(renterName);
	if (aptNo > 0)                             // если жилец с таким именем есть,
	{                                          // получить сумму платы за квартиру
		wcout << L"Введите сумму платежа (345.67): ";
		wcin >> rentPaid;
		wcin.ignore(80, L'\n');
		wcout << L"Введите номер оплачиваемого месяца (1-12): ";
		wcin >> month;
		wcin.ignore(80, L'\n');
		month--;                               // (внутренняя нумерация 0-11)
		ptrRentRecord->insertRent(aptNo, month, rentPaid);
	}
	else                                       // сообщить об ошибке
		wcout << L"Жильца с таким именем нет.\n";
	wcout << endl;
}

//////////////////// методы класса expense /////////////////////////////////////

bool operator< (const expense& e1, const expense& e2)
{                                   // сравнивает дату расходов:
	if (e1.month == e2.month)       // если совпадает месяц,
		return e1.day < e2.day;     //     сравнить дни,
	else                            // в противном случае —
		return e1.month < e2.month; //     сравнить месяцы
}

bool operator== (const expense& e1, const expense& e2)
	{ return e1.month == e2.month && e1.day == e2.day; }

wostream& operator<< (wostream& s, const expense& exp)
{
	s << exp.month << L'/' << exp.day << L'\t'
		<< left << setw(16) << exp.payee;
	s << right << setw(8) << exp.amount << L"  "
		<< exp.category << endl;
	return s;
}

//////////////////// методы класса compareDates ////////////////////////////////

bool compareDates::operator() (expense* ptrE1, expense* ptrE2) const
	{ return *ptrE1 < *ptrE2; }

//////////////////// методы класса compareCategories ///////////////////////////

bool compareCategories::operator() (expense* ptrE1, expense* ptrE2) const
	{ return ptrE1->category < ptrE2->category; }

//////////////////// методы класса expenseRecord ///////////////////////////////

expenseRecord::~expenseRecord()          // деструктор
{
	while (!vectPtrsExpenses.empty())    // освободить память из-под объектов
	{                                    // удалить указатели на них из вектора
		iter = vectPtrsExpenses.begin();
		delete *iter;
		vectPtrsExpenses.erase(iter);
	}
}

void expenseRecord::insertExp(expense* ptrExp)
	{ vectPtrsExpenses.push_back(ptrExp); }

void expenseRecord::display()
{
	wcout << L"\nДата\tПолучатель\t"
		<< right << setw(8) << L"Сумма" << L"  "
		<< L"Категория\n"
		<< L"-------------------------------------------\n";
	if (vectPtrsExpenses.size() == 0)
		wcout << L"*** Расходов нет ***\n";
	else
	{
		sort(vectPtrsExpenses.begin(), // сортируем расходы по дате
			vectPtrsExpenses.end(), compareDates());
		iter = vectPtrsExpenses.begin();
		while (iter != vectPtrsExpenses.end())
			wcout << **iter++;
	}
	wcout << endl;
}

float expenseRecord::displaySummary() // используется классом annualReport
                                      // (годовой отчет)
{
	float totalExpenses = 0;          // сумма расходов всех категорий

	if (vectPtrsExpenses.size() == 0)
	{
		wcout << L"\tВсе категории\t" << right << setw(8) << L"0" << endl;
		return 0;
	}

	// сортируем расходы по категории
	sort(vectPtrsExpenses.begin(), vectPtrsExpenses.end(), compareCategories());

	// суммируем расходы по каждой категории

	iter = vectPtrsExpenses.begin();
	wstring tempCat = (*iter)->category;
	float sumCat = 0.0;
	while (iter != vectPtrsExpenses.end())
	{
		if (tempCat == (*iter)->category) // если категория та же
			sumCat += (*iter)->amount;
		else                              // в противном случае
		{
			wcout << L'\t' << left << setw(16) << tempCat
				<< right << setw(8) << sumCat << endl;
			totalExpenses += sumCat;      // добавить сумму предыдущей категории
			tempCat = (*iter)->category;
			sumCat = (*iter)->amount;     // начать сумму следующей категории
		}
		iter++;
	}
	totalExpenses += sumCat;              // добавить сумму конечной категории
	wcout << L'\t' << left << setw(16) << tempCat
		<< right << setw(8) << sumCat << endl;
	return totalExpenses;
}

//////////////////// методы класса expenseInputScreen //////////////////////////

expenseInputScreen::expenseInputScreen(expenseRecord* per) : ptrExpenseRecord(per)
	{ }

void expenseInputScreen::getExpense()
{
	int month, day;
	wstring category, payee;
	float amount;

	wcout << L"\nВведите месяц (1-12): ";
	wcin >> month;
	wcin.ignore(80, L'\n');
	wcout << L"Введите день (1-31): ";
	wcin >> day;
	wcin.ignore(80, L'\n');
	wcout << L"Введите категорию расхода (Ремонт, Налоги): ";
	getaLine(category);
	wcout << L"Введите получателя платежа (ЭлектроСбыт): ";
	getaLine(payee);
	wcout << L"Введите сумму (39.95): ";
	wcin >> amount;
	wcin.ignore(80, L'\n');
	wcout << endl;
	
	expense* ptrExpense = new expense(month, day, category, payee, amount);
	ptrExpenseRecord->insertExp(ptrExpense);
}

//////////////////// методы класса annualReport ////////////////////////////////

annualReport::annualReport(rentRecord* pRR, expenseRecord* pER) :
	ptrRR(pRR), ptrER(pER)
	{ }

void annualReport::display()
{
	wcout << L"\nГодовой отчет\n-------------\n";

	wcout << L"Доходы\n";
	wcout << L"\tАренда\t\t";
	rents = ptrRR->getSumOfRents();
	wcout << right << setw(8) << rents << endl;

	wcout << L"Расходы\n";
	expenses = ptrER->displaySummary();
	// финансовый результат
	wcout << L"\nФин.рез.\t\t" << right << setw(8) << rents - expenses
		<< endl << endl;
}

//////////////////// методы класса userInterface ///////////////////////////////

userInterface::userInterface()
{
	// эти отчеты существуют, только пока программа работает
	ptrTenantList = new tenantList;
	ptrRentRecord = new rentRecord;
	ptrExpenseRecord = new expenseRecord;
}

userInterface::~userInterface()
{
	delete ptrTenantList;
	delete ptrRentRecord;
	delete ptrExpenseRecord;
}

void userInterface::interact()
{
	while (true)                                          // бесконечный цикл
	{
		wcout << L"Введите 'д' для ввода данных,\n"
		      << L"        'о' для вывода на экран отчета,\n"
		      << L"        'в' для выхода из программы: ";
		ch = getaChar();

		if (ch == L'д')                                   // ввод данных
		{
			wcout << L"\nВведите 'ж' для добавления жильца,\n"
			      << L"        'а' для записи арендной платы,\n"
			      << L"        'р' для записи расхода: ";
			ch = getaChar();

			switch (ch)
			{
			// экраны ввода существуют только пока они используются
			case L'ж': ptrTenantInputScreen =
				new tenantInputScreen(ptrTenantList);
				ptrTenantInputScreen->getTenant();
				delete ptrTenantInputScreen;
				break;
			case L'а': ptrRentInputScreen =
				new rentInputScreen(ptrTenantList, ptrRentRecord);
				ptrRentInputScreen->getRent();
				delete ptrRentInputScreen;
				break;
			case L'р': ptrExpenseInputScreen =
				new expenseInputScreen(ptrExpenseRecord);
				ptrExpenseInputScreen->getExpense();
				delete ptrExpenseInputScreen;
				break;
			default: wcout << L"Неизвестная опция ввода данных\n\n";
				break;
			}
		}
		else if (ch == L'о')                              // вывод данных на экран
		{
			wcout << L"\nВведите 'ж' для вывода на экран списка жильцов,\n"
			      << L"        'а' для вывода на экран таблицы арендных плат,\n"
			      << L"        'р' для вывода на экран списка расходов,\n"
			      << L"        'г' для вывода годового отчета: ";
			ch = getaChar();

			switch (ch)
			{
			case L'ж': ptrTenantList->display();
				break;
			case L'а': ptrRentRecord->display();
				break;
			case L'р': ptrExpenseRecord->display();
				break;
			case L'г':
				ptrAnnualReport = new annualReport(ptrRentRecord, ptrExpenseRecord);
				ptrAnnualReport->display();
				delete ptrAnnualReport;
				break;
			default: wcout << L"Неизвестная опция вывода на экран\n\n";
				break;
			}
		}
		else if (ch == L'в')                              // выход из программы
			return;
		else
			wcout << L"Неизвестная опция. Нажимайте только 'д', 'о' или 'в'\n";
	}
}