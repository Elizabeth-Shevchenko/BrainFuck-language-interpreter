#include "gtest/gtest.h"
#include "../include/BrainFInterpreter.h"

TEST (BrainFInterpreter, RequireThat_StartInterpretation_ThrowException_WhenCommandInvalid)
{
    BrainFInterpreter interpreter;
    std::string invalidCommand = "[---]++>----]";

    ASSERT_THROW(interpreter.StartInterpeation(invalidCommand), std::exception);
}

TEST (BrainFInterpreter, RequireThat_StartInterpretation_NotThrowException_WhenCommandValid)
{
    BrainFInterpreter interpreter;
    std::string validCommand = "[---]++>---[-]";

    ASSERT_NO_THROW(interpreter.StartInterpeation(validCommand));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
