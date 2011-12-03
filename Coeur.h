#ifndef COEUR_H
#define COEUR_H
#include <vector>
#include <map>
#include "Page.h"
#include "Enregistrement.h"
#include "Bucket.h"

#define NOMBRE_PAGE 32

/*Coeur du programme*/
class Coeur
{
    public:
        Coeur();
        ~Coeur();
        void placeEnregistrement(Enregistrement enr);
        Page trouverPage(int cle); //Trouve la page
        int ajouterPageDebordement(int numPage);
        bool isDebordement(int numPage); //La page est elle une page de d�bordement ?
        int supprimerPage(int numPage); // On indique que la page numPage n'est plus utilis�e, retourne l'index de la page de d�bordement suivante si elle existe
        Page ajouterPage(int numPage);
        bool estLibre(int n); // La page n est elle utilis�e ?
        std::map<int, Page> getPages();
        int premierePageNonRemplieBucket(int numPage);
        void pageOccupee(int numPage); /*On met le bit d'occupation de la page � l'index numPage � 1*/
        void afficher(std::ostream &out) ;
        Page ajouterBucket(int numBucket); //Cr�er la premi�re page d'un bucket
        inline bool finRonde();

        std::vector<Enregistrement> trouverEnregistrement(int a); //Trouve les enregistrements dont l'index est a

        friend class TestCoeur; //On permet � la classe de test d'acc�der � tout le coeur en public
    protected:
    private:
        std::map<int, Page> m_pages;      //Liste des pages
        int m_n;                          //fonction de hachage courante (1, 2, 4, 8, 16....)
        int m_next;                       //Position du pointeur next
        int m_ronde;                      //Index maximum de la ronde

        //TODO faire un tableau de int dynamique pour pouvoir ajouter plus de page dans le fichier
        unsigned int m_occupation;                 //Bit � droite � 1 => premi�re page occup�e...

        int m_nbBuckets;                  // L'index de la derni�re page accessible directement
        int m_minDebordement;             // L'index de la derni�re page de d�bordement

        int hachage(int a,int n);
        void reinitialiser();

    public:

};

std::ostream& operator<<(std::ostream& out, Coeur coeur);


#endif // COEUR_H
