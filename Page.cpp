#include "Page.h"
#include "Enregistrement.h"
#include <iostream>
#include <math.h>

using namespace std;

void Page::insererEnregistrement(Enregistrement e){
    m_enregistrements[premierLibre()] = e;
}

//Modifie les informations de la page pour indiquer que se page de d�bordement est utilis�e et est � l'index cleDebordement
void Page::ajouterPageDebordement(int cleDebordement){
    m_hasDebord = true;
    m_pageDebordement = cleDebordement;
}

bool Page::debord(){
    return m_hasDebord;
}

int Page::getPageDebordement(){
    return m_pageDebordement;
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
    return !(m_occupation & (int)pow(2, NOMBRE_ENREGISTREMENT) - 1);
}

void Page::afficher(ostream &out) const{
    //On afffiche chaque enregistrement occupe
    for(int i=1, lequel=0; i<256; i*=2, lequel++){
        //Si la case est occup� on l'affiche
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
