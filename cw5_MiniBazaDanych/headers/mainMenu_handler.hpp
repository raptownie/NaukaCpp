#ifndef _handler_mainMenu
#define _handler_mainMenu

#include "miniDatabase_class.hpp"

class mainMenu
{
    public:
        void MainMenu_perform(void);
    private:
        void sayHello(void);
        void showChooseSourceOfDataBase(void);
        void showAvailableMenuOptions(void);
        void handleSelectedOption(char);
        void handleSelectedDataBaseSource(char);
        bool checkInputCondition(char, char, char);
        miniDatabase* pMiniDataBase;
        bool dataBaseIsLoadedFromFile = false;
        std::string fileName = "";
        bool firstRunExecuted = false;
};

#endif