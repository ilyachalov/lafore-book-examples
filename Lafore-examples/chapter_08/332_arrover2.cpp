// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// arrover2.cpp
// демонстрация создания безопасного массива, проверяющего
// свои индексы при использовании
// (используется общая функция для установки и получения значения)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;
// #include <process.h> // для функции exit не понадобился

const int LIMIT = 100; // размер массива

class safearray // класс, реализующий «безопасный» массив
{
private:
	int arr[LIMIT];
public:
	// обратите внимание, что функция возвращает ссылку!
	int& access(int n)
	{
		if (n < 0 || n >= LIMIT)
			{ wcout << L"Ошибочный индекс!"; exit(1); }
		return arr[n];
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	safearray sa1;

	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		// используем функцию слева от знака присваивания (=)
		sa1.access(j) = j * 10;

	// показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		// используем функцию справа от знака присваивания (=)
		int temp = sa1.access(j);
		wcout << L"Элемент " << j << L" равен " << temp << endl;
	}

	return 0;
}