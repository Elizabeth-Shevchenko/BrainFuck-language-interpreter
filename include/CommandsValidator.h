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
private:
	static bool IsBracketsNestedCorrectly(std::string commands)
	{
		std::string::iterator it = begin(commands);

		for (; it != end(commands); ++it)
		{
			// can't start from the closed bracket
			if (']' == *it)
				return false;

			if ('[' == *it)
			{
				// if bracket is opened should be another one to close it
				auto res = std::find(it + 1, end(commands), ']');
				if (res == end(commands))
					return false;

				commands.erase(res);
			}
		}
		return true;
	}

	static bool IsUnknownCommandsInside(std::string commands)
	{
		// for (auto cmd : commands)
		// {
		// 	//if ()
		// }
	}

public:
    static bool IsInputCommandsValid(std::string commands)
    {
        return IsBracketsNestedCorrectly(commands);
    }
};

#endif // COMMANDSVALIDATOR_H
