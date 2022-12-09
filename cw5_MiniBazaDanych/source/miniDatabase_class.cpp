#include "miniDatabase_class.hpp"
#include <string>
#include <fstream>


miniDatabase::miniDatabase(int maxNumberOfEntries)
{
    this->maxNumberOfEntries = maxNumberOfEntries;
    this->numberOfEntries = 0U;
    pDatabaseOfHuman = new human[this->maxNumberOfEntries];
}

miniDatabase::~miniDatabase()
{
    delete[] pDatabaseOfHuman;
}

unsigned int miniDatabase::getNumberOfEntries(void)
{
    return this->numberOfEntries;
}

void miniDatabase::increaseNumberOfEntries(void)
{
    this->numberOfEntries++;
}

void miniDatabase::decreaseNumberOfEntries(void)
{
    this->numberOfEntries--;
}

unsigned int miniDatabase::getMaxNumberOfEntries(void)
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
        increaseNumberOfEntries();
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

    if (getNumberOfEntries() != 0U)
    {
        for (unsigned int i = 0; i < getNumberOfEntries(); i++)
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

std::string miniDatabase::BuildDataLine(unsigned int index)
{
    std::string TempString;
    if (index <= getNumberOfEntries() && index < getMaxNumberOfEntries())
    {
        TempString = std::to_string(index+1) + "; " \
                    + pDatabaseOfHuman[index].getName() + "; "  \
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

    MyFile.open((fileName + ".txt"), std::ios::out | std::ios::trunc);

    if (MyFile.is_open() == true)
    {
        std::string tempLine;
        for(unsigned int i = 0; i < getNumberOfEntries(); i++)
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

bool miniDatabase::maxEntriesExceeded(void)
{
    return (getNumberOfEntries() >= getMaxNumberOfEntries());
}

bool miniDatabase::loadDataBaseFromFile(std::string fileName)
{
    bool rResult = false;
    std::ifstream DataBaseFile(fileName + ".txt");
    unsigned int count = 0;
    //DataBaseFile.open((fileName+ ".txt"), std::ios::binary | std::ios::in);
    if (DataBaseFile.is_open())
    {
        DataBaseFile >> count;
        std::cout << "ilosc wpisow: " << count << std::endl;
        rResult = true;
    }
    else
    {
        std::cout << "cant open " << fileName << ".txt file" << std::endl;
        rResult = false;
    }
    return rResult;
}        


void miniDatabase::searchByName(std::string nameToFound)
{
    for (unsigned int i = 0; i < getNumberOfEntries(); i++)
    {
        if(pDatabaseOfHuman[i].getName().compare(nameToFound) == 0U) displayIndexEntries(i);
    }
}

void miniDatabase::displayIndexEntries(unsigned int index)
{
    std::cout << BuildDataLine(index) << std::endl;
}

bool miniDatabase::removeIndexEntiresFromDatabase(unsigned int index)
{
    bool rReturn = false;

    if (index == 0 ) return rReturn;

    unsigned int realIndex = index-1U;

    if (realIndex <  getNumberOfEntries())
    {
        for(unsigned int i = realIndex; i < getNumberOfEntries(); i++)
        {
            if ( (i + 1) != getNumberOfEntries())
            {
                pDatabaseOfHuman[i].setName(pDatabaseOfHuman[i+1].getName());
                pDatabaseOfHuman[i].setSurname(pDatabaseOfHuman[i+1].getSurname());
                pDatabaseOfHuman[i].setPhoneNumber(pDatabaseOfHuman[i+1].getPhoneNumber());
                pDatabaseOfHuman[i].setAge(pDatabaseOfHuman[i+1].getAge());   
            } else
            {
                pDatabaseOfHuman[i].setBlank();
            }
           rReturn = true;            
        }
        decreaseNumberOfEntries();
    }
    else
    {
        rReturn = false;
    }
    return rReturn;
}

bool miniDatabase::isNotEmpty(void)
{
    return (getNumberOfEntries() != 0U);
}