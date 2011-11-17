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
        cout << "Vous ne pouvez pas crŽer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on dŽclare l'objet crŽŽ
    alreadyCreated = true;
}

Coeur::~Coeur()
{
    // Si on veut pouvoir recrŽer la classe plus tard, on dŽclare l'objet non-existant
    alreadyCreated = false;
}

bool Coeur::alreadyCreated = false;
