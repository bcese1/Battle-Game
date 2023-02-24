#ifndef Battlemove_hpp
#define Battlemove_hpp
#include "Undoable.hpp"

class actor;

class Battlemove: public UndoableCommand
{
    public:
        Battlemove(){}
        void Execute(){}
        void Undo(){}

    protected:
        actor* self;
        actor* other;
};

class SpellCommand: public Battlemove
{
    public:
        SpellCommand(actor* attacker, actor* target);
        void Execute();
        void Undo();

    private:
        int Damage;
};
       
class CurseCommand: public Battlemove
{
    public:
        CurseCommand(actor* attacker, actor* target);
        void Execute();
        void Undo();

    private:
        int Damage;
};

class SwordCommand: public Battlemove
{
    public:
        SwordCommand(actor* attacker, actor* target);
        void Execute();
        void Undo();

    private:
        int Damage;
};

class MeleeCommand: public Battlemove
{
    public:
        MeleeCommand(actor* attacker, actor* target);
        void Execute();
        void Undo();

    private:
        int Damage;
};

class HealCommand: public Battlemove
{
    public:
        HealCommand(actor* attacker, actor* target);
        void Execute();
        void Undo();

    private:
        int Healing;
};

#endif	