#ifndef COMMANDBASE_H
#define COMMANDBASE_H

namespace Command {
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
