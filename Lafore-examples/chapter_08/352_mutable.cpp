// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// mutable.cpp
// демонстрация применения ключевого слова mutable к полю объекта-константы

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <string> // для стандартного класса wstring для работы со строками
using namespace std;

class scrollbar // класс, представляющий полосу прокрутки окна
{
private:
	int size;              // размер полосы прокрутки
	
	mutable wstring owner; // владелец полосы прокрутки
	                       // (это поле предваряется ключевым словом mutable,
	                       // что означает, что это поле может быть изменено,
	                       // даже если объект этого класса является константой)
public:
	scrollbar(int sz, wstring own) : size(sz), owner(own)
		{ }
	void setSize(int sz)             // изменяет размер полосы прокрутки
		{ size = sz; }
	void setOwner(wstring own) const // изменяет владельца полосы прокрутки
		                             // (несмотря на то, что изменяет поле класса,
		                             // всё равно помечается ключевым словом const)
		{ owner = own; }
	int getSize() const              // возвращает размер полосы прокрутки
		{ return size; }
	wstring getOwner() const         // возвращает владельца полосы прокрутки
		{ return owner; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	// создаем объект-константу класса scrollbar
	const scrollbar sbar(60, L"Приложение 1");

	// sbar.setSize(100);           // ОШИБКА: нельзя изменить поле объекта-константы.
	sbar.setOwner(L"Приложение 2"); // А тут ошибки нет, так как это поле в определении
	                                // класса помечено ключевым словом mutable.
	
	wcout << sbar.getSize() << L", " << sbar.getOwner() << endl;

	return 0;
}