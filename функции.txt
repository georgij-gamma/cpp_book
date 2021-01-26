//  функция возвращает большее из двух чисел
//arrobj.cpp -- functions with array objects
#include <iostream>

struct box
{
char maker [40];
float height;
float width;
float length;
float volume;
};

template <typename T>
T max (const T &a, const T &b);

int main()
{   
    box cont {"first", 3, 2};
    double mn = max (cont.height, cont.width);
    std::cout << mn << "\n";

    return 0;
}

template <typename T>
T max (const T &a, const T &b)
{
    return a > b ? a : b;
    
}
//////////////////////////////////////////////

// Unicode
#include <iostream>
#include <windows.h>

template <class TYPE>
void PrintTwice(TYPE data);

int main(int argc, char* argv[])
{   
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    PrintTwice(5);
    //system("pause");
    return 0;
}

template <class TYPE>
void PrintTwice(TYPE data)
{
    std::cout << "Удвоенное значение: " << data * 2 << std::endl;
}