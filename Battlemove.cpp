#include <time.h>
#include "actor.hpp"


SpellCommand::SpellCommand (actor* attacker, actor* target)
{
  this->self = self;
  this->other = other;
}

void SpellCommand::Execute ()
{
  srand(time(NULL));
  int damage = rand() % 20;
  this->Damage = damage;
  this->other->Hit (damage);
}

void SpellCommand::Undo()
{
  this->other->Heal (Damage);
}

CurseCommand::CurseCommand (actor* attacker, actor* target)
{
  this->self = self;
  this->other = other;
}

void CurseCommand::Execute ()
{
  srand(time(NULL));
  int damage = rand() % 15;
  if(damage < 5)
    {
      damage = 0;
      damage + 5;
      this->Damage = damage;
      this->other->Hit (damage);
    }
  else
    {
      this->Damage = damage;
      this->other->Hit (damage);
    }
}

void CurseCommand::Undo()
{
  this->other->Heal (Damage);
}

SwordCommand::SwordCommand (actor* attacker, actor* target)
{
  this->self = self;
  this->other = other;
}

void SwordCommand::Execute()
{
  srand(time(NULL));
  int damage = rand() % 20;
  this->Damage = damage;
  this->other->Hit (damage);
}

void SwordCommand::Undo()
{
  this->other->Heal (Damage);
}

MeleeCommand::MeleeCommand (actor* attacker, actor* target)
{
  this->self = self;
  this->other = other;
}

void MeleeCommand::Execute()
{
  srand(time(NULL));
  int damage = rand() % 15;
  if(damage < 5)
    {
      damage = 0;
      damage + 5;
      this->Damage = damage;
      this->other->Hit (damage);
    }
  else
    {
      this->Damage = damage;
      this->other->Hit (damage);
    }
}

void MeleeCommand::Undo()
{
  this->other->Heal (Damage);
}

HealCommand::HealCommand (actor* attacker, actor* target)
{
  this->self = self;
  this->other = other;
}

void HealCommand::Execute()
{
  srand(time(NULL));
  int Healed = rand() % 20;
  this->Healing = Healed;
  this->other->Heal(Healed);
}

void HealCommand::Undo()
{
  this->other->Heal (Healing);
}





