project(Easypp)

include_directories(src ${CMAKE_HOME_DIRECTORY}/include)

aux_source_directory(src SRC)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("Current platform: Linux!")
    set(SOURCE_FILES src/Commander.cpp src/Commander.h src/LinuxCommander.h src/LinuxCommander.cpp)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("Current platform: Windows")
    set(SOURCE_FILES src/Commander.cpp src/Commander.h src/WinCommander.h src/WinCommander.cpp)
else ()
    message(FATAL_ERROR "Other platform: ${CMAKE_SYSTEM_NAME} which is not supported, CMake will exit!")
endif (CMAKE_SYSTEM_NAME MATCHES "Linux")

add_library(EasyCMD SHARED ${SOURCE_FILES})