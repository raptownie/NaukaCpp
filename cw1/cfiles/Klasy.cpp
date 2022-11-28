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


Ulamek::Ulamek(){
    this->x = 0;
    this->y = 1;
    std::cout << "Konstruktor wykonal sie " << ++(this->counter) << " razy." << std::endl;
}

Ulamek::~Ulamek(){

}

void Ulamek::setLicznik(int x){
    this->x = x;
}

void Ulamek::setMianownik(int y){
    this->y = y;
}


int Ulamek::getLicznik() const {
    return this->x;
}

int Ulamek::getMianownik() const {
    return this->y;
}

void Ulamek::dodajUlamek(Ulamek x){
    int mianownikTempIn = this->y;
    int licznikTempIn = 0;
    if ( (this->y) != (x.getMianownik())){        
        mianownikTempIn = this->y * x.getMianownik();
        licznikTempIn = (this->x *x.getMianownik()) + (x.getLicznik() * this->y);
    }
    else{
        licznikTempIn = this->x + x.getLicznik();
    }
    this->setLicznik(licznikTempIn);
    this->setMianownik(mianownikTempIn);
}

int Ulamek::counter = 0;