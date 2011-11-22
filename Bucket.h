#ifndef BUCKET_H
#define BUCKET_H

#include "Page.h"
#include <vector>
#include <iostream>

class Bucket
{
    public:
        int premierLibre(); //Retourne la position du premier bucket ayant au moins un emplacement libre
        Bucket();
        virtual ~Bucket();

        void afficher(std::ostream &out) const;

        std::vector<Page> pages;

        void addPage(Page page);
        void removeLastPage();
    protected:
    private:

};

std::ostream& operator<<(std::ostream& out, Bucket const& bucket);


#endif // BUCKET_H
