#include "pch.h"
#include "WarningWindow.xaml.h"
#include "MainPage.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "WarningWindow.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::ClassOver::implementation
{
	int32_t MainPage::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainPage::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	void MainPage::ClickHandler(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&)
	{
		//Button().Content(box_value(L"Clicked"));
		creatWindowKit();
	}


	winrt::Windows::Foundation::IAsyncAction MainPage::check_30min(int hh, int mm, int ss)
	{
		winrt::apartment_context ui_thread;

		co_await winrt::resume_background(); // Return control; resume on thread pool.

		using namespace std::chrono;

		time_point now = system_clock::now();



		// =====================
		//    设置指定时间

		int SetHour = hh, SetMin = mm, SetSec = ss;

		std::time_t now_t = system_clock::to_time_t(now);

		std::tm* now_tm = new tm;
		localtime_s(now_tm, &now_t);

		now_tm->tm_hour = SetHour;
		now_tm->tm_min = SetMin;
		now_tm->tm_sec = SetSec;

		std::time_t new_time_t = std::mktime(now_tm);

		time_point setTime = system_clock::from_time_t(new_time_t);

		// 
		// Set time end.
		// ============



		system_clock::duration remainingTime = setTime - now;

		int remainingMin = duration_cast<minutes>(remainingTime).count();
		remainingMin = abs(remainingMin);

		while (abs(remainingMin) >= 60)
		{
			std::this_thread::sleep_for(minutes(30));

			now = system_clock::now();

			remainingTime = setTime - now;

			remainingMin = duration_cast<minutes>(remainingTime).count();

		}


		using namespace winrt::Microsoft::UI::Xaml::Controls;
		using namespace winrt::Windows::UI::Xaml;



		//Frame rootFrame = Frame();

		// 配置rootFrame，比如添加NavigationFailed事件处理程序

		// 不足60分钟

		check_10min(setTime, ui_thread);
	}
	winrt::Windows::Foundation::IAsyncAction MainPage::check_10min(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread)
	{
		co_await winrt::resume_background(); // Return control; resume on thread pool.

		using namespace std::chrono;


		time_point now = system_clock::now();

		system_clock::duration remainingTime = setTime - now;

		int remainingMin = duration_cast<minutes>(remainingTime).count();
		remainingMin = abs(remainingMin);
		// 先检测一遍

		while (abs(remainingMin) >= 20)
		{
			std::this_thread::sleep_for(minutes(10));

			now = system_clock::now();

			remainingTime = setTime - now;

			remainingMin = duration_cast<minutes>(remainingTime).count();

		}


		// 不足20分钟

		check_3min(setTime, ui_thread);
	}


	winrt::Windows::Foundation::IAsyncAction MainPage::check_3min(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread)
	{
		co_await winrt::resume_background(); // Return control; resume on thread pool.

		using namespace std::chrono;


		time_point now = system_clock::now();

		system_clock::duration remainingTime = setTime - now;

		int remainingMin = duration_cast<minutes>(remainingTime).count();
		remainingMin = abs(remainingMin);
		// 先检测一遍

		while (abs(remainingMin) >= 6)
		{
			std::this_thread::sleep_for(minutes(3));

			now = system_clock::now();

			remainingTime = setTime - now;

			remainingMin = duration_cast<minutes>(remainingTime).count();

		}


		// 不足6分钟

		check_1min(setTime, ui_thread);

	}


	winrt::Windows::Foundation::IAsyncAction MainPage::check_1min(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread)
	{
		co_await winrt::resume_background(); // Return control; resume on thread pool.

		using namespace std::chrono;


		time_point now = system_clock::now();

		system_clock::duration remainingTime = setTime - now;

		int remainingSec = duration_cast<seconds>(remainingTime).count();
		remainingSec = abs(remainingSec);
		// 先检测一遍 注意 变为秒钟

		while (abs(remainingSec) >= 120)
		{
			std::this_thread::sleep_for(seconds(60));

			now = system_clock::now();

			remainingTime = setTime - now;

			remainingSec = duration_cast<seconds>(remainingTime).count();

		}


		// 不足120s

		check_5s(setTime, ui_thread);

	}


	winrt::Windows::Foundation::IAsyncAction MainPage::check_5s(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread)
	{
		co_await winrt::resume_background(); // Return control; resume on thread pool.

		using namespace std::chrono;


		time_point now = system_clock::now();

		system_clock::duration remainingTime = setTime - now;

		int remainingSec = duration_cast<seconds>(remainingTime).count();
		remainingSec = abs(remainingSec);
		// 先检测一遍 注意 变为秒钟

		while (abs(remainingSec) >= 11)
		{
			std::this_thread::sleep_for(seconds(5));

			now = system_clock::now();

			remainingTime = setTime - now;

			remainingSec = duration_cast<seconds>(remainingTime).count();

		}


		// 不足11s

		check_1s(setTime, ui_thread);

	}


	winrt::Windows::Foundation::IAsyncAction MainPage::check_1s(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread)
	{
		co_await winrt::resume_background(); // Return control; resume on thread pool.

		using namespace std::chrono;


		time_point now = system_clock::now();

		system_clock::duration remainingTime = setTime - now;

		int remainingSec = duration_cast<seconds>(remainingTime).count();
		remainingSec = abs(remainingSec);
		// 先检测一遍 注意 变为秒钟

		while (abs(remainingSec) > 1)   // 留出一秒给系统
		{
			std::this_thread::sleep_for(seconds(1));

			now = system_clock::now();

			remainingTime = setTime - now;

			remainingSec = duration_cast<seconds>(remainingTime).count();

		}


		// 不足1s 
		// 正片开始

		/*window = make<WarningPage>();
		window.Activate();*/
		//winrt::Windows::UI::Xaml::Controls::Frame rootFrame = window.Content().try_as<winrt::Windows::UI::Xaml::Controls::Frame>();

		//rootFrame.Navigate(xaml_typename<WarningPage>());
		co_await ui_thread;
		creatWindowKit();

	}



	void MainPage::creatWindowKit()
	{
		using namespace winrt::Microsoft::UI;
		using namespace winrt::Microsoft::UI::Windowing;


		Microsoft::UI::Xaml::Window warningWindow_create = make<winrt::ClassOver::implementation::WarningWindow>();

		//Get access to IWindowNative
		winrt::com_ptr<::IWindowNative> windowNative = warningWindow_create.as<IWindowNative>();

		//Get the HWND for the XAML Window
		HWND hWnd;
		windowNative->get_WindowHandle(&hWnd);

		WindowId id = GetWindowIdFromWindow(hWnd);

		// Convent to AppWindow
		winrt::Microsoft::UI::Windowing::AppWindow appwind = winrt::Microsoft::UI::Windowing::AppWindow::GetFromWindowId(id);
		appwind.SetPresenter(AppWindowPresenterKind::FullScreen);
		appwind.Title(L"下课时间到！");
		appwind.MoveInZOrderAtTop();

		appWindowContentFrame = winrt::Microsoft::UI::Xaml::Controls::Frame();
		appWindowContentFrame.Navigate(xaml_typename<WarningPage>(), warningWindow_create);
		// 务必加上 warningWindow_create 传递当前窗口！ 只有这样 WarningPage 里 Navigation::NavigationEventArgs const& e 才有意义！！！！

		warningWindow_create.Content(appWindowContentFrame);

		warningWindow_create.Activate();

		//appwind.Hide();
	}

	bool MainPage::setSettings()
	{
		using namespace nlohmann;

		hstring path_main = Tools::getRoamingAppDataPath() + L"\\ClassOver\\";
		path = winrt::to_string(path_main) + R"(\settings.json)";

		if (!std::filesystem::exists(path)) {
			std::filesystem::path p = to_string(path_main);
			std::filesystem::create_directories(p);
		}

		std::string setting_s;
		if (!Tools::readFileIntoString(path, &setting_s))
			return 0;

		json jsonSource = json::parse(setting_s);

		timerSet.clear();

		int length = jsonSource.at("timerCount");
		for (size_t i = 0; i < length; i++)
		{
			string name = Tools::makeName(i);
			Timer tmpTimer{
				jsonSource.at(name).at("hh"),
				jsonSource.at(name).at("mm"),
				jsonSource.at(name).at("ss")
			};

			timerSet.push_back(tmpTimer);
		}
		return 1;
	}

	void MainPage::renewBar()
	{
		int t6 = TimerSelecterBar().Items().Size();

		TimerSelecterBar().Items().Clear(); // it dosent work
		//TimerSelecterBar().Items().RemoveAtEnd();
		int t = TimerSelecterBar().Items().Size();

		for (size_t i = 0; i < timerSet.size(); i++)
		{
			winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem item;
			hstring name = to_hstring(timerSet[i].hh) + L":" + to_hstring(timerSet[i].mm) + L":" + to_hstring(timerSet[i].ss);
			item.Name(to_hstring(i));
			item.Text(name);
			item.Click({ this, &MainPage::TimerSelect_click });
			TimerSelecterBar().Items().Append(item);
			// add timer to xaml
		}

		hstring title_first = TimerSelecterBar().Items().GetAt(selected_timer).as< winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Text();
		//TimerSelecterBar().Title(L"计时器:" + title_first);
		displayTimer(timerSet[selected_timer]);
	}


	void MainPage::displayTimer(Timer T)
	{
		timeSelecter_H().Title(L"时：" + to_hstring(T.hh));
		timeSelecter_M().Title(L"分：" + to_hstring(T.mm));
		timeSelecter_S().Title(L"秒：" + to_hstring(T.ss));
	}
	void MainPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		using namespace winrt::Microsoft::UI::Xaml;

		Window window = e.Parameter().as<Window>();
		m_window = window.AppWindow();
	}
}


void winrt::ClassOver::implementation::MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	using namespace winrt::Microsoft::UI::Xaml;
	if (setSettings())
	{
		renewBar();
		for (size_t i = 0; i < timerSet.size(); i++)
		{
			check_30min(
				timerSet[i].hh,
				timerSet[i].mm,
				timerSet[i].ss
			);
		}

	}

	hstring title_first = TimerSelecterBar().Items().GetAt(0).as< winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Text();
	//TimerSelecterBar().Title(L"计时器:" + title_first);
	displayTimer(timerSet[selected_timer]);

	for (size_t i = 1; i <= 24; i++)
	{
		winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem item;
		hstring value = to_hstring(i);
		item.Name(value);
		item.Text(value);
		item.HorizontalAlignment(HorizontalAlignment::Center);
		item.Click({ this, &MainPage::TimerSelect_click_H });
		timeSelecter_H().Items().Append(item);
	}
	for (size_t i = 0; i <= 59; i++)
	{
		winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem item;
		hstring value = to_hstring(i);
		item.Name(value);
		item.Text(value);
		item.HorizontalAlignment(HorizontalAlignment::Center);
		item.Click({ this, &MainPage::TimerSelect_click_M });
		timeSelecter_M().Items().Append(item);
	}
	for (size_t i = 0; i <= 59; i++)
	{
		winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem item;
		hstring value = to_hstring(i);
		item.Name(value);
		item.Text(value);
		item.HorizontalAlignment(HorizontalAlignment::Center);
		item.Click({ this, &MainPage::TimerSelect_click_S });
		timeSelecter_S().Items().Append(item);
	}


}




void winrt::ClassOver::implementation::MainPage::TimerSelect_click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	hstring txt = sender.as<winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Text();
	//TimerSelecterBar().Title(L"计时器:" + txt);

	hstring id_str = sender.as<winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Name();
	size_t id = std::stoi(to_string(id_str));
	selected_timer = id;
	renewBar();
	//displayTimer(timerSet[id]);
}

void winrt::ClassOver::implementation::MainPage::TimerSelect_click_H(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	hstring id_str = sender.as<winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Name();
	timerSet[selected_timer].hh = std::stoi(to_string(id_str));
	renewBar();
	//displayTimer(timerSet[selected_timer]);
}
void winrt::ClassOver::implementation::MainPage::TimerSelect_click_M(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	hstring id_str = sender.as<winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Name();
	timerSet[selected_timer].mm = std::stoi(to_string(id_str));
	renewBar();
	//displayTimer(timerSet[selected_timer]);
}
void winrt::ClassOver::implementation::MainPage::TimerSelect_click_S(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	hstring id_str = sender.as<winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem>().Name();
	timerSet[selected_timer].ss = std::stoi(to_string(id_str));
	renewBar();
	//displayTimer(timerSet[selected_timer]);
}

void winrt::ClassOver::implementation::MainPage::save_exit_h(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	nlohmann::json writeJson;

	for (size_t i = 0; i < timerSet.size(); i++)
	{
		writeJson["timerCount"] = timerSet.size();
		writeJson[Tools::makeName(i)]["hh"] = timerSet[i].hh;
		writeJson[Tools::makeName(i)]["mm"] = timerSet[i].mm;
		writeJson[Tools::makeName(i)]["ss"] = timerSet[i].ss;
	}

	Tools::writeFileFromString(path, writeJson.dump());

	try {
		m_window.Destroy();
		exit(0);
	}
	catch(hresult h){
		MessageBox(NULL, L"已保存。关闭失败，请结束进程。", L"错误", S_OK);
	}
}

void winrt::ClassOver::implementation::MainPage::delete_h(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	if (timerSet.size() > 1)
	{
		timerSet.erase(timerSet.begin() + selected_timer);
		if (selected_timer == timerSet.size())   // as if selected timer is the last timer.
		{
			selected_timer--;
		}
		renewBar();
	}
}

void winrt::ClassOver::implementation::MainPage::new_h(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	Timer tmp{ 12,34,56 };
	timerSet.push_back(tmp);
	selected_timer = timerSet.size() - 1;
	renewBar();
}
