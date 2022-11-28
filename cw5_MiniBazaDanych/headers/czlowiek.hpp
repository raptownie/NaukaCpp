#ifndef _czlowiek
#define _czlowiek

#include <iostream>

class czlowiek
{
    public:
        czlowiek();
        ~czlowiek();

        std::string getName(void);
        void setName (std::string);

        std::string getSurname(void);
        void setSurname(std::string);

        short getAge(void);
        void setAge(short);

        std::string getPhoneNumber(void);
        void setPhoneNumber(std::string);

    private:
        std::string name;
        std::string surname;
        short age;
        std::string phoneNumber;
};

#endif