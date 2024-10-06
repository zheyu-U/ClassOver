#pragma once

#include "MainPage.g.h"

namespace winrt::ClassOver::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
		MainPage()
		{
			// Xaml objects should not call InitializeComponent during construction.
			// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
		}

		int32_t MyProperty();
		void MyProperty(int32_t value);

		void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
		void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

		winrt::Windows::Foundation::IAsyncAction check_30min(int hh, int mm, int ss);

		winrt::Windows::Foundation::IAsyncAction check_10min(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread);

		winrt::Windows::Foundation::IAsyncAction check_3min(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread);

		winrt::Windows::Foundation::IAsyncAction check_1min(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread);

		winrt::Windows::Foundation::IAsyncAction check_5s(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread);

		winrt::Windows::Foundation::IAsyncAction check_1s(std::chrono::time_point<std::chrono::system_clock> setTime, winrt::apartment_context ui_thread);

		void creatWindowKit();

		bool setSettings();

		void renewBar();

	private:
		void displayTimer(Timer T);

		winrt::Microsoft::UI::Windowing::AppWindow m_window = winrt::Microsoft::UI::Windowing::AppWindow(nullptr);   // set in OnNavigatedTo

		winrt::Microsoft::UI::Xaml::Controls::Frame appWindowContentFrame;

		std::string path;  // set in setSettings()

		std::vector<Timer> timerSet;

		size_t selected_timer = 0;        // set from TimerSelect_click, used by TimerSelect_click_H...
	public:
		void TimerSelect_click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

		void TimerSelect_click_H(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void TimerSelect_click_M(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void TimerSelect_click_S(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
	
		void save_exit_h(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void delete_h(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void new_h(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

	};
}

namespace winrt::ClassOver::factory_implementation
{
	struct MainPage : MainPageT<MainPage, implementation::MainPage>
	{
	};
}
