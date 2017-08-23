#include "BrainFInterpreter.h"
#include "CommandInterpreter.h"
#include "CommandsValidator.h"
#include "CommandPlain.h"
#include "CommandComplex.h"

BrainFInterpreter::BrainFInterpreter()
{
    m_cells = std::make_shared<DataPointerArray::ArrayCells>();
    m_commandsPool = std::make_shared<Command::CommandsPool>();
}

void BrainFInterpreter::Reset()
{
    m_cells->Reset();
    m_commandsPool->Reset();
}

void BrainFInterpreter::AddCommand(std::string::iterator& it, std::string::iterator const& end)
{
    while (it != end)
    {
        auto cmdType = Command::CommandInterpreter::As_CommandType(*it);

        switch (cmdType) {
        case Command::CommandType::DecrDataPtrValue:
        case Command::CommandType::IncrDataPtrValue:
        case Command::CommandType::MoveDataPtrLeft:
        case Command::CommandType::MoveDataPtrRight:
        case Command::CommandType::OutputDataPtrValue:
        case Command::CommandType::InputDataPtrValue:
            m_commandsPool->AddCommand(std::make_shared<Command::CommandPlain>(cmdType, m_cells));
            break;
        case Command::CommandType::LoopBegin:
            auto childCmd = std::make_shared<Command::CommandComplex>(cmdType, m_cells);
            AddCommand(childCmd, it);
            m_commandsPool->AddCommand(childCmd);
            break;
        }
        ++it;
    }
}

void BrainFInterpreter::AddCommand(std::shared_ptr<Command::Command> cmd, std::string::iterator& it)
{
    while (*it != ']')
    {
        ++it;
        auto cmdType = Command::CommandInterpreter::As_CommandType(*it);
        switch (cmdType) {
        case Command::CommandType::DecrDataPtrValue:
        case Command::CommandType::IncrDataPtrValue:
        case Command::CommandType::MoveDataPtrLeft:
        case Command::CommandType::MoveDataPtrRight:
        case Command::CommandType::OutputDataPtrValue:
        case Command::CommandType::InputDataPtrValue:
            cmd->AddCommand(std::make_shared<Command::CommandPlain>(cmdType, m_cells));
            break;
        case Command::CommandType::LoopBegin:
            auto childCmd = std::make_shared<Command::CommandComplex>(cmdType, m_cells);
            cmd->AddCommand(childCmd);
            AddCommand(childCmd, it);
            break;
        }
    }
}

void BrainFInterpreter::StartInterpeation(std::string target)
{
    Reset();

    if (!CommandsValidator::IsInputCommandsValid(target))
        throw CommandsValidationException("Invalid command");

    std::string::iterator target_begin = begin(target);
    AddCommand(target_begin, end(target));
}

void BrainFInterpreter::StartExecution()
{
    // if interpretation was failed - nothing to execute because of Reset
    m_commandsPool->Execute();
}
