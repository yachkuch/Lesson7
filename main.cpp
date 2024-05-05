#include <iostream>
#include "cmd.h"

int main(int  , char**)
{
    int numberCommands = 0;
    std::cout<<"Number commands =  \n";
    std::cin>>numberCommands;
    command::cmd command(numberCommands);
}
