// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

#include <io.h>     // для функции _setmode
#include <fcntl.h>  // для константы _O_U16TEXT
#include <iostream> // для работы с std::wcout

#include "mylib.h"  // интерфейс библиотеки классов

// книжный магазинчик за углом
const unsigned int MAX_BOOKS = 5;
const book b[MAX_BOOKS] = {
	{L"Война и мир", Классика, 1200.51},
	{L"Сто лет тому вперед", Фантастика, 954.14},
	{L"Война миров", Фантастика, 1050.47},
	{L"Этюд в багровых тонах", Детектив, 1300.22},
	{L"Долгое ожидание", Детектив, 625.98}
};

// покупатель
const buyer man(L"Илья", Фантастика, 1000);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	// в магазин зашел покупатель
	std::wcout << L"Добро пожаловать, " << man.ret_name() << L"." << std::endl;
	std::wcout << L"Сегодня у нас в продаже " << MAX_BOOKS << L" книг." << std::endl;
	std::wcout << std::endl;

	// покупатель рассматривает книги на полках магазина
	bool ok = false; // подобрал или не подобрал книгу
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		std::wcout << i + 1 << L"-я книга: \"" << b[i].ret_title() << L"\". ";
		if (man.examine_genre(b[i]))
		{
			std::wcout << L"Жанр подходящий... ";
			if (man.examine_price(b[i]))
			{
				std::wcout << L"денег хватает... беру!" << std::endl;
				ok = true;
				break;
			}
			else
				std::wcout << L"дороговато...";
		}
		else
			std::wcout << L"Такое мне не нравится...";

		std::wcout << std::endl;
	}
	std::wcout << std::endl;

	// покупатель покидает магазин
	if (ok)
		std::wcout << L"Спасибо за покупку. Приходите еще.";
	else
		std::wcout << L"До свидания.";
	std::wcout << std::endl;

	// конец программы
	return 0;
}