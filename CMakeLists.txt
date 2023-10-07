cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  minicoro
  VERSION 0.0.1
  DESCRIPTION "Simple, Extendable, Minimalistic C++20 Coroutine Framework"
  HOMEPAGE_URL "https://github.com/Kelvinyu1117/minicoro"
  LANGUAGES CXX C
)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)

# add_subdirectory(example)
# include(CTest)
# add_subdirectory(test)
