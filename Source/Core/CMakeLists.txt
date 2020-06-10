########################################
# Setup target
########################################

add_library(Core STATIC
    Callbacks.cpp
    Callbacks.hpp
    Core.cpp
    Core.hpp
    Data/DataManager.cpp
    Data/DataManager.hpp
    Data/ProjectData.cpp
    Data/ProjectData.hpp
    Project.cpp
    Project.hpp
    ProjectManager.cpp
    ProjectManager.hpp
    Task/Task.cpp
    Task/Task.hpp
    Task/TaskManager.cpp
    Task/TaskManager.hpp
)

# Set C++ settings
target_compile_features(Core PUBLIC cxx_std_17)
set_target_properties(Core PROPERTIES CXX_EXTENSIONS OFF)

target_link_libraries(Core ${CT_STUDIO_DEPS})
