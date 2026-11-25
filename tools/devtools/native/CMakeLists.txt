cmake_minimum_required(VERSION 3.23)
project(SkyrimDevTools LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "The plugin requires Windows x64")
endif()

set(COMMONLIB_SOURCE "" CACHE PATH "Pinned CommonLibSSE-NG checkout")
set(HTTPLIB_SOURCE "" CACHE PATH "Pinned cpp-httplib checkout")
set(ENABLE_SKYRIM_SE OFF CACHE BOOL "")
set(ENABLE_SKYRIM_VR OFF CACHE BOOL "")
set(BUILD_TESTS OFF CACHE BOOL "")
set(COMMONLIB_ENABLE_IPO OFF CACHE BOOL "")
set(SKSE_SUPPORT_PATCH_SAFETY OFF CACHE BOOL "")
add_subdirectory("${COMMONLIB_SOURCE}" commonlib)
find_package(nlohmann_json CONFIG REQUIRED)

add_library(SkyrimDevToolsRpc STATIC rpc.cpp)
target_compile_features(SkyrimDevToolsRpc PRIVATE cxx_std_20)
target_include_directories(SkyrimDevToolsRpc PRIVATE "${HTTPLIB_SOURCE}")
target_compile_definitions(SkyrimDevToolsRpc PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN
    _WIN32_WINNT=0x0A00 CPPHTTPLIB_WEBSOCKET_MAX_PAYLOAD_LENGTH=8192)
target_link_libraries(SkyrimDevToolsRpc PUBLIC nlohmann_json::nlohmann_json PRIVATE ws2_32)

add_library(SkyrimDevTools SHARED plugin.cpp)
target_compile_definitions(SkyrimDevTools PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
target_link_libraries(SkyrimDevTools PRIVATE
    CommonLibSSE::CommonLibSSE SkyrimDevToolsRpc user32)
