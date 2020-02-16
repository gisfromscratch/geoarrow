# CMakeList.txt: CMake-Projekt für "geoarrow-shell". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# vcpkg includes
include_directories($ENV{vcpkgRoot}/x64-windows/include)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (geoarrow-shell "geoarrow-shell.cpp" "geoarrow-shell.h")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
if ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
configure_file (../../../data/cities1000_50.txt cities1000_50.txt COPYONLY)
elseif ("${CMAKE_BUILD_TYPE}" MATCHES "RelWithDebInfo")
endif ()
