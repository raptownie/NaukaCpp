#ifndef _miniDatabase_class
#define _miniDatabase_class

#include "human_class.hpp"


class miniDatabase : private human
{
    public:
        miniDatabase(int maxNumberOfEntries = 20);
        ~miniDatabase();
        int getNumberOfEntries(void);
        int getMaxNumberOfEntries(void);
        bool setNewHuman(human);
        bool showAllHumansInDatabase(void);
        bool saveDatabaseToFile(std::string);
        bool loadDataBaseFromFile(std::string);
        bool maxEntriesExceeded(void);
        unsigned int * searchByName(std::string);
        void displayDataBaseByIndex(unsigned int *);
        //void removeEntiresFromDatabase(int);
    private:
        int numberOfEntries;
        int maxNumberOfEntries;
        human *pDatabaseOfHuman;
        std::string BuildDataLine(int);
};

#endif