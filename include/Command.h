#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <string>

namespace Command
{
	class CommandException : public std::exception
    {
    private:
        std::string m_message;

    public:
        explicit CommandException(const std::string& message) : m_message(message) {}

        const char *what() const throw()
        {
            return m_message.c_str();
        }
    };

    class Command
    {
    public:
        virtual ~Command(){}

        // Interface
        virtual void Execute() = 0;
        virtual void AddCommand(std::shared_ptr<Command> cmd) = 0;
    };
}

#endif // COMMANDBASE_H
