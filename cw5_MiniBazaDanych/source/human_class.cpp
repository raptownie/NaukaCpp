#include "human_class.hpp"


human::human()
{
    setName("NoData");
    setSurname("NoData");
    setPhoneNumber("NoData");
    setAge(999);
}


human::~human()
{

}

std::string human::getName(void)
{
    return this->name;
}

void human::setName(std::string Name)
{
    this->name = Name;
}

std::string human::getSurname(void)
{
    return this->surname;
}

void human::setSurname(std::string Surname)
{
    this->surname = Surname;
}

std::string human::getPhoneNumber(void)
{
    return this->phoneNumber;
}

void human::setPhoneNumber(std::string TelNumber)
{
    this->phoneNumber = TelNumber;
}

short human::getAge(void)
{
    return this->age;
}

void human::setAge(short Age)
{
    this->age = Age;
}


