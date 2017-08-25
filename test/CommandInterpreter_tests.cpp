#include "gtest/gtest.h"
#include "../include/CommandInterpreter.h"

TEST(CommandInterpreter, RequireThat_As_CommandType_ReturnsValidCommand_WhenCommandCanBeInterpreted)
{
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType('+'), Command::CommandType::IncrDataPtrValue);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType('-'), Command::CommandType::DecrDataPtrValue);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType('>'), Command::CommandType::MoveDataPtrRight);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType('<'), Command::CommandType::MoveDataPtrLeft);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType('.'), Command::CommandType::OutputDataPtrValue);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType(','), Command::CommandType::InputDataPtrValue);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType('['), Command::CommandType::LoopBegin);
	ASSERT_EQ(Command::CommandInterpreter::As_CommandType(']'), Command::CommandType::LoopEnd);
}

TEST (CommandInterpreter, RequireThat_As_CommandType_ReturnsUnknownCommand_WhenCommandCanNotBeInterpreted)
{
	auto cmdAsChar = '='; // unknown command

	ASSERT_EQ(Command::CommandInterpreter::As_CommandType(cmdAsChar), Command::CommandType::Unknown);
}