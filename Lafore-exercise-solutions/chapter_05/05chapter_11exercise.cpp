// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_11exercise.cpp
// программа должна получать от пользователя две денежные суммы в виде
// структуры sterling (из упражнения 10 главы 4), складывать эти значения
// и выводить результат на экран, для этого разработать три функции

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct sterling // денежная сумма в старой английской системе
{
	int pounds;    // фунты (1 фунт = 20 шиллингов = 240 пенсов)
	int shillings; // шиллинги (1 шиллинг = 12 пенсов)
	int pences;    // пенсы
};

sterling getSterling();                         // прототипы функций
sterling sumSterling(sterling s1, sterling s2);
void outSterling(sterling s);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	sterling ster, ster1, ster2; // для суммы и слагаемых

	// получаем две денежные суммы
	wcout << L"1. "; ster1 = getSterling();
	wcout << L"2. "; ster2 = getSterling();
	// складываем их
	ster = sumSterling(ster1, ster2);
	// выводим результат на экран
	wcout << L"Сумма этих денежных сумм: ";
	outSterling(ster);
	wcout << endl;

	return 0;
}

// функция получает от пользователя денежную сумму в фунтах, шиллингах,
// пенсах и возвращает структурное значение типа sterling
sterling getSterling()
{
	sterling res;
	wcout << L"Введите сумму (фунты, шиллинги и пенсы через пробел): ";
	wcin >> res.pounds >> res.shillings >> res.pences;
	return res;
}

// функция возвращает сумму двух заданных денежных сумм
sterling sumSterling(sterling s1, sterling s2)
{
	sterling sum;
	long p; // сумма в пенсах
	p = s1.pounds * 240 + s1.shillings * 12 + s1.pences + // переводим всё в пенсы
		s2.pounds * 240 + s2.shillings * 12 + s2.pences;
	sum.pounds = p / 240;
	sum.shillings = (p % 240) / 12;
	sum.pences = (p % 240) % 12;
	return sum;
}

// функция выводит заданное значение на экран
void outSterling(sterling s)
{
	wcout << s.pounds << L" фунтов, " << s.shillings << L" шиллингов, " << s.pences << L" пенсов";
}