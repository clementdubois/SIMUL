#include "Enregistrement.h"
#include <string.h>

#include <iostream>
using namespace std;

void Enregistrement::afficher(ostream &out) const{
    //On afffiche l'enregistrement
    out << m_a << "::" << m_b;

}

ostream& operator<<(ostream& out, Enregistrement const& enregistrement){
    enregistrement.afficher(out);
    return out;
}

Enregistrement::Enregistrement(){
    m_a = 0;
    strcpy(m_b, "test");
}
Enregistrement::Enregistrement(int a, char* b){
    m_a = a;
    strcpy(m_b, b);
}

//Destructor
Enregistrement::~Enregistrement(){
}
