﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// horse.cpp
// симулятор лошадиных скачек

// Длина дистанции для лошадиных скачек в Англии традиционно измеряется
// в фурлонгах (1 фурлонг = 1/8 мили). На экране будем изображать движение
// лошадей слева направо. Значит, длина дистанции будет измеряться в количестве
// столбцов (так как мы используем для симулятора консольную графику). Для
// регулировки длины дистанции для изображения на экране в программе будет
// использоваться константа CPF (columns per furlong или по-русски «длина
// фурлонга в столбцах»).

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include "msoftcon.h" // для функций консольной графики
#include <iostream>   // для функций ввода/вывода
#include <cstdlib>    // для функции random
#include <ctime>      // для функции time
using namespace std;

const int CPF = 5;       // для изображения на экране: длина фурлонга в столбцах
const int maxHorses = 7; // максимально возможное количество лошадей

class track; // класс, представляющий скаковой трек
             // (предварительное объявление класса для того, чтобы можно было
             // его использовать в тексте программы раньше, чем он будет определен)

class horse // класс, представляющий бегущую лошадь
{
private:
	const track* ptrTrack;  // скаковой трек, по которому бежит лошадь
	                        // (указатель на константу)
	const int horse_number; // номер лошади (константа)
	float finish_time;      // время со старта забега до пересечения линии финиша
	                        // (в секундах)
	float distance_run;     // длина (в фурлонгах) части дистанции, пройденной
	                        // на данный момент
public:
	// конструктор с двумя аргументами: номер лошади, указатель на трек
	horse(const int n, const track* ptrT) :
		horse_number(n),
		ptrTrack(ptrT),
		distance_run(0.0) // лошадь еще не стартовала
		{ }
	// деструктор
	~horse()
		{ }
	// метод для отображения лошади на экране
	void display_horse(const float elapsed_time);
};

class track // класс, представляющий скаковой трек
{
private:
	horse* hArray[maxHorses]; // массив указателей на объекты-лошади
	int total_horses;         // обшее количество лошадей, участвующих в забеге
	int horse_count;          // счетчик лошадей, обработанных на текущий момент времени
	                          // (в каждый момент времени нужно вычислять новое положение
	                          // каждой лошади и отображать эту лошадь на экране; счетчик
	                          // показывает сколько лошадей уже обработано)
	const float track_length; // длина трека (в фурлонгах)
	float elapsed_time;       // время, прошедшее со старта забега (в секундах)
public:
	// конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге
	track(float lenT, int nH);
	~track();                    // деструктор
	void display_track();        // метод для отображения трека на экране
	void run();                  // метод для запуска забега
	float get_track_len() const; // метод для получения длины трека
};

// метод для отображения лошади на экране
// (elapsed_time — время, прошедшее со старта забега)
void horse::display_horse(float elapsed_time)
{
	// установим курсор в нужную позицию на экране:
	// координата Х зависит от длины части дистанции пройденной лошадью на данный момент;
	// координата Y зависит от номера лошади, так как лошади отображаются по порядку сверху вниз
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);

	// все лошади отображаются разных цветов, цвет зависит от номера лошади
	set_color(static_cast<color>(cBLUE + horse_number));
	
	// вычисляем символ для отображения номера лошади
	wchar_t horse_char = L'0' + static_cast<wchar_t>(horse_number);

	// отображаем лошадь четырьмя символами:
	// пробел, закрашенный прямоугольник, номер лошади, закрашенный прямоугольник
	// (шестнадцатиричный код закрашенного прямоугольника в Юникоде — 2588)
	// (пробел нужен, чтобы стирать предыдущее местонахождение лошади)
	_putwch(L' '); _putwch(L'\x2588'); _putwch(horse_char); _putwch(L'\x2588');

	// если финиш еще не достигнут
	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)
	{
		// случайным образом генерируем одно из трех чисел: 0 или 1 или 2
		// в случае генерации 0 лошадь остается на месте,
		// в случае генерации 1 или 2 лошадь продвигается вперед на 0,2 фурлонга
		if (rand() % 3)
			distance_run += 0.2F;
		// запоминаем в поле finish_time для текущей лошади время, прошедшее
		// со старта забега
		finish_time = elapsed_time;
	}
	else // финиш достигнут
	{
		// вывести время, прошедшее со старта забега до пересечения линии финиша,
		// на экран
		int mins = int(finish_time) / 60;
		int secs = int(finish_time) - mins * 60;
		wcout << L" Время = " << mins << ":" << secs;
	}
}

// конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге
track::track(float lenT, int nH) :
	track_length(lenT), // длина трека
	total_horses(nH),   // количество лошадей, участвующих в забеге
	horse_count(0),     // на треке еще нет лошадей
	elapsed_time(0.0)   // забег еще не стартовал
{
	// инициализация консольной графики
	init_graphics();
	// количество лошадей не может быть больше указанного в константе maxHorses
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;

	// создать объекты класса horse и заполнить массив указателей на них
	for (int j = 0; j < total_horses; j++)
		hArray[j] = new horse(horse_count++, this);

	// инициализировать генерацию случайных чисел, исходя из текущего системного времени
	time_t aTime;
	srand(static_cast<unsigned>(time(&aTime)));

	// отобразить сконструированный трек на экране
	display_track();
}

// деструктор
track::~track()
{
	// освободить память, выделенную в конструкторе под объекты-лошади
	for (int j = 0; j < total_horses; j++)
		delete hArray[j];
}

// метод для отображения трека на экране
void track::display_track()
{
	// очистить экран
	clear_screen();
	// отобразить трек
	for (int f = 0; f <= track_length; f++) // цикл столбцов (фурлонгов)
		for (int r = 1; r <= total_horses * 2 + 1; r++) // цикл экранных строк (рядов)
		{
			set_cursor_pos(f * CPF + 5, r);  // установим курсор в нужное место
			if (f == 0 || f == track_length) // если это начало или конец трека
				wcout << L'\x2590';          // рисуем стартовую или финишную линию
			else                             // иначе
				wcout << L'\x2502';          // рисуем отметку очередного фурлонга
		}
}

// метод для запуска забега
void track::run()
{
	// продолжать цикл до момента нажатия любой клавиши на клавиатуре
	while (!_kbhit())
	{
		elapsed_time += 1.75; // увеличиваем время забега на 1,75 секунд
		// обрабатываем очередное движение каждой лошади
		for (int j = 0; j < total_horses; j++)
			hArray[j]->display_horse(elapsed_time);
		// функция из msoftcon.h, пауза на 500 миллисекунд
		// (то есть описанное выше увеличение времени забега elapsed_time соответствует
		// в реальном измерении интервалу времени в 500 миллисекунд)
		wait(500);
	}
	_getwch(); // принять символ с клавиатуры, возникший из-за нажатия на клавишу
	wcout << endl;
}

// метод для получения длины трека
float track::get_track_len() const
	{ return track_length; }

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	float length; // длина трека (дистанции)
	int total;    // количество лошадей, участвующих в забеге

	// получаем данные для забега от пользователя
	wcout << L"Введите длину дистанции (от 1 до 12 фурлонгов): "; wcin >> length;
	wcout << L"Введите количество лошадей (от 1 до 7): "; wcin >> total;
	wcout << endl;

	track theTrack(length, total); // создаем трек
	theTrack.run();                // запускаем забег
	wcout << endl;

	// возвратим первоначальный цвет текста в консоли
	end_graphics();

	return 0;
}