cmake_minimum_required(VERSION 3.20)

project(
    TradeCore
    VERSION 1.0.0
    DESCRIPTION "High-Performance Order Matching Engine"
    LANGUAGES CXX
)

# --------------------------------------------------------------------
# C++ Standard
# --------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# --------------------------------------------------------------------
# Executable
# --------------------------------------------------------------------

add_executable(
    TradeCore
    src/main.cpp
)

# --------------------------------------------------------------------
# Compiler Warnings
# --------------------------------------------------------------------

target_compile_options(
    TradeCore
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)