#ifndef _handler_mainMenu
#define _handler_mainMenu

#include "miniDatabase_class.hpp"

class mainMenu : private miniDatabase
{
    public:
        void MainMenu_perform(void);
    private:
        void sayHello(void);
        void availableMenuOptions(void);
};

#endif