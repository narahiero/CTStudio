########################################
# CT Lib
########################################

set(CT_LIB_BUILD_DOCS OFF CACHE STRING "Disable CT Lib docs")
set(CT_LIB_BUILD_EXAMPLES OFF CACHE BOOL "Disable CT Lib examples")

# Use atomic buffer states
add_compile_definitions(CT_LIB_USE_ATOMIC_BUFFER_STATES)

add_subdirectory(CTLib)


########################################
# pugixml
########################################

add_subdirectory(pugixml)


########################################
# Constants
########################################

set(CT_STUDIO_DEPS "CTLib;pugixml" CACHE INTERNAL "")
