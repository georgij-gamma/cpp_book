int is 4 bytes.
short is 2 bytes.
long is 4 bytes.

long long is 8 bytes.

Maximum values:
int: 2147483647
short: 32767
long: 2147483647
long long: 9223372036854775807

Minimum int value = -2147483648
Bits per byte = 8

/*Форма d.dddE+n означает перемещение десятичной точки на п позиций вправо, 
а форма d.dddE-n — перемещение десятичной точки на п позиций влево.*/

//* Методы форматирования*//
 // устанавливает флаг, который инструктирует cout отображать true и false вместо 1 и 0:
std::cout.setf(ios_base::boolalpha);

 // предотвратит переключение на экспоненциальную запись для больших чисел и заставит 
 // отображать шесть цифр справа от десятичной точки:
std::cout.setf(ios_base::fixed, ios_base::floatfield); 

std::cout.precision(3); // оператор заставляет cout выводить три десятичных знака после точки
std::streamsize prec = std::cout.precision(3); // сохранение предыдущего значения точности
std::cout.precision(prec); // восстановление предыдущего значения

std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed); // Сохранение исходных флагов
std::cout.setf(orig, std::ios_base::floatfield); // Восстановление сохраненных значений
 /* fmtflags — это тип, определенный в классе iosbase. orig хранит все флаги, и оператор сброса
 // использует эту информацию для восстановления установок в разделе floatfield, который включает
 // флаги для нотации с фиксированной точкой и экспоненциальной нотации.
	Метод */ setf () /* позволяет устанавливать различные состояния форматирования.
Например, при вызове метода: */
setf (ios_base :: fixed) /* объект переводится в режим
использования фиксированной десятичной точки.*/
//При вызове метода
setf (ios_base :: showpoint) /* объект переводится в режим 
отображения завершающей десятичной точки, даже если последующие 
цифры являются нулями.
	Метод */ precision () /*, указывает количество цифр, отображаемых справа от 
десятичной точки (если объект выводится в режиме fixed).
	Вызов метода */ width () /*, позволяет установить ширину поля для следующей 
операции вывода.*/
ostream & os; /* параметр типа ostream & может ссылаться на объект ostream, 
такой как cout, и на объект ofstream, подобный fout.*/
ios_base::fmtflags initial; // имя типа данных, необходимых для хранения информации.
initial = os.setf(ios_base::fixed); // сохранение исходного состояния форматирования
...
os.setf(initial); // восстановление исходного состояния форматирования*/

int is 4 bytes.
short is 2 bytes.
long is 4 bytes.

long long is 8 bytes.

Maximum values:
int: 2147483647
short: 32767
long: 2147483647
long long: 9223372036854775807

Minimum int value = -2147483648
Bits per byte = 8

/*Форма d.dddE+n означает перемещение десятичной точки на п позиций вправо, 
а форма d.dddE-n — перемещение десятичной точки на п позиций влево.*/

//* Методы форматирования*//
 // устанавливает флаг, который инструктирует cout отображать true и false вместо 1 и 0:
std::cout.setf(ios_base::boolalpha);

 // предотвратит переключение на экспоненциальную запись для больших чисел и заставит 
 // отображать шесть цифр справа от десятичной точки:
std::cout.setf(ios_base::fixed, ios_base::floatfield); 

std::cout.precision(3); // cout выводит три десятичных знака после точки
std::streamsize prec = std::cout.precision(3); // сохранение предыдущего значения точности
std::cout.precision(prec); // восстановление предыдущего значения

std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed); // Сохранение исходных флагов
std::cout.setf(orig, std::ios_base::floatfield); // Восстановление сохраненных значений
 /* fmtflags — это тип, определенный в классе iosbase. orig хранит все флаги, и оператор сброса
 // использует эту информацию для восстановления установок в разделе floatfield, который включает
 // флаги для нотации с фиксированной точкой и экспоненциальной нотации.
	Метод */ setf () /* позволяет устанавливать различные состояния форматирования.
Например, при вызове метода: */
setf (ios_base :: fixed) /* объект переводится в режим
использования фиксированной десятичной точки.*/
//При вызове метода
setf (ios_base :: showpoint) /* объект переводится в режим 
отображения завершающей десятичной точки, даже если последующие 
цифры являются нулями.
	Метод */ precision () /*, указывает количество цифр, отображаемых справа от 
десятичной точки (если объект выводится в режиме fixed).
	Вызов метода */ width () /*, позволяет установить ширину поля для следующей 
операции вывода.*/
ostream & os; /* параметр типа ostream & может ссылаться на объект ostream, 
такой как cout, и на объект ofstream, подобный fout.*/
ios_base::fmtflags initial; // имя типа данных, необходимых для хранения информации.
initial = os.setf(ios_base::fixed); // сохранение исходного состояния форматирования
...
os.setf(initial); // восстановление исходного состояния форматирования*/

// It's prog defines type name & out him on display
// this prog releas on vscode under gcc c++11
#include <iostream>
#include <string>
#include <typeinfo>

template <typename T>
void iquote (const T &p);

template <typename T>
T getT (const T &);

int main() {
using namespace std;
short a = 100;
iquote (a);
int b = 100;
iquote (b);
string c = "Hellow";
iquote (c);
double d = 777.888;
iquote (d);
float e = 777.888;
iquote (e);
char f[] = "Hellow";
iquote (f);
long g = 30;
iquote (g);
long long h = 300;
iquote (h);
long double i = 300.333L;
iquote (i);
bool j = true;
cout.setf(ios_base::boolalpha);
iquote (j);
auto gt = getT(1.1);
cout << "entered text have ";
iquote (gt);
//getT();
system("pause");
return 0;
}

template <typename T>
T getT (const T &)
{
    using namespace std;
    cout << "Enter text or number: ";
    auto t = T();   // инизиализируем auto неопределённостью
    cin >> t;
    cout << "entered text have ";
    iquote (t); 
    return t;
}

template <typename T>
void iquote (const T &p)
{
std::string t = typeid(p).name(); // выясняем имя типа
std::string type;
switch (t[0])
{
case 's':
    type = "short";
    break;
case 'i':
    type = "int";
    break;
case 'd':
    type = "double";
    break;
case 'f':
    type = "float";
    break;
case 'l':
    type = "long";
    break;
case 'e':
    type = "long double";
    break;
case 'x':
    type = "long long";
    break;
case 'b':
    type = "bool";
    break;
case 'N':
    type = "string";
    break;
case 'A':
    type = "char";
    break;
default: type = "unknown";
    break;
}
std::cout << "type " << type << ":\t\t"      // отправляем имя типа
          << "\"" << p << "\"" << std::endl; // Вывод на экран значения
}