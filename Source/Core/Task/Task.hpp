//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <string>

class Task final
{

public:

    using VoidFunc = void(*)();

    Task(const std::string& name, VoidFunc func);
    ~Task();

    Task(const Task&) = delete;
    void operator=(const Task&) = delete;

    std::string getName() const;

    void run();

    bool hasFinished() const;

private:

    std::string m_name;
    VoidFunc m_func;
};
