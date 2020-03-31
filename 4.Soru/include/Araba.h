#ifndef ARABA_H
#define ARABA_H

class Araba
{
    public:
        Araba();
        void setX(int x);
        int getX();
        int getY();
        void setY(int y);
        virtual ~Araba();
        void xEgit();
        void yukariCikar();
    protected:

    private:
        int x,y;
        char renk;
        bool onumBosmu;

};

#endif // ARABA_H
