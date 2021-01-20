#include "pch.h"

#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.Foundation.h>

#include <sstream>


#include "azure/storage/files/shares.hpp"

#include "AzureApiTestFunctions2.h"

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::System::Threading;

bool AzureApiTestFunctions2::IsComplete = false;

void AzureApiTestFunctions2::TestAzureRestApi()
{
    using namespace Azure::Storage::Files::Shares;

    ThreadPool::RunAsync([&](IAsyncAction const& workItem)
        {
            UNREFERENCED_PARAMETER(workItem);

            IsComplete = false;

            std::string storage_connection_string_remote =
                "bla bla bla";

            std::string shareName = "sample-share";
            std::string fileName = "sample-file.txt";
            std::string fileContent = "Hello Azure!";

            std::wstringstream errStream;
            errStream << "Begin Azure REST APT test" << std::endl;


            auto shareClient = ShareClient::CreateFromConnectionString(storage_connection_string_remote, shareName);
            try
            {
                shareClient.Create();
            }
            catch (std::runtime_error& e)
            {
                // The share may already exist
                std::cout << e.what() << std::endl;
            }

            ShareFileClient fileClient = shareClient.GetShareFileClient(fileName);
            //FileClient fileClient = shareClient.GetFileClient(fileName);

            fileClient.UploadFrom(reinterpret_cast<const uint8_t*>(fileContent.data()), fileContent.size());

            Azure::Storage::Metadata fileMetadata = { {"key1", "value1"}, {"key2", "value2"} };
            fileClient.SetMetadata(fileMetadata);

            auto properties = *fileClient.GetProperties();
            //for (auto metadata : properties.Metadata)
            //{
            //    std::cout << metadata.first << ":" << metadata.second << std::endl;
            //}
            fileContent.resize(static_cast<std::size_t>(properties.ContentLength));

            fileClient.DownloadTo(reinterpret_cast<uint8_t*>(&fileContent[0]), fileContent.size());

            errStream << fileContent.c_str() << std::endl;

            errStream << "Azure REST APT II test complete" << std::endl;

            OutputDebugString(errStream.str().c_str());
            IsComplete = true;
        });
}
