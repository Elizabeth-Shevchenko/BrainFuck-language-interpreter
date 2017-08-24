#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
#include <algorithm>
#include <map>

#include "CommandType.h"

namespace Command
{
    class CommandInterpreter
    {
    private:
        // to simplify conversioins
        // decided to use 'char' as a key as conversions char -> CmdType
        // will be more that cmdType -> char
        static std::map<char, CommandType> m_commandsDictionary;

    public:
        static bool IsCommand(const char cmd)
        {
            auto check = m_commandsDictionary.find(cmd);
            return end(m_commandsDictionary) != check;
        }

        static CommandType As_CommandType(const char cmdType)
        {
            auto check = m_commandsDictionary.find(cmdType);

            if (end(m_commandsDictionary) != check)
                return check->second;

            return CommandType::Unknown;
        }
    };

    std::map<char, CommandType> CommandInterpreter::m_commandsDictionary = {
        {'>', CommandType::MoveDataPtrRight},
        {'<', CommandType::MoveDataPtrLeft},
        {'+', CommandType::IncrDataPtrValue},
        {'-', CommandType::DecrDataPtrValue},
        {'.', CommandType::OutputDataPtrValue},
        {',', CommandType::InputDataPtrValue},
        {'[', CommandType::LoopBegin},
        {']', CommandType::LoopEnd}
    };

}


#endif // COMMANDINTERPRETER_H
