#include "pch.h"
#include "WarningWindow.xaml.h"
#if __has_include("WarningWindow.g.cpp")
#include "WarningWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ClassOver::implementation
{
    int32_t WarningWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void WarningWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void WarningWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

    
    
}
