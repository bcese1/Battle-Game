#include <iostream>
#include "actor.hpp"


using namespace std;

void actor::DoCommand (CommandManager& mgr, Movetype movetype, actor* target)
{
  string MovetypeA[5] = {"Spell", "Curse", "Sword", "Melee", "Heal"};
  cout << this->getName() << " used: " << MovetypeA[static_cast<int>(movetype)] << endl;
  mgr.Executemove(BattleMoveFactory::Buildmove (movetype, this, target), this, target);
}

void actor::Hit (int damage)
{
  cout << this->getName() << " - (" << this->getHealth() << ") is attacked with " << damage << "damage!" << endl;
  this->Health -= damage;
}

void actor::Heal (int amount)
{
  cout << this->getName () << " - (" << this->getHealth () << ") gets healed with " << amount << "health!" << endl;
  this->Health += amount;
}

vector<Movetype> actor::GetMoves()
{
  return this->moves;
}

bool actor::IsDead()
{
  return this->Health <= 0;
}

