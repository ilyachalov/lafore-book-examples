// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// asso_arr.cpp
// использует отображение (map) в качестве ассоциативного массива

// #pragma warning (disable:4786) // для работы с отображениями
                                  // (только для компиляторов Microsoft)
                                  // эта директива не понадобилась

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <string>       // для работы с классом wstring
#include <map>          // для работы с контейнером map
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wstring name;
	int pop;

	wstring states[] = { L"Вайоминг", L"Колорадо", L"Невада",
	                     L"Монтана", L"Аризона", L"Айдахо" };
	int pops[] = { 470, 2890, 800, 787, 2718, 944 };

	map<wstring, int, less<wstring>> mapStates;      // отображение
	map<wstring, int, less<wstring>>::iterator iter; // итератор

	for (int j = 0; j < 6; j++)
	{
		name = states[j];                 // получить данные из массивов
		pop = pops[j];
		mapStates[name] = pop;            // занести их в отображение
	}
	
	wcout << L"Введите название штата: "; // получить штат от пользователя
	wcin >> name;

	pop = mapStates[name];                // найти население введенного штата
	wcout << L"Население: " << pop << L" 000\n";

	wcout << endl;                        // вывести всё отображение на экран
	for (iter = mapStates.begin(); iter != mapStates.end(); iter++)
		wcout << (*iter).first << L' ' << (*iter).second << " 000\n";
	
	return 0;
}