#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

#define NOMBRE_CARAC 46
#include <iostream>

class Enregistrement{
    public:
        int m_a;
        char m_b[NOMBRE_CARAC];

        void afficher(std::ostream &out) const;

        Enregistrement();
        Enregistrement(int a, char *b);
        virtual ~Enregistrement();
    protected:
    private:
};

std::ostream& operator<<(std::ostream& out, Enregistrement const& enregistrement);

#endif // ENREGISTREMENT_H
