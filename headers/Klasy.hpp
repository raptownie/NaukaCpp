#ifndef _KlasyHeader
#define _KlasyHeader

#include <iostream>

class Czlowiek{
    private:
        std::string imie;
        int wiek;
    public:     
        Czlowiek();
        Czlowiek(int age);
        ~Czlowiek();
        void setAge (int age);
        void setName (std::string name);
        int getAge ();
        std::string getName();
};

class Ulamek {
    public:
        Ulamek();
        ~Ulamek();
        int getLicznik() const;
        int getMianownik() const;
        void setLicznik(int x);
        void setMianownik(int y);
        void dodajUlamek(Ulamek p);
        static int counter;
    private:
        int x;
        int y;        
};

#endif