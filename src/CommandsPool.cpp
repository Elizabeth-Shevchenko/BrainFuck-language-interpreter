#include <algorithm>

#include "CommandsPool.h"

namespace Command
{
    void CommandsPool::AddCommand(std::shared_ptr<Command> command) noexcept
    {
        m_commandsToExecute.push_back(command);
    }

    void CommandsPool::Execute()
    {
        try {
            std::for_each(begin(m_commandsToExecute), end(m_commandsToExecute),
                                [](std::shared_ptr<Command> cmd){cmd->Execute();});
        }
        catch (const CommandException &exception)
        {
            // log CommandExecution exception
            std::string details = exception.what();
            throw CommandsPoolException("CommandsPoolException: " + details); 
        }

    }

    int CommandsPool::GetCount() const noexcept
    {
        return m_commandsToExecute.size();
    }

    void CommandsPool::Reset()
    {
        m_commandsToExecute.clear();
    }
}
