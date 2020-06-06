//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include <gtest/gtest.h>

#include "Core/Project.hpp"

TEST(CoreProjectTests, Path)
{
    Project project("Test");
    EXPECT_EQ("", project.getPath());

    // 'AUTO' tests
    project.setPath("./some/path"); // action is -1 default
    EXPECT_EQ("./some/path/Test.ctsproj", project.getPath());

    project.setPath("./some/path/Project.ctsproj", -5);
    EXPECT_EQ("./some/path/Project.ctsproj", project.getPath());

    project.setPath("./some/path/Name.ctsp");
    EXPECT_EQ("./some/path/Name.ctsp/Test.ctsproj", project.getPath());

    // 'DIR' tests
    project.setPath("./some/path", 0);
    EXPECT_EQ("./some/path/Test.ctsproj", project.getPath());

    project.setPath("./some/path/Project.ctsproj", 0);
    EXPECT_EQ("./some/path/Project.ctsproj/Test.ctsproj", project.getPath());

    project.setPath("./some/path/Name.ctsp", 0);
    EXPECT_EQ("./some/path/Name.ctsp/Test.ctsproj", project.getPath());

    // 'FILE' tests
    project.setPath("./some/path", 1);
    EXPECT_EQ("./some/path", project.getPath());

    project.setPath("./some/path/Project.ctsproj", 32);
    EXPECT_EQ("./some/path/Project.ctsproj", project.getPath());

    project.setPath("./some/path/Name.ctsp", 8432);
    EXPECT_EQ("./some/path/Name.ctsp", project.getPath());
}
