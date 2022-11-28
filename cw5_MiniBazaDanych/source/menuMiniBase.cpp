#include "menuMiniBase.hpp"


void menuMiniBase::sayHello()
{
    std::cout << "Witaj, oto cwiczebna mini baza danych :)" << std::endl;
}

void menuMiniBase::availableMenuOptions()
{
    std::cout << "MENU: " << std::endl;
    std::cout << "1. Dodaj osobe " << std::endl;
    std::cout << "2. Pokaz osoby " << std::endl;
    std::cout << "3. Zapisz osoby do pliku" << std::endl;
    std::cout << "4. Wczytaj osoby z pliku" << std::endl;
    std::cout << "5. Przeszukaj baze" << std::endl;
    std::cout << "6. Usun osobe z bazy danych" << std::endl;
}

