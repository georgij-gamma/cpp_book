// Рассчёт високосных лет
bool is_leap( int year )
{
   if( year%400 == 0 ) return true ;
   else if( year%100 == 0 ) return false ;
   else return year%4 == 0 ;
}

int days_in_month( int month, int year ) // jan == 1
{
    switch(month)
    {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 : return 31 ;
        case 4 : case 6 : case 9 : case 11 : return 30 ;
        case 2 : return 28 + is_leap(year) ; // 28 or 29 if leap year
        default: return 0 ; // sanity check
    }
}

bool is_valid_date( int mm, int dd, int yy )
{
    return yy > 1599 && // valid year
           mm > 0 && mm < 12 && // valid month
           dd > 0 && dd <= days_in_month( mm, yy ) ; // valid day
}

int day_number( int mm, int dd, int yy )
{
    if( !is_valid_date(mm,dd,yy) ) return 0 ; // get rid of trash

    int ndays = 0 ;
    // sum up all the days in months up to the previous (last completed) month
    // for( int month = 1 ; month < mm ; ++m ) ndays += days_in_month( monthy, yy ) ;
    for( int month = 1 ; month < mm ; ++month ) ndays += days_in_month( month, yy ) ;

    return ndays + dd ; // add the days in the current month
}

////////////////////////////////////////////////////////////////////////////////////
// outfile.cpp -- writing to a file
#include <iostream>
#include <ctime>   // system time
#include <stdio.h>
#include <cstdlib>

const int SIZE_SIMB = 30;

int main()
{
using namespace std;

time_t nowtime;	// Системное время
struct tm *timeinfo;

char name[SIZE_SIMB] = {0}; // 20 var

time(&nowtime);	// Получаем системное время
timeinfo = localtime(&nowtime);	// с компа
strftime(name, SIZE_SIMB, "%d.%m.%Y_%Hh%Mm%Ss", timeinfo); // add date/time to array char
cout << "localtime:\t" << name << endl;   // Вывод на экран

time(&nowtime);  // Получаем системное время
timeinfo = gmtime(&nowtime);	// gmt
strftime(name, SIZE_SIMB, "%d.%m.%Y_%Hh%Mm%Ss", timeinfo); // add date/time to array char
cout << "gmtime:\t\t" << name << endl;   // Вывод на экран

system("pause");
return 0;
}