#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>

#include "CommandType.h"

namespace Command
{
    class CommandInterpreter
    {
    public:
        // To simplify conversions between 'CommandType' and 'char'
        static CommandType As_CommandType(const char cmdType)
        {
            return static_cast<CommandType>(cmdType);
        }

        static char As_Char(const CommandType cmdType)
        {
            return static_cast<char> (cmdType);
        }
    };

}


#endif // COMMANDINTERPRETER_H
