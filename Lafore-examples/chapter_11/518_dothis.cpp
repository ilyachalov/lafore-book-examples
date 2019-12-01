// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// dothis.cpp
// обращение к данным объекта с помощью указателя this

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>  // для функций ввода/вывода
using namespace std;

class what
{
private:
	int alpha;
public:
	void tester()
	{
		this->alpha = 11;     // то же, что alpha = 11;
		wcout << this->alpha; // то же, что wcout << alpha;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	what w;
	w.tester();
	wcout << endl;

	return 0;
}