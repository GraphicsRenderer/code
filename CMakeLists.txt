cmake_minimum_required(VERSION 3.16)
project(SoftwareRenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    thirdparty/spdlog/include/
    thirdparty/assimp/include/
    thirdparty/eigen/
    thirdparty/stb/
    thirdparty/json/
    src/
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
add_subdirectory(thirdparty/assimp)

set(THIRD_PARTY_LIBS assimp)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(SoftwareRenderer.exe main.cpp ${SOURCES})
target_link_libraries(SoftwareRenderer.exe PRIVATE ${THIRD_PARTY_LIBS})

file(GLOB_RECURSE CHAPTER_SOURCES chapters/*.cpp)
foreach(c IN LISTS CHAPTER_SOURCES)
    get_filename_component(PARENT_DIR ${c} DIRECTORY)
    get_filename_component(PARENTNAME ${PARENT_DIR} NAME_WLE)
    get_filename_component(FILENAME ${c} NAME_WLE)
    add_executable(${PARENTNAME}-${FILENAME}.exe ${c} ${SOURCES})
    target_link_libraries(${PARENTNAME}-${FILENAME}.exe PRIVATE ${THIRD_PARTY_LIBS})
endforeach()
