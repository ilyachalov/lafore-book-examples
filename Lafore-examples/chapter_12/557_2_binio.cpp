// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// binio.cpp
// двоичный вывод в файл и чтение из файла целых чисел

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

const int MAX = 100; // размер буфера
int buff[MAX];       // буфер для целых чисел

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ошибок в формат Юникода
	_setmode(_fileno(stderr), _O_U16TEXT);

	for (int j = 0; j < MAX; j++) // заполним буфер данными
		buff[j] = j;              // (0, 1, 2, ...)
	                              // создадим выходной поток (откроем файл для записи)
	ofstream os(L"данные.dat", ios::binary);
	                              // запишем в него буфер с данными
	os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
	os.close();                   // закроем выходной поток (файл)

	for (int j = 0; j < MAX; j++) // очистим буфер
		buff[j] = 0;
	                              // создадим входной поток (откроем файл для чтения)
	ifstream is(L"данные.dat", ios::binary);
	                              // получим из него буфер с данными
	is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));

	for (int j = 0; j < MAX; j++) // проверим корректность данных
		if (buff[j] != j)
			{ wcerr << L"Некорректные данные!\n"; return 1; }
	wcout << L"Данные корректны\n";

	return 0;
}