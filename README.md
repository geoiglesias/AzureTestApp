# AzureTestApp
Test for https://github.com/Azure/azure-storage-cpp/issues/367

I created this self-contained solution to test https://github.com/Azure/azure-storage-cpp/issues/367
I am using On VS2019 v142 with the Universal Windows Platform (UWP) workload installed.
The NuGet C++/WinRT standard C++ language projection v2.0.201113.7 is installed.
The solution contains two simple projects and shared code to test the Azure CPP REST API from here:
https://github.com/Azure/azure-storage-cpp
Track1 SDK 

SharedAzureFiles – The shared code called from both projects to ensure the  actual code is the same for both applications. 
The actual API calls are called from with in a background thread using winrt::Windows::System::Threading::ThreadPool::RunAsync
See static void AzureApiTestFunctions::TestAzureRestApi() in AzureApiTestFunctions.cpp

AzureTestApp – UWP Application.

I created a C++winrt blank UWP App and placed test code to access my Azure storage when the user clicks the button on the blank application main page. The code fails with an abort from an attempt to destroy a mutex when using the Track1 SDK

AzureTestConsole – Console Application. 

I created a C++winrt console App and placed test code to access my Azure storage when the application is run. The Azure CPP REST API Track1 SDK works fine here.

The solution contains one simple projects and code to test the Azure CPP REST API from here:
https://github.com/Azure/azure-sdk-for-cpp/tree/master/sdk/storage
Track2 SDK 

AzureTestApp2 – UWP Application.

I created a C++winrt blank UWP App and placed test code to access my Azure storage when the user clicks the button on the blank application main page. The Azure CPP REST API Track2 SDK works fine here.

