# Minimum cmake version for wxWidgets is 3.10
# Minimum cmake version Visual Studio 2022 is 3.21
cmake_minimum_required(VERSION 3.21)

# Change this for your system's installation of vcpkg
set(CMAKE_TOOLCHAIN_FILE "/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(main VERSION 0.90.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(VCPKG_TARGET_ARCHITECTURE x64)

# Put include files (*.h) here
if(WIN32)
include_directories(h windows)
else()
include_directories(h linux)
endif()

# Add source files to this list
set(SOURCES
	src/mainapp.cpp
	src/mainframe.cpp
)

if(WIN32)
	# Fixes error:
	# The link interface of target "wx::wxgl" contains: OpenGL::GLU but the target was not found.
	find_package(OpenGL REQUIRED)
elseif(APPLE)
	find_package(OpenGL REQUIRED)
endif()

find_package(wxWidgets CONFIG REQUIRED)

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

target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})

message(STATUS "************************************************************")
message(STATUS "Project version:   ${PROJECT_VERSION}")
message(STATUS "wxWidgets version: ${wxWidgets_VERSION}")
message(STATUS "wxWidgets Libs:    ${wxWidgets_LIBRARIES}")
message(STATUS "OpenGL Libs:       ${OPENGL_LIBRARIES}")
message(STATUS "************************************************************")
