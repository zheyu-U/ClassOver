#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include "WarningWindow.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ClassOver::implementation
{
    /// <summary>
    /// Initializes the singleton application object.  This is the first line of authored code
    /// executed, and as such is the logical equivalent of main() or WinMain().
    /// </summary>
    App::App()
    {
        // Xaml objects should not call InitializeComponent during construction.
        // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
        UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
#endif
    }

    /// <summary>
    /// Invoked when the application is launched.
    /// </summary>
    /// <param name="e">Details about the launch request and process.</param>
    void App::OnLaunched([[maybe_unused]] LaunchActivatedEventArgs const& e)
    {
        window = make<MainWindow>();
        

       // using namespace winrt::Windows::UI::Xaml::Controls;
        using namespace winrt::Microsoft::UI::Xaml::Controls;
        

        //Frame rootFrame = window.Content().as<Frame>();
        Frame rootFrame = Frame();
        
        window.Content(rootFrame);
        //rootFrame.Navigate(xaml_typename<MainPage>());
        
        //Frame rootFrame = Frame();

        rootFrame.Navigate(xaml_typename<MainPage>(), window);


        // 配置rootFrame，比如添加NavigationFailed事件处理程序
        rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });

        /*using namespace;*/
        /*window.SetAlwaysOnTop(true);
        WinUIEx*/
        //Get access to IWindowNative
        winrt::com_ptr<::IWindowNative> windowNative = window.as<IWindowNative>();

        //Get the HWND for the XAML Window
        HWND hWnd;
        windowNative->get_WindowHandle(&hWnd);

        window.Activate();

        window.AppWindow().Hide();
    }

    void App::OnNavigationFailed(IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& e)
    {
        MessageBox(NULL, L"初始化失败（导航失败）。\n请尝试重启应用，或找LZY。", L"错误", MB_OK);
    }

}
