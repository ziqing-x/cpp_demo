cmake_minimum_required(VERSION 3.10)
project("demo" LANGUAGES C CXX)

set(TOP ${CMAKE_CURRENT_SOURCE_DIR})
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "请别在源码目录编译, 污染工程")
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++17" COMPILER_SUPPORTS_CXX17)
check_cxx_compiler_flag("-std=c++14" COMPILER_SUPPORTS_CXX14)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX17)
  message("---- support cpp 17 ----")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX14)
  message("---- support cpp 14 ----")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
  message("---- support cpp 11 ----")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  message(
    FATAL_ERROR
      "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler."
  )
endif()

include(${TOP}/cmake/modules/Colors.cmake)
define_colors()
include(${TOP}/cmake/Option.cmake)
include(${TOP}/cmake/modules/GitHash.cmake)
include(${TOP}/cmake/modules/StaticCheck.cmake)
include(${TOP}/cmake/ConfigProject.cmake)
include(${TOP}/cmake/Output.cmake)
include(${TOP}/cmake/Debug.cmake)
include(${TOP}/cmake/Pack.cmake)

add_subdirectory(src)