// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// pubpriv.cpp
// Тестирование производных классов с типом наследования public или private.

// Данную программу не предполагается запускать, так как в отмеченных ниже
// в комментариях местах компилятор выдаст ошибки и не сможет создать исполняемый файл.

#include <iostream>
using namespace std;

// Правила доступа к методам базового класса A совпадают с правилами доступа к
// полям базового класса A. Поэтому, чтобы сократить код этого примера, в базовый
// класс A включены только поля, методы не описаны.

class A // базовый класс
{
private:
	int privdataA;
protected:
	int protdataA;
public:
	int pubdataA;
};

class B : public A // производный класс с типом наследования public
{
public:
	void funct()
	{
		int a;
		a = privdataA; // ошибка: член базового класса privdataA недоступен
		a = protdataA; // так можно
		a = pubdataA;  // так можно
	}
};

class C : private A // производный класс с типом наследования private
{
public:
	void funct()
	{
		int a;
		a = privdataA; // ошибка: член базового класса privdataA недоступен
		a = protdataA; // так можно
		a = pubdataA;  // так можно
	}
};

int main()
{
	int a;

	B objB;
	a = objB.privdataA; // ошибка: член базового класса privdataA недоступен
	a = objB.protdataA; // ошибка: член базового класса protdataA недоступен
	a = objB.pubdataA;  // так можно

	C objC;
	a = objC.privdataA; // ошибка: член базового класса privdataA недоступен
	a = objC.protdataA; // ошибка: член базового класса protdataA недоступен
	a = objC.pubdataA;  // ошибка: член базового класса pubdataA недоступен

	return 0;
}