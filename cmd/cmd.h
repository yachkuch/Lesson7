#ifndef __CMD_H_PIQDZK0VGO84__
#define __CMD_H_PIQDZK0VGO84__

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
namespace command
{

/// @brief Переичаление типов команд
enum class e_CammandsTipe : int
{
    defaultCom,     //!< Дефолтная команда 
    newBlockStart,  //!< начало нового блока
    newBlockFinish, //!< конец блока
    breakBlock,     //!< прекращение ввода данных любого типа
};



///////////////////////////////////////////////////////////
/// @brief cmd Класс командной строки 
///
class cmd 
{
public:
    cmd(int numberCommands);
    ~cmd(); 
    cmd(const cmd &other) = delete ;
    cmd(cmd &&other) = delete;
    cmd &operator=(const cmd &other) = delete;
    cmd &operator=(cmd &&other) = delete;

private:
    std::ofstream file;
    unsigned  counterCommands = 0;

    void start();
    void openfile();
    std::vector<std::string> startDynamicBock( std::string command);
};
}
#endif  // __CMD_H_PIQDZK0VGO84__
