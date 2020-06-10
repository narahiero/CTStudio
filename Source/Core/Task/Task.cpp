//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/Task/Task.hpp"

Task::Task(const std::string& name, VoidFunc func) :
    m_name(name),
    m_func(func)
{

}

Task::~Task() = default;

std::string Task::getName() const
{
    return m_name;
}

void Task::run()
{
    m_func();
}
