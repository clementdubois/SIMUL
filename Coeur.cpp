#include "Coeur.h"

#include <iostream>
using namespace std;


/*-------------------Fonctions Membres----------------------------*/
int hachage(int a, int n){
    return a%n;
}

/*--------------------Constructor/Destructor----------------------*/
Coeur::Coeur(){
    if (alreadyCreated)
        cout << "Vous ne pouvez pas cr�er une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on d�clare l'objet cr��
    alreadyCreated = true;
}

Coeur::~Coeur()
{
    // Si on veut pouvoir recr�er la classe plus tard, on d�clare l'objet non-existant
    alreadyCreated = false;
}

bool Coeur::alreadyCreated = false;
