#include "cmd.h"
#include <vector>
#include <functional>
using namespace command;

const static auto printAll = [](const std::vector<std::string> &com)
{
    std::cout << "bulk:";
    for (const auto &el : com)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
};

//! Список всех возможных команд
const std::unordered_map<std::string, e_CammandsTipe> commandsList =
    {
        {"{", e_CammandsTipe::newBlockStart}, {"}", e_CammandsTipe::newBlockFinish}, {"EOF", e_CammandsTipe::breakBlock}};

const auto spendDynamicBlock = [](const std::string &command, const std::unordered_map<std::string, e_CammandsTipe> &commandsList) -> bool
{
    return !(commandsList.contains(command));
};

cmd::cmd(int numberCommands)
{
    this->counterCommands = numberCommands;
    start();
}

void cmd::start()
{
    std::vector<std::string> commandes(counterCommands);
    int position{};
    while (this->counterCommands != 0)
    {
        std::string command;
        counterCommands--;
        std::cin >> command;
        try
        {
            auto val = commandsList.at(command);
            switch (val)
            {
            case e_CammandsTipe::newBlockStart:
                startDynamicBock(command);
                break;
            }
        }
        catch (...)
        {
            commandes[position] = command;
            position++;
        }
    }
    printAll(commandes);
}

void cmd::startDynamicBock( std::string command)
{
    std::vector<std::string> commandes(3);
    int position{};
    do{
            std::cin >> command;
        try
        {
            auto val = commandsList.at(command);
            switch (val)
            {
            case e_CammandsTipe::newBlockStart:
                startDynamicBock(command);
                break;
            }
        }
        catch (...)
        {
            commandes[position] = command;
            position++;
        }
    }
    while (spendDynamicBlock(command, commandsList));
    printAll(commandes);
}
