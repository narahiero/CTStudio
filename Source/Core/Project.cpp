//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/Project.hpp"

Project::Project() : Project("Untitled")
{

}

Project::Project(const std::string& name) :
    m_name(name)
{

}

Project::~Project() = default;

void Project::setName(const std::string& name)
{
    m_name = name;
}

std::string Project::getName() const
{
    return m_name;
}

void Project::setPath(const std::filesystem::path& path, int action)
{
    if (action < 0) // 'AUTO'
    {
        if (path.extension() != PROJECT_EXTENSION)
        {
            action = 0; // 'DIR'
        }
        else
        {
            action = 1; // 'FILE'
        }
    }

    if (action == 0) // 'DIR'
    {
        m_path = path / (m_name + PROJECT_EXTENSION);
    }
    else // 'FILE'
    {
        m_path = path;
    }
}

std::filesystem::path Project::getPath() const
{
    return m_path;
}
