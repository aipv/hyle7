#*******************************************************************************
# Project Hyle Lib
#*******************************************************************************

cmake_minimum_required(VERSION 3.13)
project(hyle_lib
    VERSION 1.0.0
    LANGUAGES C
    DESCRIPTION "Hyle Lib")

#*******************************************************************************
# Source code
#*******************************************************************************

# Set source codes
set(LIB_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/hyle_profile.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hyle_bag.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hyle_board.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hyle_game.c)

#*******************************************************************************
# Path to Head Files
#*******************************************************************************

#*******************************************************************************
# Define libraries
#*******************************************************************************

# Library
add_library(lib_hyle OBJECT ${LIB_SRC})

# Include directories
target_include_directories(lib_hyle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
