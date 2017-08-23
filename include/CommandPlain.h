#ifndef COMMANDPLAIN_H
#define COMMANDPLAIN_H

#include <memory>

#include "Command.h"
#include "CommandType.h"
#include "ArrayCells.h"

namespace Command
{
using DataPointerArray::ArrayCells;
using std::shared_ptr;

    class CommandPlain : public Command
    {
    private:
        CommandType m_cmdType;
        shared_ptr<ArrayCells> m_cellsToModify;

    public:
        explicit CommandPlain(CommandType, std::shared_ptr<DataPointerArray::ArrayCells>);

        CommandPlain(const CommandPlain&) = delete;
        CommandPlain& operator=(const CommandPlain&) = delete;

        void Execute() override;
        void AddCommand(std::shared_ptr<Command> cmd) override;
    };
}

#endif // COMMANDPLAIN_H
