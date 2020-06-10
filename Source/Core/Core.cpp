//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/Core.hpp"

#include "Core/ProjectManager.hpp"
#include "Core/Task/TaskManager.hpp"

namespace Core
{

static TaskManager s_taskManager;
static ProjectManager s_projectManager;

void shutdown()
{
    s_taskManager.stopAndWait();
}

TaskManager& getTaskManager()
{
    return s_taskManager;
}

ProjectManager& getProjectManager()
{
    return s_projectManager;
}
}
