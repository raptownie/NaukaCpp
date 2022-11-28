#include "czlowiek.hpp"


czlowiek::czlowiek()
{
    setName("NoData");
    setSurname("NoData");
    setPhoneNumber("NoData");
    setAge(999);
}


czlowiek::~czlowiek()
{

}

std::string czlowiek::getName(void)
{
    return this->name;
}

void czlowiek::setName(std::string Name)
{
    this->name = Name;
}

std::string czlowiek::getSurname(void)
{
    return this->surname;
}

void czlowiek::setSurname(std::string Surname)
{
    this->surname = Surname;
}

std::string czlowiek::getPhoneNumber(void)
{
    return this->phoneNumber;
}

void czlowiek::setPhoneNumber(std::string TelNumber)
{
    this->phoneNumber = TelNumber;
}

short czlowiek::getAge(void)
{
    return this->age;
}

void czlowiek::setAge(short Age)
{
    this->age = Age;
}


