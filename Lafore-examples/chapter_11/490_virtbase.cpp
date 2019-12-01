// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// virtbase.cpp
// виртуальные базовые классы

class Parent
{
protected:
	int basedata;
};

class Child1 : virtual public Parent // совместно использует копию класса Parent
	{ };

class Child2 : virtual public Parent // совместно использует копию класса Parent
	{ };

class Grandchild : public Child1, public Child2
{
public:
	int getdata()
		{ return basedata; } // ТАК МОЖНО: неоднозначность отсутствует, так как
	                         // существует только одна копия базового класса Parent,
	                         // которую совместно используют классы Child1 и Child2
};