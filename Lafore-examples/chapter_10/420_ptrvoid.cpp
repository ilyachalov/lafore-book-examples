// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrvoid.cpp
// указатель на void

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int intvar;          // целочисленная переменная
	float flovar;        // вещественная переменная

	int* ptrint;         // указатель на int
	float* ptrflo;       // указатель на float
	void* ptrvoid;       // указатель на void
	
	ptrint = &intvar;    // так можно:  int* = int*
	// ptrint = &flovar; // так нельзя: int* = float*
	// ptrflo = &intvar; // так нельзя: float* = int*
	ptrflo = &flovar;    // так можно:  float* = float*
	
	ptrvoid = &intvar;   // так можно:  void* = int*
	ptrvoid = &flovar;   // так можно:  void* = float*

	return 0;
}