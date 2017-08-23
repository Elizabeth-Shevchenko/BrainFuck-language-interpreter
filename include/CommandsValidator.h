#ifndef COMMANDSVALIDATOR_H
#define COMMANDSVALIDATOR_H

#include <algorithm>
#include <string>
#include <regex>

class CommandsValidator
{
public:
    static bool IsInputCommandsValid(std::string commands)
    {
        auto openBrackets = std::count(begin(commands), end(commands), '[');
        auto closeBrackets = std::count(begin(commands), end(commands), ']');

        return (openBrackets == closeBrackets);
    }
};

#endif // COMMANDSVALIDATOR_H
