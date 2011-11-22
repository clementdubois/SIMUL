#include "Bucket.h"
#include "Page.h"

#include <iostream>
using namespace std;

void Bucket::addPage(Page page){
    pages.push_back(page);
}

void Bucket::removeLastPage(){
    pages.pop_back();
}

/*Renvoi l'indice de la première page avec au moins un enregistrement libre
* ou renvoit -1 si rien est libre dans le bucket
*/
int Bucket::premierLibre(){
    for(int i=0; i<pages.size(); i++){
        if(pages[i].premierLibre() != -1)
            return i;
    }
    return -1;
}

void Bucket::afficher(ostream &out) const{
    out << "Bucket :" << endl;
    for(int i=0; i<pages.size(); i++){
        out << "\t" << "Page " << i << " :" << endl;
        out << pages[i] << endl;
    }
}

ostream& operator<<(ostream& out, Bucket const& bucket){
    bucket.afficher(out) ;
    return out;
}

Bucket::Bucket()
{
    addPage(Page());
}

Bucket::~Bucket()
{

}
