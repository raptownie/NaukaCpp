#ifndef _human_class
#define _human_class

#include <iostream>

class human
{
    public:
        human();
        ~human();

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