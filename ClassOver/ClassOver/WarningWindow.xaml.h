#pragma once

#include "WarningWindow.g.h"

namespace winrt::ClassOver::implementation
{
    struct WarningWindow : WarningWindowT<WarningWindow>
    {
        WarningWindow()
        {
            this->InitializeComponent();
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
           
            
            
            winrt::ClassOver::WarningWindow warningWindow = *this;
            
            winrt::com_ptr<::IWindowNative> windowNative = warningWindow.as<IWindowNative>();

            HWND hWnd;
            windowNative->get_WindowHandle(&hWnd);

            winrt::Microsoft::UI::WindowId id = winrt::Microsoft::UI::GetWindowIdFromWindow(hWnd);

            // Convent to AppWindow
            m_Window = winrt::Microsoft::UI::Windowing::AppWindow::GetFromWindowId(id);
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    
        //winrt::Windows::Foundation::IAsyncAction timer();

        winrt::Microsoft::UI::Windowing::AppWindow get_Wwindow() const
        {
            return m_Window;
        }

    private:
        winrt::Microsoft::UI::Windowing::AppWindow m_Window{ nullptr };

    };
}

namespace winrt::ClassOver::factory_implementation
{
    struct WarningWindow : WarningWindowT<WarningWindow, implementation::WarningWindow>
    {
    };
}
