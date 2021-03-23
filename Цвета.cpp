// устанавливает цвет текста и фона  в консоли  
// 2 - значение цвета фона, 0 - значение цвета текста 
system("color 20" );
cout << "TEXT";
/* Атрибуты цветов задаются в виде ДВУХ шестнадцатеричных 
цифр -- первая задает цвет фона, а вторая определяет цвет 
переднего плана. Каждая цифра может иметь следующие значения: */

0 = Черный 8 = Серый
1 = Синий 9 = Светло-синий
2 = Зеленый A = Светло-зеленый
3 = Голубой B = Светло-голубой
4 = Красный C = Светло-красный
5 = Лиловый D = Светло-лиловый
6 = Желтый E = Светло-желтый
7 = Белый F = Ярко-белый

///////////////////////////////////////////////////////////

#include <iostream.h>
#include "stdafx.h"
#include <windows.h>
 
void main()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | BACKGROUND_RED);
    cout << "Hello world!" << endl;
}
// Пример:
    SetConsoleTextAttribute(hConsoleHandle, 0xE | 0);   // жёлтый на черном
    std::cout << "This color is Yellow on black\n";
    SetConsoleTextAttribute(hConsoleHandle, 7 | 0);     // белый на черном (восстановление цвета)
///////////////////////////////////////////////////////////

#include <iostream.h>
#include "stdafx.h"
#include <windows.h>
enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
		DarkGray 	  = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};
 
void SetColor(ConsoleColor text, ConsoleColor background) 
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text, ConsoleColor background) // перегрузка, чтобы и int и ConsoleColor
{												 // пользоваться: SetColor(Black, Red) и SetColor(0, 4)
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int main()
{
   SetColor(Blue,Black); 
   std::cout << "H1"; // цвет текста голубой, цвет фона черный
}
/* Почему используется побитовый сдвиг именно на 4?
Значение в диапазоне от 0 до 15 занимает 4 бита - 0000, соответственно, чтобы сохранить значения двух объектов внутри одного, необходимо значение одного сдвинуть на 4 бита влево.
Предположим, что: */
background = 0x9; // 9 (ярко-синий)
foreground = 0xf; // 15 (ярко-белый)
// В бинарном представлении 
background = 1001;
foreground = 1111;
// оба эти значения занимают одинаковую область младшего байта - 
0000 1111 (0x0f)
// если применить побитовый сдвиг влево для background, получится следующее:
0000 1001 << 4 == 1001 0000
// Затем, применяется побитовая дизъюнкция с foreground:
1001 0000 | 0000 1111 == 1001 1111
// И наконец, завершающей операцией является явное приведение через c-style cast к двухбайтовому типу WORD.
(WORD) 1001 1111 = 0000 0000 1001 1111 // (в big-endian)
1001 1111 0000 0000 // (в little-endian).
///////////////////////////////////////////////////////////
//////////////////////// FOR LINUX: ///////////////////////
#ifndef _COLORMODE_H_
#define _COLORMODE_H_
#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator << (std::ostream& os, const Modifier& mod)
		{
            return os << "\033[" << mod.code << "m";
        }
    };
}
#endif

// using:
#include "colormod.h"
#include <iostream>
using namespace std;
int main()
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    cout << "This ->" << red << "word" << def << "<- is red." << endl;
}
