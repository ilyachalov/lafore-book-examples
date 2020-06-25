// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// vectcon.cpp
// демонстрирует конструкторы вектора и его методы swap, empty, back, pop_back

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <vector>    // для работы с контейнером vector
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	double arr[] = { 1.1, 2.2, 3.3, 4.4 }; // массив типа double

	vector<double> v1(arr, arr + 4);       // инициализация вектора массивом
	vector<double> v2(4);                  // пустой вектор размером в 4 позиции

	v1.swap(v2);                           // обменять содержимое векторов v1 и v2

	while (!v2.empty())                    // пока вектор не пуст,
	{
		wcout << v2.back() << L' ';        // вывести на экран последний элемент
		v2.pop_back();                     // удалить последний элемент
	}                                      // вывод: 4.4 3.3 2.2 1.1

	wcout << endl;
	
	return 0;
}