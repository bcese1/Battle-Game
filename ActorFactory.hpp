#ifndef ActorFactory_hpp
#define ActorFactory_hpp
#include "actor.hpp"

class ActorFactory
{
    public:
        static actor* CreateActor(Actortype actor)
            {
                actor* actor = nullptr;
                switch(actor)
                    {
                        case Actortype::ghost:
                            return new ghost::actor(100, "Ghost");
                            break;
                        case Actortype::knight:
                            return new knight::actor(100, "Knight");
                            break;
                    }
            }
};
                        

#endif	