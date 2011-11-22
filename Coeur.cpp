#include "Coeur.h"

#include <iostream>
using namespace std;


/*-------------------Fonctions Membres----------------------------*/
void Coeur::placeEnregistrement(Enregistrement e){

}

int Coeur::trouverPage(int cle){
    int np;

    //Si aucune page dans le bucket n'à d'enregistrement libre...
    Bucket bucket = buckets[hachage(cle)];
    if((np = bucket.premierLibre()) == -1){
        //...On rajoute une page au bucket

    }

    return np;
}

/*Hache l'entier a par la fonction de hachage n*/
int Coeur::hachage(int a){
    return a%n;
}

/*Creer un nouveau bucket*/
void Coeur::createBucket(){
    buckets.push_back(Bucket());
}


/*--------------------Constructor/Destructor----------------------*/
Coeur::Coeur(){
    if (alreadyCreated)
        cout << "Vous ne pouvez pas creer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on declare l'objet cree
    alreadyCreated = true;

    n=0;
    next = 0;
    ronde = 0;
}

Coeur::~Coeur()
{
    // Si on veut pouvoir recreer la classe plus tard, on declare l'objet non-existant
    alreadyCreated = false;
}

bool Coeur::alreadyCreated = false;
