# Red Hat Enterprise 9.2 x64

June 13, 2023

Building wxWidgets applications for Red Hat is not as simple as Ubuntu. Since there is no compatible wxWidgets VCPKG available, you must download and compile wxWidgets yourself. This document shows how I setup Red Hat Enterprise 9.2, prepared wxWidgets and built everything.

Red Hat is setup as a Workstation with GNOME. Since wxWidgets is a GUI application, GNOME is required.

I used VirtualBox 7.0.8 to run Red Hat Enterprise 9.2. I allocated the following resources to the virtual machine:
 - Memory: 8192 MB
 - CPU: 4 processors
 - Disk: 256 GB
 - Network: Bridge Adapter
 - Installed the VirtualBox Guest Additions.

---
## Download Red Hat Enterprise 9.2

- https://developers.redhat.com/products/rhel/getting-started
 - The [ISO Image](https://developers.redhat.com/content-gateway/file/rhel/9.2/rhel-9.2-x86_64-dvd.iso) that I used. You will need a Red Hat account to download.

---
## Red Hat Enterprise 9.2 Installation
 - Base Environment
   - Workstation
   - GNOME Applications
   - Console Internet Tools
   - Development Tools
   - Graphical Administration Tools
   - RPM Development Tools
   - System Tools
 - Update system
   - sudo dnf check-update
   - sudo dnf upgrade
   - sudo dnf upgrade --security

---
## Red Hat Enterprise 9.2 Application Developer Setup
 - Development Tools
   - sudo dnf group install "Development Tools"
   - sudo dnf install llvm-toolset
   - sudo dnf install kernel-devel elfutils-libelf-devel
 - Install required packages:
   - dnf install perl-IPC-Cmd
   - dnf install perl-FindBin
   - dnf install perl-Pod-Html
   - dnf install gtk3-devel
 - VirtualBox Guest Additions CD Image
   - Follow GUI
   - logout or reboot system
 - VIM (install not required)
   - sudo dnf install vim
 - GIT (install not required)
   - sudo dnf install git
 - GIT setup
   - git config --global user.name "Full Name"
   - git config --global user.email "email@example.com"
   - git config --global core.editor vim
 - CMAKE
   - sudo dnf install cmake3
 - VCPKG
   - cd /
   - git clone https://github.com/Microsoft/vcpkg.git
   - cd vcpkg
   - ./bootstrap-vcpkg.sh

---
## Preparation
 - create a directory to hold everthing. For this example, ${HOME}/work
   - mkdir ${HOME}/work
   - cd ${HOME}/work

---
## wxWidgets
 - cd ${HOME}/work
 - wget https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.2.1/wxWidgets-3.2.2.1.tar.bz2
 - bzip2 -d wxWidgets-3.2.2.1.tar.bz2
 - tar xf ./wxWidgets-3.2.2.1.tar
 - cd wxWidgets-3.2.2.1
 - mkdir gtk-build
 - cd gtk-build
 - ../configure --with-gtk=3
 - make -j3
 - sudo make install

---
## Application Setup
 - cd ${HOME}/work
 - git clone https://github.com/jhanley-com/jhanley-wxwidgets.git
 - cd jhanley-wxwdigets
 - cd wxWidgets-tree-list
 - Edit CMakeLists.txt:
   - Modify `CMAKE_TOOLCHAIN_FILE` to match your vcpkg installation.
 - `chmod +x tools/redhat/*.sh`

---
## Build
 - DEBUG version:
   - Configure cmake:
     - `tools/redhat/configure_cmake_debug.sh`
   - Build program
     - `tools/redhat/build_debug.sh`
   - Run program (debug version):
     - `tools/redhat/run_debug.sh`
 - RELEASE version:
   - Configure cmake:
     - `tools/redhat/configure_cmake_release.sh`
   - Build program
     - `tools/redhat/build_release.sh`
   - Run program
     - `tools/redhat/run_release.sh`

---
## Limitations
 - None

---
## Known Issues
 - None

---
## Known Bugs
 - None
