//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "Core/Task/Task.hpp"

class TaskManager final
{

public:

    static unsigned int defaultNumWorkers();

    TaskManager(unsigned int numWorkers = defaultNumWorkers());
    ~TaskManager();

    TaskManager(const TaskManager&) = delete;
    void operator=(const TaskManager&) = delete;

    void submitTask(const std::shared_ptr<Task>& task);

    // stops all workers; non-blocking
    void stop();

    // stops all workers and wait for them to finish their current task
    void stopAndWait();

private:

    // code executed by each worker
    void runWorker();

    const unsigned int m_numWorkers;

    std::atomic_bool m_stop;
    bool m_finished;

    std::vector<std::thread> m_workers;
    std::queue<std::shared_ptr<Task>> m_taskQueue;
    std::mutex m_mu;
    std::condition_variable m_cv;
};
