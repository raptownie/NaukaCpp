#include "../headers/daneCzlowieka.hpp"
#include <iostream>

HumanData * WypelnijDaneLudzi(int LiczbaLudkow){
    HumanData * HumanStruct = new HumanData[LiczbaLudkow];
    for (int i=0; i<LiczbaLudkow; i++){
        std::cout << "Podaj imie osoby " << (i+1) << " :";
        std::cin >> HumanStruct[i].imie;
        std::cout << "Podaj nazwisko osoby " << (i+1) << " :";
        std::cin >> HumanStruct[i].nazwisko;
        std::cout << "Podaj nr Telefonu osoby " << (i+1) << " :";
        std::cin >> HumanStruct[i].nrTel;
        std::cout << "Podaj wiek osoby " << (i+1) << " :";
        std::cin >> HumanStruct[i].wiek;
    }
    return HumanStruct;
}


void WyswietlDaneLudkow(HumanData* HumanStructData, int LiczbaLudkow){
    for(int i=0; i<LiczbaLudkow; i++){
        std::cout << "Imie " << (i+1) << " osoby: " << HumanStructData[i].imie << std::endl;
        std::cout << "Nazwisko " << (i+1) << " osoby: " << HumanStructData[i].nazwisko << std::endl;
        std::cout << "Nr Tel " << (i+1) << " osoby: " << HumanStructData[i].nrTel << std::endl;
        std::cout << "Wiek " << (i+1) << " osoby: " << HumanStructData[i].wiek << std::endl;
    }
}
 

