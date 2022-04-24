#ifndef _daneCzlowieka
#define _daneCzlowieka
#include <iostream>
struct HumanData{
    std::string imie;
    std::string nazwisko;
    std::string nrTel;
    unsigned short wiek;
};

HumanData * WypelnijDaneLudzi(int );
void WyswietlDaneLudkow(HumanData* , int );

#endif