#include "Log.h"
#include <string>
#include <sstream>

using namespace std;

bool Logger::logDisabled = true;
Logger::Verbosity Logger::logVerbosity = Verbosity::Normal;
HANDLE Logger::logFile = nullptr;

static string lineEnd("\r\n");

Logger::Logger() {
}

void Logger::SetVerbosity(Verbosity newVerbosity) {
	logVerbosity = newVerbosity;
}

bool Logger::CanLog(Verbosity desiredVerbosity) {
	if (logDisabled) return false;
	return logVerbosity <= desiredVerbosity;
}

bool Logger::InitLog(wstring fileName) {
	if (logDisabled) return false;

	logFile = CreateFile(fileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (!logFile) return FALSE;
	return TRUE;
}

void Logger::Log(string message, Verbosity logVerbosity) {
	if (logDisabled) return;
	if (!CanLog(logVerbosity)) return;
	DWORD len = 0;
	string fMessage = message + lineEnd;
	WriteFile(logFile, fMessage.c_str(), fMessage.length(), &len, NULL);
}

bool Logger::CloseLog() {
	if (logDisabled) return false;

	if (logFile)
	{
		CloseHandle(logFile);
		logFile = NULL;
		return TRUE;
	}
	return FALSE;
}