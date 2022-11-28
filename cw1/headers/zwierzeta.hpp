#ifndef _zwierzeta
#define _zwierzeta

/* */

class Zwierze {
    public:
        Zwierze();
        virtual ~Zwierze();
        virtual void DajGlos(void);/* jeśli ta klasa bedzie dziedzizona to zeby dac znac kompilatorowi ze jesli obiekt  */
    private:
        int i;
    protected:
};

class Krowa : public Zwierze
{
    public:
        Krowa();
        ~Krowa();
        void DajGlos(void);
        void Mut(int b);
    private:
        //static int k = 5; /*zakazane inicjalizacja membera wewnatrz klasy - musi byc constem */
        int k;
};


#endif