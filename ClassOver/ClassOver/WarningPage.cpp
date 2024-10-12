#include "pch.h"
#include "WarningPage.h"
#if __has_include("WarningPage.g.cpp")
#include "WarningPage.g.cpp"
#endif


using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::ClassOver::implementation
{
    WarningPage::WarningPage() {
        //InitializeComponent();
    }


    int32_t WarningPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void WarningPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void WarningPage::ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        using namespace winrt;
        using namespace Microsoft::UI;
        using namespace Windowing;
        using namespace winrt::Microsoft::UI::Xaml;

        /*
        if (m_Window == nullptr) MessageBox(NULL, L"退出全屏失败（导航失败）。", L"错误", MB_OK);
        else    m_Window.SetPresenter(AppWindowPresenterKind::Default);*/

        m_Window.Destroy();
    }

    void WarningPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        using namespace winrt::Microsoft::UI::Xaml;

        Window w_window = e.Parameter().as<Window>();   // 见MainPage批注
        WarningWindow warningWindow = w_window.as<winrt::ClassOver::WarningWindow>();
        
        m_Window = warningWindow.get_Wwindow();
        //MessageBox(NULL, L"do it", L"错误", MB_OK);
        
    }


    void WarningPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        timer();
    }

    winrt::Windows::Foundation::IAsyncAction WarningPage::timer()
    {
        winrt::apartment_context ui_thread;

        co_await winrt::resume_background(); // Return control; resume on thread pool.


        using namespace std::chrono;

        time_point start = system_clock::now();

        time_point current = system_clock::now();

        system_clock::duration dur = start - current;

        int lesstime = duration_cast<seconds>(dur).count() + 5;

        while (lesstime > 0)
        {
            current = system_clock::now();
            system_clock::duration dur = start - current;
            lesstime = duration_cast<seconds>(dur).count() + 5;

            co_await ui_thread;
            cnter().Text(to_hstring(lesstime));
            co_await winrt::resume_background();

            std::this_thread::sleep_for(milliseconds(100));
        }
        co_await ui_thread;
        exitButton().Visibility(Visibility::Visible);
    }
}

