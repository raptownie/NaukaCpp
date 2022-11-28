#include "mainMenu_handler.hpp"
#include <iostream>

void mainMenu::sayHello()
{
    std::cout << "Welcome in my mini Database :)" << std::endl;
}

void mainMenu::availableMenuOptions()
{
    std::cout << "MENU: " << std::endl;
    std::cout << "1. Add person " << std::endl;
    std::cout << "2. Show All persons " << std::endl;
    std::cout << "3. Save Database to file" << std::endl;
    std::cout << "4. Load Database from file" << std::endl;
    std::cout << "5. Search Database by name" << std::endl;
    std::cout << "6. Remove person from Database" << std::endl;
    std::cout << "Press . (dot) for exit" << std::endl;
}

void mainMenu::MainMenu_perform()
{
    system("cls");
    sayHello();
    char selectedNumber = '0';

    while(selectedNumber != '.')
    {
        availableMenuOptions();
        std::cin >> selectedNumber;
        if (selectedNumber == '.') break;
        if (selectedNumber > '9' || selectedNumber < '1')
        {

            std::cout << "its not a number" << std::endl;
                    system("pause");  
        }else
        {

             system("pause"); 
        }
        system("cls");
    };

}
