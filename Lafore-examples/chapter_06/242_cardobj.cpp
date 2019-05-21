// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// cardobj.cpp
// игральные карты в качестве объектов

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades }; // масти

const int jack = 11;    // именованные достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;

class card
{
private:
	int number; // достоинство карты
	Suit suit;  // масть
public:
	card() // конструктор без аргументов
		{ }
	card(int n, Suit s) : number(n), suit(s) // конструктор с двумя аргументами
		{ }
	void display();     // вывод карты на экран (прототип функции)
	bool isEqual(card); // результат сравнения карт (прототип функции)
};

void card::display() // вывод карты на экран
{
	if (number >= 2 && number <= 10)
		wcout << number << L" ";
	else
		switch (number)
		{
		case jack:  wcout << L"валет ";  break;
		case queen: wcout << L"дама ";   break;
		case king:  wcout << L"король "; break;
		case ace:   wcout << L"туз ";    break;
		}

	switch (suit)
	{
	case clubs:    wcout << L"треф";   break;
	case diamonds: wcout << L"бубен";  break;
	case hearts:   wcout << L"червей"; break;
	case spades:   wcout << L"пик";    break;
	}
}

bool card::isEqual(card c) // сравнение двух карт
{
	return (number == c.number && suit == c.suit) ? true : false;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	card temp, chosen, prize; // три карты
	int position;

	card card1(7, clubs);                     // определение и инициализация карты 1
	wcout << L"Карта 1: "; card1.display();   // вывод карты 1 на экран
	card card2(jack, hearts);                 // определение и инициализация карты 2
	wcout << L"\nКарта 2: "; card2.display(); // вывод карты 2 на экран
	card card3(ace, spades);                  // определение и инициализация карты 3
	wcout << L"\nКарта 3: "; card3.display(); // вывод карты 3 на экран

	prize = card3; // карту prize будет необходимо угадать

	wcout << L"\nМеняем местами карту 1 и карту 3...";
	temp = card3; card3 = card1; card1 = temp;
	wcout << L"\nМеняем местами карту 2 и карту 3...";
	temp = card3; card3 = card2; card2 = temp;
	wcout << L"\nМеняем местами карту 1 и карту 2...";
	temp = card2; card2 = card1; card1 = temp;

	wcout << L"\nНа какой позиции (1, 2 или 3) теперь "; prize.display(); wcout << " ? ";
	wcin >> position; // ввод позиции игроком

	switch (position)
	{
	case 1: chosen = card1; break; // chosen – карта на позиции, выбранной игроком
	case 2: chosen = card2; break;
	case 3: chosen = card3; break;
	}
	
	if (chosen.isEqual(prize)) // сравнение карт
		wcout << L"Правильно! Вы выиграли!";
	else
		wcout << L"Неверно. Вы проиграли.";
	wcout << L" Вы выбрали карту "; chosen.display(); wcout << endl;

	return 0;
}