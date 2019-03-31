// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// cardenum.cpp
// карточная игра с использованием перечислений

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int jack = 11; // именованные достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;

enum Suit { clubs, diamonds, hearts, spades }; // масти

struct card
{
	int number; // достоинство карты
	Suit suit;  // масть
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	card temp, chosen, prize; // определение карт
	int position;

	card card1 = { 7, clubs };     // инициализация карты 1
	wcout << L"Карта 1: 7 треф\n";
	card card2 = { jack, hearts }; // инициализация карты 2
	wcout << L"Карта 2: валет червей\n";
	card card3 = { ace, spades };  // инициализация карты 3
	wcout << L"Карта 3: туз пик\n";

	prize = card3; // запоминаем карту 3

	wcout << L"Меняем местами карту 1 и карту 3...\n";
	temp = card3; card3 = card1; card1 = temp;
	wcout << L"Меняем местами карту 2 и карту 3...\n";
	temp = card3; card3 = card2; card2 = temp;
	wcout << L"Меняем местами карту 1 и карту 2...\n";
	temp = card2; card2 = card1; card1 = temp;

	wcout << L"На какой позиции (1, 2 или 3) теперь туз пик? ";
	wcin >> position;

	switch (position)
	{
	case 1: chosen = card1; break;
	case 2: chosen = card2; break;
	case 3: chosen = card3; break;
	}
	
	if (chosen.number == prize.number && // сравнение карт
		chosen.suit == prize.suit)
		wcout << L"Правильно! Вы выиграли!\n";
	else
		wcout << L"Неверно. Вы проиграли.\n";

	return 0;
}