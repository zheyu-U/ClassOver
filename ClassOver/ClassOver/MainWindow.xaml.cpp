#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif


using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ClassOver::implementation
{
	MainWindow::MainWindow()
	{
		//InitializeComponent();

	   // m_mainAppWindow = GetAppWindowForCurrentWindow();

		this_AppWindow = this->AppWindow();

		this_AppWindow.Closing(&my_onClosing);


	}

	int32_t MainWindow::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainWindow::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
	{

		myButton().Content(box_value(L"Clicked"));
		auto window = Window();
		auto tb = winrt::Microsoft::UI::Xaml::Controls::TextBlock();
		tb.Text(L"Hello");
		window.Content(tb);
		window.Activate();
	}

	void MainWindow::my_onClosing(IInspectable const& sender, Microsoft::UI::Windowing::AppWindowClosingEventArgs e)
	{
		//__debugbreak();
		e.Cancel(true);     // 取消关闭窗口
		onDoubleClick_handler();
		MessageBox(NULL, L"已隐藏，双击托盘打开。", L"ClassOver", S_OK);
	}


	void MainWindow::onDoubleClick_handler()
	{
		if (this_AppWindow.IsVisible()) this_AppWindow.Hide();
		else this_AppWindow.Show();
	}

	Microsoft::UI::Windowing::AppWindow MainWindow::this_AppWindow = nullptr;


	
}




void winrt::ClassOver::implementation::MainWindow::Window_Activated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args)
{
	using namespace winrt::Microsoft::UI::Xaml::Controls;

}

