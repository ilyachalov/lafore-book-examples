// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 10chapter_02exercise.cpp
// Дан класс String из примера 440_newstr.cpp этой (10-й) главы.
// Требуется добавить в этот класс метод upit, который преобразует
// строку в верхний регистр. Для этого предлагается использовать
// библиотечную функцию towupper. В функции main требуется написать
// программу, тестирующую добавленный метод.

// для использования небезопасной функции wcscpy
#define _CRT_SECURE_NO_WARNINGS

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cstring> // для функций wcscpy и wcslen не понадобился
// #include <cctype>  // для функции towupper не понадобился
using namespace std;

class String // класс, представляющий строку (массив символов)
{
private:
	wchar_t* str; // указатель на строку
public:
	String(const wchar_t* s) // конструктор с одним параметром
	{
		int length = wcslen(s);        // вычисляем длину строки
		str = new wchar_t[length + 1]; // выделяем необходимую память
		wcscpy(str, s);                // копируем строку
	}
	~String() // деструктор
		{ delete[] str; }              // освобождаем память
	void display() const // вывод строки на экран
		{ wcout << str << endl; }
	void upit(); // метод преобразует строку в верхний регистр
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	// создадим объекты нашего класса String и покажем их на экране
	String s1 = L"Тише едешь — дальше будешь.";         // кириллица
	String s2 = L"Who knows nothing doubts nothing.";   // латиница
	String s3 = L"Кто не знает ничего doubts nothing."; // смесь кириллицы и латиницы
	wcout << L"s1 = "; s1.display();
	wcout << L"s2 = "; s2.display();
	wcout << L"s3 = "; s3.display();
	
	wcout << endl;

	// преобразуем строки в верхний регистр и покажем результаты на экране
	s1.upit();
	s2.upit();
	s3.upit();
	wcout << L"s1 = "; s1.display();
	wcout << L"s2 = "; s2.display();
	wcout << L"s3 = "; s3.display();

	return 0;
}

// метод преобразует строку в верхний регистр
void String::upit()
{
	// если не установить русскую локаль для категории LC_CTYPE,
	// функция towupper сработает только для латиницы, так как эта
	// функция является локалезависимой, а по умолчанию для программ
	// на языке C++ устанавливается локаль "C" (латинская буква "C"),
	// при которой символы интерпретируются как однобайтовые со значением
	// всегда меньше 256
	setlocale(LC_CTYPE, "ru-RU");
	
	int length = wcslen(str);
	for (int j = 0; j < length; j++)
		*(str + j) = towupper(*(str + j));
}