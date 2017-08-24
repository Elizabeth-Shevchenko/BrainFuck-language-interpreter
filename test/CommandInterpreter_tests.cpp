#include "gtest/gtest.h"
#include "../include/CommandInterpreter.h"

TEST (CommandInterpreter, RequireThat_As_CommandType_ReturnsCorrectCommand_WhenCommandCanBeInterpreted)
{
    auto cmdAsChar = '+'; // (increase by one) the byte at the data pointer (Command::CommandType::IncrDataPtrValue)

    ASSERT_EQ(Command::CommandInterpreter::As_CommandType(cmdAsChar), Command::CommandType::IncrDataPtrValue);
}