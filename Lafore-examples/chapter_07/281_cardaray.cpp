// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// cardaray.cpp
// массив объектов класса игральных карт

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cstdlib> // для функций srand и rand не понадобился
#include <ctime>      // для функции time
using namespace std;

enum Suit { clubs, diamonds, hearts, spades }; // масти

const int jack = 11;    // именованные достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;

class card // класс, представляющий игральную карту
{
private:
	int number; // достоинство карты
	Suit suit;  // масть
public:
	card() // конструктор без аргументов
		{ }
	void set(int n, Suit s) // установка достоинства и масти карты
		{ number = n; suit = s; }
	void display(); // вывод карты на экран (прототип функции)
};

void card::display() // вывод карты на экран
{
	if (number >= 2 && number <= 10)
		wcout << number;
	else
		switch (number)
		{
		case jack:  wcout << L'J'; break;
		case queen: wcout << L'Q'; break;
		case king:  wcout << L'K'; break;
		case ace:   wcout << L'A'; break;
		}

	switch (suit)
	{
	// коды 5, 4, 3 и 6 верны для кодовой страницы 437, а у нас — Юникод
	case clubs:    wcout << L'♣'; break; // или L'\x2663' вместо static_cast<char>(5)
	case diamonds: wcout << L'♦'; break; // или L'\x2666' вместо static_cast<char>(4)
	case hearts:   wcout << L'♥'; break; // или L'\x2665' вместо static_cast<char>(3)
	case spades:   wcout << L'♠'; break; // или L'\x2660' вместо static_cast<char>(6)
	}
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	card deck[52]; // массив объектов класса, представляющего игральную карту
	int j; // для счетчика циклов
	
	// создаем упорядоченную колоду карт
	for (j = 0; j < 52; j++)
	{
		int num = (j % 13) + 2; // 4 серии по 13 карт = 52 карты,
		                        // каждая серия — это значения от 2 до 14
		Suit su = Suit(j / 13); // 13 раз значение перечисления Suit с кодом 0 (трефы),
		                        // 13 раз — с кодом 1 (бубны), 13 раз — с кодом 2 (черви),
		                        // 13 раз — с кодом 3 (пики)
		deck[j].set(num, su);
	}
	
	// показываем исходную колоду на экране
	wcout << L"Исходная колода:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
			wcout << endl;
		else                 // иначе, если карта не 13-я, 26-я, 39-я или 52-я,
			wcout << L" ";   // то выводим пробел, разделяющий карты одной масти
	}

	srand(time(NULL)); // инициализируем генератор случайных чисел
	                   // значением текущего времени компьютера, на котором
	                   // запускается программа; из-за того, что при запуске программы
	                   // время каждый раз будет разное, колода каждый раз будет перемешана
	                   // по-разному
	// перемешиваем колоду карт с помощью генератора случайных чисел
	for (j = 0; j < 52; j++)
	{
		int k = rand() % 52; // выбираем случайную карту из 52 карт в колоде
		card temp = deck[j]; // и меняем ее с текущей, определенной счетчиком цикла
		deck[j] = deck[k];
		deck[k] = temp;
	}

	// показываем перемешанную колоду на экране
	wcout << L"\nПеремешанная колода:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
			wcout << endl;
		else                 // иначе, если карта не 13-я, 26-я, 39-я или 52-я,
			wcout << L" ";   // то выводим пробел, разделяющий карты одной масти
	}

	return 0;
}