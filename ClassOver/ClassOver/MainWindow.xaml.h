#pragma once

#include "MainWindow.g.h"

namespace winrt::ClassOver::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
	{
		MainWindow();

		int32_t MyProperty();
		void MyProperty(int32_t value);

		void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

		// winrt::Microsoft::UI::Windowing::AppWindow MyAppWindow();

		static void my_onClosing(IInspectable const& sender, Microsoft::UI::Windowing::AppWindowClosingEventArgs e);

		LRESULT CALLBACK WindowProc(HWND hwnd,
			UINT uMsg,
			WPARAM wParam,
			LPARAM lParam
		);


		void Window_Activated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args);

		Microsoft::UI::Windowing::AppWindow get_window()
		{
			return this->AppWindow();
		}

	private:
		//winrt::Microsoft::UI::Windowing::AppWindow GetAppWindowForCurrentWindow();

		//winrt::Microsoft::UI::Windowing::AppWindow m_mainAppWindow{ nullptr };


		static void onDoubleClick_handler();


		TrayIcon my_tray{
			LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)),
			LPWSTR(L"count down -click to open setting page"),
			std::function<void()>(MainWindow::onDoubleClick_handler)
		};

		

		static Microsoft::UI::Windowing::AppWindow this_AppWindow/* = nullptr*/;
		
	};
}

namespace winrt::ClassOver::factory_implementation
{
	struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
	{
	};
}
