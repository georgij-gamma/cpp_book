/*Постановки на базовые классы и классы общего назначения
Оглавление
1 Вводные замечания	3
2 Общие базовые классы и отдельные типы	4
2.1 Перечисление TLogMessageType	4
2.2 Класс QCustomObject (175)	4
2.3 Базовый класс устройств QCustomDevice(180)	4
3 Классы общего назначения	6
3.1 Класс QEventLoopThread	6
3.2 Класс-диспетчер потоков QThreadManager	7
3.3 Модуль журналирования (369)	8
3.3.1 Базовый класс ведения журнала QCustomEventLogger	8
3.3.2 Класс вывода журнала в консоль QDebugEventLogger	8
3.3.3 Класс сохранения журнала в файл QFileEventLogger	9
3.4 Класс сохранения скриншотов QScreenShotSaver (374)	9
3.5 Класс диспетчера сессий QSessionManager (381)	10
4 Базовые классы абстрактных устройств	12
4.1 Модуль классов CustomSerialDevice (174)	12
4.1.1 Структура TSerialSettings	12
4.1.2 Класс QCustomSerialDevice	12
4.1.3 Перечисление типов ожидания ответов TAnswerWaitType	13
4.1.4 Структура команд очереди TSerialCmdData	13
4.1.5 Класс QCustomSerialPollingDevice	13
4.2 Базовый класс QCustomUdpDevice (199)	15
4.1 Устройства, работающие по tcp-протоколу	16
4.1.1 Перечисление типов клиент-серверных устройств – TClientServerType	16
4.1.2 Базовый класс для работы с устройствами по tcp-протоколу (255)	17
5 Базовые классы устройств	19
5.1 Модуль базового класса джойстика QCustomGoes321(193)	19
5.1.1 Общие типы данных для джойстика ПУ ГОЭС 321.30М	19
5.1.1.1 Класс TGoes321int16	19
5.1.1.2 Структура TGoes321Data	19
5.1.2 Базовый класс джойстика QCustomGoes321(193)	19
5.2 Модуль базового класса кнопочных постов (210)	20
5.2.1 Вспомогательные типы	20
5.2.1.1 Структура данных для кнопочных постов на основе ADAM-4100 TAdam4100KeypadData	20
5.2.1.2 Структура данных элемента TKeypadItem	20
5.2.1.3 Структура данных кнопки TKeypadButton	20
5.2.1.4 Перечисление TKeypadSwitchState	20
5.2.1.5 Структура данных переключателя TKeypadSwitch	20
5.2.1.6 Базовый класс-список элементов кнопочных постов TKeypadItemVector	20
5.2.2 Базовый класс QCustomAdam4100Keypad	20
5.3 Модуль базового класса Survey+ (214)	22
5.3.1 Структура TUdpSurveyData	22
5.3.2 Базовый класс QCustomUdpSurvey	23
5.4 Классы для работы с интерфейсом ARINC-429	23
5.4.1 Классы меток протокола TXXXArincLabel (348)	23
5.4.2 Базовый класс для работы с адаптером PCI429_3 QCustomArinc429 (234)	24
5.4.3 Класс для периодического адресного чтения данных из адаптера PCI429_3 QArinc429AddressInput (378)	26
6 Классы визуальных элементов интерфейса	28
6.1 Базовый класс QCustomWidget (259)	28
6.2 Классы виртуальной кнопочной панели	29
6.2.1 Базовый класс виртуальной кнопочной панели QCustomVirtualKeypad (269)	29
6.3 Классы строки состояния	30
6.3.1 Перечисление TInfoItemStatus	30
6.3.2 Структура TInfoData	30
6.3.3 Класс-список сообщений QMapInfoList	30
6.3.4 Класс надписи для строки состояния QInfoLabel	31
6.3.5 Базовый класс строки состояния QCustomStatusBar (318)	32
6.4 Базовый класс «легенды» QCustomLegend (367)	33
7 Различные вспомогательные классы	34
7.1 Базовый класс карты QCustomMap (323)	34
7.2 Классы обработки значений осей джойстика (384)	35
7.2.1 Базовый класс осей джойстика QCustomJoyAxis	36
7.2.2 Класс оси джойстика для координаты экрана QJoyScreenMove	36
7.2.3 Класс оси джойстика для перебора элементов QJoyScroller (413)	38

1 Вводные замечания
Использовать базовые классы, а также классы общего назначения, разработаны в рамках работ по проекту DA-42_RTI-2 (борт 422). Подробные постановки на них опускаются, приведены только объявления классов. При необходимости подробности смотреть в файле «Постановки задач в рамках проекта ДА-42 РТИ-2.docx».
Все постановки привязаны к задачам в Redmine. Номер задачи в скобках указан в заголовке пункта, являющегося корневым для связанной с ним задачи; с номером связана гиперссылка на задачу в Redmine.
Во всех файлах в самом начале указан код постановки; если на отдельные файлы постановки нет (файлы с типами), в качестве кода указан код «родительской» постановки. Код постановки добавлен в виде:
//	Код постановки №хххх
2 Общие базовые классы и отдельные типы
2.1 Перечисление TLogMessageType
Перечисление типов журналируемых сообщений.*/
enum TLogMessageType {lmtDebug=-1, lmtInfo, lmtWarning, lmtError, lmtFatal};
/*2.2 Класс QCustomObject (175)
Класс-предок для всех классов-объектов с метаобъектной функциональностью.*/
class QCustomObject: public QObject;
	Q_PROPERTY:
	bool Enabled		//	Чтение и запись, причем оба метода виртуальные и публичные; здесь просто установка/чтение закрытого члена данных
public:
	explicit QCustomObject(QObject* AParent = 0);	//!<    Конструктор
~QCustomObject();                                 	//!<    Деструктор
signals:
	void sendLogMessage(QString /*AFileName*/, QString /*AFuncName*/, quint32 /*ALineNumber*/,
						QString /*AMessage*/, TLogMessageType AMessageType);
// Макрос:
#define doSendLogMessage(AMessage, AMessageType) emit sendLogMessage(QString(__FILE__), \
QString (Q_FUNC_INFO), __LINE__, AMessage, AMessageType)
//2.3 Базовый класс устройств QCustomDevice(180)
class QCustomDevice: public QCustomObject;
	Q_PROPERTY:
	QString DeviceName		//	Только чтение, в конечных потомках будет назначаться непосредственно в 
// конструкторе, связанный член данных имеет смысл хранить в protected; он же по сути будет именем раздела в конфиге
	QString ConfigFileName	//	Чтение и запись (поле данных – в защищенной секции)
protected:
	bool m_Updated; //	Флаг, устанавливаемый перед изменением нескольких св-в для предотвращения нескольких реконнектов
	virtual bool connect()=0;	//	Подключение (здесь и далее: true – успешно)
	virtual void disconnect()=0;	//	Отключение
	void reconnect();			//	Переподключение
	virtual void readSettings(QSettings* ASettings)=0;	//	Чтение настроек
	virtual void writeSettings(QSettings* ASettings)=0;	//	Запись настроек
public:
	QCustomDevice(const QString& ADeviceName, QObject* AParent=0);
	quint8 calcChecksum(char* ApData, ACount);		//	Проверка контрольной суммы
	quint8 calcChecksum(const QByteArray& AData);	//	Проверка контрольной суммы
public slots:
	void setEnabled(bool AValue);					//	Переопределенный метод предка
	virtual void defineDefaultSettings()=0;			//	Установка настроек по-умолчанию
	void loadSettings();	//	Загрузка настроек
	void saveSettings();	//	Сохранение настроек
/*3 Классы общего назначения
3.1 Класс QEventLoopThread
Класс-обертка для выполнения функций-слотов объектов в отдельном потоке.*/
class QEventLoopThread: public QThread;
Q_PROPERTY:
TObjectVector ObjectList;	//	Список объектов
bool Enabled		//	Чтение и запись, чтение просто возвращает закрытый член, запись – см. ниже
private:
TObjectVector m_ObjectList;	//	Список объектов
protected:
virtual void beforeExec();
virtual void afterExec();
void run();
public:
explicit QEventLoopThread(const QCustomDevice* AObject, QObject* AParent = 0);     //!<    Конструктор
~QEventLoopThread();                                 //!<    Деструктор
void appendObject(const QCustomDevice* AObject);	//!<    Добавить объект в поток
TObjectVector* getObjectList() const;                  //!<    Получить указатель на список объектов
public slots:
void setEnabled(bool AValue);
void setConfigFileName(const QString& AConfigFileName); //!<    Метод записи имени файлов настроек
void defineDefaultSettings();                   //!<    Установка настроек по-умолчанию
void loadSettings();                                    //!<    Загрузка настроек
void saveSettings();                                    //!<    Сохранение настроек
signals:
void doSetEnabled(bool);	//	Вызвать слоты setEnabled дочерних объектов
 void doSetConfigFileName(const QString&); //!<    Запись имени файлов настроек
virtual void doDefineDefaultSettings();                   //!<    Установка настроек по-умолчанию
void doLoadSettings();                                    //!<    Загрузка настроек
void doSaveSettings();                                    //!<    Сохранение настроек
3.2 Класс-диспетчер потоков QThreadManager
Класс-диспетчер потоков. Позволяет централизовано управлять множеством объектов в разных потоках
class QThreadManager: public QCustomObject;
Q_PROPERTY:
TThreadVector ThreadList;	//	Список потоков
QCustomEventLogger* m_Logger //	Указатель на объект журналирования 
private:
TThreadVector m_ThreadList;	//	Список потоков
public:
explicit QThreadManager(QObject* AParent = 0);     //!<    Конструктор
~QThreadManager();                                 //!<    Деструктор
TThreadVector* getThreadList() const;                  //!<    Получить указатель на список потоков
public slots:
QEventLoopThread* appendObject(const QCustomDevice* AObject);	//!<    Добавить объект в новый поток
void appendObjectToThread(const QCustomDevice* AObject, QEventLoopThread* AThread);	//!<    Добавить объект в существующий поток
void setEnabled(bool AValue);	//!<    Вызвать setEnabled всех потоков
void setConfigFileName(const QString& AConfigFileName); //!<    Метод записи имени файлов настроек
virtual void defineDefaultSettings();                   //!<    Установка настроек по-умолчанию
void loadSettings();                                    //!<    Загрузка настроек
void saveSettings();                                    //!<    Сохранение настроек
void start();	//!<    Вызвать start всех потоков
void quit();	//!<    Вызвать quit всех потоков
3.3 Модуль журналирования (369)
Классы журналирования.
3.3.1 Базовый класс ведения журнала QCustomEventLogger
Предназначен для получения сигнала sendLogMessage от любого потомка QCustomObject и передачи параметров в виртуальный метод вывода лога.
class QCustomEventLogger: public QCustomDevice;
protected:
virtual void processLogMessage (const QString& AFileName, const QString& AFuncName, quint32 ALineNumber, const QString& AMessage, TLogMessageType AMessageType) = 0;
public:
explicit QCustomEventLogger(const QString& ADeviceName, QObject* AParent=0);   //!<    Конструктор
public slots:
void receiveLogMessage(QString AFileName, QString AFuncName, quint32 ALineNumber, QString AMessage, TLogMessageType AMessageType);
3.3.2 Класс вывода журнала в консоль QDebugEventLogger
Только перегрузить метод processLogMessage:
    qDebug() << AFileName << AFuncName << ALineNumber << AMessage << AMessageType;
Можно добавить текстовые преамбулы. Это чисто отладочная версия логгера.
3.3.3 Класс сохранения журнала в файл QFileEventLogger
«Боевой» класс сохранения журнала в файл. Устанавливается имя каталога сессии, имя каталога журналов и имя файла журнала. В конструктор предка передать имя («FileEventLogger»). В методе connect файл журнала нужно открыть, в disconnect – закрыть. В методе processLogMessage писать в журнал форматированные сообщения из переданных параметров.
class QFileEventLogger: public QCustomEventLogger;
PROPERTY	// «Свойства», которые требуется читать/писать из/в файла конфигурации
QString SessionName //!<    Имя каталога сессии (чтение/запись) (его не надо читать/писать в настройках!!!)
QString CatalogName //!<    Имя каталога журналов (его не надо читать/писать в настройках!!!)
QString LogName	//!<    Имя файла журнала (чтение/запись)
protected:
void processLogMessage (const QString& AFileName, const QString& AFuncName, quint32 ALineNumber, const QString& AMessage, TLogMessageType AMessageType);
bool connect();	//	Открытие файла
void disconnect();	//	Закрытие файла
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
public:
explicit QFileEventLogger(QObject* AParent=0);   //!<    Конструктор
3.4 Класс сохранения скриншотов QScreenShotSaver (374)
Класс принимает сигнал с изображением QImage и индексом экрана (0-3). Должен сохранить полученное от виджетов изображение и отправить сигнал классу отправки разовых команд на «землю».
class QScreenShotSaver: public QCustomDevice
PROPERTY
	QString SessionPath	//	Путь к каталогу сессии (его не надо читать/писать в настройках!!!)
QString CatalogName; //	Имя каталога скриншотов (по-умолчанию – «ScreenShots»)
	QString DateTimeMask // Маска поля даты-времени в имени файла (по-умолчанию – «yyyyMMdd_hhmmsszzz»)
	QString FileNameMask // Маска имени файла (по-умолчанию – «%1_Scr_%2.png»)
private:
createSessionDir();
protected:
bool connect();
void disconnect();
void readSettings(QSettings* ASettings);	//	Чтение «св-в»
void writeSettings(QSettings *ASettings); 	//	Запись «св-в»
public:
explicit QScreenShotSaver(QWidget *AParent = 0);
public slots:
void defineDefaultSettings();
	void receiveScreenShot(QImage, quint32 AScreenIndex);
signals:
	void saveScreenShots(QString);	//	Отправка сигнала о сохранении файла
3.5 Класс диспетчера сессий QSessionManager (381)
Класс служит для создания дерева каталога сессии. У свойства SessionTree должны быть методы чтения и записи по ключу.
class QSessionManager: public QCustomDevice
PROPERTY
	QMap<QString, QString> SessionTree // Дерево каталогов сессии
	QString RootDirName; //	Имя корневого каталога файлового хранилища
	QString CommonLogName; // Имя общего файла журнала
protected:
bool connect();
void disconnect();
void readSettings(QSettings* ASettings);	//	Чтение «св-в»
void writeSettings(QSettings *ASettings); 	//	Запись «св-в»
public:
explicit QSessionManager(QWidget *AParent = 0);
QString getError();	//	Возвращает сообщение об ошибке



4 Базовые классы абстрактных устройств
4.1 Модуль классов CustomSerialDevice (174)
Базовые классы устройств с последовательным интерфейсом и общие типы данных.
4.1.1 Структура TSerialSettings
TSerialSettings – структура с настройками последовательного порта.
4.1.2 Класс QCustomSerialDevice 
Базовый класс устройств с последовательным интерфейсом. Включает методы чтения/записи настроек порта, инициализации, подключения и отключения.
class QCustomSerialDevice: public QCustomDevice;
private:
QSerialPort* m_Port;
TSerialSettings m_SerialSettings;
protected:
bool connect();	//	Подключение
void disconnect();	//	Отключение
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
public:
QCustomSerialDevice(const QString& ADeviceName, QObject* AParent=0);
QSerialPort* getPort() const;                       //!<  Метод чтения указателя на порт
TSerialSettings* getSerialSettings() const;         //!<  Метод чтения указателя на настройки порта
qint64 writeData(const char* AData, qint64 ALen);   //!<  Запись данных в порт
qint64 writeData(const QByteArray AData);           //!<  Запись данных в порт 
Методы getPort и getSerialSettings являются функциями доступа к закрытым членам данных, а writeData – обрамление соответствующих функций объекта порта.
4.1.3 Перечисление типов ожидания ответов TAnswerWaitType
enum TAnswerWaitType
{
awtNone,    //!<    Не ждать
awtLength,  //!<    Ответ определенной длины
awtTail     //!<    Ответ должен заканчиваться определенным сочетанием байт (или одним байтом)
};
4.1.4 Структура команд очереди TSerialCmdData
struct TSerialCmdData
{
QByteArray Command; //!<    Собственно команда
quint32 Length;     //!<    Длина ожидаемого ответа
TSerialCmdData(const QByteArray& ACmd, quint32 ALength);
};
4.1.5 Класс QCustomSerialPollingDevice 
/*Базовый класс устройств с последовательным интерфейсом и с опросом порта для получения данных.
Включает методы чтения/записи настроек порта, инициализации, подключения и отключения, таймеры для 
опроса и таймаута по ошибке. Реализован механизм конвейера команд – для обеспечения гарантированного 
получения ответа (или выхода из режима ожидания ответа по ошибке) перед отправкой новой команды. 
Условием полного получения ответа может быть длина ответа или определенное сочетание байт (в т.ч. 
1 байт – по умолчанию – 0x0D – может использоваться для Modbus ASCII), а также ожидание может быть 
выключено (по-умолчанию).*/
class QCustomSerialPollingDevice: public QCustomSerialDevice;
Q_PROPERTY:
	QByteArray PollingCmd		//	Чтение и запись – команда для запроса данных из порта
qint32 TimeoutByWrite;	//  Таймаут на запись команд в порт (связано с членом данных)
qint32 TimeoutByRead;	// Таймаут по чтению (связано со свойством Interval m_TimeoutTimer)
qint32 PollingCmdInterval;	// Период посылки команды в порт (связано со свойством Interval m_Timer)
	bool SingleShot	//	Флаг однократной отправки команды по таймеру (для возобновления нужно включить вручную); метод записи должен установить соответствующее св-во таймера m_Timer; по-умолчанию – false
TAnswerWaitType AnswerWaitType	// Тип ожидания ответов на команды
quint32 AnswerLength	// Длина ожидаемых ответов на команды
QByteArray AnswerTail	// Окончание ожидаемых ответов на команды
private:
QTimer* m_Timer;
QTimer* m_TimeoutTimer;
	bool m_WaitingRequest;	//	Если установлен, значит отправили команду, но пока не получили ответ
quint32 m_CurrentAnswerLength;      //  Длина ожидаемого ответа на текущую команду
	QQueue<TSerialCmdData> m_CmdQueue;	//	Конвейер команд
void clearRequestFlag();	//	Очистка флага m_WaitingRequest и вызов onClearRequestFlag через очередь
private slots:
void writePollingCmd();	//	Запись команды в порт
void readFromPort();	//	Чтение из порта
void onReadTimeoutError();	//	Ошибка по таймауту по чтению
void onPortError(QSerialPort::SerialPortError error);   // Ошибка в порте 
void onClearRequestFlag();	//	Отправка команд из конвейера
protected:
QByteArray m_InputBuffer;                               //!<    Буфер приема
bool connect();	//	Подключение
void disconnect();	//	Отключение
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
virtual void beforePollingCmd(){}	//	Сделать что-нибудь перед отправкой команды
void sendCmd(QByteArray ACmd, quint32 ALength=0);       // Отправить команду в порт или загрузить ее в конвейер
void writeCmd(QByteArray ACmd, quint32 ALength=0);      //!<    Отправить команду в порт
void startPolling();	// Включение таймера посылки команд
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
virtual void processTheData(const QByteArray& AData)=0; //! Обработка после получения данных из порта
#pragma GCC diagnostic pop
public:
QCustomSerialPollingDevice(const QString& ADeviceName, QObject* AParent=0);
4.2 Базовый класс QCustomUdpDevice (199)
Базовый класс устройств на основе udp-сокета.
class: QCustomUdpDevice: public QCustomDevice;
Q_PROPERTY:
	bool SenderOnly		//!<    Флаг, отключающий чтение порта
	bool EchoOff			//!<    Флаг, отключающий чтение своих же дейтаграмм
QString SourceAddress	//!<    Строка с адресом источника данных
bool AnySourceAddress 	//!<    Флаг получения данных с любого адреса
quint16 SourcePort		//!<    Порт для получения дейтаграмм
BindMode SourceBindMode	//!<    Тип соединения с портом
QString DestAddress	//!<    Строка с адресом клиента
bool AnyDestAddress 	//!<    Флаг отправки данных любому клиенту
quint16 DestPort		//!<    Порт для отправки дейтаграмм
private:
	QString m_SourceAddressStr;
QHostAddress m_SourceAddress;
	QString m_DestAddressStr;
QHostAddress m_DestAddress;
protected:
	QUdpSocket* m_UdpSocket;
bool connect();	//	Подключение
void disconnect();	//	Отключение
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
virtual void processTheDatagram(const QByteArray& ADatagram) = 0;	//	Обработка дейтаграммы
private slots:
void onReadyRead();	//  Слот для связи с QUdpSocket
public:
QCustomUdpDevice(const QString& ADeviceName, QObject* AParent=0);
QCustomUdpDevice(const QString& ADeviceName, const QString& ASourceAddress, quint16 ASourcePort, QObject* AParent=0);
QCustomUdpDevice(const QString& ADeviceName, bool AAnySourceAddress, quint16 ASourcePort, QObject* AParent=0);
public slots:
writeDatagram(char* ApData, qint64 ASize);
writeDatagram(const QByteArray& ADatagram);
4.1 Устройства, работающие по tcp-протоколу
В данную группу входит пока только базовый класс.
4.1.1 Перечисление типов клиент-серверных устройств – TClientServerType
enum TClientServerType
{
    cstClient,  //!<    Клиент
    cstServer,  //!<    Сервер
    cstBoth     //!<    Оба
};
4.1.2 Базовый класс для работы с устройствами по tcp-протоколу (255)
Базовый класс для работы с устройствами по tcp-протоколу. Сохранять в подкаталоге CommonUnits. Имена файлов: CustomTcpDevice.
Одно из свойств класса – DeviceType – определяет, будет ли класс выполнять функции сервера, клиента или обе сразу. В зависимости от значения данного свойства будет созданы (или уничтожены) экземпляры QTcpServer и QTcpSocket – для приема и отправки данных соответственно.
Сервер, может обрабатывать множество соединений (для изменения кол-ва доступных соединений обращаться к методам QTcpServer через метод чтения). При поступлении входящего соединения для него создаются сигнал-слотовые связи для чтения данных readyRead=>onReadyRead и для отключения сокета входящего соединения disconnected=>onDisconnected.
«Протокол» обмена данного класса определяет только одно соглашение: в начале «пакета» передается его длина (quint32). Поскольку данные могут прийти все сразу, а могут быть фрагментированы, сервер должен уметь получать данные во всех возможных ситуациях, даже если поступило несколько запросов от разных клиентов. Для этого реализован специальный алгоритм в слоте чтения onReadyRead (см. стр. 566 Макса Шлее), а также имеется закрытый член данных m_DataSize – ассоциативный массив размеров получаемых блоков данных, ключом которого являются указатели на сокет. Запись в массив добавляется (и инициализируется нулем) в слоте onNewConnection (связан с сигналом сервера newConnection), а удаляется в слоте onDisconnected.
class: QCustomTcpDevice: public QCustomDevice;
Q_PROPERTY:
	TClientServerType DeviceType;	//!<    Тип устройства – клиент, сервер или оба
QString SourceAddress	//!<    Строка с адресом источника данных
bool AnySourceAddress 	//!<    Флаг получения данных с любого адреса
quint16 SourcePort		//!<    Порт для получения данных
QString DestAddress	//!<    Строка с адресом приемника данных
quint16 DestPort		//!<    Порт для отправки данных
private:
	QString m_SourceAddressStr;		//	Показаны только эти члены, чтобы подчеркнуть – для адреса получателя нет строкового члена
QHostAddress m_SourceAddress;
QHostAddress m_DestAddress;
QMap<QTcpSocket*, quint32> m_DataSize;
protected:
	QTcpServer* m_TcpServer;
	QTcpSocket* m_TcpSocket;
bool connect();	//	Подключение
void disconnect();	//	Отключение
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
virtual void processTheAnsweredData(const QByteArray& AData) = 0;	//	Обработка полученных ответных данных
virtual void processTheData(const QByteArray& AData) = 0;	//	Обработка полученных данных
private slots:
void onNewConnection();	// Слот обработки входящего подключения к QTcpServer 
void onDisconnected();	// Слот обработки отключения от QTcpServer
void onReadyRead();	// Слот для чтения данных
public:
QCustomTcpDevice(const QString& ADeviceName, QObject* AParent=0);
QCustomTcpDevice(const QString& ADeviceName, TClientServerType ADeviceType, const QString& AAddress, quint16 APort, QObject* AParent=0);
public slots:
writeData(char* ApData, qint64 ASize);	//	Отправка данных через QTcpSocket
writeData(const QByteArray& AData);
5 Базовые классы устройств
5.1 Модуль базового класса джойстика QCustomGoes321(193)
5.1.1 Общие типы данных для джойстика ПУ ГОЭС 321.30М
Уже написаны, лежат в файле Goes321Data.h тут вместе с примером.
5.1.1.1 Класс TGoes321int16
Класс данных для осей джойстика ПУ ГОЭС 321.30М.
5.1.1.2 Структура TGoes321Data
Структура TGoes321Data, соответствующая 11 байтам, возвращаемым ПУ ГОЭС 321.
5.1.2 Базовый класс джойстика QCustomGoes321(193)
Класс реализует установку имени устройства, дефолтных настроек порта, опрос джойстика, получение 11 байт данных и генерацию общего сигнала с этими данными.
class: QCustomGoes321: public QCustomSerialPollingDevice;
protected:
void processTheData(const QByteArray& AData);   //!<    Обработка после получения данных из порта
public:
QCustomGoes321(QObject* AParent=0);
public slots:
	void defineDefaultSettings();	//	Установка настроек по-умолчанию
signals:
void sendJoystickData(TGoes321Data);	 //!<    Сигнал со всеми данными джойстика в виде структуры
5.2 Модуль базового класса кнопочных постов (210)
5.2.1 Вспомогательные типы
5.2.1.1 Структура данных для кнопочных постов на основе ADAM-4100 TAdam4100KeypadData
5.2.1.2 Структура данных элемента TKeypadItem
Базовая структура данных элемента кнопочных постов. Уже написана, лежат в файле KeypadData.h вместе с примером.
5.2.1.3 Структура данных кнопки TKeypadButton
Потомок TKeypadItem. Структура данных кнопки кнопочных постов. Уже написана, лежат в файле KeypadData.h вместе с примером.
5.2.1.4 Перечисление TKeypadSwitchState
Перечисление – положения переключателя кнопочных постов. Уже написано, лежат в файле KeypadData.h вместе с примером.
5.2.1.5 Структура данных переключателя TKeypadSwitch
Потомок TKeypadItem. Структура данных переключателя кнопочных постов. Уже написана, лежат в файле KeypadData.h вместе с примером.
5.2.1.6 Базовый класс-список элементов кнопочных постов TKeypadItemVector
Базовый класс-список элементов кнопочных постов TKeypadItemVector. Реализует методы поиска элементов по коду таймеров задержки и периода длительного нажатия, а также методы установки общих данных (то, что они у каждого элемента свои – закладка на будущее).
5.2.2 Базовый класс QCustomAdam4100Keypad
Базовый класс для кнопочных постов на основе ADAM-4100.
class QCustomAdam4100Keypad: public QCustomSerialPollingDevice;
Q_PROPERTY:
bool CommonSignalOnly		//	Флаг генерации только общего сигнала sendKeypadData (default=false)
bool AutoRepeatButtons		//	Флаг генерации повторного нажатия кнопок при их удержании (default=false)
bool AutoRepeatSwitches		//	Флаг генерации повторного нажатия переключателей при их удержании (default=true)
quint32 AutoRepeatDelay		//	Задержка, мс, до начала генерации повторного нажатия кнопок при их удержании (default=300)
quint32 AutoRepeatInterval	//	Период, мс, генерации повторного нажатия кнопок при их удержании (default=100)
private:
quint8 m_DeviceAddress;	//	Адрес только для отправки запросов данных!
QByteArray m_Buffer;                            //  буфер приема
bool m_WaitData;	//	Флаг ожидания корректных данных
protected:
TKeypadData m_KeypadData;	//	Структура для генерации сигнала
TKeypadData m_OldKeypadData;	//	Структура с данными предыдущего опроса;
TKeypadButtonsVector m_Buttons;	//	Список кнопок
TKeypadSwitchesVector m_Switches;	//	Список переключателей
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
void beforePollingCmd();	//	Тут будем формировать команду перед отправкой
void processTheData(const QByteArray& AData);   //!<    Обработка после получения данных из порта
virtual void processData();	//	Разбор всех данных и генерация дополнительных сигналов
void timerEvent(QTimerEvent* event);	//	Перехват событий таймера
public:
QCustomAdam4100Keypad(QObject* AParent=0);
public slots:
	void defineDefaultSettings();	//	Установка настроек по-умолчанию

	void setBacklightState(quint32 AButton, bool AState);	//!<	Установка состояния подсветки кнопок
	void setBacklightStates(quint8 ADeviceId, quint8 AStates);	//!<	Установка состояния подсветки всех кнопок одного устройства
	void setBacklightStates(quint16 AStates);	//!<	Установка состояния подсветки всех кнопок
signals:
void sendKeypadData(TKeypadData);	 //!<    Сигнал со всеми данными
void pressButton(quint8, bool);	 //!<    Сигнал нажатия кнопки с ее кодом и состоянием подсветки
void pressRepeatButton(quint8, bool);	 //!<    Сигнал повторного нажатия кнопки при длительном удержании с ее кодом и состоянием подсветки
void releaseButton(quint8);	 //!<    Сигнал отпускания кнопки с ее кодом
void pressSwitch(quint8, TKeypadSwitchState);	 //!<    Сигнал нажатия переключателя с его кодом и кодом состояния
void pressRepeatSwitch(quint8, TKeypadSwitchState);	 //!<    Сигнал нажатия переключателя кнопки при длительном удержании с его кодом и кодом состояния
void releaseSwitch(quint8);	 //!<    Сигнал отпускания переключателя с его кодом
В методах установок свойств кнопок и переключателей использовать соответствующие методы эти классов-списков, а не заводить свои члены данных.
5.3 Модуль базового класса Survey+ (214)
5.3.1 Структура TUdpSurveyData
Написать структуру, соответствующую полным возвращаемым данным по udp-протоколу. Сохранить в SurveyTypes.h.
5.3.2 Базовый класс QCustomUdpSurvey
Класс для работы с инерциальной навигационной системой Survey+ по udp-протоколу. Потомок QCustomUdpDevice. Сохранять в подкаталоге UdpSurveyUnits. Имена файлов: CustomUdpSurvey.
class: QCustomUdpSurvey: public QCustomUdpDevice;
protected:
void processTheDatagram(const QByteArray& ADatagram);	//	Обработка дейтаграммы
public:
QCustomUdpSurvey(QObject* AParent=0);
public slots:
	void defineDefaultSettings();	//	Установка настроек по-умолчанию
signals:
void sendSurveyData(TUdpSurveyData);	 //!<    Сигнал со всеми данными
void sendSurveyStatus(bool /*AEnabled*/, bool /*ACorrect*/);	 //!<    Сигнал статуса оборудования
5.4 Классы для работы с интерфейсом ARINC-429
5.4.1 Классы меток протокола TXXXArincLabel (348)
Реализованы базовый класс TCustomArincLabel и классы TBnrArincLabel и TBcdArincLabel для двоичных и двоично-десятичных данных соответственно. Здесь приведено только публичное объявление базового класса
class TCustomArincLabel
public:
TCustomArincLabel(quint8 ALabelId, quint8 ALeastBit, double AResolution, bool ACheckLabelId = true, QString AName = 0, QString AUnits = 0, QString APosSignPrefSuff = 0, QString ANegSignPrefSuff = 0, bool ASignPrefOrSuff = false, quint8 APrecision = 2, quint8 ALength = 0);
virtual ~TCustomArincLabel(){}; // Виртуальный деструктор!
TArincLabelTypes getType(); //  Получить тип метки (она устанавливается в потомках!)
quint8 getLabelId(); //  Чтение кода метки
QString getOctLabelId(); //  Чтение кода метки в восьмеричной системе
quint32 getData(); //  Чтение кода метки (перед записью в шину)
virtual void setData(quint32 AData)=0; //  Установка кода метки (после чтения из шины)
TArincSsmTypes getSsm(); //  Чтение матрицы знака/статуса (после чтения из шины)
void setSsm(TArincSsmTypes ASsm); //  Установка значения метки (перед записью в шину)
double getValue(); //  Чтение значения метки (после чтения из шины)
virtual void setValue(double AValue)=0; //  Установка значения метки (перед записью в шину)
bool getNotNormal(); //  Получить флаг не нормального состояния
QString getStatus(); //  Получить строку статуса
virtual QString getFormattedValue()=0; //  Получить форматированную строку значения метки
QString getValueStr(); //  Получить неформатированную строку значения метки
В потомках перегружены конструкторы (задается тип метки) и методы setData, setValue и getFormattedValue. В классе для двочино-десятичных данных метод setValue не формирует BCD-данные и пока класс может использоваться только для чтения. Для форматирования специфических данных нужно или добавлять маски или делать специфических потомков.
5.4.2 Базовый класс для работы с адаптером PCI429_3 QCustomArinc429 (234)
Класс является оберткой для драйвера pci429_3win и является потомком класса QCustomDevice. Должны быть подключены intrfacePCI3.h и ioctlPCI3.h. Пока будет реализованы разовая и циклическая выдача в канал последовательного кода (ПК), адресный и файловый прием отдельных параметров и их массива из канала ПК. Работа с каналами разовых команд (РК) пока реализована не будет, обработка прерываний – тоже.
class QCustomArinc429: public QCustomDevice;
Q_PROPERTY:
bool ConnectByIndex //!<    Флаг поиска адаптера по индексу или серийному номеру
quint32 DeviceIndex //!<    Индекс устройства
quint16 SerialNumber //!<    Серийный номер
TArincChannelsFreqs ChannelsFreqs //!<    Частоты каналов
QString ModelName //!<    Наименование модификации
private:
bool startInput(DWORD AIoControlCode, quint16 AChannelNumber, quint16 AArrayNumber, quint16 AInterruptParamAddr, quint16 AStopParamAddr); 
protected:
bool connect();	//	Подключение
void disconnect();	//	Отключение
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
bool getConnected() {return m_Arinc;} //!<    Возврат статуса подключения 
bool prepareOutputParams(quint16 AChannelNumber, quint16 AArrayNumber, const TParamsOutputArray& AParams, bool AInterruptOnEnd = false); //!< Подготовка массива к однократной выдаче
bool startSingleOutput(quint16 AChannelNumber, quint16 AArrayNumber); //!< Старт однократной выдачи
TArincChannelState getOutputChannelState(quint16 AChannelNumber); //!< Опрос состояния выходного канала
bool startCyclicOutput(quint16 AChannelNumber, quint16 APeriod, const TParamsOutputArray& AParams, bool AInterruptOnEnd = false); //!< Старт циклической выдачи
bool sendParamToCyclicOutput(quint16 AChannelNumber, quint16 AParamNumber, quint32 AParamValue); //!< Передача параметра в циклическую выдачу
bool stopCyclicOutput(quint16 AChannelNumber); //!< Остановка циклической выдачи
bool startAddressInput(quint16 AChannelNumber, quint16 AArrayNumber, quint16 AInterruptParamAddr = 0xfff, quint16 AStopParamAddr = 0xfff);  //!< Старт адресного приема
bool startFileInput(quint16 AChannelNumber, quint16 AArrayNumber, quint16 AInterruptParamAddr = 0xfff, quint16 AStopParamAddr = 0xfff); //!< Старт файлового приема
bool stopInput(quint16 AChannelNumber); //!< Остановка приема
TArincChannelState getInputChannelState(quint16 AChannelNumber); //!< Опрос состояния входного канала
bool ReadParam(quint16 AChannelNumber, quint16 AArrayNumber, quint16 AParamNumber, quint32& AParamValue); //!< Чтение принятого слова ПК
bool ReadParams(quint16 AChannelNumber, quint16 AArrayNumber, const TParamsInputArray& AParams); //!< Чтение массива входных параметров
public:
QCustomArinc429(const QString& ADeviceName, QObject* AParent=0);
~QCustomArinc429();
5.4.3 Класс для периодического адресного чтения данных из адаптера PCI429_3 QArinc429AddressInput (378)
Класс содержит массив словарей меток для 8 каналов (максимально возможное количество). При включении инициируется адресное чтение каналов, для которых в словарях заданы метки, и запускается таймер опроса канала. Таймер запускается в любом случае!!! В слоте таймера onTimer, если ARINC инициализирован нормально, происходит чтение всех меток, заданных в словарях. В конце вызывается виртуальный метод afterRead, который должен быть реализован в потомках
class QArinc429AddressInput: public QCustomArinc429;
Q_PROPERTY:
	quint32 TimerPeriod	//  Период чтения данных
private:
	QTimer* m_Timer;
private slots:
bool onTimer(); //!< Слот таймера - периодическое чтение данных из адаптера
protected:
QMap<quint8, TCustomArincLabel*> m_Labels[8]; // Массив словарей меток
bool connect();	//	Подключение
void disconnect();	//	Отключение
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
virtual void afterRead(bool AErr=false)=0; //!<    Метод обработки прочитанных данных
прочитанных данных
public:
QArinc429AddressInput(const QString& ADeviceName, QObject* AParent=0);
~QArinc429AddressInput(); // Удаление меток!!!
6 Классы визуальных элементов интерфейса
6.1 Базовый класс QCustomWidget (259)
Класс-предок для всех визуальных классов с метаобъектной функциональностью. По сути включают почти те же свойства и методы, что и классы QCustomObject и QCustomDevice. Добавить в подпроект CommonUnits.
class QCustomWidget: public QWidget;
Q_PROPERTY:
QString DeviceName	//	Только чтение, в конечных потомках будет назначаться непосредственно в конструкторе, связанный член данных имеет смысл хранить в protected; он же по сути будет именем раздела в конфиге
QString ConfigFileName	//	Чтение и запись (поле данных – в защищенной секции)
protected:
bool m_Updated;	//	Флаг, устанавливаемый перед изменением нескольких св-в для предотвращения нескольких переключений
virtual void readSettings(QSettings* ASettings)=0;	//	Чтение настроек
virtual void writeSettings(QSettings* ASettings)=0;	//	Запись настроек
public:
QCustomWidget(const QString& ADeviceName, QObject* AParent=0);
public slots:
	virtual void defineDefaultSettings()=0;	//	Установка настроек по-умолчанию
void loadSettings();	//	Загрузка настроек
void saveSettings();	//	Сохранение настроек
6.2 Классы виртуальной кнопочной панели
6.2.1 Базовый класс виртуальной кнопочной панели QCustomVirtualKeypad (269)
Класс предназначен для реализации панели виртуальных кнопок сбоку экрана для организации древовидных деревьев меню в совокупности с реальными кнопочными панелями. Представляет собой один вертикальный ряд объектов типа QLabel. Каждая кнопка характеризуется значением статуса (тип TVirtualButtonStatus) и кодом надписи. Ассоциативный список всех возможных надписей загружается из файла формата ini или xml, либо может быть установлен непосредственно в коде потомка данного класса. Настраиваются цвета и стили надписей, цвет фона – для всех возможных состояний – посредством свойства типа ассоциативного списка стилей.
class QCustomVirtualKeypad: public QCustomWidget;
PROPERTY 
quint32 ButtonsCount // Количество «кнопок»; при установке добавлять или удалять объекты типа QLabel
TVirtualButtons Buttons // Список структур (QVector<TVirtualButtonData>), хранящий статусы и коды надписей «кнопок»
QMap<TVirtualButtonStatus, QString> ButtonStyle // Ассоциативный список стилей «кнопок»; ключ – код статуса
private:
	QVector<QLabel*> m_Labels; //	Список указателей на созданные «кнопки»
	QMap<quint32, QString> m_Captions;	//	Список всех возможных надписей на «кнопках»
protected:
void readSettings(QSettings* ASettings);	//	Чтение настроек
void writeSettings(QSettings* ASettings);	//	Запись настроек
public:
QCustomVirtualKeypad(const QString& ADeviceName, quint8 ACount, QWidget* AParent = 0);
public slots:
void defineDefaultSettings();                   //  Настройки по умолчанию
void setButtons(TVirtualButtons& AButtons);      //  Установить состояние кнопок (если кол-во отличается от текущего, предварительно вызвать setButtonsCount)
void setButton(quint Aid, TVirtualButtonData& AButtonData);      //  Установить состояние одной кнопки
6.3 Классы строки состояния
6.3.1 Перечисление TInfoItemStatus
Перечисление со статусами информационных сообщений:
enum TInfoItemStatus
{
    iisDisabled,        //  Выключен (серый)
    iisInfo,            //  Иноформация (синий)
    iisWarning,         //  Предупреждение (желтый)
    iisError            //  Ошибка (красный)
};
6.3.2 Структура TInfoData
Структура хранения данных информационного сообщения:
struct TInfoData
{
    QString Text;
    TInfoItemStatus Status;
    quint32 TimerId;
};
6.3.3 Класс-список сообщений QMapInfoList
Класс – ассоциативный список – для хранения данных информационных сообщений. Реализован метод поиска записи по идентификатору одного из полей дочерней структуры – коду таймера.
class QMapInfoList : public QMap<QObject*, TInfoData>
public:
    QObject* getItemByTimerId(quint32 ATimerId);
6.3.4 Класс надписи для строки состояния QInfoLabel
Класс информационной надписи с возможностью поочередного вывода набора сообщений от разных источников, характеризующихся текстом сообщения и статусом. Статус сообщений определяет стиль отображения. Стили для всех статусов едины для всех экземпляров класса (статические данные).
class QInfoLabel : public QLabel
private:
QMapInfoList::const_iterator m_Iterator;
QTimer* m_ListTimer;
QMapInfoList m_InfoList;
static QMap<TInfoItemStatus, QString> m_StylesList;
TInfoItemStatus m_DefaultStatus;
void next();
protected:
void timerEvent(QTimerEvent* ATimerEvent);
public:
QInfoLabel(QWidget* AParent = 0);
QInfoLabel(const QString& ACaption, const TInfoItemStatus AStatus = iisInfo, QWidget* AParent = 0);
QString getStyleStatus(const TInfoItemStatus AStatus); //!<	Считать стиль статуса
quint32 getListTimerPeriod() const; //!<    Считать период таймера
TInfoItemStatus getDefaultStatus() const; //!<    Считать статус по-умолчанию
void setStyleStatus(const TInfoItemStatus AStatus, const QString AStyle); //!< Установить стиль статуса
public slots:
void setListTimerPeriod(quint32 ATime); //!<    Установить период таймера
void addInfoData(const QString& AText, const TInfoItemStatus AStatus = iisInfo, quint32 ATime = 0, QObject *AObject = 0); //!<    Добавить сообщение
void removeInfoData(QObject* AObject = 0); //!<    Удалить сообщение
void clearInfoData(); //!<	Очистить весь список
void setDefaultStatus(const TInfoItemStatus AStatus); //!<    Статус по-умолчанию
void changeStatus(const TInfoItemStatus AStatus); //!<    Слот для вызова при изменении стиля
private slots:
void update(); //!<    Перерисовать надпись
6.3.5 Базовый класс строки состояния QCustomStatusBar (318)
Класс строки состояния – набор объектов QInfoLabel.
По архитектуре класс очень похож на QCustomVirtualKeypad, но расположение элементов горизонтальное, а вместо QLabel используется QInfoLabel, уже обладающий необходимой функциональностью.
class QCustomStatusBar : public QCustomWidget
private:
QHBoxLayout* m_BoxLayout;
QVector<QInfoLabel*> m_Labels;
protected:
void readSettings(QSettings* ASettings);
void writeSettings(QSettings *ASettings);
public:
QCustomStatusBar(const QString& ADeviceName, quint8 ACount, QWidget *AParent = 0);
quint8 getLabelsCount() const; //!<    Считать количество надписей
QString getStatusStyle(TInfoItemStatus AStatus) const; //!<    Считать стиль для статуса
QInfoLabel* getInfoLabel(quint8 AId) const;	//!<    Получить указатель на надпись по индексу
void addInfoData(quint8 AId, const QString& AText, TInfoItemStatus AStatus, quint32 ATime);      //!<    Добавить сообщение
void removeInfoData(quint8 AId);
public slots:
void defineDefaultSettings();
void setLabelsCount(quint8 ANewCount); //!<    Установить количество надписей
void setStatusStyle(TInfoItemStatus AStatus, const QString &AStyle); //!<    Стиль для статуса
void addInfoData(quint8 AId, const QString& AText, TInfoItemStatus AStatus, quint32 ATime, QObject *AObject);      //!<    Добавить сообщение
void removeInfoData(quint8 AId, QObject* AObject); //!<    Удалить сообщение
void setWidthLabel(quint8 AId, quint32 AWidth//!<    Ширина надписи
6.4 Базовый класс «легенды» QCustomLegend (367)
Потомок QCustomWidget. Полупрозрачный виджет с выводом информации в виде списка параметров. Задаются стили для вывода координат и угловых параметров. Реализован в ходе выполнения задачи 367 и сделан базовым классом для QObrcTargetLegend и QPlaneTelemetryWidget.
7 Различные вспомогательные классы
7.1 Базовый класс карты QCustomMap (323)
Класс-обертка для объекта карты библиотеки gisAPI. Не является контроллером, но будет активно применяться в их составе. Должен создавать единичный объект карты, хранить его дескриптор, открывать матричные данные, обеспечивать доступ к ряду функций объекта карты, дополнительные сервисные функции для расчетов, а также функции формирования изображения QImage.
Все функции записи – публичные слоты, в описании класса, для краткости, ни они, ни публичные функции чтения, а также приватные члены данных не указаны.
class QCustomMap: public QObject;
PROPERTY 
QString MapName	//!<    Имя файла векторной карты (чтение/запись)
QString MapMatrixName	//!<    Имя файла матрицы (чтение/запись)
double HeightMin //!<    Минимальная высота в матрице высот (чтение)
double HeightMax //!<    Максимальная высота в матрице высот (чтение)
double HeightElementSize //!<    Размер элемента матрицы в метрах на местности (чтение)
qint64 MapWidthPixel	//!<    Ширина изображения в пикселах для текущего масштаба (чтение)
qint64 MapHeightPixel	//!<    Высота изображения в пикселах для текущего масштаба (чтение)
double AngleRad	//!<    Угол поворота карты в радианах (чтение/запись) – вызов ф-ции mapSetupTurn; все угловые члены данных хранить в радианах, для градусных «свойств» реализовать только ф-ции чтения/записи
double AngleDegree	//!<    Угол поворота карты в градусах (чтение/запись)
double MinAngleRad	//!<    Минимальный угол поворота карты в радианах (чтение/запись); свойство определяет параметр для ф-ции mapSetupTurn
double MinAngleDegree	//!<    Минимальный угол поворота карты в градусах (чтение/запись)
double Scale	//!<    Знаменатель текущего масштаба (чтение/запись)
	TGeodeticCoords CenterPointGeoCoords	//	Геодезические координаты центра просмотра (для ф-ции формирования изображения); хранить именно геодезические координаты
	TProjectionCoords CenterPointProjCoords	//	Проекционные координаты центра просмотра (для ф-ции формирования изображения)
	SIZE ViewSize	//	Размер области просмотра карты (для ф-ции формирования изображения)
protected:
HMAP m_hMap;	//  Идентификатор векторной карты (можно и в приватную, но если захотим делать потомков, придется геттер добавлять)
public:
explicit QCustomMap(QObject* AParent=0);    //!<    Конструктор
~QCustomMap();                              //!<    Деструктор
void drawMapRect(QImage* AImage); //  Перерисовка окна с фрагментом карты 
public slots:
void mapOpen(QString AMapName = "", QString AMapMatrixName = "");   //!<    Открытие векторной карты и матриц
void mapClose();                                    //!<    Закрытие векторной карты и матрицы, если была открыта
void rotateRad(double ADelta);                 //!<    Поворот карты на угол ADelta в радианах
void rotateDegree(double ADelta);              //!<    Поворот карты на угол ADelta в градусах
void changeCenterPos(long int dx,long int dy);            //!<    Перемещение карты в окне просмотра
void changeCenterPos(QPoint AShift);                      //!<    Перемещение карты в окне просмотра
7.2 Классы обработки значений осей джойстика (384)
Классы для осей джойстика сохранить в каталоге JoystickUnits в подпроекте JoystickMath.
7.2.1 Базовый класс осей джойстика QCustomJoyAxis
Класс служит для настройки и хранения кривой отклика оси джойстика, а также для преобразования входного значения оси в выходное с учетом кривой отклика. Должны быть методы чтения/записи у всех свойств (не все приведены ниже), а также реализация чтения/записи в конфиг.
class QCustomJoyAxis: public QCustomDevice
PROPERTY
	quint32 MaxValue // Максимальное значение по оси
quint8 Sensitivity[11] // Кривая отклика оси (%)
quint8 Deadband // Мертвая зона (%)
quint8 Smoothing // Сглаживание
TSplineType SplineType // Тип интерполяционного сплайна
void recalc();	// Пересчет коэффициентов
protected:
bool connect(){return true};
void disconnect(){};
void readSettings(QSettings* ASettings);	//	Чтение «св-в»
void writeSettings(QSettings *ASettings); 	//	Запись «св-в»
public:
explicit QCustomJoyAxis(const QString& ADeviceName, QObject* AParent = 0);
public slots: 
	void setSensitivity(quint8 AIndex, quint8 AValue);
	void setMaxValue (quint32 AValue);
	void setSplineType(TSplineType ASplineType);
	void setAxis(qint32 AValue);
signals:
void sendAxis(qint32);	//	Послать значение оси с учетом кривой отклика
7.2.2 Класс оси джойстика для координаты экрана QJoyScreenMove
Класс служит для преобразования отклонения джойстика в координату на экране. Можно задать стартовое значение координаты, при отклонении джойстика по оси будет расчитана новая координата (float), при изменении ее целой части должен быть послан сигнал с целой частью новой координаты.
class QJoyScreenMove: public QCustomJoyAxis
PROPERTY
	TBorderActionType BorderActionType// Поведение курсора на границе; по-умолчанию - batStopOnBorders
	quint32 TotalPixels // Количество пикселей по оси
	quint32 MinPos // Минимальное значение по оси (0)
	quint32 MaxPos // Максимальное значение по оси (TotalPixels)
	quint32 TotalTime // Время, за которое «точка» должна пройти весь экран в направлении оси, мс
	quint32 Position // Текущее значение (без чтения/записи конфига – только методы)
private: 
	float m_Position; // Специально пишу и приватный член, потому что методы – целые, а он – вещественный
private slots: 
void receiveAxis(qint32 AValue);	//	Принять значение оси
protected:
void readSettings(QSettings* ASettings);	//	Чтение «св-в»
void writeSettings(QSettings *ASettings); 	//	Запись «св-в»
void recalc();	// Пересчет скорости точки (здесь)
public:
explicit QJoyScreenMove(const QString& ADeviceName, QObject* AParent = 0);
public slots: 
	void setTotalPixels(quint32 AValue);
	void setTotalTime(quint32 AValue);
	void setPosition(quint32 AValue); // Установка целой координаты (программно)
signals:
	void sendPosition(qint32); // Изменение целой координаты (отклонением джойстика)
7.2.3 Класс оси джойстика для перебора элементов QJoyScroller (413)
Класс служит для перебора / промотки каких-либо элементов с помощью джойстика.
С помощью свойства Steps задаются пороговые величины:
•	при превышении первой пороговой величины – с индексом 0 –происходит однократная генерация сигнала sendScroll; для повторной однократной генерации сигнала необходимо вернуть джойстик в «нейтральное» положение (ниже первой пороговой величины);
•	при превышении второй пороговой величины (и до достижения третьей) происходит генерация сигнала sendScroll раз в секунду;
•	при превышении третьей пороговой величины – происходит генерация сигнала sendScroll два раза в секунду и т.д.
class QJoyScroller: public QCustomJoyAxis
PROPERTY
	QVector Steps // Пороговые величины
private:
	QTimer* m_Timer;
qint32 m_OldAbsValue;
private slots: 
void receiveAxis(qint32 AValue);	//	Принять значение оси
void onTimer();	//	Слот срабатывания таймера
protected:
void readSettings(QSettings* ASettings); // Чтение Steps (с beginWriteArray)
void writeSettings(QSettings *ASettings); // Запись Steps (с beginReadArray)
public:
explicit QJoyScroller(const QString& ADeviceName, QObject* AParent = 0);
public slots:
void defineDefaultSettings();
signals:
	void sendScroll(TDirectType ADirect); // Сигнал «скроллинга» вверх или вниз
