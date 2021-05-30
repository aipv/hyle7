#*******************************************************************************
# Project Hyle Test
#*******************************************************************************

cmake_minimum_required(VERSION 3.13)
project(hyle_test
    VERSION 1.0.0
    LANGUAGES C
    DESCRIPTION "Hyle Test")

#*******************************************************************************
# Source code
#*******************************************************************************

# Set source codes
set(TEST_BAG ${CMAKE_CURRENT_SOURCE_DIR}/test_bag.c)
set(TEST_BOARD ${CMAKE_CURRENT_SOURCE_DIR}/test_board.c)
set(TEST_GAME ${CMAKE_CURRENT_SOURCE_DIR}/test_game.c)

#*******************************************************************************
# Path to Head Files
#*******************************************************************************

# Set path to head files
set(PATH_TO_LIB ../lib/)

#*******************************************************************************
# Define libraries
#*******************************************************************************

add_library(bag_test OBJECT ${TEST_BAG})
add_library(board_test OBJECT ${TEST_BOARD})
add_library(game_test OBJECT ${TEST_GAME})

# Include directories
target_include_directories(bag_test PUBLIC ${PATH_TO_LIB})
target_include_directories(board_test PUBLIC ${PATH_TO_LIB})
target_include_directories(game_test PUBLIC ${PATH_TO_LIB})

