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

struct data {
    int a;
    int b;
    float c;
};


#endif