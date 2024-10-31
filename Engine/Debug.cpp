#include <windows.h>
#include "Debug.h"

void Debug::Log(int value, bool isLineFeed)
{
	char str[256];
	sprintf_s(str, "%d", value);
	Debug::Log(str, isLineFeed);
}

void Debug::Log(float value, bool isLineFeed)
{
	char str[256];
	sprintf_s(str, "%f", value);
	Debug::Log(str, isLineFeed);
}

void Debug::Log(std::string value, bool isLineFeed)
{
	if (isLineFeed)	value += "\n";
	OutputDebugString((PCWSTR)value.c_str());
	/*
	wchar_t buffer[256];
	if (isLineFeed)	value += "\n"; 
	swprintf_s(buffer, L"%s", value);
	OutputDebugString(buffer);
	*/

}
