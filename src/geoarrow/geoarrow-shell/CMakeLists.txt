﻿# CMakeList.txt: CMake-Projekt für "geoarrow-shell". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# vcpkg includes
include_directories($ENV{vcpkgRoot}/x64-windows/include)

# Arrow Paket
find_package(Arrow REQUIRED)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (geoarrow-shell "geoarrow-shell.cpp" "geoarrow-shell.h" 
	"record.cpp" "record.h"
	"record_filter.cpp" "record_filter.h")

# Arrow linking
target_link_libraries(geoarrow-shell PRIVATE arrow_shared)

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
if ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
configure_file (../../../data/cities1000_50.txt cities1000_50.txt COPYONLY)
elseif ("${CMAKE_BUILD_TYPE}" MATCHES "RelWithDebInfo")
endif ()
