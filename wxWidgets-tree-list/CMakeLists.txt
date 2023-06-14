# Minimum cmake version for wxWidgets is 3.10
# Minimum cmake version Visual Studio 2022 is 3.21
# Downgraded to 3.20 for Red Hat Enterprise 9.2
cmake_minimum_required(VERSION 3.20)

# Change this for your system's installation of vcpkg
set(CMAKE_TOOLCHAIN_FILE "/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(main VERSION 0.90.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(VCPKG_TARGET_ARCHITECTURE x64)

if (MSVC)
	# warning level 4
	add_compile_options(/W4)
elseif(REDHAT)
	# additional warnings
	add_compile_options(-Wall -Wextra -Wpedantic -pthread)
	add_compile_definitions(
		_FILE_OFFSET_BITS=64
		DWXUSINGDLL
		__WXGTK__
	)
else()
	# additional warnings
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Put include files (*.h) here
if(WIN32)
	include_directories(h windows)
elseif(REDHAT)
	include_directories(
		h
		linux
		/usr/local/lib/wx/include/gtk3-unicode-3.2
		/usr/local/include/wx-3.2
	)
else()
	include_directories(h linux)
endif()

# Add source files to this list
set(SOURCES
	src/clock.cpp
	src/listctrl.cpp
	src/mainapp.cpp
	src/mainframe.cpp
	src/menus.cpp
	src/toolbar.cpp
	src/treectrl.cpp
)

if(WIN32)
	# Fixes error:
	# The link interface of target "wx::wxgl" contains: OpenGL::GLU but the target was not found.
	find_package(OpenGL REQUIRED)
elseif(APPLE)
	find_package(OpenGL REQUIRED)
endif()

if(NOT REDHAT)
	find_package(wxWidgets CONFIG REQUIRED)
endif()

# wx::base;wx::net;wx::core;wx::adv;wx::aui;wx::html;wx::propgrid;
# wx::ribbon;wx::richtext;wx::stc;wx::xrc;wx::gl;wx::qa;wx::xml

if(WIN32)
	add_executable(main WIN32 ${SOURCES} windows/app.rc)
elseif(APPLE)
	set(MACOSX_BUNDLE_ICON_FILE app.icns)
	set(app_ICON ${CMAKE_CURRENT_SOURCE_DIR}/macos/app.icns)
	set_source_files_properties(${app_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

	add_executable(
		main
		MACOSX_BUNDLE 
		${app_ICON}
		${SOURCES}
	)

	set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/macos/Info.plist)
else()
	add_executable(main ${SOURCES})
endif()

if(REDHAT)
	target_link_directories(
		main PRIVATE
		/usr/local/lib
	)

	target_link_libraries(
		main PRIVATE
		wx_gtk3u_xrc-3.2
		wx_gtk3u_html-3.2
		wx_gtk3u_qa-3.2
		wx_gtk3u_core-3.2
		wx_baseu_xml-3.2
		wx_baseu_net-3.2
		wx_baseu-3.2 
	)
else()
	target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})
endif()

message(STATUS "************************************************************")
message(STATUS "Project version:   ${PROJECT_VERSION}")
message(STATUS "wxWidgets version: ${wxWidgets_VERSION}")
message(STATUS "wxWidgets Libs:    ${wxWidgets_LIBRARIES}")
message(STATUS "OpenGL Libs:       ${OPENGL_LIBRARIES}")
message(STATUS "************************************************************")
