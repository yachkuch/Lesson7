#ifndef __CMD_H_PIQDZK0VGO84__
#define __CMD_H_PIQDZK0VGO84__

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

namespace command
{

/// @brief Переичаление типов команд
enum class e_CammandsTipe : int
{
    defaultCom,     //!< Дефолтная команда 
    newBlockStart,  //!< начало нового блока
    newBlockFinish, //!< конец блока
    breakBlock,     //!< принудительное прерывание блока
};



///////////////////////////////////////////////////////////
/// @brief cmd Класс командной строки 
///
class cmd 
{
public:
    cmd(int numberCommands);
    ~cmd() = default; 
    cmd(const cmd &other) = delete ;
    cmd(cmd &&other) = delete;
    cmd &operator=(const cmd &other) = delete;
    cmd &operator=(cmd &&other) = delete;

private:
    unsigned  counterCommands = 0;

    void start();
    void startDynamicBock( std::string command);
};
}
#endif  // __CMD_H_PIQDZK0VGO84__
