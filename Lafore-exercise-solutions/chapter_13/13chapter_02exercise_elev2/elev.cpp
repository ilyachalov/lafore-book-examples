// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// elev.cpp
// содержит определения данных и методов классов

#include "elev.h" // включаем заголовочный файл с описателями классов

////////////////////////////////////////////////////////////////////////////////
// определения методов класса building, представляющего здание
////////////////////////////////////////////////////////////////////////////////

building::building() // конструктор
{
	wchar_t ustring[BUF_LENGTH];           // строка для номеров этажей
	init_graphics();                       // инициализируем графику
	clear_screen();                        // очищаем экран
	car = new elevator(this);              // создаём лифт
	for (int j = 0; j < NUM_FLOORS; j++)   // для каждого этажа
	{
		set_cursor_pos(3, NUM_FLOORS - j); // вывести номер этажа
		_itow(j + 1, ustring, 10);         // на экран
		wcout << setw(3) << ustring;
		floor_request[UP][j] = false;      // запросов с этажей еще не было
		floor_request[DN][j] = false;
	}
}

building::~building() // деструктор
{
	delete car; // освобождаем память, занятую ранее
	            // в конструкторе под объект-лифт
}

void building::master_tick() // главный тик, запускающий тики лифта
{
	show_floor_reqs(); // отобразить на экране запросы с этажей
	car->car_tick1();  // запустить тик 1 лифта
	car->car_tick2();  // запустить тик 2 лифта
}

void building::show_floor_reqs() const // отображение на экране запросов с этажей
{
	for (int j = 0; j < NUM_FLOORS; j++)
	{
		set_cursor_pos(SPACING, NUM_FLOORS - j);
		if (floor_request[UP][j] == true)
			wcout << L'\x25B2';            // стрелка вверх (Юникод)
		else
			wcout << L' ';                 // пробел
		set_cursor_pos(SPACING + 3, NUM_FLOORS - j);
		if (floor_request[DN][j] == true)
			wcout << L'\x25BC';            // стрелка вниз (Юникод)
		else
			wcout << L' ';                 // пробел
	}
}

void building::record_floor_reqs() // получение запросов от пассажиров с этажей
{
	wchar_t ch = L'x';                     // вспомогательный символ для ввода
	wchar_t ustring[BUF_LENGTH];           // вспомогательная строка для ввода
	int iFloor;                            // этаж, с которого был запрос
	wchar_t chDirection;                   // 'в' (вверх) или 'н' (вниз) для выбора направления

	set_cursor_pos(1, 22);                 // низ экрана

	wcout << L"Нажмите [Enter] для вызова лифта или [Esc] для выхода из программы: ";
	if (!_kbhit())                         // ждём нажатия клавиши (символ '\r')
		return;
	// Этот код требует пояснения: данный метод record_floor_reqs не используется другими
	// методами класса building или класса elevator. Он запускается в клиентской программе
	// elev_app.cpp в бесконечном цикле. Пока пользователь не нажал какую-либо клавишу,
	// цикл будет приходить к этому ветвлению if и возвращаться обратно в клиентскую
	// программу из-за инструкции return. И так — до бесконечности. Как только пользователь
	// нажмет любую клавишу на клавиатуре (не только Enter), ход программы продолжится
	// по инструкциям ниже этого комментария.

	// Почему в комментарии к этому коду в учебнике Лафоре указано, что ожидается
	// символ '\r' (CR, carriage return или по-русски «возврат каретки»)? В операционных
	// системах MS Windows в текстах символ новой строки кодируется двумя символами:
	// CR + LF ('\r' + '\n'). При нажатии клавиши Enter сгенерируются оба эти символа,
	// а функция _kbhit среагирует на первый из них, то есть '\r'.

	// wcin.ignore(10, L'\n');             // здесь у Лафоре ошибка, закомментируем
	ch = _getwch();                        // вот это правильный вариант

	// Очевидно, что чтобы проверить значение нажатой пользователем клавиши,
	// в переменную ch должно быть считано это значение. У Лафоре вместо этого
	// (видимо, по ошибке) стоит инструкция cin.ignore(10, '\n'); которая никак не
	// связана ни с переменной ch, ни с функцией _kbhit.

	if (ch == L'\x1B')                     // при нажатии клавиши Esc
		exit(0);                           // завершить программу

	set_cursor_pos(1, 22); clear_line();   // стираем ненужный текст
	set_cursor_pos(1, 22);                 // низ экрана

	wcout << L"Введите номер этажа, на котором вы находитесь: ";
	wcin.get(ustring, BUF_LENGTH);         // получаем номер этажа
	wcin.ignore(10, L'\n');                // удаляем лишние символы, включая '\n'
	iFloor = _wtoi(ustring);               // преобразуем строку в число

	wcout << L"В каком направлении будете двигаться ('в' (вверх) или 'н' (вниз)): ";
	wcin.get(chDirection);            // (избегаем множественных переводов строк)
	wcin.ignore(10, L'\n');           // удаляем лишние символы, включая '\n'
	if (chDirection == L'в' || chDirection == L'В')
		floor_request[UP][iFloor - 1] = true; // запрос на движение вверх
	if (chDirection == L'н' || chDirection == L'Н')
		floor_request[DN][iFloor - 1] = true; // запрос на движение вниз

	set_cursor_pos(1, 22); clear_line();   // стираем ненужный текст
	set_cursor_pos(1, 23); clear_line();
	set_cursor_pos(1, 24); clear_line();
}

// проверка: есть ли указанный запрос с этажа
bool building::get_floor_req(const int dir, const int floor) const
{
	return floor_request[dir][floor];
}

// установка указанного значения указанному запросу с этажа
void building::set_floor_req(const int dir, const int floor, const bool updown)
{
	floor_request[dir][floor] = updown;
}

// получить номер этажа, на котором находится кабина лифта
int building::get_cars_floor() const
{
	return car->get_floor();
}

// получить направление движения кабины лифта
direction building::get_cars_dir() const
{
	return car->get_direction();
}

////////////////////////////////////////////////////////////////////////////////
// определения методов класса elevator, представляющего лифт
////////////////////////////////////////////////////////////////////////////////

// конструктор
elevator::elevator(building* ptrB) : ptrBuilding(ptrB)
{
	current_floor = 0;                   // текущий этаж 0 (для пользователя — 1)
	old_floor = 0;                       // предыдущий этаж тоже 0
	current_dir = STOP;                  // пока кабина лифта стоит на месте
	for (int j = 0; j < NUM_FLOORS; j++) // пассажиры еще не
		destination[j] = false;          //     нажимали кнопки
	loading_timer = 0;                   // еще не началась посадка пассажиров
	unloading_timer = 0;                 // еще не началась высадка пассажиров
}

int elevator::get_floor() const // получение номера текущего этажа
{
	return current_floor;
}

direction elevator::get_direction() const // получение текущего направления
{
	return current_dir;
}

void elevator::car_tick1() // тик 1 для лифта (выбор действия)
{
	car_display();         // отображение кабины лифта на экране
	dests_display();       // отображение меток этажей, куда едут люди
	if (loading_timer)     // отсчет времени посадки пассажиров
		--loading_timer;
	if (unloading_timer)   // отсчет времени высадки пассажиров
		--unloading_timer;
	decide();              // принятие решения о следующем действии
}

void elevator::car_tick2() // тик 2 для лифта (движение кабины)
{
	move();                // передвинуть лифт, если это необходимо
}

void elevator::car_display() // отображение лифта на экране
{
	set_cursor_pos(SPACING + SPACING, NUM_FLOORS - old_floor);
	wcout << L"   ";                      // стереть лифт на старой позиции (3 пробела)
	set_cursor_pos(SPACING - 1 + SPACING, NUM_FLOORS - current_floor);
	switch (loading_timer)                // отображение погрузки в лифт
	{                                     // (Юникод)
	case 3:
		wcout << L"\x263A\x2588 \x2588 "; // дверь лифта открывается,
		break;                            // пассажиры хотят войти (слева)
	case 2:
		wcout << L" \x2588\x263A\x2588 "; // пассажиры внутри кабины с открытой дверью,
		get_destinations();               // получаем этажи назначения
		break;
	case 1:
		wcout << L" \x2588\x2588\x2588 "; // дверь лифта закрывается,
		break;                            // пассажиры внутри кабины и их не видно
	case 0:
		wcout << L" \x2588\x2588\x2588 "; // дверь лифта закрыта,
		break;                            // пассажиров нет (по умолчанию)
	}
	set_cursor_pos(SPACING + SPACING, NUM_FLOORS - current_floor);
	switch (unloading_timer)              // отображение выгрузки из лифта
	{                                     // (Юникод)
	case 3:
		wcout << L"\x2588\x263A\x2588 ";  // дверь лифта открывается,
		break;                            // видны пассажиры внутри кабины
	case 2:
		wcout << L"\x2588 \x2588\x263A";  // дверь лифта открыта,
		break;                            // пассажиры вышли из лифта (направо)
	case 1:
		wcout << L"\x2588\x2588\x2588 ";  // дверь лифта закрылась,
		break;                            // пассажиров не видно
	case 0:
		wcout << L"\x2588\x2588\x2588 ";  // дверь лифта закрыта,
		break;                            // пассажиров нет (по умолчанию)
	}
	old_floor = current_floor;            // запоминаем текущий этаж как старый
}

void elevator::dests_display() const // отображение меток этажей, куда едут люди
{
	for (int j = 0; j < NUM_FLOORS; j++)
	{
		set_cursor_pos(SPACING - 2 + SPACING, NUM_FLOORS - j);
		if (destination[j] == true)
			wcout << L'\x25A0';           // маленький квадратик (Юникод)
		else
			wcout << L' ';                // пробел
	}
}

void elevator::decide() // принятие решения о следующем действии
{
	int j;
	
	// эти флаги указывают, есть ли запросы с этажей (ЗЭ) или конечные пункты выше и ниже нас
	bool destins_above, destins_below;   // конечные пункты
	bool requests_above, requests_below; // запросы с этажей
	
	// номер этажа ближайшего запроса с этажей выше и ниже нас
	int nearest_higher_req = 0;
	int nearest_lower_req = 0;

	// убедиться, что мы не уедем выше самого верхнего этажа и ниже самого нижнего
	if ((current_floor == NUM_FLOORS - 1 && current_dir == UP)
		|| (current_floor == 0 && current_dir == DN))
		current_dir = STOP;

	// если текущий этаж является одним из пунктов назначения, высадить пассажиров
	if (destination[current_floor] == true)
	{
		destination[current_floor] = false; // удалить этот пункт назначения из списка
		if (!unloading_timer)               // начать высадку пассажиров
			unloading_timer = LOAD_TIME;
		return;                             // завершить процесс принятия решения
	}

	// если есть запрос «вверх» с этого этажа и
	// если мы едем вверх или стоим, произвести посадку пассажиров
	if ((ptrBuilding->get_floor_req(UP, current_floor) && current_dir != DN))
	{
		current_dir = UP;                   // (для случая, если лифт стоял)
		                                    // удалить ЗЭ в данном направлении движения
		ptrBuilding->set_floor_req(current_dir, current_floor, false);
		if (!loading_timer)                 // начать посадку пассажиров
			loading_timer = LOAD_TIME;
		return;                             // завершить процесс принятия решения
	}

	// если есть запрос «вниз» с этого этажа и
	// если мы едем вниз или стоим, произвести посадку пассажиров
	if ((ptrBuilding->get_floor_req(DN, current_floor) && current_dir != UP))
	{
		current_dir = DN;                   // (для случая, если лифт стоял)
		                                    // удалить ЗЭ в данном направлении движения
		ptrBuilding->set_floor_req(current_dir, current_floor, false);
		if (!loading_timer)                 // начать посадку пассажиров
			loading_timer = LOAD_TIME;
		return;                             // завершить процесс принятия решения
	}

	// проверим, есть ли другие конечные пункты или запросы с этажей выше и ниже от нас;
	// запомним ближайший этаж с запросом сверху и снизу от нас
	destins_above = destins_below = false;
	requests_above = requests_below = false;
	for (j = current_floor + 1; j < NUM_FLOORS; j++) // проверяем верхние этажи
	{
		if (destination[j])                      // если они являются пунктами назначения,
			destins_above = true;                // то установить флаг
		if (ptrBuilding->get_floor_req(UP, j) || // если есть запрос с этого этажа,
			ptrBuilding->get_floor_req(DN, j))
		{
			requests_above = true;               // то установить флаг
			if (!nearest_higher_req)             // если ранее не запомнен этаж ближайшего ЗЭ,
				nearest_higher_req = j;          // запомнить этот этаж таковым
		}
	}
	for (j = current_floor - 1; j >= 0; j--)         // проверяем нижние этажи
	{
		if (destination[j])                      // если они являются пунктами назначения,
			destins_below = true;                // то установить флаг
		if (ptrBuilding->get_floor_req(UP, j) || // если есть запрос с этого этажа,
			ptrBuilding->get_floor_req(DN, j))
		{
			requests_below = true;               // то установить флаг
			if (!nearest_lower_req)              // если ранее не запомнен этаж ближайшего ЗЭ,
				nearest_lower_req = j;           // запомнить этот этаж таковым
		}
	}

	// если нет запросов с этажей или пунктов назначения сверху или снизу,
	if (!destins_above && !requests_above &&
		!destins_below && !requests_below)
	{
		current_dir = STOP;                 // остановиться
		return;                             // завершить процесс принятия решения
	}

	// если имеются пункты назначений, а мы стоим или движемся к ним,
	if (destins_above && (current_dir == STOP || current_dir == UP))
	{
		current_dir = UP; // начать или продолжить движение вверх
		return;           // завершить процесс принятия решения
	}
	if (destins_below && (current_dir == STOP || current_dir == DN))
	{
		current_dir = DN; // начать или продолжить движение вниз
		return;           // завершить процесс принятия решения
	}

	// если мы едем вверх или остановились, а выше нас есть запрос с этажа
	if ((current_dir == UP || current_dir == STOP)
		&& requests_above)
	{
		current_dir = UP; // то ехать вверх
		return;           // завершить процесс принятия решения
	}

	// если мы едем вниз или остановились, а ниже нас есть запрос с этажа
	if ((current_dir == DN || current_dir == STOP)
		&& requests_below)
	{
		current_dir = DN; // то ехать вниз
		return;           // завершить процесс принятия решения
	}

	// если ничего из вышеперечисленного не подошло, остановиться
	current_dir = STOP;
}

void elevator::move() // движение лифта
{
	if (loading_timer || unloading_timer) // если идет посадка или высадка,
		return;                           // ничего не делать, завершить метод
	if (current_dir == UP)                // если движемся вверх,
		current_floor++;                  // увеличить номер текущего этажа
	else if (current_dir == DN)           // если движемся вниз,
		current_floor--;                  // уменьшить номер текущего этажа
}

void elevator::get_destinations() // получение номеров конечных этажей (лифт остановился)
{
	wchar_t ustring[BUF_LENGTH];                 // вспомогательный буфер для ввода
	int dest_floor;                              // этаж назначения
	set_cursor_pos(1, 22); clear_line();         // стереть верхнюю строку
	set_cursor_pos(1, 22);
	wcout << L"Лифт остановился на этаже " << (current_floor + 1) << L"..."
		<< L"\nВведите этажи назначения (0 для окончания ввода).";
	// цикл выборов этажей назначения (так как общее количество этажей равно NUM_FLOORS,
	// пассажиры могут выбрать максимум NUM_FLOORS - 1 этажей (за минусом текущего этажа))
	for (int j = 1; j < NUM_FLOORS; j++)
	{
		// в этом цикле под j подразумевается не номер этажа, а номер выбора этажа
		
		set_cursor_pos(1, 24);
		wcout << L"Выбор " << j << L" этажа назначения: ";

		wcin.get(ustring, BUF_LENGTH);           // (во избежание множественных переходов на новую строку
		wcin.ignore(10, L'\n');                  // удалить лишние символы, включая '\n')
		dest_floor = _wtoi(ustring);
		set_cursor_pos(1, 24); clear_line();     // стереть старую строку ввода
		if (dest_floor == 0)                     // если введен 0 (окончание ввода),
		{
			set_cursor_pos(1, 22); clear_line(); // стереть нижние три строки
			set_cursor_pos(1, 23); clear_line();
			set_cursor_pos(1, 24); clear_line();
			return;                              // и закончить работу метода
		}
		--dest_floor;                            // поправка на то, что в программе
		                                         // этажи нумеруются с 0, а не с 1
		if (dest_floor == current_floor)         // если выбрали текущий этаж,
			{ --j; continue; }                   // забыть его и продолжить цикл
		// если мы стояли, первый выбор этажа назначения выбирает направление движения
		if (j == 1 && current_dir == STOP)
			current_dir = (dest_floor < current_floor) ? DN : UP;
		destination[dest_floor] = true;          // запомним выбранный этаж назначения
		dests_display();                         // выведем на экран этажи назначения
	}
}