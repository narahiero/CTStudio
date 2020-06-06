########################################
# Fetch GoogleTest
########################################

include(FetchContent)
FetchContent_Declare(gtest_fetch
    GIT_REPOSITORY  "https://github.com/google/googletest.git"
    GIT_TAG         "release-1.10.0"
)

FetchContent_GetProperties(gtest_fetch)

if(NOT gtest_fetch_POPULATED)
    FetchContent_Populate(gtest_fetch)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory("${gtest_fetch_SOURCE_DIR}" "${gtest_fetch_BINARY_DIR}")
endif()


########################################
# Function to add tests
########################################

function(ct_studio_add_test EXECNAME SOURCES)
    # Create target
    add_executable(${EXECNAME} "${SOURCES}")

    # Add include directories
    target_include_directories(${EXECNAME} PRIVATE
        "${PROJECT_SOURCE_DIR}/Source"
        "${PROJECT_BINARY_DIR}/Source"
        "${CMAKE_CURRENT_BINARY_DIR}"
    )

    # Link CT Lib and Google Test
    target_link_libraries(${EXECNAME} gtest_main Core)

    # Let GTest find and add the tests
    gtest_discover_tests(${EXECNAME}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )
endfunction()


########################################
# Add tests
########################################

ct_studio_add_test(CoreProjectTests Core/Project.cpp)
