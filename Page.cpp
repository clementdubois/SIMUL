#include "Page.h"
#include "Enregistrement.h"
#include <iostream>
#include <math.h>

using namespace std;

void Page::insererEnregistrement(Enregistrement e){
    int position = premierLibre();
    m_enregistrements[position] = e;
    m_occupation += pow(2, position);
}

/*Récupère un enregistrement grâce à son index n dans la page*/
Enregistrement Page::getEnregistrement(int n){
        return m_enregistrements[n];
}
/*Récupère des enregistrements grâce à la cle a*/
vector<Enregistrement> Page::getEnregistrementsByCle(int a){
    vector<Enregistrement> results;

    for(int n = 0; n<NOMBRE_ENREGISTREMENT; n++){
        if(!estLibre(n))
            results.push_back(getEnregistrement(n));
    }

    return results;
}

/*Supprime un enregistrement de l'emplacement n*/
void Page::supprimerEnregistrement(int n){
    m_occupation -= pow(2,n);
}

//Modifie les informations de la page pour indiquer que se page de débordement est utilisée et est à l'index cleDebordement
void Page::ajouterPageDebordement(int cleDebordement){
    m_hasDebord = true;
    m_pageDebordement = cleDebordement;
}
//Modifie la page pour indiquer qu'elle ne déborde plus
void Page::supprimerPageDebordement(int cleDebordement){
    m_hasDebord = false;
}

bool Page::debord(){
    return m_hasDebord;
}

int Page::getPageDebordement(){
    if(debord())
        return m_pageDebordement;
    else
        return -1;
}

int Page::premierLibre(){
    for(int i=0; i<NOMBRE_ENREGISTREMENT; i++){
        if(estLibre(i))
            return i;
    }
    return -1;
}

bool Page::estLibre(int n){
    return (!(m_occupation >> n & 1));
}

bool Page::estPleine(){
    return m_occupation == (int)pow(2, NOMBRE_ENREGISTREMENT) - 1;
}

bool Page::estVide(){
    return m_occupation == 0;
}

void Page::afficher(ostream &out) const{
    //On afffiche chaque enregistrement occupe
    int max = sizeof(m_occupation)*8;
    for(int n=0, occ = m_occupation; n<max; n++, occ >>= 1){
        //Si la case est occupé on l'affiche
        if(occ & 1){
            out << "-----------------------------------" << endl;
            out << "Enregistrement :" << n << " : " ;
            out << m_enregistrements[n] ;
            out << endl;
        }
    }
    out << "---------------------------------------------" << endl;
    out << "| Deborde ? | Page debordement | occupation |" << endl;
    out << "|    " << boolalpha <<  m_hasDebord << "   |    " << m_pageDebordement ;
    out << "     |     " << "0x" << hex << m_occupation  << "    |" << endl;
    out << "---------------------------------------------" << endl;

}

ostream& operator<<(ostream& out, Page const& page){
    page.afficher(out);
    return out;
}

Page::Page(){
    //les infos de la page
    m_occupation = 0;
    m_hasDebord = false;
    m_pageDebordement = -1;
    //Les enregistrements
    for(int i=0; i<NOMBRE_ENREGISTREMENT; i++){
        m_enregistrements[i] = Enregistrement();
    }
}

Page::~Page(){
    //dtor
}
