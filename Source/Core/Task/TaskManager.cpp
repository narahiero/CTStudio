//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/Task/TaskManager.hpp"

unsigned int TaskManager::defaultNumWorkers()
{
    static unsigned int s_hc = std::thread::hardware_concurrency();
    static unsigned int s_num = s_hc == 0 ? 1 : s_hc;
    return s_num;
}

TaskManager::TaskManager(unsigned int numWorkers) :
    m_numWorkers(numWorkers),
    m_stop(false)
{
    while (numWorkers--)
    {
        m_workers.push_back(std::thread([this]() { runWorker(); }));
    }
}

TaskManager::~TaskManager()
{
    stopAndWait();
}

void TaskManager::submitTask(const std::shared_ptr<Task>& task)
{
    m_taskQueue.push(task);
    m_cv.notify_one();
}

void TaskManager::stop()
{
    m_stop = true;
}

void TaskManager::stopAndWait()
{
    m_stop = true;
    if (m_finished) return; // do not join twice

    m_cv.notify_all();
    for (auto& worker : m_workers)
    {
        worker.join();
    }
    m_finished = true;
}

void TaskManager::runWorker()
{
    std::shared_ptr<Task> task;
    while (!m_stop)
    {
        bool acquired = false;
        {
            std::unique_lock<std::mutex> lock(m_mu);
            m_cv.wait(lock, [this]() { return m_stop || !m_taskQueue.empty(); });

            if (m_stop)
            {
                break;
            }

            if (!m_taskQueue.empty())
            {
                task = m_taskQueue.front();
                m_taskQueue.pop();
                acquired = true;
            }
        }

        if (acquired)
        {
            task->run();
        }
    }
}
