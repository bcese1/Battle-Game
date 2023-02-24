#include "UserInterface.hpp"
#include <time.h>

using namespace std;

void UserInterface::Begin()
{
  vector<actor*>actors;
  CommandManager mgr;
  
  while(actors.size() != 2)
    {
      if(actors.size() == 1)
        {
          cout << "Select Player's Character: 0. Ghost, 1. Knight" << endl;
        }
      else
        {
          cout << "Select CPU's Character: 0. Ghost, 1. Knight" << endl;
        }
      
      int choice;
      cout << "Selection: ";
      cin >> choice;
      
      switch((Actortype)choice)
        {
          case Actortype::Ghost:
            actors.push_back (new ghost("Ghost", 100));
            break;
          
          case Actortype::Knight:
            actors.push_back(new knight("Knight", 100));
            break;
          default:
            cout << "\nPlease enter the correct selection\n" << endl;
            break;
        }
    }
  
  cout << "\nMatch is starting! Please wait..." << endl;
  cout << actors[0]->getName () << " - ("<<actors[0]->getHealth ()<<" Health)" << endl;
  cout << actors[1]->getName () << " - ("<<actors[1]->getHealth ()<<" Health)" << endl;
  
  while(!actors[0]->IsDead () && !actors[1]->IsDead ())
    {
      int choice;
      cout << "Choose action: \n"
              "1. Player 1 ATTACKS CPU\n"
              "2. CPU ATTACKS Player 2\n"
              "3. Undo Last 2 Actions" << endl;
      
      cout << "Selection: ";
      cin >> choice;
      
      srand(time(NULL));
      int random = rand() % 2 + 1;
      
      switch(choice)
        {
            case 1:
              actors[0]->DoCommand (mgr,actors[0]->GetMoves ()[random],actors[1]);
              break;
            case 2:
              actors[1]->DoCommand (mgr, actors[1]->GetMoves ()[random], actors[0]);
            case 3:
              mgr.Undolaststep ();
              break;
            default:
              cout << "\nPlease enter the correct selection\n" << endl;
        }
      
        cout << "[Player: " << actors[0]->getName () << ", (" << actors[0]->getHealth() 
    << ")][Opponent: " << actors[1]->getName() << ", (" << actors[1]->getHealth() << ")]\n";
      
      
    }
  
    cout << "Winner is: " << (actors[0]->IsDead()? "Opponent" : "Player") << endl;
  
  
}
