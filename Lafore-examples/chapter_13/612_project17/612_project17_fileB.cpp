﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 612_project17_fileB.cpp

#include <iostream>

namespace                    // неименованное пространство имен,
{                            // уникальное для текущего файла
	int gloVar = 222;
}

void funcB()
	{ std::cout << gloVar; } // выводит на экран число 222

int main() {}  // функция main обязательно должна быть определена в одном из файлов
			   // многофайловой программы