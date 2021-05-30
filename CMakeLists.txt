#*******************************************************************************
# Project Hyle
#*******************************************************************************

cmake_minimum_required(VERSION 3.13)
project(hyle
    VERSION 1.0.0
    LANGUAGES C
    DESCRIPTION "Hyle")

#*******************************************************************************
# Submodules
#*******************************************************************************

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)

#*******************************************************************************
# Define libraries
#*******************************************************************************

add_library(hyle_s $<TARGET_PROPERTY:lib_hyle,SOURCES>)
add_library(hyle_d SHARED $<TARGET_PROPERTY:lib_hyle,SOURCES>)

# Include directories
target_include_directories(hyle_s
    PRIVATE $<TARGET_PROPERTY:lib_hyle,INCLUDE_DIRECTORIES>)

target_include_directories(hyle_d
    PRIVATE $<TARGET_PROPERTY:lib_hyle,INCLUDE_DIRECTORIES>)

#*******************************************************************************
# Define executables
#*******************************************************************************

add_executable(test_bag
    $<TARGET_PROPERTY:hyle_s,SOURCES>
    $<TARGET_PROPERTY:bag_test,SOURCES>)

add_executable(test_board
    $<TARGET_PROPERTY:hyle_s,SOURCES>
    $<TARGET_PROPERTY:board_test,SOURCES>)

add_executable(test_game
    $<TARGET_PROPERTY:hyle_s,SOURCES>
    $<TARGET_PROPERTY:game_test,SOURCES>)

add_executable(app_console
    $<TARGET_PROPERTY:hyle_s,SOURCES>
    $<TARGET_PROPERTY:console_app,SOURCES>)

# Include directories

target_include_directories(test_bag
    PRIVATE $<TARGET_PROPERTY:bag_test,INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:hyle_s,INCLUDE_DIRECTORIES>)

target_include_directories(test_board
    PRIVATE $<TARGET_PROPERTY:board_test,INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:hyle_s,INCLUDE_DIRECTORIES>)

target_include_directories(test_game
    PRIVATE $<TARGET_PROPERTY:game_test,INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:hyle_s,INCLUDE_DIRECTORIES>)

target_include_directories(app_console
    PRIVATE $<TARGET_PROPERTY:console_app,INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:hyle_s,INCLUDE_DIRECTORIES>)