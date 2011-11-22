#include "Page.h"
#include "Enregistrement.h"
#include <iostream>

using namespace std;

bool Page::debord(){
    return m_hasDebord;
}

int Page::getPageDebordement(){
    return m_pageDebordement;
}

int Page::premierLibre(){
    for(int i=1, libre=1; i<256; i*=2, libre++){
        if(m_occupation & i)
            return libre;
    }

    return -1;
}

void Page::afficher(ostream &out) const{
    //On afffiche chaque enregistrement occupe
    for(int i=1, lequel=0; i<256; i*=2, lequel++){
        //Si la case est occupŽ on l'affiche
        if(m_occupation & i){
            out << "\t\tEnregistrement :" << i << " : " ;
            out << m_enregistrements[lequel] ;
            out << endl;
        }
    }
    out << "\t\tGestion :"<< m_hasDebord << " / " << m_pageDebordement << " / " << (int)m_occupation;

}

ostream& operator<<(ostream& out, Page const& page){
    page.afficher(out);
    return out;
}

Page::Page(){
    //les infos de la page
    m_occupation = 3;
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
