#include "pch.h"

#include <was/storage_account.h>
#include <was/blob.h>
#include <was/file.h>
#include <cpprest/filestream.h>  
#include <cpprest/containerstream.h> 

#include <ppltasks.h>
#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.Foundation.h>

#include <sstream>

#include "AzureApiTestFunctions.h"

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::System::Threading;


bool AzureApiTestFunctions::IsComplete = false;

void AzureApiTestFunctions::TestAzureRestApi()
{
    ThreadPool::RunAsync([&](IAsyncAction const& workItem)
        {
            UNREFERENCED_PARAMETER(workItem);

            IsComplete = false;

            // We're now on a background thread.
            std::wstring storage_connection_string_remote =
                L"DefaultEndpointsProtocol=https;AccountName=innovoycetest;AccountKey=R3qEO2Zp5Z4dIiCCwufpZC1wM6UF1O7uSSLdQweWVo19Mw/Qq8YMyaeWvsRKXpUQOVaIdLEEb00ycDobAMGeEA==;EndpointSuffix=core.windows.net";

            std::wstringstream errStream;
            errStream << "Begin Azure REST APT test" << std::endl;

            try
            {
                errStream << L"Connecting to Cloud ..." << std::endl;

                // Retrieve storage account from connection string.
                azure::storage::cloud_storage_account storage_account = azure::storage::cloud_storage_account::parse(storage_connection_string_remote);

                errStream << L"Creating file client ..." << std::endl;
                // Create the blob client.
                azure::storage::cloud_file_client file_client = storage_account.create_cloud_file_client();

                errStream << L"Getting share reference ..." << std::endl;
                // Retrieve a reference to a container.
                azure::storage::cloud_file_share file_share = file_client.get_share_reference(L"azureapptest");

                errStream << L"Calling create_if_not_exists() ..." << std::endl;
                // Create the container if it doesn't already exist.
                file_share.create_if_not_exists();
            }
            catch (azure::storage::storage_exception& e) {
                errStream << "Error: " << e.what() << std::endl;
            }
            catch (std::exception& e) {
                errStream << "Error: " << e.what() << std::endl;
            }
            catch (...) {
                errStream << "some other exception" << std::endl;
            }

            errStream << "Azure REST APT test complete" << std::endl;

            OutputDebugString(errStream.str().c_str());
            IsComplete = true;
        });
}

