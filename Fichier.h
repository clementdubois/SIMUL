#ifndef FICHIER_H
#define FICHIER_H

#include "Page.h"
#define NOMBRE_PAGE 128
#define OCCUPATION NOMBRE_PAGE/8

class Fichier
{
    public:
        Page m_pages[NOMBRE_PAGE];
        char m_occupation[OCCUPATION];
        int m_fctHach;

        Fichier();
        ~Fichier();
        Fichier(int fctHach);
    protected:
    private:
};

#endif // FICHIER_H
