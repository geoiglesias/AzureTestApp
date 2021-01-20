
This project demonstrates a simple inegration with https://github.com/Azure/azure-sdk-for-cpp/tree/master/sdk/storage

This project assums that the Track 2 SDK was built with the instructions located here 
https://github.com/Azure/azure-sdk-for-cpp/tree/master/sdk/storage

for bothe x64-windows-static and arm-windows vcpkg architectures

 -> vcpkg.exe install libxml2:x64-windows-static curl:x64-windows-static nlohmann-json:x64-windows-static
 -> vcpkg.exe install libxml2:arm-windows curl:arm-windows nlohmann-json:arm-windows

I built the Track 2 SDK from Source
First, download the repository to your local folder:
git clone https://github.com/Azure/azure-sdk-for-cpp.git
Open the folder in VS2019 and built as a cmake project.
For the Arm builds  I created a new enttry in the Cmakesettigs .json to add an arm-Dubug target using the x86-Debug entry as a template and replacing x86-windows with arem-windows for he vcpkg target.

After all the above is built ensure the link paths are correct and the correct dlls are references in the project.
