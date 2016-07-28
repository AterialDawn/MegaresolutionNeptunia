#include "Config.h"
#include "RenderInfo.h"
#include "resource.h"
#include "Log.h"
#include <iostream>
#include "INIReader.h"

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

	float scaledWidth = static_cast<float>(configReader.GetReal("Render", "ScaledWidth", 1920.0));
	float scaledHeight = static_cast<float>(configReader.GetReal("Render", "ScaledHeight", 1080.0));
	float bloomScalar = static_cast<float>(configReader.GetReal("Extra", "BloomTextureScalar", 0.0));
	if (bloomScalar <= 0.0f) bloomScalar = 1.0f;
	RenderInfo::SetUpscaledRenderSize(scaledWidth, scaledHeight);
	RenderInfo::SetBloomTextureScalar(bloomScalar);
	Logger::logDisabled = !configReader.GetBoolean("Debug", "Log", false);
}