#include "headers/main.hpp"

union Typsd{
    uint8_t Workhard5;
    uint16_t playhardID;
}das;



int main(int argc, char * argv[]){
    /*
    std::cout << "Podaj liczbe elementow w tablicy: ";
    std::cin >> a;

    double *tab = new double[a];

    for (int i=0; i<a; i++){
        std::cout << "Podaj " << (i+1) << " wartosc: ";
        std::cin >> tab[i];
    }

    std::cout << std::endl << std::endl;

    for (int i=0; i<a; i++){
        std::cout << "tab[" << i << "] = " << static_cast<double>(tab[i]) << std::endl;
    }
    */

   /*
    std::string kolorek;
    kolorek.length();
*/
    /*
    std::cout << argc << std::endl;
    std::cout << "Wartosc argv : " << argv[0]<< std::endl;
    int a;
    while(argc--){
        if (!strcmp(argv[argc], "b")){     
            a = 1; 
        }
        if (!strcmp(argv[argc], "t")){
            a = 2;
        }
           
    }
    std::cout << "a = " << a << std::endl;

    */
   /*
    double LiczbaZmiennoPrzecinkowa = 3.14;
    std::cout << "Liczba przed rzutowaniem : " << LiczbaZmiennoPrzecinkowa << std::endl;
    std::cout << "Liczba PO RZUTOWANIU : " << ConvertToInt(LiczbaZmiennoPrzecinkowa) << std::endl;
    */
    /*
    int LiczbaLudzi;
    std::cout << "Podaj liczbe ludkow: ";
    std::cin >> LiczbaLudzi; 
 
    HumanData* DaneLudkow = Wypeln ijDaneLudzi(LiczbaLudzi);
    
    WyswietlDaneLudkow( DaneLudkow, LiczbaLudzi);
    */
   /*
    Czlowiek Kamcioszkin(29);
    
    //Kamcioszkin.setAge(5);
    std::cout << "imie Kamila to : " << Kamcioszkin.getName() << std::endl; 
    std::cout << "wiek Kamila to : " << Kamcioszkin.getAge() << std::endl;    



    int8_t temp = 0;
    if (temp) std::cout << "wykonalo sie" << std::endl;
    */  

   Zwierze Zwierzatko;
   Krowa Krowiatko;
 std::cout << " deklaracja zwierza : " <<std::endl;
   Zwierze *pZwierze = new Zwierze;

   std::cout << " deklaracja krowy : " <<std::endl;
   Krowa *pKrowa = new Krowa;

    pZwierze = &Krowiatko;
    pZwierze->DajGlos();



    delete pKrowa;
    delete pZwierze;
    std::cout << "wiek Kamila to : " << Kamcioszkin.getAge() << std::endl;


    Ulamek a;
    Ulamek b;

    a.setLicznik(5);
    a.setMianownik(2);
    b.setLicznik(10);
    b.setMianownik(3);
    a.dodajUlamek(b);
    std::cout << "Po dodawaniu ulamkow = " << a.getLicznik() << "/" << a.getMianownik() << std::endl;

    system("pause");
    return 0;
}
