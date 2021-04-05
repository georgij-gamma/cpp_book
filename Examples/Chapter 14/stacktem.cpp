// stacktem.cpp -- тестирование шаблонного класса стека
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st;                                      // создание пустого стека
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"         // A - добавить заказ,
         << "P to process a PO, or Q to quit.\n";               // P - обработать заказ, Q - выйти
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";     // Ввод номера добавляемого заказа
                      cin >> po;
                      if (st.isfull())
                          cout << "stack already full\n";       // стек уже полон
                      else
                          st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                          cout << "stack already empty\n";      // стек уже пуст
                      else {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";  // заказ извлечен
                          break;
                      }
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0; 
}
