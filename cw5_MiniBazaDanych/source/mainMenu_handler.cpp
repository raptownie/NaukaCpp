#include "mainMenu_handler.hpp"
#include "human_class.hpp"
#include <iostream>
#include <limits>


void mainMenu::sayHello()
{
    std::cout << "Welcome in my mini Database :)" << std::endl;
}

void mainMenu::showAvailableMenuOptions()
{
    std::cout << "MENU: " << std::endl;
    std::cout << "1. Add person " << std::endl;
    std::cout << "2. Show All persons " << std::endl;
    std::cout << "3. Save Database to file" << std::endl;
    std::cout << "4. Load Database from file" << std::endl;
    std::cout << "5. Search Database by name" << std::endl;
    std::cout << "6. Remove person from Database (by index)" << std::endl;
    std::cout << "Press . (dot) for exit" << std::endl;
}

void mainMenu::showChooseSourceOfDataBase(void)
{
    std::cout << "Please chose one of the folliwing option:" << std::endl;
    std::cout << "1. Create new DataBase" << std::endl;
    std::cout << "2. Load Database from file" << std::endl;
    std::cout << "Press . (dot) for exit" << std::endl;
}

void mainMenu::MainMenu_perform()
{
    system("cls");
    sayHello();
    char selectedNumber = '0';

    while(selectedNumber != '.')
    {        
        if (firstRunExecuted == false)
        {
            showChooseSourceOfDataBase();
            std::cin >> selectedNumber;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (selectedNumber == '.') break;
            if (checkInputCondition(selectedNumber, '1', '2'))
            {
                handleSelectedDataBaseSource(selectedNumber);
                firstRunExecuted = true;
            }
        }
        else
        {
            showAvailableMenuOptions();
            std::cin >> selectedNumber;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (selectedNumber == '.') break;
            if (checkInputCondition(selectedNumber, '1', '6'))
            {
                system("cls");
                handleSelectedOption(selectedNumber);
                system("pause"); 
            }
        }
        system("cls");
    }

}

void mainMenu::handleSelectedOption(char Input)
{
    human humanData;
    std::string tempStringInput = "";
    unsigned short tempShort = 0U;

    switch (Input)
    {        
        /* 1. Add person              */
        case '1': 
            if (pMiniDataBase->maxEntriesExceeded() == false)
            {
                std::cout << "Name: ";
                std::cin >> tempStringInput;
                humanData.setName(tempStringInput);

                tempStringInput = "";
                std::cout << "Surname: ";
                std::cin >> tempStringInput;
                humanData.setSurname(tempStringInput);

                tempStringInput = "";
                std::cout << "Phone number: ";
                std::cin >> tempStringInput;
                humanData.setPhoneNumber(tempStringInput);

                tempStringInput = "";
                std::cout << "Age: ";
                std::cin >> tempShort;
                humanData.setAge(tempShort);

                pMiniDataBase->setNewHuman(humanData);
            }
            else
            {
                std::cout << "maximum number of entries exceeded" << std::endl;
            }   
            break;

        /* 2. Show All persons            */
        case '2':
            if(pMiniDataBase->isNotEmpty())
            {
                pMiniDataBase->showAllHumansInDatabase();
            }
            else
            {
                std::cout << "DataBase is Empty!" << std::endl;
            }
            break;

        /* 3. Save Database to file       */
        case '3':
            if(pMiniDataBase->isNotEmpty())
            {
                if(fileName.empty())
                {
                    std::cout << "Set name of database file: ";
                    std::cin >> fileName;
                    pMiniDataBase->saveDatabaseToFile(fileName);
                }
                else
                {
                    pMiniDataBase->saveDatabaseToFile(fileName);
                }
            }
            else
            {
                std::cout << "DataBase is Empty!" << std::endl;
            }

            break;

        /* 4. Load Database from file     */
        case '4':
            std::cout << "Not implemented" << std::endl;
            break;
        
        /* 5. Search Database by name     */
        case '5':
            if (pMiniDataBase->isNotEmpty())
            {
                std::cout << "Search by name : ";
                std::cin >> tempStringInput;
                pMiniDataBase->searchByName(tempStringInput);
            }
            else
            {
                std::cout << "DataBase is Empty!" << std::endl;
            }
            break;

        /* 6. 6. Remove person from Database (by index) */
        case '6':
            if (pMiniDataBase->isNotEmpty())
            {
                std::cout << "Tell me, witch index do you want to delte? ";
                std::cin >> tempShort;
                if (pMiniDataBase->removeIndexEntiresFromDatabase(tempShort))
                {
                    std::cout << "index " << tempShort << " successfully removed" << std::endl;
                }
                else
                {
                    std::cout << "Can't removed index: " << tempShort << std::endl;  
                }
            }
            else
            {
                std::cout << "DataBase is Empty!" << std::endl;
            }
            break;
        default:
            /* should never reached */
            break;
    }
}

bool mainMenu::checkInputCondition(char Input, char start, char end)
{
    bool rReturn = true;
    if (Input > '9' || Input < '0')
    {
        system("cls");
        std::cout << "its not a number" << std::endl;
        system("pause");
        rReturn = false;
    }
    else if ( Input > end || Input < start)
    {
        system("cls");
        std::cout << "No available option for this value" << std::endl;
        system("pause");
        rReturn = false;
    }
    return rReturn;
}


void mainMenu::handleSelectedDataBaseSource(char Input)
{
    int numberOfEtries = 0;
    switch (Input)
    {
        /* '1' - new Database               */
        /* '2' - load Database from file    */
        case '1':            
            std::cout << "How many entries should be supported? : ";
            std::cin >> numberOfEtries;
            pMiniDataBase = new miniDatabase(numberOfEtries);            
            std::cout << "New database is created successfully!" << std::endl;
            dataBaseIsLoadedFromFile = false;
            fileName = "";
            break;
        case '2':
            pMiniDataBase->loadDataBaseFromFile("MojaBazaDanych");
            system("pause");
            std::cout << "Not implemented" << std::endl;
            break;
        default:
            /* should never reached */
            break;
    }
}