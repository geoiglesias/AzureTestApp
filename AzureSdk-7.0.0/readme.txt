First, download and bootstrap vcpkg itself; it can be installed anywhere,
but generally we recommend using vcpkg as a submodule for CMake projects,
and installing it globally for Visual Studio projects.
Somewhere like `C:\src\vcpkg` or `C:\dev\vcpkg`,
since otherwise you may run into path issues for some port build systems.

We will assume `C:\dev\vcpkg` for this release note
In `C:\dev\vcpkg` open a PowerShell terminal

```cmd
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
```

To install the libraries for the project, run:

```cmd
> .\vcpkg.exe install azure-storage-cpp:x64-windows
```
In the Vcpkg directory C:\dev\vcpkg\installed\x64-windows
the following sub directories are created
bin/  debug/  include/  lib/  share/

copy bin/  include/  lib/ from C:\dev\vcpkg\installed\x64-windows
to the 'blu\3rdParty\AzureSdk-7.0.0' directory