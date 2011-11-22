#ifndef COEUR_H
#define COEUR_H
#include <vector>
#include "Page.h"
#include "Enregistrement.h"
#include "Bucket.h"

#define NOMBRE_PAGE 128

/*Coeur du programme (Singleton)*/
class Coeur
{
    public:
        Coeur();
        ~Coeur();
        void placeEnregistrement(Enregistrement e);
        int trouverPage(int cle);
        void createBucket();

    protected:
    private:
        std::vector<Bucket> buckets;    //Liste des buckets
        int n;                          //fonction de hachage courante (1, 2, 4, 8, 16....)
        int next;                       //Position du pointeur next
        int ronde;                      //Index maximum de la ronde
        static bool alreadyCreated;

        int hachage(int a);

    public:

};


#endif // COEUR_H
