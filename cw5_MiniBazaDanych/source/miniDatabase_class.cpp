#include "miniDatabase_class.hpp"
#include <string>
#include <fstream>


miniDatabase::miniDatabase(int maxNumberOfEntries)
{
    this->maxNumberOfEntries = maxNumberOfEntries;
    this->numberOfEntries = 0;
    pDatabaseOfHuman = new human[this->maxNumberOfEntries];
}

miniDatabase::~miniDatabase()
{
    delete[] pDatabaseOfHuman;
}


int miniDatabase::getNumberOfEntries(void)
{
    return this->numberOfEntries;
}

int miniDatabase::getMaxNumberOfEntries(void)
{
    return this->maxNumberOfEntries;
}

bool miniDatabase::setNewHuman(human NewHuman)
{
    bool rResult = false;

    if (getNumberOfEntries() < getMaxNumberOfEntries())
    {
        pDatabaseOfHuman[numberOfEntries].setName(NewHuman.getName());
        pDatabaseOfHuman[numberOfEntries].setSurname(NewHuman.getSurname());
        pDatabaseOfHuman[numberOfEntries].setPhoneNumber(NewHuman.getPhoneNumber());
        pDatabaseOfHuman[numberOfEntries].setAge(NewHuman.getAge());
        numberOfEntries++;
        rResult = true;
    }
    else
    {
        std::cout << "maximum number of entries exceeded" << std::endl;
        rResult = false;
    }
    return rResult;
}

bool miniDatabase::showAllHumansInDatabase(void)
{
    bool rResult = false;

    if (getNumberOfEntries() != 0)
    {
        for (int i = 0; i < getNumberOfEntries(); i++)
        {
            std::cout <<  BuildDataLine(i) << std::endl;
        }
        rResult = true;
    }
    else
    {
        std::cout << "Database is empty!" << std::endl;
        rResult = false;
    }

    return rResult;
}

std::string miniDatabase::BuildDataLine(int index)
{
    std::string TempString;
    if (index <= getNumberOfEntries() && index < getMaxNumberOfEntries())
    {
        TempString = pDatabaseOfHuman[index].getName() + "; "  \
                    + pDatabaseOfHuman[index].getSurname() + "; " \
                    + pDatabaseOfHuman[index].getPhoneNumber() + "; " \
                    + std::to_string(pDatabaseOfHuman[index].getAge());
    }
    else
    {
        TempString = "No Data / out of bound";
    }

    return TempString;
}
bool miniDatabase::saveDatabaseToFile(std::string fileName)
{
    bool rResult = false;
    std::fstream MyFile;

    if (getNumberOfEntries() == 0)
    {
        std::cout << "Database is empty!" << std::endl;
        return false;
    }

    MyFile.open(fileName, std::ios::out | std::ios::trunc);

    if (MyFile.is_open() == true)
    {
        std::string tempLine;
        for(int i = 0; i < getNumberOfEntries(); i++)
        {
            tempLine = BuildDataLine(i);
            MyFile << tempLine << std::endl;
        }
        MyFile.close();
        rResult = true;
    }
    else
    {
        std::cout << "can't open file " << fileName << std::endl;
        rResult = false;
    }

    return rResult;
}

bool loadDataBaseFromFile(std::string fileName)
{
    bool rResult = false;
    std::fstream DataBaseFile;

    //DataBaseFile.open(fileName, std::ios::binary | std::ios::in);

    return rResult;
}        

//czlowiek searchByName(std::string);
//void removeEntiresFromDatabase(int);
