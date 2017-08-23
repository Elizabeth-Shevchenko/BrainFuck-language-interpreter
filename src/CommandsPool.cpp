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
        std::for_each(begin(m_commandsToExecute), end(m_commandsToExecute),
                      [](std::shared_ptr<Command> cmd){cmd->Execute();});
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
