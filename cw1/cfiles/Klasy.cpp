#include "../headers/Klasy.hpp"




Czlowiek::Czlowiek(){
    static int i=0;
    wiek=18;
    std::cout << "Konstruktor wykonal sie " << ++i << " razy." << std::endl;
}

Czlowiek::Czlowiek(int age){
    static int i=0;
    setAge(age);
    std::cout << "Przeciazony konstruktor wykonal sie " << ++i << " razy." << std::endl;
}

Czlowiek::~Czlowiek(){
    static int i=0;
    std::cout << "Destruktor wykonal sie " << ++i << " razy." << std::endl;
}


int Czlowiek::getAge(){
    return wiek;
}

std::string Czlowiek:: getName(){
    return imie;
}

void Czlowiek::setAge (int age){
    if (age < 18 ){
        std::cout << "Wiek niedozwolony!" << std::endl;
        wiek = 18;
    } else{
        wiek = age;
    }    
}

void Czlowiek::setName(std::string name){
    imie = name;
}

