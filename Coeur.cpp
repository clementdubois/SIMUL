#include "Coeur.h"
#include <math.h>
#include <iostream>
using namespace std;


/*------------------------Fonctions Membres----------------------------*/
void Coeur::placeEnregistrement(Enregistrement e){
    //On hache l'entier de l'enregistrement pour obtenir la cle du bucket
    int cleHashage = hachage(e.m_a);
    int clePage = cleHashage;

    //On vérifie que la première page du bucket 'cle' existe
    map<int, Page>::iterator it = m_pages.find(cleHashage);

    //Si la page existe
    if(it != m_pages.end()){

        Page p = m_pages[clePage];

        //Tant que la page est pleine et qu'on a une page de débordement ...
        while(p.estPleine() && p.debord()){
            //... On teste la page de débordement
            clePage = p.getPageDebordement();
            p = m_pages[clePage];
        }

        //Si la page est pleine mais qu'elle n'a pas de page suivante
        if(p.estPleine()){
            //On créer la page
            m_pages[m_minDebordement];
            //On indique qu'on utilise la page minDebordement
            m_occupation += pow(2, m_minDebordement);
            //On ajoute une page de débordement à la page du tableau
            m_pages[clePage].ajouterPageDebordement(m_minDebordement);

            //On insère l'enregistrement e dans un espace vide de la page
            m_pages[m_minDebordement].insererEnregistrement(e);

            //On indique que la prochaine page de débordement devra se situer sur la page précédente
            m_minDebordement--;
        }else{
            //On insère l'enregistrement e dans un espace vide de la page
            m_pages[clePage].insererEnregistrement(e);
        }

    }else{ // Si elle n'existe pas

    }

}

int Coeur::trouverPage(int cle){
   return 0;
}

void Coeur::creerPageDebordement(){

}

/*Hache l'entier a par la fonction de hachage n*/
int Coeur::hachage(int a){
    return a%m_n;
}


/*--------------------Constructor/Destructor----------------------*/
Coeur::Coeur(){
    if (m_alreadyCreated)
        cout << "Vous ne pouvez pas creer une seconde instance de la classe Singleton." << endl;
    // Sinon, on construit la classe et on declare l'objet cree
    m_alreadyCreated = true;

    m_n=0;
    m_next = 0;
    m_ronde = 0;

    m_maxDirect = 0;
    m_minDebordement = NOMBRE_PAGE - 1;
}

Coeur::~Coeur()
{
    // Si on veut pouvoir recreer la classe plus tard, on declare l'objet non-existant
    m_alreadyCreated = false;
}

bool Coeur::m_alreadyCreated = false;
