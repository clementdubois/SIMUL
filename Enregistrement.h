#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

#define NOMBRE_CARAC

class Enregistrement{
    public:
        int m_a;
        char m_b[NOMBRE_CARAC];

        Enregistrement();
        Enregistrement(int a, char *b);
        virtual ~Enregistrement();
    protected:
    private:
};

#endif // ENREGISTREMENT_H
