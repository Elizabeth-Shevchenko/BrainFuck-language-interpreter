#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H

namespace Command
{
    enum class CommandType : char
    {
        Unknown,                  // unknown command

        MoveDataPtrRight = '>',   // point to the next cell to the right

        MoveDataPtrLeft = '<',    // point to the next cell to the left

        IncrDataPtrValue = '+',   // (increase by one) the byte at the data pointer

        DecrDataPtrValue = '-',   // (decrease by one) the byte at the data pointer

        OutputDataPtrValue = '.', // output the byte at the data pointer

        InputDataPtrValue = ',',  // accept one byte of input, storing its value in the byte at the data pointer

        LoopBegin = '['          /* if the byte at the data pointer is zero, then instead of moving the instruction pointer
                                     forward to the next command, jump it forward to the command after the matching ] command */

        /*LoopEnd = ']'              if the byte at the data pointer is nonzero, then instead of moving the instruction pointer
                                     forward to the next command, jump it back to the command after the matching [ command */
    };
}
#endif // COMMANDTYPE_H
