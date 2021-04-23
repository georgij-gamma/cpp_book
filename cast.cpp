static_cast, dynamic_cast, const_cast, reinterpret_cast, 
C-style cast, qobject_cast и qvariant_cast
//	1. static_cast. Синтаксис:
TYPE static_cast<TYPE> (object);
static_cast /* преобразует выражения одного статического типа в объекты и значения другого 
статического типа. Поддерживается преобразование численных типов, указателей и ссылок по 
иерархии наследования как вверх, так и вниз. Проверка производится на уровне компиляции, 
так что в случае ошибки сообщение будет получено в момент сборки приложения или библиотеки. */
//	2. dynamic_cast Синтаксис:
TYPE& dynamic_cast<TYPE&> (object);
TYPE* dynamic_cast<TYPE*> (object);
/* Используется для динамического приведения типов во время выполнения. В случае 
неправильного приведения типов для ссылок вызывается исключительная ситуация std::bad_cast, 
а для указателей будет возвращен 0. Использует систему RTTI (Runtime Type Information). 
Безопасное приведение типов по иерархии наследования, в том числе для виртуального наследования.*/
//	3. const_cast. Синтаксис:
TYPE const_cast<TYPE> (object);
/* Пожалуй самое простое приведение типов. Снимает cv-qualifiers — const и volatile, то есть 
константность и отказ от оптимизации компилятором переменной. Это преобразование проверяется 
на уровне компиляции и в случае ошибки приведения типов будет выдано сообщение. */
//	4. reinterpret_cast Синтаксис:
TYPE reinterpret_cast<TYPE> (object);
/* Приведение типов без проверки. reinterpret_cast — непосредственное указание компилятору. 
Применяется только в случае полной уверенности программиста в собственных действиях. Не снимает 
константность и volatile. применяется для приведения указателя к указателю, указателя к целому 
и наоборот. */
//	5. duration_cast Синтаксис:
duration_cast<ratio>
/* Конвертирует промежуток времени в известные единицы */
#include <iostream>
#include <cmath>
#include <chrono>
using namespace std::chrono;
int main()
{
    auto t0 = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std::cout << '\b';
    auto t1 = high_resolution_clock::now();

    // std::cout << std::fixed;

    uint32_t dt = duration_cast<nanoseconds>(t1 - t0).count();
    std::cout << '\n' << dt << "ns\n";
    dt = (round (double(dt) / 1000) );
    std::cout << dt << "us\n";
    dt = (round (double(dt) / 1000) );
    std::cout << dt << "ms\n";

    //std::cin.get();
	return 0;
}
//	6. C-style cast Синтаксис:
TYPE (TYPE*) object;
/* Си-шный метод приведения типов. Пожалуй самый нежелательный способ приведения типов. 
Страуструп пишет: «Например, что это значит выражение: x = (T)y;. Мы не знаем. Это зависит от 
типа T, типов x и y. T может быть названием типа, typedef или может быть параметр template-а. 
Может быть, х и у являются скалярными переменными и Т представляет собой значение преобразования. 
Может быть, х объекта класса, производного от класса Y и Т — нисходящее преобразование. 
По этой причине программист может не знать, что он делает на самом деле».
Вторая причина нежелательного использования приведения типов в C-style — трудоемкость процесса 
поиска мест приведения типов. */
//	7. qobject_cast Синтаксис:
TYPE qobject_cast<TYPE>(QObject *object)
/* Приводит объект QObject* к типу TYPE если объект типа объекта TYPE или тип наследует от TYPE 
иначе возвращает 0. qobject_cast от 0 также дает 0. Необходимое условие. Класс должен наследовать 
от QObject и содержать в себе макрос Q_OBJECT. Функция ведет себя аналогично стандартному 
dynamic_cast, но при этом не использует RTTI. Вот как описана данная функция в Qt 4.7.0: */
template <class T>
inline T qobject_cast(QObject *object)
{
	#if !defined(QT_NO_MEMBER_TEMPLATES) && !defined(QT_NO_QOBJECT_CHECK)
		reinterpret_cast<T>(0)->qt_check_for_QOBJECT_macro(*reinterpret_cast<T>(object));
	#endif
	return static_cast<T>(reinterpret_cast<T>(0)->staticMetaObject.cast(object));
}
//	* This source code was highlighted with Source Code Highlighter.
/* Итак, что тут происходит:
Во-первых если не определены QT_NO_MEMBER_TEMPLATES (определяется только в том случае, если 
используется версия Microsoft Visual Studio ниже 2002) и QT_NO_QOBJECT_CHECK (определяется в 
случае использования версии Microsoft Visual Studio ниже 2003), то происходит проверка наличия 
макроса Q_OBJECT в объявлении класса. И после этого выполняется непосредственно само 
преобразование — сначала получаем статический объект класса QMetaObject, который называется 
staticMetaObject, у которого вызывается метод cast, который возвращает const_cast переданного 
ему объекта, попутно проверяя наследуется ли данный объект от QObject. Далее полученному объекту 
делается static_cast и возвращается результат. */
// 8. qvariant_cast Синтаксис:
TYPE qvariant_cast<TYPE>(const QVariant &value)
/* Приводит объект класса QVariant к нужному классу. Функция аналогична функции qVariantValue.
Рассмотрим, что происходит внутри: */
template<typename T> inline T qvariant_cast(const QVariant &v)
{
  const int vid = qMetaTypeId<T>(static_cast<T *>(0));
  if (vid == v.userType())
    return *reinterpret_cast<const T *>(v.constData());
  if (vid < int(QMetaType::User))
  {
    T t;
    if (qvariant_cast_helper(v, QVariant::Type(vid), &t))
      return t;
  }
  return T();
}
//	* This source code was highlighted with Source Code Highlighter.
/* В первой секции кода производится получение идентификатора класса через метасистему Qt. 
В том случае если класс не зарегистрирован через Q_DECLARE_METATYPE, компиляция кода с приведением 
к этому типу выдаст ошибку. Далее, если тип объекта, полученный от метасистемы совпадает с типом в 
значении QVariant, производится reinterpret_cast содержимого объекта, если идентификатор класса не 
является встроенным типом и его id не совпадает с заложенным в значении QVariant, то возвращается 
TYPE(). Для случаев, когда мы приводим к встроенному типу, вызывается функция qvariant_cast_helper, 
которая вызывает в свою очередь функцию convert, адрес которой хранится в структуре Handler. В ней 
уже осуществляется приведение способом подходящим для типа TYPE. Если конвертация не удалась 
возвращается объект TYPE()/
	UPD: C-style cast по сути самое медленное преобразование, так как в этом случае последовательно 
перебираются следующие вызовы: */
const_cast
static_cast
static_cast + const_cast
reinterpret_cast
reinterpret_cast + const_cast
/* UPD:
1. const_cast также умеет добавлять cv-квалификаторы
2. для преобразования указателей лучше использовать двойной static_cast через void* вместо 
reinterpret_cast, потому как такое преобразование позволяет быть уверенным в том, что только pointer-ы 
участвуют в приведении. */

