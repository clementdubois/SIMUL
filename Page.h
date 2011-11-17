#ifndef PAGE_H
#define PAGE_H

#define NOMBRE_ENREGISTREMENT 2

#include "Enregistrement.h"

class Page{
    public:
        Enregistrement m_enregistrements[NOMBRE_ENREGISTREMENT];
        char m_occupation;
        bool m_hasDebord;
        int m_pageDebordement;

        Page();
        virtual ~Page();
    protected:
    private:
};

#endif // PAGE_H
