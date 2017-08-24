#include <algorithm>
#include <iostream>

#include "CommandComplex.h"

namespace Command
{
    CommandComplex::CommandComplex(const CommandType cmdType, std::shared_ptr<DataPointerArray::ArrayCells> cells)
    {
        m_cmdType = cmdType;
        m_cellsToModify = cells;
    }

    void CommandComplex::Execute()
    {
        while (!m_cellsToModify->IsCurrentCellNull())
        {
            try {
                for_each(begin(m_cmds), end(m_cmds), [](std::shared_ptr<Command> cmd){cmd->Execute();});
            }
            catch (DataPointerArray::ArrayCellsException exception)
            {
                std::string details = exception.what();
                throw CommandException("Complex Command: " + details);
            }
        }

    }

    void CommandComplex::AddCommand(std::shared_ptr<Command> cmd)
    {
        m_cmds.push_back(cmd);
    }
}

