#ifndef PAGE_H
#define PAGE_H

#define NOMBRE_ENREGISTREMENT 2

#include "Enregistrement.h"
#include <iostream>

class Page{
    public:
        bool debord();
        int getPageDebordement();
        int premierLibre(); //Retourne la position du premier enregistrement non occupe

        void afficher(std::ostream &out) const;

        Enregistrement m_enregistrements[NOMBRE_ENREGISTREMENT];
        char m_occupation;
        bool m_hasDebord;
        int m_pageDebordement;

        Page();
        virtual ~Page();
    protected:
    private:
};

std::ostream& operator<<(std::ostream& out, Page const& page);


#endif // PAGE_H
