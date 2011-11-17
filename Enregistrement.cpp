#include "Enregistrement.h"
#include <string.h>

Enregistrement::Enregistrement(){
}

Enregistrement::Enregistrement(int a, char* b){
    m_a = a;
    strcpy(m_b, b);
}

//Destructor
Enregistrement::~Enregistrement(){

}
