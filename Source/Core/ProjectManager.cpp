//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/ProjectManager.hpp"

#include "Core/Callbacks.hpp"

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

void ProjectManager::createProject(const std::string& name)
{
    m_project = std::make_shared<Project>(name);
    Callbacks::projectStateChanged();
}

void ProjectManager::renameProject(const std::string& name)
{
    m_project->setName(name);
    Callbacks::projectStateChanged();
}
