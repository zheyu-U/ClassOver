#pragma once

#include "App.xaml.g.h"

namespace winrt::ClassOver::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

        void OnNavigationFailed(IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& e);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };

        int a;
        std::vector<Timer> timerSet;
    };
}
