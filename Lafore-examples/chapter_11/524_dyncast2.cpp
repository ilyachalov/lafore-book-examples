// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// dyncast2.cpp
// тестирование динамического приведения типов
// (возможность RTTI в компиляторе должна быть включена)

// В среде «Visual Studio Community 2017» возможность RTTI включается и выключается
// с помощью ключа компилятора /GR. По умолчанию эта возможность включена.

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>   // для функций ввода/вывода
//#include <typeinfo> // для операции dynamic_cast не понадобился
using namespace std;

class Base
{
protected:
	int ba;
public:
	Base() : ba(0)
		{ }
	Base(int b) : ba(b)
		{ }
	virtual void vertFunc() // нужна для динамического приведения типов
		{ }
	void show()
		{ wcout << L"Base: ba = " << ba << endl; }
};

class Derv : public Base
{
private:
	int da;
public:
	Derv(int b, int d) : da(d)
		{ ba = b; }
	void show()
		{ wcout << L"Derv: ba = " << ba << L", da = " << da << endl; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	Base* pBase = new Base(10);     // указатель на объект класса Base
	Derv* pDerv = new Derv(21, 22); // указатель на объект класса Derv

	// восходящее приведение классов: от Derv (производного) к Base (базовому)
	pBase = dynamic_cast<Base*>(pDerv);
	pBase->show();                  // "Base: ba = 21"

	pBase = new Derv(31, 32);
	// нисходящее приведение классов: от Base (базового) к Derv (производному)
	// (обязательное условие: приводимый указатель pBase должен указывать на объект
	// класса Derv, что и было соблюдено в предыдущей строке программы)
	pDerv = dynamic_cast<Derv*>(pBase);
	pDerv->show();                  // "Derv: ba = 31, da = 32"

	return 0;
}