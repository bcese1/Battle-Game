#ifndef Undoable_hpp
#define Undoable_hpp

class UndoableCommand
{
    public:
        void virtual Execute()=0;
        void virtual Undo()=0;
        virtual ~UndoableCommand() {};
};
#endif	