// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 612_project17_fileA.cpp

#include <iostream>

namespace                    // неименованное пространство имен,
{                            // уникальное для текущего файла
	int gloVar = 111;
}

void funcA()
	{ std::cout << gloVar; } // выводит на экран число 111