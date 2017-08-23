#ifndef COMMANDSPOOL_H
#define COMMANDSPOOL_H

#include <memory>
#include <vector>

#include "Command.h"

namespace Command
{
    class CommandsPool
    {
    private:
        std::vector<std::shared_ptr<Command>> m_commandsToExecute;

    public:
        CommandsPool() = default;

        void AddCommand(std::shared_ptr<Command>) noexcept;
        int GetCount() const noexcept;
        void Execute();
        void Reset();
    };
}

#endif // COMMANDSPOOL_H
