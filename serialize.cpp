
class MyClass
{
public:
    MyClass(QString _field1 = "", qint32 _field2 = 0, qreal _field3 = 0) :
        field1(_field1),
        field2(_field2),
        field3(_field3)
    {
 
    }
 
    QString field1;
    qint32 field2;
    qreal field3;
 
    friend QDataStream &operator>>(QDataStream &in, MyClass &myObj)
    {
        in >> myObj.field1;
        in >> myObj.field2;
        in >> myObj.field3;
 
        return in;
    }
 
    friend QDataStream &operator<<(QDataStream &out, const MyClass &myObj)
    {
        out << myObj.field1;
        out << myObj.field2;
        out << myObj.field3;
        return out;
    }
};

Сериализация:
C++ (Qt)
Выделить код	

QVector<MyClass> myList;
 
myList.append(MyClass("hello1", 1, 2.4));
myList.append(MyClass("hello2", 2, 3.4));
myList.append(MyClass("hello3", 3, 4.5));
QFile file("C:/1.bin");
if(file.open(QIODevice::WriteOnly))
{
    QDataStream stream(&file);
    stream << myList;
    file.close();
}

Десериализация:
C++ (Qt)
Выделить код

QVector<MyClass> myList;
 
QFile file("C:/1.bin");
if(file.open(QIODevice::ReadOnly))
{
     QDataStream stream(&file);
     stream >> myList;
     file.close();
}
 
for(int i = 0; i < myList.size(); i++)
{
    qDebug() << myList[i].field1 << " " << myList[i].field2 << " " << myList[i].field3;
}

Но при таком подходе возникнет проблема, когда мы захотим добавить filed4 с каким-то данным, все старые данные "поламаются". что бы такого не произошло, можно сделать так:

C++ (Qt)
Выделить код

friend QDataStream &operator>>(QDataStream &in, MyClass &myObj)
    {
        QVariantMap m;
        in >> m;
 
        myObj.field1 = m.value("field1").toString();
        myObj.field2 = m.value("field2").toInt();
        myObj.field3 = m.value("field3").toDouble();
 
        return in;
    }
 
    friend QDataStream &operator<<(QDataStream &out, const MyClass &myObj)
    {
        QVariantMap m;
        m.insert("field1",    myObj.field1);
        m.insert("field2",    myObj.field2);
        m.insert("field3",    myObj.field3);
        out << m;
        return out;
    }
////////////////////////////////////////////////////////
инструментальный класс MyDatastream. При его использовании вам необходимо создать экземпляр объекта и вызвать соответствующую функцию сериализации или десериализации. Читатели могут расширить его в соответствии со своей собственной структурой. Структура в примере следующая:

struct UserInfo
{
  unsigned char id[20];
  int idint;
  unsigned char ip[16];
};

//Заголовочный файл инструмента mydatastream.h
// #include <QDebug>
#include "paraglobe.h" // Используется для размещения структуры UserInfo
class MyDatastream
{
  public:
    MyDatastream();
         UserInfo readStruct (QByteArray ba); // Функция сериализации
         QByteArray writeStruct (UserInfo ss); // Функция десериализации
};

//Инструмент cpp файл mydatastream.cpp
#include "mydatastream.h"
MyDatastream::MyDatastream()
{
}
UserInfo MyDatastream::readStruct(QByteArray ba)
{
  UserInfo *test = (UserInfo*)ba.data();
  return *test;
}
QByteArray MyDatastream::writeStruct(UserInfo ss)
{
  QByteArray ba;
  ba.resize(sizeof(UserInfo));
  memset(ba.data(), 0, sizeof(UserInfo));
  memcpy(ba.data(), &test, sizeof(UserInfo));
  return ba;
}
// Есть два недостатка. Во-первых, код может использовать способ ссылки для улучшения использования памяти и эффективности обработки; во-вторых, каждый раз, когда появляется новая структура, необходимо писать пару новых функций.
