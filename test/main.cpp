#include "gtest/gtest.h"
#include "../include/BrainFInterpreter.h"

TEST (BrainFInterpreter, RequireThat_StartInterpretation_NotThrowException_WhenCommandInvalid)
{
    BrainFInterpreter interpreter;
    std::string failedTestStr = "[---]++>]----";

    ASSERT_NO_THROW(interpreter.StartInterpeation(failedTestStr));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
