// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// strobj.cpp
// строка как класс

// для использования небезопасных функций wcscpy и wcscat
#define _CRT_SECURE_NO_WARNINGS

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cstring> // для функций wcscpy, wcslen и wcscat не понадобился
using namespace std;

class String // класс, представляющий строку (массив символов)
{
private:
	// enum { SZ = 80 }; // максимальный размер строки (нестандартный синтаксис)
	static const int SZ = 80; // максимальный размер строки
							  // (одна константа для всех объектов, статическая)
	wchar_t str[SZ];          // сама строка
public:
	String() // конструктор без параметров
		{ str[0] = L'\0'; }
	String(const wchar_t s[]) // конструктор с одним параметром
	{
		wcscpy(str, s);
		// wcscpy_s(str, SZ, s); // рекомендуемый более безопасный вариант
	}
	void display() // показ строки на экране
		{ wcout << str; }
	void concat(String s2) // сложение строк
	{
		if (wcslen(str) + wcslen(s2.str) < SZ)
			wcscat(str, s2.str);
			// wcscat_s(str, SZ, s2.str); // рекомендуемый более безопасный вариант
		else
			wcout << L"\nПереполнение!";
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	String s1(L"С Новым годом! ");    // конструктор с одним параметром
	String s2 = L"С новым счастьем!"; // аналогично, но в другой форме
	String s3;                        // конструктор без параметров

	// в объекте-строке s1 при определении последним символом идет пробел, чтобы
	// в дальнейшем (см. ниже) при сложении строк две фразы разделились пробелом,
	// а слова не слепились вместе

	wcout << L"s1 = "; s1.display();  // показываем все строки
	wcout << L"\ns2 = "; s2.display();
	wcout << L"\ns3 = "; s3.display();
	
	s3 = s1;                          // присвоение
	wcout << L"\ns3 = "; s3.display();

	s3.concat(s2);                    // сложение: s3 = s3 + s2
	wcout << L"\ns3 = "; s3.display();
	wcout << endl;

	return 0;
}