#include "pch.h"

#include <thread>

#include "AzureApiTestFunctions.h"

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());

    // test the Azure REST API
    AzureApiTestFunctions::TestAzureRestApi();

    while (AzureApiTestFunctions::IsComplete == false)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
