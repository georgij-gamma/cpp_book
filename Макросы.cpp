// Для мониторинга входа в ту или иную функцию
#define LOG_TRACE printf("Entering %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__); // СИ
LOG_TRACE // даёт: Entering getT() (D:\repos\visual\code\Prata.cpp:50) (например)

// На C++ в конструкторе будет сообщать о входе в функцию, а в деструкторе о выходе.
// TraceLogger.h:
class TraceLogger {
public:
	TraceLogger(const char* fileName, const char* funcName, int lineNumber);
	~TraceLogger();
	
private:
	const char* _fileName;
	const char* _funcName;
};

#define LOG_TRACE TraceLogger traceLogger(__FILE__, __FUNCTION__, __LINE__);
/* за макросом скрывается создание объекта на стеке с передачей ему в конструкторе имени файла, 
имени функции и номера строки. */
// TraceLogger.cpp:
TraceLogger::TraceLogger(const char* fileName, const char* funcName, int lineNumber) {
	_fileName = fileName;
	_funcName = funcName;
	std::cout << "Entering " << _funcName << "() - (" << _fileName << ":" << lineNumber << ")" << std::endl;
}

TraceLogger::~TraceLogger() {
	std::cout << "Leaving  " << _funcName << "() - (" << _fileName << ")" << std::endl;
}
/* Заведём статический член класса, в котором будем хранить строку-отступ (несколько пробелов) и будем 
выводить её в начале лог-строки. При создании нового экземпляра (что происходит при входе в очередную функцию) 
будем увеличивать отступ, а при его разрушении (что происходит в момент выхода из функции) будем его уменьшать.*/
// TraceLogger.h:
class TraceLogger {
	...
private:
	...
	static std::string Indent;
};

// TraceLogger.cpp:
std::string TraceLogger::Indent;

TraceLogger::TraceLogger(const char* fileName, const char* funcName, int lineNumber) {
	_fileName = fileName;
	_funcName = funcName;
	std::cout << Indent << "Entering " << _funcName << "() - (" << _fileName << ":" << lineNumber << ")" << std::endl;
	Indent.append("  ");
}

TraceLogger::~TraceLogger() {
	Indent.resize(Indent.length() - 2);
	std::cout << Indent << "Leaving  " << _funcName << "() - (" << _fileName << ")" << std::endl;
}
/* Теперь в любой момент выполнения программы можно наглядно видеть, в какой функции мы в данный момент находимся 
и как мы туда, собственно, попали. Ну и если что-то упало, то сразу видно, где именно
	Отключить всё это в релиз-версии:
// TraceLogger.h: */
...
#ifdef DEBUG
#define LOG_TRACE TraceLogger logger(__FILE__, __FUNCTION__, __LINE__);
#else
#define LOG_TRACE
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////