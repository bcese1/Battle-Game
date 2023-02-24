#ifndef CommandManager_hpp
#define CommandManager_hpp
#include "Battlemove.hpp"
#include "CreateStack.hpp"

class CommandManager
{
    private:
        Stack<Battlemove*>stack;
    public:
        CommandManager():
            stack{Stack<Battlemove*>()}
        {}
        
        void Executemove(Battlemove* cmd, actor* attacker, actor* target)
        {
            cmd->Execute();
            stack.Push(cmd);
        }

        void Undolaststep()
        {
            if(stack.isempty())
            {
                std::cout << "Can't undo this action" << std::endl;
                return;
            }

            Battlemove* cmd = stack.Top();
            cmd->Undo();
            stack.Pop();
        }

        ~CommandManager()
        {
            while(!stack.isempty())
            {
                delete stack.Top();
                stack.Pop();
            }
        }

    
};


#endif	