#ifndef COMMANDCOMPLEX_H
#define COMMANDCOMPLEX_H

#include <vector>
#include <memory>

#include "Command.h"
#include "CommandType.h"
#include"ArrayCells.h"

namespace Command
{
    class CommandComplex : public Command
    {
    private:
        CommandType m_cmdType;
        std::shared_ptr<DataPointerArray::ArrayCells> m_cellsToModify;

        // e.g. [++>.] - is a ComplexCommand (staff inside the [] coud be executed several times etc.)
        // so used nested sructure
        std::vector<std::shared_ptr<Command>> m_cmds;

    public:
        explicit CommandComplex(CommandType, std::shared_ptr<DataPointerArray::ArrayCells>);

        CommandComplex(const CommandComplex&) = delete;
        CommandComplex& operator=(const CommandComplex&) = delete;

        void Execute() override;
        void AddCommand(std::shared_ptr<Command> cmd) override;
    };
}


#endif // COMMANDCOMPLEX_H
