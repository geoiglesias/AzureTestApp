#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

#include "AzureApiTestFunctions.h"


using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::AzureTestApp::implementation
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
        AzureApiTestFunctions::TestAzureRestApi();

        myButton().Content(box_value(L"Clicked"));
    }
}
