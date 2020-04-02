// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// mylib.cpp
// реализация библиотеки классов (определения методов классов)

#include "mylib.h" // интерфейс библиотеки классов

////////////////////////////////////////////////////////////////////////////////
// определения методов класса book, представляющего книгу в магазине
////////////////////////////////////////////////////////////////////////////////

std::wstring book::ret_title() const // вернуть название книги
{
	return title;
}

genre_list book::ret_genre() const   // вернуть жанр книги
{
	return genre;
}

float book::ret_price() const        // вернуть цену книги
{
	return price;
}

////////////////////////////////////////////////////////////////////////////////
// определения методов класса buyer, представляющего покупателя в магазине
////////////////////////////////////////////////////////////////////////////////

std::wstring buyer::ret_name() const     // вернуть имя покупателя
{
	return name;
}

bool buyer::examine_genre(book b) const  // проверить жанр книги
{
	if (b.ret_genre() == favorite_genre)
		return true;
	else
		return false;
}

bool buyer::examine_price(book b) const  // проверить цену книги
{
	if (b.ret_price() <= sum_of_money)
		return true;
	else
		return false;
}