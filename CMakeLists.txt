cmake_minimum_required(VERSION 3.20)

project(
    TradeCore
    VERSION 1.0.0
    DESCRIPTION "High-Performance Order Matching Engine"
    LANGUAGES CXX
)

# --------------------------------------------------------------------
# Global Configuration
# --------------------------------------------------------------------

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# --------------------------------------------------------------------
# Executable
# --------------------------------------------------------------------

add_executable(TradeCore
    src/main.cpp
    src/model/Order.cpp
    src/model/PriceLevel.cpp
)

target_include_directories(
    TradeCore
    PRIVATE
        include
)

# --------------------------------------------------------------------
# Target Configuration
# --------------------------------------------------------------------

target_compile_features(
    TradeCore
    PRIVATE
        cxx_std_20
)

target_compile_options(
    TradeCore
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)