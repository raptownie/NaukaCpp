#include <iostream>
#include <cstdlib>
#include "miniDatabase_class.hpp"
#include "mainMenu_handler.hpp"

int main ()
{
    mainMenu MainMenuExecutor;
    
    MainMenuExecutor.MainMenu_perform();

    system("pause");
    return 0;
}