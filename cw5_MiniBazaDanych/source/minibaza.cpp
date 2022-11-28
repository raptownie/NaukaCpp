#include "minibaza.hpp"
#include <string>
#include <fstream>


miniBaza::miniBaza(int maxNumberOfEntries)
{
    this->maxNumberOfEntries = maxNumberOfEntries;
    this->numberOfEntries = 0;
    pDatabaseOfHuman = new czlowiek[this->maxNumberOfEntries];
}

miniBaza::~miniBaza()
{
    delete[] pDatabaseOfHuman;
}


int miniBaza::getNumberOfEntries(void)
{
    return this->numberOfEntries;
}

int miniBaza::getMaxNumberOfEntries(void)
{
    return this->maxNumberOfEntries;
}

bool miniBaza::setNewHuman(czlowiek czlowiek)
{
    bool rResult = false;

    if (this->numberOfEntries < this->maxNumberOfEntries)
    {
        pDatabaseOfHuman[numberOfEntries].setName(czlowiek.getName());
        pDatabaseOfHuman[numberOfEntries].setSurname(czlowiek.getSurname());
        pDatabaseOfHuman[numberOfEntries].setPhoneNumber(czlowiek.getPhoneNumber());
        pDatabaseOfHuman[numberOfEntries].setAge(czlowiek.getAge());
        numberOfEntries++;
        rResult = true;
    }
    else
    {
        std::cout << "Przekroczono maksymalna ilosc osob" << std::endl;
        rResult = false;
    }
    return rResult;
}

bool miniBaza::showAllHumansInDatabase(void)
{
    bool rResult = false;

    if (this->numberOfEntries != 0)
    {
        for (int i = 0; i < numberOfEntries; i++)
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

std::string miniBaza::BuildDataLine(int index)
{
    std::string TempString;
    if (index <= numberOfEntries && index < maxNumberOfEntries)
    {
        TempString = pDatabaseOfHuman[index].getName() + "; " + pDatabaseOfHuman[index].getSurname() + "; " + pDatabaseOfHuman[index].getPhoneNumber() + "; " + static_cast<char>((int)(pDatabaseOfHuman[index].getAge()));
    }
    else
    {
        TempString = "No Data / out of bound";
    }

    return TempString;
}
bool miniBaza::saveDatabaseToFile(std::string & fileName)
{
    bool rResult = false;
    std::fstream MyFile;

    if (this->numberOfEntries == 0)
    {
        std::cout << "Database is empty!" << std::endl;
        return false;
    }

    MyFile.open(fileName, std::ios::out | std::ios::trunc);

    if (MyFile.is_open() == true)
    {
        std::string tempLine;
        for(int i = 0; i<numberOfEntries; i++)
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
