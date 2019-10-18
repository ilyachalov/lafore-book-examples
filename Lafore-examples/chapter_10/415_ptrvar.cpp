// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrvar.cpp
// указатели (переменные, содержащие адреса)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int var1 = 11;              // две целочисленные переменные
	int var2 = 22;

	wcout << &var1 << endl      // выведем на экран адреса этих переменных
	      << &var2 << endl << endl;

	int* ptr;                   // это переменная-указатель на целое

	ptr = &var1;                // присвоим ей значение адреса var1
	wcout << ptr << endl;       // и покажем на экране

	ptr = &var2;                // теперь присвоим ей значение адреса var2
	wcout << ptr << endl;       // и покажем на экране

	return 0;
}