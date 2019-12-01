// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// normbase.cpp
// неоднозначная ссылка на базовый класс

class Parent
{
protected:
	int basedata;
};

class Child1 : public Parent
	{ };

class Child2 : public Parent
	{ };

class Grandchild : public Child1, public Child2
{
public:
	int getdata()
		{ return basedata; } // ОШИБКА: неоднозначность
};