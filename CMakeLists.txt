cmake_minimum_required(VERSION 3.1)
project(onset-http VERSION 1.0)


list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

if(UNIX)
	# hide non-exported symbols
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(HORIZONSDK_ROOT_DIR "${PROJECT_SOURCE_DIR}/libs/sdk")
find_package(HorizonPluginSDK REQUIRED)

# curl library
set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})
link_libraries(${CURL_LIBRARIES})
# curl library end

add_subdirectory(src)
