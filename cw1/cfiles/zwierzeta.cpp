#include "../headers/zwierzeta.hpp"
#include <iostream>

Zwierze::Zwierze(){
    std::cout << "Konstruktor zwierzecia" << std::endl;
}

Zwierze::~Zwierze(){
    std::cout << "Destruktor Zwierze" << std::endl;
}

void Zwierze::DajGlos(void){
    std::cout << "Glos Zwierze" << std::endl;
}

Krowa::Krowa(){
    std::cout << "Konstruktor Krowa" << std::endl;
}

Krowa::~Krowa(){
    std::cout << "Destruktor Krowa" << std::endl;
}

void Krowa::DajGlos(void){
    std::cout << "Muuuu kurwa" << std::endl;   
}

void Krowa::Mut(int b){
    this->k += b;
}
