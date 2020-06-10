//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <memory>

#include "Core/Project.hpp"

class ProjectManager final
{

public:

    ProjectManager();
    ~ProjectManager();

    ProjectManager(const ProjectManager&) = delete;
    void operator=(const ProjectManager&) = delete;

    bool hasActiveProject() const;
    std::shared_ptr<Project> getActiveProject() const;

private:

    std::shared_ptr<Project> m_project;
};
