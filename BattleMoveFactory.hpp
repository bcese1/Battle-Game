#ifndef BattleMoveFactory_hpp
#define BattlemoveFactory_hpp
#include "Mainenums.hpp"
#include "Actor.hpp"
#include "Battlemove.hpp"

class BattleMoveFactory
{
    public:
        static Battlemove* Buildmove(Movetype type, actor* attacker, actor* target)
        {
            Battlemove* BM = nullptr;
            //Battlemove* BM;
            switch(type)
            {
                case Movetype::spell:
                        BM = new SpellCommand(attacker, target);
                        break;
                    case Movetype::curse:
                        BM = new CurseCommand(attacker, target);
                        break;
                    case Movetype::sword:
                        BM = new SwordCommand(attacker, target);
                        break;
                    case Movetype::melee:
                        BM = new MeleeCommand(attacker, target);
                        break;
                    case Movetype::heal:
                        BM = new HealCommand(attacker, target);
                        break;
                    default:
                        std::cout << "Does not exist";
            }
            return BM;
        }
};
        

#endif	