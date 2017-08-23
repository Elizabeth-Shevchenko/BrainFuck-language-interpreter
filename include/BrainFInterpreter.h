#ifndef BRAINFINTERPRETATOR_H
#define BRAINFINTERPRETATOR_H

#include <memory>
#include <string>

#include "ArrayCells.h"
#include "CommandsPool.h"

class BrainFInterpreter
{
private:
    // will be shared with all Commands (for modifying)
    std::shared_ptr<DataPointerArray::ArrayCells> m_cells;
    std::shared_ptr<Command::CommandsPool> m_commandsPool;

private:
    // Recursion constructing of nested commands
    void AddCommand(std::string::iterator &, std::string::iterator const&);
    void AddCommand(std::shared_ptr<Command::Command>, std::string::iterator&);
    // Resets commands pool and array byte cells before each new interpretation
    void Reset();

public:
    BrainFInterpreter();

    void StartInterpeation(std::string);
    void StartExecution();
};

#endif // BRAINFINTERPRETATOR_H
