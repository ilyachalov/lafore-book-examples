// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// reforder.cpp
// упорядочивает по возрастанию пары чисел

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	void order(int&, int&); // прототип

	int n1 = 99, n2 = 11; // неупорядоченная пара
	int n3 = 22, n4 = 88; // упорядоченная пара

	order(n1, n2); // упорядочивание обеих пар
	order(n3, n4);
	
	wcout << L"n1=" << n1 << endl; // вывод результатов
	wcout << L"n2=" << n2 << endl;
	wcout << L"n3=" << n3 << endl;
	wcout << L"n4=" << n4 << endl;

	return 0;
}

void order(int& numb1, int& numb2) // упорядочивает два числа
{
	if (numb1 > numb2)    // если первое число больше второго,
	{
		int temp = numb1; // то меняем их местами
		numb1 = numb2;
		numb2 = temp;
	}
}