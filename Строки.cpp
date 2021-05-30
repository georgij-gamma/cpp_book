/* Функцию, которая добавляет заданную строку к обеим сторонам другой строки. 
Функция version () не создает временную строку, вместо этого она напрямую 
изменяет исходную строку: */
const string & version(string & s1, const string & s2) // имеет побочный эффект
{
si = s2 + s1 + s2;
// Возврат ссылки, переданной функции, безопасен
return s1;
}
/* Эта функция может изменять значение s1, т.к. переменная s1, в отличие от s2,
объявлена без const.

	Способ установки размера новой строки состоит в том, чтобы присвоить
переменной n меньшую величину из переданного значения и длины строки: */
int len = strlen(str);
n = (n < len) ? n : len; // меньшее из n и len
char *p = new char[n+l];
/* Это гарантирует, что new не выделит больше пространства, чем необходимо для
хранения строки.
Если время, затраченное на вызов функции strlen() неприемлемо, можно позволить 
непосредственно выбрать меньшее из значений n и длины строки. Приведенный ниже 
цикл завершается, когда m достигает значения n или длины строки, что бы ни 
случилось первым: */
int m = 0;
while ( m <= n && str[m] != '\0')
	m++;
char *p = new char[m+l];
/* В остальном коде будет использоваться m вместо n
Выражение */ str[m] != '\0' /* вычисляется как true, когда str[m] не
является нулевым символом, и как false — в противном случае. Поскольку в 
выражении && ненулевые значения преобразуются в true, а нулевые —
в false, проверочное условие while может быть также записано следующим образом: */
while (m <= n && str[m])

/*	Подсчет цифр в числе: */
unsigned digits = 1;
while (n /= 10)
	digits++;
/* Деление числа на 10 уменьшает его запись на одну цифру.
В этом цикле подсчитывается, сколько раз можно удалить цифру из числа п до
того, как не останется ни одной цифры.
	Предположим, что исходное число содержит пять цифр и нужно 
возвратить первые три цифры. Чтобы получить данное трехзначное число, можно два раза
разделить исходное число на 10. При каждом делении числа на 10 в записи числа 
удаляется одна цифра справа. Чтобы узнать, какое количество цифр нужно удалить, 
следует просто вычислить количество цифр, которые требуется отобразить, из общего
количества цифр в представлении исходного числа. Например, чтобы отобразить 
четыре цифры числа, представленного девятью цифрами, удалите последние пять цифр:*/
unsigned long left(unsigned long num, unsigned ct) // Возвращает первых ct цифр числа num
{
unsigned digits = 1;
unsigned long n = num;
if (ct == 0 | | num == 0)
	return 0; // возврат О в случае отсутствия цифр
while (n /= 10)
	digits++;
if (digits > ct)
{
	ct = digits - ct;
	while (ct--)
		num /= 10;
	return num; // возврат ct знаков слева
}
else // если ct >= количества цифр
	return num; // возврат числа целиком
}

// Возвращает указатель на новую строку, состоящую
// из n первых символов строки str
char *left (const char *str, int n)
{
if (n < 0)
    n = 0;
char *p = new char[n+1];
int i;
for (i = 0; i < n && str[i]; i++ )
    p[i] = str[i]; // копирование символов
while (i <= n)
    p[i++] = '\0'; // установка остальных символов строки в '\0'
return p;
}
///////////////////////////////////////////////
int fill_array(double ar[], int limit)
{
using namespace std;
double temp;
int i;
for (i = 0; i < limit; i++)
{
	cout << "Enter value #" << (i + 1) << ": "; // ввод значения
	cin >> temp;
	if (!cin) // неправильный ввод
	{
		cin.clear();
		while (cin.getO != '\n ')
			continue;
	cout << "Bad input; input process terminated.\n"; // ввод прекращен
	break;
	}
else if (temp < 0) // сигнал завершения
break;
ar[i] =
temp;
}
return i;
}
/* Этот код включает выдачу приглашения пользователю на
ввод. Если пользователь вводит неотрицательное значение, оно 
записывается в массив. В противном случае цикл прекращается. 
Если пользователь вводит только правильные значения, то цикл 
завершается после чтения limit значений. Последнее, что делает 
цикл — увеличивает і, поэтому после завершения цикла і равно 
величине, на единицу большей, чем последний индекс массива, 
т.е. і соответствует количеству введенных элементов. Затем 
функция возвращает это значение.
// arrfun3.cpp -- array functions and const */
#include <iostream>
const int Max = 5;
// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);  // const - не изменять данные
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: "; // ввод коэффициента переоценки
        double factor;
        while (!(cin >> factor))    // неправильный ввод
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; Please enter a number: "; // повторный запрос на ввод числа
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": "; // ввод значения
        cin >> temp;
        if (!cin)    // неправильный ввод
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n"; // процесс ввода прекращен
           break;
        }
        else if (temp < 0)     // сигнал завершения
            break;
        ar[i] = temp;
    }
    return i;
}
// Следующая функция может использовать, но не изменять, массив по адресу ar
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++) // Вывод содержимого массива ar
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}
// Умножает на r каждый элемент ar[]
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}

// static.cpp -- using a static local variable
#include <iostream>
// constants
const int ArSize = 10;
//////////////////////////////////////////////////////////////////////////
// Способ проверки пустой строки массива char *
void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
	/* Метод ввода cin.
get (input, ArSize) читает до конца экранной
строки или до позиции ArSize-1, в зависимости от того, что случится раньше.
Символ новой строки остается во входной очереди. Программа использует метод
cin.get(next) для чтения символа, который следует после введенной строки. Если
next является символом новой строки, значит, предыдущий вызов cin.get (input,
ArSize) должен был прочитать целиком всю строку. Если next не является символом
новой строки, в строке ввода остались непрочитанные символы. Затем в программе
с помощью цикла отбрасывается оставшаяся часть строки, но код можно изменить
так, чтобы остаток строки был задействован в следующем цикле ввода. Кроме того,
в программе используется тот факт, что попытка чтения пустой строки с помощью
get(char *, int) приводит к тому, что сіn возвращает false: */
char input[ArSize];
char next;
cout << "Enter a line: \n";
cin.get(input, ArSize);
while (cin)
{
    cin.get(next);
    while (next != '\n')    // строка не помещается!
        cin.get(next);      // избавиться от остатка
    strcount(input);
    cout << "Enter next line (empty line to quit):\n";
	cin.get(input, ArSize);
	}
cout << "Bye\n";
void strcount(const char *str)
{
	using namespace std;
	static int total = 0; // статическая локальная переменная: при следующем
// входе в эту функцию не будет инициализирована нулём, а примет 
// релультат, полученный при предыдущем входе в эту функцию
	int count = 0; // автоматическая локальная переменная, всегда 
// инициализируется нулём
	cout << "V" << str <<"\" contains ";
	while (*str++) // переход к концу строки
		count++;
	total += count; // здесь статическая переменная обновляется
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
// code to keep window open for MSVC++
/*
cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}

/* Если статическая локальная переменная инициализируется, это делается 
только один раз при запуске программы. Последующие вызовы функции не 
будут приводить к повторной инициализации переменной, как это происходит 
в случае автоматических переменных. */
void strcount(const char *str)
{
	using namespace std;
	static int total = 0; // статическая локальная переменная: при следующем
// входе в эту функцию не будет инициализирована нулём, а примет 
// релультат, полученный при предыдущем входе в эту функцию
	int count = 0; // автоматическая локальная переменная, всегда 
// инициализируется нулём
	cout << "V" << str <<"\" contains ";
	while (*str++) // переход к концу строки
		count++;
	total += count; // здесь статическая переменная обновляется
	cout << count << " characters\n";
	cout << total << " characters total\n";
}

