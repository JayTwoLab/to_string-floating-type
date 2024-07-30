cmake_minimum_required(VERSION 3.5)

project(testPrecision LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testPrecision
    main.cpp
    to_string.h)

include(GNUInstallDirs)
install(TARGETS testPrecision
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
