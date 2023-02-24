#ifndef actor_hpp
#define actor_hpp
#include <iostream>
#include <vector>
#include <string>
#include "Mainenums.hpp"
#include "CommandManager.hpp"
#include "BattleMoveFactory.hpp"

class actor
{
    private:
        std::string iName;
        int Health;
        std::vector<Movetype> moves;

    protected:
        void addmove(Movetype move) { moves.push_back(move); }
        

    public:
        actor(std::string name, int health)
            :iName(name), Health(health)
        { }
        void Hit(int damage);
        void Heal(int amount);
        std::vector<Movetype> GetMoves();
        bool IsDead();
        auto getName() const -> std::string { return this->iName; }
        auto getHealth() const -> int { return this->Health; }
        void DoCommand(CommandManager& mgr, Movetype, actor* target);
};

class knight: public actor
{
    public:
        knight(std::string name, int health): actor(name, health)
            {
                addmove(Movetype::sword);
                addmove(Movetype::melee);
                addmove(Movetype::heal);
            }
};

class ghost: public actor
{
    public:
        ghost(std::string name, int health): actor(name, health)
            {
                addmove(Movetype::spell);
                addmove(Movetype::curse);
                addmove(Movetype::heal);
            }
};

#endif