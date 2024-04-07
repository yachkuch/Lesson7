#include <iostream>
#include "cmd.h"

int main(int numberCommands, char**){
    std::cout << "Hello, from cmd!\n";
    numberCommands = 4;
    command::cmd command(numberCommands);
}
