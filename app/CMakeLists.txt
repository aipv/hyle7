#*******************************************************************************
# Project Application
#*******************************************************************************

cmake_minimum_required(VERSION 3.13)
project(application
    VERSION 1.0.0
    LANGUAGES C
    DESCRIPTION "Application")

#*******************************************************************************
# Source code
#*******************************************************************************

# Set source codes
set(SRC_APP_CONSOLE ${CMAKE_CURRENT_SOURCE_DIR}/console.c)

#*******************************************************************************
# Path to Head Files
#*******************************************************************************

# Set path to head files
set(PATH_TO_LIB ../lib/)

#*******************************************************************************
# Define libraries
#*******************************************************************************

add_library(console_app OBJECT ${SRC_APP_CONSOLE})

# Include directories
target_include_directories(console_app PUBLIC ${PATH_TO_LIB})
