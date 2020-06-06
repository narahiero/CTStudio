//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <string>

class Project
{

public:

    static constexpr char* PROJECT_EXTENSION_NAME = "ctsproj";
    static constexpr char* PROJECT_EXTENSION = ".ctsproj";

    // name will be set to "Untitled"
    Project();
    Project(const std::string& name);

    ~Project();

    void setName(const std::string& name);
    std::string getName() const;

    // the path can be non-existant, including parent directories
    //
    // behaviour depending on 'action' value ('PROJ_NAME' is the name of this project)
    // < 0: 'AUTO': 'FILE' if file extension is '.ctsproj', 'DIR' otherwise
    // = 0:  'DIR': the path is a directory, and "PROJ_NAME.ctsproj" is appended to the path
    // > 0: 'FILE': the path to the project location, even if the extension is wrong
    void setPath(const std::filesystem::path& path, int action = -1);
    std::filesystem::path getPath() const;

private:

    std::string m_name;

    std::filesystem::path m_path;
};
