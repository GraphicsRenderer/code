cmake_minimum_required(VERSION 3.16)
project(SoftwareRenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ThirdParty/spdlog/include/
    ThirdParty/assimp/include/
    ThirdParty/eigen/
    ThirdParty/stb/
    ThirdParty/json/
    Source/
)

set(ASSIMP_BUILD_ZLIB ON)
set(ZLIB_LIBRARIES zlibstatic)
set(ENABLE_BOOST_WORKAROUND ON)
set(BUILD_STATIC_LIB ON)
set(ASSIMP_BUILD_STATIC_LIB ON)
set(BUILD_SHARED_LIBS OFF)
set(ASSIMP_BUILD_SHARED_LIBS OFF)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(ThirdParty/assimp)

file(GLOB_RECURSE SOURCES Source/*.cpp)
add_executable(SoftwareRenderer main.cpp ${SOURCES})
target_link_libraries(SoftwareRenderer PRIVATE assimp)
