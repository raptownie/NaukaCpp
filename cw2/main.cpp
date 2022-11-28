#include <iostream>
#include <cstdlib> // includuje funkcje "system"

class ExceptionsMessages
{
  public:
    void divZeroMessage();  
};

double dzielenie(double a, double b) throw(ExceptionsMessages)
{

        if (b == 0) throw ExceptionsMessages();
        return (a/b);       

}

int dodawanie (int a, int b)
{
    if (a==b) throw int();
    return (a+b);
}

int main ()
{
    try{
        dzielenie (5,1);
        dodawanie (5,5);
    }
    //dzielenie (5,0);
    catch(ExceptionsMessages wyjatek)
    {
        wyjatek.divZeroMessage();
    }
    catch(int wyjatek)
    {
        std::cout << "dodawanie rownych liczb, moze lepiej pomnozyc>? " << std::endl;
    }
    catch(...)
    {
        std::cout << "Blad nie obsluzony" << std::endl;
    }

    system ("pause");
    return 0;
}


void ExceptionsMessages::divZeroMessage()
{
    std::cout << "Nie dziel przez zero!" << std::endl;
}