#ifndef COMMANDSVALIDATOR_H
#define COMMANDSVALIDATOR_H

#include <algorithm>
#include <string>

class CommandsValidationException : public std::exception
{
private:
	std::string m_message;

public:
	explicit CommandsValidationException(const std::string& message) : m_message(message) {}

    const char *what() const throw()
    {
    	return m_message.c_str();
    }
};

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
