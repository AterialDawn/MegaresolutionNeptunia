#pragma once
#include "stdafx.h"
#include <string>
#include <sstream>

class Logger {
private:
	static HANDLE logFile;
	Logger();
public:
	static bool logDisabled;
	static bool InitLog(std::wstring fileName);
	static void Log(std::string message);
	static bool CloseLog();
};