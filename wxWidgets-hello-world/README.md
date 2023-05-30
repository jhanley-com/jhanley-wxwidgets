# Base wxWidgets project configured for vcpkg and cmake

## Release Date
May 29, 2023

---
## Program License

MIT Licensed. Refer to [copyright.txt](copyright.txt) and [LICENSE](LICENSE) for details.

---
## Repository Description

This is a base wxWidgets project setup for vcpkg and cmake. Windows, macOS and Ubuntu are supported.

This package is as a getting started [wxWidgets](https://www.wxwidgets.org/) C++ GUI project configured for for vcpkg and cmake to simplify future projects.

Example installers are provided for Windows and Debian systems.

 - Libraries are managed by [vcpkg](https://vcpkg.io/en/getting-started.html).
 - Build configuration is managed by [cmake](https://cmake.org/).
 - Windows
   - [Visual Studio 2019 Community](https://visualstudio.microsoft.com/vs/older-downloads/).
   - [Visual Studio 2022 Community](https://visualstudio.microsoft.com/vs/).
 - Ubuntu
   - gcc version 11.3.0
 - macOS
   - clang version 14.0.0
 - Installer
   - Windows
     - [Inno Setup Compiler 6.2.2](https://jrsoftware.org/isinfo.php).
   - Ubuntu
     - [dpkg](https://man7.org/linux/man-pages/man1/dpkg.1.html).

---
## See Also

This repository provides a multiplatorm cmake system. They do some things differently.

[wx_cmake_template](https://github.com/lszl84/wx_cmake_template)

This repository supports multiplatform builds using Visual Studio Code.

[wxwidgets-vscode](https://github.com/huckor/wxwidgets-vscode/tree/master)

---
## Tested Environments
 - Windows 10 x64 version 10.0.19045.2965
   - Visual Studio 2019 x64 build 16.11.26, compiler version 19.29.30148
   - Visual Studio 2022 x64 build 17.6.2, compiler version 19.35.32217
   - Visual Studio Build Tools 2022 x64 build 17.5.5, compiler version 19.35.32217
   - Visual Studio Code 1.74.3 and 1.78.2
   - wxWidgets version 3.2.2
   - cmake version 3.26.3
   - vcpkg version 2023-04-07
 - Ubuntu 22.04 x64
   - gcc version 11.3.0
   - wxWidgets version 3.2.2
   - cmake version 3.22.1
   - vcpkg version 2023-04-07
 - macOS Monterey 12.6.1 (Intel)
   - clang version 14.0.0
   - cmake version 3.26.4
   - vcpkg version 2023-04-07

---
## Setup Windows

 - Edit CMakeLists.txt:
   - Modify `CMAKE_TOOLCHAIN_FILE` to match your vcpkg installation.
 - VCPKG:
   - `vcpkg install --triplet x64-windows wxwidgets`

---
## Setup Ubuntu 22.04
 - Edit CMakeLists.txt:
   - Modify `CMAKE_TOOLCHAIN_FILE` to match your vcpkg installation.

 - Install required packages:
   - `sudo apt install build-essential`
   - `sudo apt install cmake`
   - `sudo apt install gettext`
   - `sudo apt install bison`
   - `sudo apt install pkg-config`
   - `sudo apt install python3-pip`
   - `sudo apt install libdbus-1-dev libxi-dev libxtst-dev`
   - `sudo apt install libx11-dev libxft-dev libxext-dev`
   - `sudo apt install linux-libc-dev`
   - `sudo apt install libxrandr-dev`
 - Install optional packages:
   - `sudo apt install libwayland-dev libxkbcommon-dev libegl1-mesa-dev`
   - `sudo apt install libibus-1.0-dev`

 - VCPKG:
   - `./vcpkg install opengl:x64-linux`
   - `./vcpkg install wxwidgets:x64-linux`

---
## Setup macOS Monterey
 - Edit CMakeLists.txt:
   - Modify `CMAKE_TOOLCHAIN_FILE` to match your vcpkg installation.
 - Install required packages:
   - `brew install pkg-config`

 - VCPKG:
   - `./vcpkg install opengl:x64-osx`
   - `./vcpkg install wxwidgets:x64-osx`

---
## Build Windows
 - Configure cmake:
   - `tools-windows\configure_cmake.bat`
 - DEBUG version:
   - Build program
     - `tools-windows\build_debug.bat`
   - Run program
     - `tools-windows\run_debug.bat`
 - RELEASE version:
   - Run program
     - `tools-windows\run_release.bat`
   - Build program
     - `tools-windows\build_release.bat`

---
## Build Ubunutu
 - `chmod +x tools-debian/*.sh`
 - DEBUG version:
   - Configure cmake:
     - `tools-debian/configure_cmake_debug.sh`
   - Build program
     - `tools-debian/build_debug.sh`
   - Run program (debug version):
     - `tools-debian/run_debug.sh`
 - RELEASE version:
   - Configure cmake:
     - `tools-debian/configure_cmake_release.sh`
   - Build program
     - `tools-debian/build_release.sh`
   - Run program
     - `tools-debian/run_release.sh`

---
## Build macOS
 - `chmod +x tools-macos/*.sh`
 - DEBUG version:
   - Configure cmake:
     - `tools-macos/configure_cmake_debug.sh`
   - Build program
     - `tools-macos/build_debug.sh`
   - Run program (debug version):
     - `tools-macos/run_debug.sh`
 - RELEASE version:
   - Configure cmake:
     - `tools-macos/configure_cmake_release.sh`
   - Build program
     - `tools-macos/build_release.sh`
   - Run program
     - `tools-macos/run_release.sh`

---
## Limitations
 - macOS
   - I have not created an example installer as I did for Windows and Debian systems.

---
## Known Issues
 - Windows
   - None
 - Ubuntu 22.04
   - This message is printed when a program is started. Does not affect anything so far.
     - Gtk-Message: 20:40:02.583: Failed to load module "canberra-gtk-module"
 - macOS
   - None

---
## Known Bugs
 - None
