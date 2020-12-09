#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

#include "AzureApiTestFunctions2.h"


using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::AzureTestApp2::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        // test the Azure REST API
        AzureApiTestFunctions2::TestAzureRestApi();
        while (AzureApiTestFunctions2::IsComplete == false)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        myButton().Content(box_value(L"Clicked"));
    }
}
