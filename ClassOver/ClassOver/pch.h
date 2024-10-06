#pragma once
#include <windows.h>
#include <unknwn.h>
#include <restrictederrorinfo.h>
#include <hstring.h>

// Undefine GetCurrentTime macro to prevent
// conflict with Storyboard::GetCurrentTime
#undef GetCurrentTime

#define WM_TRAYTASK  WM_USER+1

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Data.h>
#include <winrt/Microsoft.UI.Xaml.Interop.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Navigation.h>
#include <winrt/Microsoft.UI.Xaml.Shapes.h>
#include <winrt/Microsoft.UI.Dispatching.h>
#include <wil/cppwinrt_helpers.h>

//#include <winrt/Windows.UI.Xaml.Navigation.h>
//#include <winrt/Windows.UI.Xaml.Controls.h>

//#include <winrt/Windows.Web.Syndication.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.ViewManagement.h>

#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.h>
#include <Microsoft.UI.Xaml.Window.h>
#include <winrt/Microsoft.UI.Interop.h>

#include <winrt/Microsoft.UI.Xaml.Hosting.h>

#include <chrono>
#include <ctime>
// time check

#include "Settings.h"
// class

#include <filesystem>
#include <fstream>
#include <winrt/Windows.Storage.h>


#include "SimpleTrayIcon/MyTrayMenu.h"
#ifdef _WIN64
#pragma comment(lib, "SimpleTrayIcon_x64.lib")
// SimpleTrayIcon x64 only
#endif 
#include "SimpleTrayIcon/framework.h"
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include "SimpleTrayIcon/Win32Exception.h"
// copy  SimpleTrayIcon to here

#include "nlohmann/json.hpp"
// using nlohmann/json.hpp for json to store settings

#pragma comment(lib, "Shell32.lib")

#include <Resources/resource.h>