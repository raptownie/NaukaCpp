#ifndef _minibaza
#define _minibaza

#include "czlowiek.hpp"
#include "menuMiniBase.hpp"

class miniBaza : public menuMiniBase, public czlowiek
{
    public:
        miniBaza(int maxNumberOfEntries = 20);
        ~miniBaza();
        int getNumberOfEntries(void);
        int getMaxNumberOfEntries(void);
        bool setNewHuman(czlowiek);
        bool showAllHumansInDatabase(void);
        bool saveDatabaseToFile(std::string &);
        bool loadDataBaseFromFile(std::string);
        //czlowiek searchByName(std::string);
        //void removeEntiresFromDatabase(int);
    private:
        int numberOfEntries;
        int maxNumberOfEntries;
        czlowiek *pDatabaseOfHuman;
        std::string BuildDataLine(int);
};

#endif