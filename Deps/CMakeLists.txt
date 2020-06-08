########################################
# Add CTLib
########################################

set(CT_LIB_BUILD_DOCS OFF CACHE STRING "Disable CT Lib docs")
set(CT_LIB_BUILD_EXAMPLES OFF CACHE BOOL "Disable CT Lib examples")

add_subdirectory(CTLib)


########################################
# Constants
########################################

set(CT_STUDIO_DEPS CTLib CACHE INTERNAL "")
