// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// mylib.h
// интерфейс библиотеки классов (определения классов с объявлениями методов)

#pragma once        // запрет повторных включений
#include <string>   // для работы с std::wstring

enum genre_list { Детектив, Фантастика, Классика };

class book // класс, представляющий книгу в магазине
{
private:
	std::wstring title; // название
	genre_list genre;   // жанр
	float price;        // цена
public:
	// конструктор (определение)
	book(std::wstring t, genre_list g, float p) : title(t), genre(g), price(p)
		{ }
	std::wstring ret_title() const; // вернуть название книги (объявление метода)
	genre_list ret_genre() const;   // вернуть жанр книги (объявление метода)
	float ret_price() const;        // вернуть цену книги (объявление метода)
};

class buyer // класс, представляющий покупателя в магазине
{
private:
	std::wstring name;         // имя покупателя
	genre_list favorite_genre; // любимый жанр
	float sum_of_money;        // денежная сумма, которую покупатель готов потратить
public:
	// конструктор (определение)
	buyer(std::wstring n, genre_list fg, float m) : name(n), favorite_genre(fg), sum_of_money(m)
		{ }
	std::wstring ret_name() const;  // вернуть имя покупателя (объявление метода)
	bool examine_genre(book) const; // проверить жанр книги (объявление метода)
	bool examine_price(book) const; // проверить цену книги (объявление метода)
};