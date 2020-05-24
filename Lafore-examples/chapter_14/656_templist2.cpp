// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// templist.cpp
// реализация класса, представляющего связный список, в виде шаблона
// (демонстрация возможности хранения объектов класса employee в этом связном списке)

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int LEN = 80;  // максимальная длина фамилий работников

class employee       // класс employee, представляющий работника
{
private:
	wchar_t name[LEN];    // фамилия работника
	unsigned long number; // номер работника
public:
	friend wistream& operator>> (wistream& s, employee& e);
	friend wostream& operator<< (wostream& s, employee& e);
};

wistream& operator>> (wistream& s, employee& e)
{
	wcout << L"\n Введите фамилию: "; wcin >> e.name;
	wcout << L" Введите номер: "; wcin >> e.number;
	return s;
}

wostream& operator<< (wostream& s, employee& e)
{
	wcout << L"\n Фамилия: " << e.name;
	wcout << L"\n Номер: " << e.number;
	return s;
}

template<class TYPE> // структура link<TYPE>
struct link          // представляет элемент связного списка
                     // внутри этой структуры термин «link» означает link<TYPE>
{
	TYPE data;            // данные
	link* next;           // указатель на следующий элемент связного списка
};

template<class TYPE> // класс linklist<TYPE>
class linklist       // представляет связный список
                     // внутри этого класса термин «linklist» означает linklist<TYPE>
{
private:
	link<TYPE>* first;    // указатель на первый элемент связного списка
public:
	linklist()            // конструктор без аргументов
		{ first = NULL; } // первого элемента связного списка пока нет
	// примечание: неплохо бы здесь иметь и деструктор; для упрощения не показываем его
	void additem(TYPE d); // добавление элемента в связный список
	void display();       // вывод на экран всех элементов связного списка
};

template<class TYPE>
void linklist<TYPE>::additem(TYPE d)      // добавление элемента в связный список
{
	link<TYPE>* newlink = new link<TYPE>; // выделим память под новый элемент,
	newlink->data = d;                    // запишем в него данные,
	newlink->next = first;                // запишем в него указатель на предыдущий элемент
	                                      // (новый элемент добавляется в начало связного списка)
	first = newlink;                      // новый элемент теперь считается первым элементом
}

template<class TYPE>
void linklist<TYPE>::display()          // вывод на экран всех элементов связного списка
{
	link<TYPE>* current = first;        // начиная с первого элемента,
	while (current != NULL)             // переберем в цикле все элементы связного списка
	{
		wcout << endl << current->data; // вывести данные из элемента связного списка на экран
		current = current->next;        // перейти к следующему элементу
	}
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	linklist<employee> lemp;   // lemp — объект класса linklist<employee>
	employee emptemp;          // для временного хранения объекта класса employee
	wchar_t ans;               // ответ пользователя: 'д' (да) или 'н' (нет)

	do
	{
		wcin >> emptemp;       // получить данные работника от пользователя
		lemp.additem(emptemp); // и добавить их в связный список lemp
		wcout << L"\nДобавить еще одного работника (д/н)? ";
		wcin >> ans;
	} while (ans != L'н');     // окончание ввода — по нажатию 'н'
	
	lemp.display();            // вывести на экран все элементы связного списка
	wcout << endl;
	
	return 0;
}