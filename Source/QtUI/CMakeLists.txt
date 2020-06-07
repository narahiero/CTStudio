########################################
# Find and setup Qt 5
########################################

if(NOT Qt5_DIR)
    message(FATAL_ERROR
        "You must set Qt5_DIR to your local installation of Qt 5!"
    )
endif()

find_package(Qt5 REQUIRED COMPONENTS Gui Widgets)

if(NOT ${Qt5Core_VERSION} MATCHES "5.14.1" AND NOT CT_STUDIO_NO_WARNINGS)
    message(WARNING
        "Your version of Qt (${Qt5Core_VERSION}) does not match the recommended version (5.14.1)."
        "\nIf you wish to disable those warnings, set CT_STUDIO_NO_WARNINGS."
    )
endif()

set(CMAKE_AUTOMOC ON)


########################################
# Setup target
########################################

add_executable(CTStudio
    main.cpp
    AboutDialog.cpp
    AboutDialog.hpp
    Editor/EditorBar.cpp
    Editor/EditorBar.hpp
    Editor/EditorBase.cpp
    Editor/EditorBase.hpp
    Editor/EditorContainer.cpp
    Editor/EditorContainer.hpp
    Editor/ProjectOutliner.cpp
    Editor/ProjectOutliner.hpp
    MainWindow.cpp
    MainWindow.hpp
    MenuBar.cpp
    MenuBar.hpp
    StatusBar.cpp
    StatusBar.hpp
)

target_link_libraries(CTStudio Core Qt5::Widgets)


########################################
# Windows-specific setup
########################################

if(WIN32)
    set_target_properties(CTStudio PROPERTIES
        WIN32_EXECUTABLE TRUE
        DEBUG_POSTFIX "D"
    )

    # Deploy Qt on Windows

    # Find Qt binaries directory
    get_target_property(MOC_EXE_LOC Qt5::moc IMPORTED_LOCATION)
    get_filename_component(QT_BIN_DIR "${MOC_EXE_LOC}" DIRECTORY)
    find_program(WINDEPLOYQT_EXE windeployqt HINTS "${QT_BIN_DIR}")

    # Add windeployqt command
    add_custom_command(TARGET CTStudio POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E env PATH="${QT_BIN_DIR}"
            "${WINDEPLOYQT_EXE}"
                $<IF:$<CONFIG:Debug>,--debug,--release>
                "$<TARGET_FILE:CTStudio>"
    )
endif()
