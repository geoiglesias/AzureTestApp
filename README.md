# AzureTestApp
Test for https://github.com/Azure/azure-storage-cpp/issues/367

I created this self-contained solution to test https://github.com/Azure/azure-storage-cpp/issues/367 I am using On VS2019 v142 with the Universal Windows Platform (UWP) workload installed. The NuGet C++/WinRT standard C++ language projection v2.0.201113.7 is installed. 
The solution contains two simple projects and shared code to test the Azure CPP REST API Track1 SDK
The solution also contains one simple projects not using shared code to test the Azure CPP REST API Track2 SDK

AS of Jan-20-2021
Track2 SDK located here: https://github.com/Azure/azure-sdk-for-cpp/tree/master/sdk/storage (I used revision 12 beta)
Depricated Track1 SDK located here: https://github.com/Azure/azure-storage-cpp


SharedAzureFiles – The shared code called from both AzureTestApp and AzureTestConsole projects to ensure the actual code is the same for both Azure REST Track 1 applications. The actual API calls are called from with in a background thread using winrt::Windows::System::Threading::ThreadPool::RunAsync See static void AzureApiTestFunctions::TestAzureRestApi() in AzureApiTestFunctions.cpp

AzureTestApp – UWP Application using Azure Track 1 API.
I created a C++winrt blank UWP App and placed test code to access my Azure storage when the user clicks the button on the blank application main page. The code fails with an abort from an attempt to destroy a mutex when using the Track1 SDK

AzureTestConsole – Console Application using Azure Track 1 API.
I created a C++winrt console App and placed test code to access my Azure storage when the application is run. The Azure CPP REST API Track1 SDK works fine here.

AzureTestApp2 – UWP Application using Azure Track 2 API.
I created a C++winrt blank UWP App and placed test code to access my Azure storage when the user clicks the button on the blank application main page. The App and libraries were cross-compiled for x64 Windows targes (Windows 10 Pro 1903 laptop) and ARM Windows targets (RPi 3B) in VS2019. The Azure CPP REST API Track2 SDK works fine here. I could not uses the SharedAzureFiles as the API has some significant changes. Like the Shared project functions, Azure REAT API calls are called from with in a background thread using winrt::Windows::System::Threading::ThreadPool::RunAsync See void AzureApiTestFunctions2::TestAzureRestApi() in AzureApiTestFunctions2.cpp. 

Building Azure Rest Api and dependancies.
The Track2 SDK ws built using Vcpkg x64-windows-static and arm-windows Vcpkg architecture triplets.
 .\vcpkg.exe install libxml2:arm-windows curl:arm-windows nlohmann-json:arm-windows
 
The depricated Track1 SDK ws built using Vcpkg x64-windows-static Vcpkg architecture triplets.
 .\vcpkg.exe install cpprestsdk:x64-windows-static wastorage:x64-windows-static 
