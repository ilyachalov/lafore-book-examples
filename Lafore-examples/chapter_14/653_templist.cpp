// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// templist.cpp
// реализация класса, представляющего связный список, в виде шаблона

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

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

	linklist<double> ld;   // ld — объект класса linklist<double>

	ld.additem(151.5);     // добавим три числа типа double в связный список ld
	ld.additem(262.6);
	ld.additem(373.7);
	ld.display();          // выведем на экран все элементы связного списка ld

	linklist<wchar_t> lch; // lch — объект класса linklist<wchar_t>

	lch.additem(L'а');     // добавим три широких символа в связный список lch
	lch.additem(L'б');
	lch.additem(L'в');
	lch.display();         // выведем на экран все элементы связного списка lch
	wcout << endl;
	
	return 0;
}