cmake_minimum_required(VERSION 3.19)
project(client)

option(BUILD_TESTS OFF)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES src/data_processor.cpp src/input_listener.cpp src/shared_buffer.cpp src/sync_ostream.cpp)
set(HEADERS include/data_processor.h include/input_listener.h include/shared_buffer.h include/sync_ostream.h)

set(Boost_INCLUDE_DIR "../vcpkg_installed/x64-linux/include/")
list(APPEND CMAKE_PREFIX_PATH "../vcpkg_installed/x64-linux/share/")
include_directories("../vcpkg_installed/x64-linux/include/")

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})

add_library(client-lib STATIC ${SOURCES} ${HEADERS})

target_include_directories(client-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_precompile_headers(client-lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pch.h)

add_executable(client src/main.cpp)

target_link_libraries(client PRIVATE client-lib ${Boost_LIBRARIES})
