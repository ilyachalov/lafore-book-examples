// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// elev_app.cpp
// клиентский файл

#include "elev.h" // описатели классов

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	building theBuilding;

	while (true)
	{
		theBuilding.master_tick();       // запустить тики (такты) всех лифтов
		wait(1000);                      // пауза
		theBuilding.record_floor_reqs(); // получить запросы с этажей
		                                 // от пользователя
	}

	return 0;
}