/* 
 * File:   main.cpp
 * Author: benja
 *
 * Created on March 20, 2021, 10:46 AM
 */
#include <iostream>
#include "UserInterface.hpp"

int main(int argc, const char * argv[])
{
  UserInterface* run = new UserInterface;
  run->Begin();
  
  delete run;
  
  return 0;
}
