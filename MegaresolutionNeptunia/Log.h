#pragma once
#include "stdafx.h"
#include <string>
#include <sstream>

class Logger {
public:
	enum class Verbosity : int
	{
		Debug = 0, //Per-frame messages
		Normal = 1, //Normal initialization messages
		Always = 2 //Always logged
	};

	static bool logDisabled;
	static bool InitLog(std::wstring fileName);
	static void SetVerbosity(Logger::Verbosity newVerbosity);
	static bool CanLog(Logger::Verbosity desiredVerbosity);
	static void Log(std::string message, Logger::Verbosity messageVerbosity);
	static bool CloseLog();

private:
	static Verbosity logVerbosity;
	static HANDLE logFile;
	Logger();
	
};