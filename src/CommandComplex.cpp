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
            for_each(begin(m_cmds), end(m_cmds), [](std::shared_ptr<Command> cmd){cmd->Execute();});
//            for (auto i = 0; i < m_cmds.size(); ++i)
//            {
//                m_cmds[i]->Execute();
//            }
        }

    }

    void CommandComplex::AddCommand(std::shared_ptr<Command> cmd)
    {
        m_cmds.push_back(cmd);
    }
}

