#ifndef _miniDatabase_class
#define _miniDatabase_class

#include "human_class.hpp"


class miniDatabase : private human
{
    public:
        miniDatabase(int maxNumberOfEntries = 20);
        ~miniDatabase();
        unsigned int getNumberOfEntries(void);
        unsigned int getMaxNumberOfEntries(void);
        bool setNewHuman(human);
        bool showAllHumansInDatabase(void);
        bool saveDatabaseToFile(std::string);
        bool loadDataBaseFromFile(std::string);
        bool maxEntriesExceeded(void);
        void searchByName(std::string);
        void displayIndexEntries(unsigned int index);
        bool removeIndexEntiresFromDatabase(unsigned int);
        bool isNotEmpty(void);
    private:
        int numberOfEntries;
        int maxNumberOfEntries;
        human *pDatabaseOfHuman;
        const unsigned short numberOfSemicolonsInDatabaseEntries = 4;
        std::string BuildDataLine(unsigned int);
        void increaseNumberOfEntries(void);
        void decreaseNumberOfEntries(void);
};

#endif