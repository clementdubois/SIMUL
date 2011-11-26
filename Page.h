#ifndef PAGE_H
#define PAGE_H

#define NOMBRE_ENREGISTREMENT 2

#include "Enregistrement.h"
#include <iostream>

class Page{
    public:
        bool debord();
        int getPageDebordement();
        int premierLibre(); //Retourne la position du premier enregistrement non occupe (-1 si la page est pleine)
        bool estLibre(int n); // L'enregistrement n est il occup� ?
        bool estPleine(); // La page est-elle pleine ?
        void ajouterPageDebordement(int cleDebordement); //Modfie la page pour indiquer qu'elle � une page de d�bordement
        void insererEnregistrement(Enregistrement e);

        void afficher(std::ostream &out) const;

        Enregistrement m_enregistrements[NOMBRE_ENREGISTREMENT];
        int m_occupation; // Premier bit : le premier enregistrement est utilis�(jusqu'a 32 enregistrements)
        bool m_hasDebord; // La page � t'elle une page de d�bordement ?
        int m_pageDebordement; // Quelle est la page de d�bordement ?

        Page();
        virtual ~Page();
    protected:
    private:
};

std::ostream& operator<<(std::ostream& out, Page const& page);


#endif // PAGE_H
