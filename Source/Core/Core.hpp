//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

class ProjectManager;
class TaskManager;

namespace Core
{

// stops all worker threads
void shutdown();

TaskManager& getTaskManager();

ProjectManager& getProjectManager();
}
