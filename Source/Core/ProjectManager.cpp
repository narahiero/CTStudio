//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/ProjectManager.hpp"

ProjectManager::ProjectManager()
{

}

ProjectManager::~ProjectManager()
{

}

bool ProjectManager::hasActiveProject() const
{
    return m_project != nullptr;
}

std::shared_ptr<Project> ProjectManager::getActiveProject() const
{
    return m_project;
}
