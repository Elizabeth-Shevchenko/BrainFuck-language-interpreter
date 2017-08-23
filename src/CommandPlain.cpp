#include <iostream>

#include "CommandPlain.h"

namespace Command
{
    CommandPlain::CommandPlain(CommandType cmdType, std::shared_ptr<DataPointerArray::ArrayCells> cellsToModify)
    {
        m_cmdType = cmdType;
        m_cellsToModify = cellsToModify;
    }

    void CommandPlain::Execute()
    {
        switch (m_cmdType) {
        case CommandType::DecrDataPtrValue:
            return m_cellsToModify->DecrDataPtrValue();
        case CommandType::IncrDataPtrValue:
            return m_cellsToModify->IncrDataPtrValue();
        case CommandType::MoveDataPtrLeft:
            return m_cellsToModify->MoveDataPtrLeft();
        case CommandType::MoveDataPtrRight:
            return m_cellsToModify->MoveDataPtrRight();
        case CommandType::InputDataPtrValue:
            return m_cellsToModify->InputDataPtrValue();
        case CommandType::OutputDataPtrValue:
            return m_cellsToModify->OutputDataPtrValue();
        default:
            break;
        }
    }

    void CommandPlain::AddCommand(std::shared_ptr<Command>)
    {
        // do nothing
    }
}

