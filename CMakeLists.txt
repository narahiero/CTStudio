########################################
# General CMake setup
########################################

cmake_minimum_required(VERSION 3.11)

project(CTStudio VERSION 0.0.0)


########################################
# Add subdirectories
########################################

add_subdirectory(Source)

if(ENABLE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(Tests)
endif()
