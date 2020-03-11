# lafore-book-examples
Примеры и решения упражнений из книги Роберта Лафоре «ООП в C++», 4-е издание (перевод с английского на русский язык).

Пока только для 2-13 глав (к первой главе в книге нет ни примеров, ни упражнений). Всего в книге 16 глав. Данный проект начат в 2019 году.

Книга вышла в оригинале на английском языке в 2001 году. С тех пор автор новых редакций не выпускал, а внесение исправлений и дополнений книге не помешало бы, учитывая, как минимум, несколько крупных изменений стандарта языка C++ за прошедшие 18 лет.

Кроме того, автор не рассчитывал на русский язык. Переводчик просто перевел с английского на русский комментарии и строковые константы. В итоге студент после запуска примеров из книги получает в консоли вместо русских букв кракозябры.

Я переписал примеры из книги с использованием Юникода (широких символов). То есть, к примеру, вместо cout и cin используются их версии для широких символов wcout и wcin, вместо char используется wchar_t и так далее.

Тексты программ разложены в две папки: 1) [Lafore-examples](https://github.com/ilyachalov/lafore-book-examples/tree/master/Lafore-examples) (примеры); 2) [Lafore-exercise-solutions](https://github.com/ilyachalov/lafore-book-examples/tree/master/Lafore-exercise-solutions) (решения упражнений). Внутри этих папок файлы еще разбиты по главам. Названия файлов с примерами начинаются трехзначным числом — это номер страницы в книге, на которой встречается этот пример. В названиях файлов с решениями упражнений указан номер главы и номер упражнения.

Тексты программ сохранены в файлах с расширением ".cpp" в кодировке UTF-8 с сигнатурой (BOM). Завершения строк выполнены в формате Windows (CR LF).

Все выложенные тут программы были собраны без ошибок в среде «Visual Studio Community 2017», запускались и тестировались в операционной системе «Windows 7 Профессиональная» (SP1).

Переключение стандартных потоков ввода и вывода в режим Юникода выполнено с помощью нестандартной для языка C++ функции \_setmode, поэтому в Linux, видимо, работать не будет.
## lafore-console-graphics-lite
Библиотека (в папке [Lafore-console-graphics-lite](https://github.com/ilyachalov/lafore-book-examples/tree/master/Lafore-console-graphics-lite)), содержащая функции «упрощенного варианта консольной графики», написанные Лафоре для использования в примерах книги. Подробное ее описание можно посмотреть в приложении «Д» к книге (стр.824-835).

Используется в примерах и упражнениях:
* [179_circstrc.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_05/179_circstrc.cpp) 5-й главы;
* [225_circles.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_06/225_circles.cpp) и [231_circtor.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_06/231_circtor.cpp) 6-й главы;
* [380_multshap.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_09/380_multshap.cpp) 9-й главы;
* [461_horse.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_10/461_horse.cpp) 10-й главы;
* [486_virtshap.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_11/486_virtshap.cpp) и [11chapter_08exercise.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-exercise-solutions/chapter_11/11chapter_08exercise.cpp) 11-й главы;
* многофайловой программе [elev](https://github.com/ilyachalov/lafore-book-examples/tree/master/Lafore-examples/chapter_13/elev) 13-й главы.

Кроме использования Юникода (широких символов) я еще внес некоторые изменения: 1) добавил функцию end_graphics, которая возвращает настройки цвета текста консоли к тем, которые были установлены до запуска программы; 2) изменил функцию set_cursor_pos так, чтобы графические объекты рисовались относительно текущего положения курсора, а не относительно левого верхнего угла.
## вывод на печать
Для реализации вывода текста на печать в примерах 12-й главы использованы функции из набора Windows API (через функции Windows GDI). В названия файлов, где используются эти функции, добавлена концовка «_winapi»:
* [589_ezprint_winapi.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_12/589_ezprint_winapi.cpp);
* [589_oprint_winapi.cpp](https://github.com/ilyachalov/lafore-book-examples/blob/master/Lafore-examples/chapter_12/589_oprint_winapi.cpp).
