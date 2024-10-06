#pragma once

#include "WarningPage.g.h"

namespace winrt::ClassOver::implementation
{
    struct WarningPage : WarningPageT<WarningPage>
    {
        WarningPage();
        

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        winrt::Windows::Foundation::IAsyncAction timer();
        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        void closingHandler()
        {

        }
    private:
        winrt::Microsoft::UI::Windowing::AppWindow m_Window{ nullptr };
    };
}

namespace winrt::ClassOver::factory_implementation
{
    struct WarningPage : WarningPageT<WarningPage, implementation::WarningPage>
    {
    };
}
