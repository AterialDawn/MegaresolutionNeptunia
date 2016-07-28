#include "Config.h"
#include "RenderInfo.h"
#include "resource.h"
#include "Log.h"
#include <iostream>
#include <string>
#include "INIReader.h"

#define SETTINGS_FILE_VERSION 1

using namespace std;

HMODULE thisModule = NULL;

//Extract the config from resource
void ExtractConfig(bool forceExtract) {
	HRSRC configRes = FindResource(thisModule, MAKEINTRESOURCE(IDR_DATA1), MAKEINTRESOURCE(TEXTFILE));
	if (configRes != NULL)
	{
		HGLOBAL hData = LoadResource(thisModule, configRes);
		if (hData)
		{
			DWORD dataSize = SizeofResource(thisModule, configRes);
			void* resourceData = LockResource(hData);
			HANDLE outputFile = CreateFile(L"MegaresolutionNeptunia.ini", GENERIC_WRITE, 0, NULL, forceExtract ? CREATE_ALWAYS : CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
			if (!outputFile)
			{
				return;
			}
			DWORD bytesWritten;
			WriteFile(outputFile, resourceData, dataSize, &bytesWritten, NULL);
			CloseHandle(outputFile);
		}
		else
		{
			OutputDebugString(L"Unable to load config resource!");
		}
	}
	else
	{
		OutputDebugString(L"Unable to find config resource!");
	}
}

//Load the config into the RenderInfo class
void LoadConfig() {
	ExtractConfig(false);

	INIReader configReader("MegaresolutionNeptunia.ini");
	if (configReader.ParseError() < 0) {
		OutputDebugString(L"Unable to load config file!");
	}
	OutputDebugString(L"Config loaded!");

	if (configReader.GetInteger("General", "SettingsVersion", 0) != SETTINGS_FILE_VERSION) {
		ExtractConfig(true); //Force extract the config, but use defaults internally
	}

	float scaledWidth = static_cast<float>(configReader.GetReal("Render", "ScaledWidth", 1920.0));
	float scaledHeight = static_cast<float>(configReader.GetReal("Render", "ScaledHeight", 1080.0));
	float bloomScalar = static_cast<float>(configReader.GetReal("Extra", "BloomTextureScalar", 0.0));
	if (bloomScalar <= 0.0f) bloomScalar = 1.0f;
	RenderInfo::SetUpscaledRenderSize(scaledWidth, scaledHeight);
	RenderInfo::SetBloomTextureScalar(bloomScalar);
	Logger::logDisabled = !configReader.GetBoolean("Debug", "Log", false);
	string logLevel = configReader.Get("Debug", "LogLevel", "Always");

	if (!logLevel.compare("Normal")) Logger::SetVerbosity(Logger::Verbosity::Normal);
	else if (!logLevel.compare("Debug")) Logger::SetVerbosity(Logger::Verbosity::Debug);
	else Logger::SetVerbosity(Logger::Verbosity::Always);
}