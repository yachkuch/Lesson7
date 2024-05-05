#include "cmd.h"
#include <vector>
#include <functional>


using namespace command;

const static auto printAll = []( std::vector<std::string> &com, std::ofstream &fstream)
{
    if(com.empty()) return;
    std::cout << "bulk:";
    for (const auto &el : com)
    {
        std::cout << el << " ";
        fstream << el << std::endl;
    }
    std::cout << std::endl;
    com.clear();
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

cmd::~cmd()
{
    file.close();
}

void cmd::start()
{
    std::vector<std::string> commandes(counterCommands);
    int position{};
    while (this->counterCommands != 0)
    {
        std::string command;
        std::cin >> command;
        if(!file.is_open())
        {
            openfile();
        }
        try
        {
            auto val = commandsList.at(command);
            switch (val)
            {
            case e_CammandsTipe::newBlockStart:
                printAll(commandes,file);
                auto printDynamic = startDynamicBock(command);
                auto iter = std::find(commandes.begin(), commandes.end(),"EOF" );
                if(iter != commandes.end()) 
                {
                    std::abort();
                }
                printAll(printDynamic,file);
                command = "dg";
                continue;
            }
        }
        catch (...)
        {
            commandes[position] = command;
            position++;
            counterCommands--;
        }
    }
    printAll(commandes,file);
}

void cmd::openfile()
{
    const auto p1 = std::chrono::system_clock::now();
    auto val =  std::chrono::duration_cast<std::chrono::seconds>(
                   p1.time_since_epoch()).count();
    std::string file_name = std::to_string(val);
    file_name += ".txt";
    file.open(file_name);
    if(!file.is_open())
    {
        std::cout<<"Файл не открылся"<<std::endl;
        std::abort();
    }
}

std::vector<std::string> cmd::startDynamicBock(std::string command)
{
    std::vector<std::string> commandes(3);
    int position{};
    do
    {
        std::cin >> command;
        try
        {
            auto val = commandsList.at(command);
            switch (val)
            {
            case e_CammandsTipe::newBlockStart:
            {
                auto result = startDynamicBock(command);
                commandes.insert(commandes.end(),result.begin(),result.end());
                command = "dg";           
                continue;
            }
            case e_CammandsTipe::breakBlock:
            {
                commandes[position] = command;
                return commandes;
            }
            default:
            {
                break;
            }
            }
        }
        catch (...)
        {
            commandes[position] = command;
            position++;
        }
    }
    while (spendDynamicBlock(command, commandsList));
    return commandes;
}
