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
        bool estLibre(int n); // L'enregistrement n est il occupŽ ?
        bool estPleine(); // La page est-elle pleine ?
        void ajouterPageDebordement(int cleDebordement); //Modfie la page pour indiquer qu'elle à une page de débordement
        void insererEnregistrement(Enregistrement e);

        void afficher(std::ostream &out) const;

        Enregistrement m_enregistrements[NOMBRE_ENREGISTREMENT];
        int m_occupation; // Premier bit : le premier enregistrement est utilisé(jusqu'a 32 enregistrements)
        bool m_hasDebord; // La page à t'elle une page de débordement ?
        int m_pageDebordement; // Quelle est la page de débordement ?

        Page();
        virtual ~Page();
    protected:
    private:
};

std::ostream& operator<<(std::ostream& out, Page const& page);


#endif // PAGE_H
