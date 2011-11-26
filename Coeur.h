#ifndef COEUR_H
#define COEUR_H
#include <vector>
#include <map>
#include "Page.h"
#include "Enregistrement.h"
#include "Bucket.h"

#define NOMBRE_PAGE 32

/*Coeur du programme (Singleton)*/
class Coeur
{
    public:
        Coeur();
        ~Coeur();
        void placeEnregistrement(Enregistrement e);
        int trouverPage(int cle); //Trouve la page pour mettre l'enregistrement, renvoit -1 si aucune page n'est trouvé
        void createBucket();
        void creerPageDebordement();

    protected:
    private:
        std::map<int, Page> m_pages;      //Liste des pages
        int m_n;                          //fonction de hachage courante (1, 2, 4, 8, 16....)
        int m_next;                       //Position du pointeur next
        int m_ronde;                      //Index maximum de la ronde

        //TODO faire un tableau de int dynamique pour pouvoir ajouter plus de page dans le fichier
        int m_occupation;                 //Bit à droite à 1 => première page occupée...

        static bool m_alreadyCreated;     //singleton

        int m_maxDirect;                  // L'index de la dernière page accessible directement
        int m_minDebordement;             // L'index de la dernière page de débordement

        int hachage(int a);

    public:

};


#endif // COEUR_H
