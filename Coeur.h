#ifndef COEUR_H
#define COEUR_H

#include "Page.h"
/*Coeur du programme (Singleton)*/
class Coeur
{
    public:
        Coeur();
        ~Coeur();
    protected:
    private:
        Page *buckets;
        static bool alreadyCreated;
        int hachage(int a, int n);

    public:


};


#endif // COEUR_H
