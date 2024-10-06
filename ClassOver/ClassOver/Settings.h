#pragma once
//#include "pch.h"
//#define _AFXDLL
//#include <Winsock2.h>
//#include <afxwin.h>
#include <shellapi.h>
#include <string.h>
#include <Windows.h> 
#include <WinUser.h>
#include <strsafe.h>


#define WM_SHOWTASK  WM_USER+1
namespace Tools
{
	winrt::hstring getRoamingAppDataPath();
	bool readFileIntoString(std::string Path, std::string* str);
	bool writeFileFromString(std::string Path, std::string_view scr);
	std::string makeName(size_t num);

}




	class Timer
	{
	public:
		Timer(int h, int m, int s) :hh{ h }, mm{ m }, ss{ s }
		{}

		int hh, mm, ss;




	};

